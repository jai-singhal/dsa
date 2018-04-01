/*--------------------------------------------------------------------------*
 *----                                  ----*
 *----      This file defines a recursive-descent parser for a simple   ----*
 *----  grammar for cleaning one's house or apartment.          ----*
 *----                                  ----*
 *----      (1) S -> WS S                        ----*
 *----      (2) S -> RS S                        ----*
 *----      (3) S ->                     ----*
 *----      (4) WS -> WV the WL period               ----*
 *----      (5) RS -> RV the RL period               ----*
 *----      (6) WV -> wash|scrub                 ----*
 *----      (7) RV -> vacuum|sweep|mop               ----*
 *----      (8) WL -> WI WL                      ----*
 *----      (9) WL ->                        ----*
 *----      (10) RL -> RI RL                 ----*
 *----      (11) RL ->                       ----*
 *----      (12) WI -> dishes|pots|windows|sink|toilet|shower    ----*
 *----      (13) RI -> hall|foyer|bedroom|kitchen|bathroom       ----*
 *----                                  ----*
 *----      Compile with:                       ----*
 *----      g++ cleaningLang.cpp -o cleaningLang -g         ----*
 *----                                  ----*
 *----  ----    ----    ----    ----    ----    ----    ----    ----    ----*
 *----                                  ----*
 *----  Version 1.0     2018 March 28       Joseph Phillips ----*
 *----                                  ----*
 *--------------------------------------------------------------------------*/

//
// $ ./cleaningLang
// Expression to compute: Mop the bathroom.
// This house looks better already!
// $ ./cleaningLang
// Expression to compute: Wash the dishes.
// This house looks better already!
// $ ./cleaningLang
// Expression to compute: Wash the dishes pots windows.
// This house looks better already!
// $ ./cleaningLang
// Expression to compute: Wash the dishes pots windows. Mop the kitchen bathroom.  Vacuum the bedroom foyer.
// This house looks better already!

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <list>
#include <map>

  //  PURPOSE:  To tell the length of a global string.
  const int TEXT_LEN = 256;

//  PURPOSE:  To represent the different lexemes in the language.
typedef enum {
  END_OF_INPUT_SYM,
  THE_KEYWORD_SYM,

  WASH_KEYWORD_SYM,
  SCRUB_KEYWORD_SYM,

  VACUUM_KEYWORD_SYM,
  SWEEP_KEYWORD_SYM,
  MOP_KEYWORD_SYM,

  DISHES_KEYWORD_SYM,
  POTS_KEYWORD_SYM,
  WINDOWS_KEYWORD_SYM,
  SINK_KEYWORD_SYM,
  TOILET_KEYWORD_SYM,
  SHOWER_KEYWORD_SYM,

  HALL_KEYWORD_SYM,
  FOYER_KEYWORD_SYM,
  BEDROOM_KEYWORD_SYM,
  BATHROOM_KEYWORD_SYM,
  KITCHEN_KEYWORD_SYM,

  PERIOD_SYM,
  NUMBER_SYM,
  IDENTIFIER_SYM,
  STRING_SYM,
  BEGIN_PAREN_SYM,
  END_PAREN_SYM,
  COMMA_SYM
}
symbol_ty;

//  PURPOSE:  To represent the string delimitor character.
const char QUOTE_CHAR = 0x22;

//  PURPOSE:  To represent the decimal point character.
const char DECIMAL_PT_CHAR = '.';

/*  PURPOSE:  To implement an interface that manages the character source.
 */
class InputCharStream {
    //  I.  Member vars:
    //  PURPOSE:  To hold the input.
    std::string input_;

    //  PURPOSE:  To hold where the cursor is.
    int index_;

    //  II.  Disallowed auto-generated methods:

    //  III.  Protected methods:
    protected:

    public:
        //  IV.  Constructor(s), assignment op(s), factory(s) and destructor:
        //  PURPOSE:  To
    InputCharStream(std::string & newInput):
        input_(newInput), index_(0) {
    }

    //  V.  Accessors:

    //  VI.  Mutators:

    //  VII.  Methods that do main and misc work of class:
    //  PURPOSE:  To return the current char, or '\0' if there are no more.
    //  No parameters.
    char peek() const throw () {
        return ((index_ >= input_.length()) ? '\0' : input_[index_]);
    }

    //  PURPOSE:  To return 'true' if at eof-of-input, or 'false' otherwise.
    bool isAtEnd() const throw () {
        return (index_ >= input_.length());
    }

    //  PURPOSE:  To advance to the next char (if not already at end).  No
    //  parameters.  No return value.
    void advance() throw () {
        if (index_ < input_.length())
            index_++;
    }
};

//  PURPOSE:  To represent a parsed symbol, and any associated data.
class Symbol {
    //  I.  Member vars:
    //  PURPOSE:  To tell the type of symbol that '*this' represents.
    symbol_ty symbol_;

    //  PURPOSE:  To hold the address of a string associated with '*this' symbol
    //  (if there is one).
    std::string * stringPtr_;

    //  PURPOSE:  To hold the number associated with '*this' symbol (if there is one).
    double number_;

    //  II.  Disallowed auto-generated methods:
    //  No default constructor:
    Symbol();

    //  No copy constructor:
    Symbol(const Symbol & );

    //  No copy assignment op:
    Symbol & operator = (const Symbol & );

    protected:
    //  III.  Protected methods:

    public:
    //  IV.  Constructor(s), assignment op(s), factory(s) and destructor:
    //  PURPOSE:  To initialize '*this' to hold symbol 'newSymbol'.  No return
    //  value.
    Symbol(symbol_ty newSymbol):
        symbol_(newSymbol),
        stringPtr_(NULL),
        number_(0.0) {}

    //  PURPOSE:  To initialize '*this' to hold string 'newString'.  No return
    //  value.
    Symbol(const std::string & newString):
    symbol_(STRING_SYM),
    stringPtr_(new std::string(newString)),
    number_(0.0) {}

    //  PURPOSE:  To initialize '*this' to hold number 'newNumber'.  No return
    //  value.
    Symbol(double newNumber):
    symbol_(NUMBER_SYM),
    stringPtr_(NULL),
    number_(newNumber) {}

    //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return value.
    ~Symbol() {
        delete(stringPtr_);
    }

    //  V.  Accessors:
    //  PURPOSE:  To return the type associated with '*this' Symbol.  No parameters.
    symbol_ty getType() const {
        return (symbol_);
    }

    //  PURPOSE:  To return a reference to the string stored at '*this' Symbol,
    //  or a reference to the empty string if '*this' is not a string.
    const std::string & getString() const {
        static std::string empty("");
        return ((stringPtr_ == NULL) ? empty : * stringPtr_);
    }

    //  PURPOSE:  To return the number stored at '*this' Symbol, or '0' if
    //  '*this' does not represent a number.
    double getNumber() const {
        return (number_);
    }
};

//  PURPOSE:  To hold a shared global array of characters.
char text[TEXT_LEN];

//  PURPOSE:  To implement an interface that gathers characters into lexemes.
class TokenStream {
  //  I.  Member vars:
  //  PURPOSE:  To hold the source of the character input.
  InputCharStream & inputCharStream_;

  //  PURPOSE:  To hold the lastest lexeme parsed.
  Symbol * lastParsedPtr_;

  //  PURPOSE:  To hold the keyword string to symbol_ty mapping.
  std::map < std::string, symbol_ty >
    keywordToSymbolTMap_;

  //  II.  Disallowed auto-generated methods:
  //  No default constructor:
  TokenStream();

  //  No copy constructor:
  TokenStream(const TokenStream & );

  //  No copy assignment op:
  TokenStream & operator =
    (const TokenStream & );

  protected:
    //  III.  Protected methods:
    //  PURPOSE:  To return a pointer representing a scanned string constant.
    //  No parameters.
    Symbol * scanString() {
      std::string lex("");
      bool haveFoundEnd = false;

      //  Advance past first quote:
      inputCharStream_.advance();

      while (!inputCharStream_.isAtEnd()) {
        char c = inputCharStream_.peek();

        inputCharStream_.advance();

        if (c == QUOTE_CHAR) {
          haveFoundEnd = true;
          break;
        }

        lex += c;
      }

      if (!haveFoundEnd)
        throw "Non-terminated string constant";

      return (new Symbol(lex));
    }

  //  PURPOSE:  To return a pointer representing a scanned number.  No
  //  parameters.
  Symbol * scanNumber(){
    bool haveSeenDecimalPt = false;
    std::string lex("");
    char c;

    while (c = inputCharStream_.peek(),
      isdigit(c) || ((c == DECIMAL_PT_CHAR) &&
        !haveSeenDecimalPt
      )
    ) {
      lex += c;
      haveSeenDecimalPt = (c == DECIMAL_PT_CHAR);
      inputCharStream_.advance();
    }

    return (new Symbol(atof(lex.c_str())));
  }

  //  PURPOSE:  To return a pointer to a Symbol instance representing an
  //  address.
  Symbol * scanIdentifier() {
    std::string lex("");
    char c;

    lex += tolower(inputCharStream_.peek());
    inputCharStream_.advance();

    while (c = inputCharStream_.peek(),
      isalnum(c) || (c == '_')
    ) {
      lex += tolower(c);
      inputCharStream_.advance();
    }

    std::map < std::string, symbol_ty > ::iterator
    iter = keywordToSymbolTMap_.find(lex);

    if (iter != keywordToSymbolTMap_.end())
      return (new Symbol(iter -> second));

    std::string keywords;
    bool isFirst = true;

    return (new Symbol(IDENTIFIER_SYM));
    /*
     for  (iter  = keywordToSymbolTMap_.begin();
     iter != keywordToSymbolTMap_.end();
     iter++
     )
     {
     if  (isFirst)
     isFirst     = false;
     else
     keywords   += ", ";

     keywords += iter->first;
     }

     snprintf
     (text,TEXT_LEN,
     "Expected one of %s, not %s",
     keywords.c_str(),lex.c_str()
     );
     throw text;
     */
  }

  //  PURPOSE:  To return a pointer representing a scanned Symbol, or to return
  //  'new Symbol(END_OF_INPUT_SYM)' if the '*this' is at the end-of-input.
  //  No parameters.
  Symbol * scanner() {
    while (isspace(inputCharStream_.peek()))
      inputCharStream_.advance();

    if (inputCharStream_.isAtEnd())
      return (new Symbol(END_OF_INPUT_SYM));

    if (inputCharStream_.peek() == QUOTE_CHAR)
      return (scanString());

    if (isdigit(inputCharStream_.peek()))
      return (scanNumber());

    if (isalpha(inputCharStream_.peek()) || (inputCharStream_.peek() == '_'))
      return (scanIdentifier());

    char ch = inputCharStream_.peek();
    Symbol * symbolPtr = NULL;

    inputCharStream_.advance();

    switch (ch) {
    case '(':
      symbolPtr = new Symbol(BEGIN_PAREN_SYM);
      break;

    case ')':
      symbolPtr = new Symbol(END_PAREN_SYM);
      break;

    case ',':
      symbolPtr = new Symbol(COMMA_SYM);
      break;

    case '.':
      symbolPtr = new Symbol(PERIOD_SYM);
      break;

    default:
      throw "Unexpected character in input";
    }

    return (symbolPtr);
  }

  public:
    //  IV.  Constructor(s), assignment op(s), factory(s) and destructor:
    //  PURPOSE:  To initialize '*this' to tokenize given characters read from
    //      'newInputCharStream'.  No parameters.
    TokenStream(InputCharStream & newInputCharStream)
//   throw (const char * ):
//   inputCharStream_(newInputCharStream),
//     lastParsedPtr_(NULL)
    {
      keywordToSymbolTMap_["the"] = THE_KEYWORD_SYM;
      keywordToSymbolTMap_["wash"] = WASH_KEYWORD_SYM;
      keywordToSymbolTMap_["scrub"] = SCRUB_KEYWORD_SYM;
      keywordToSymbolTMap_["vacuum"] = VACUUM_KEYWORD_SYM;
      keywordToSymbolTMap_["sweep"] = SWEEP_KEYWORD_SYM;
      keywordToSymbolTMap_["mop"] = MOP_KEYWORD_SYM;
      keywordToSymbolTMap_["dishes"] = DISHES_KEYWORD_SYM;
      keywordToSymbolTMap_["pots"] = POTS_KEYWORD_SYM;
      keywordToSymbolTMap_["windows"] = WINDOWS_KEYWORD_SYM;
      keywordToSymbolTMap_["sink"] = SINK_KEYWORD_SYM;
      keywordToSymbolTMap_["toilet"] = TOILET_KEYWORD_SYM;
      keywordToSymbolTMap_["shower"] = SHOWER_KEYWORD_SYM;
      keywordToSymbolTMap_["hall"] = HALL_KEYWORD_SYM;
      keywordToSymbolTMap_["foyer"] = FOYER_KEYWORD_SYM;
      keywordToSymbolTMap_["bedroom"] = BEDROOM_KEYWORD_SYM;
      keywordToSymbolTMap_["bathroom"] = BATHROOM_KEYWORD_SYM;
      keywordToSymbolTMap_["kitchen"] = KITCHEN_KEYWORD_SYM;
      advance();
    }

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
  //  value.
  ~TokenStream() {}

  //  V.  Accessors:

  //  VI.  Mutators:

  //  VII.  Methods that do main and misc work of class:
  //  PURPOSE:  To return the 'symbol_ty' of the 'Symbol' instance that is next
  //  in the symbol stream.  No parameters.
  symbol_ty peek()
//   throw (const char * ) 
  {
    if (lastParsedPtr_ == NULL)
      lastParsedPtr_ = scanner();

    return (lastParsedPtr_ -> getType());
  }

  //  PURPOSE:  To return the pointer to the old Symbol at that was at the
  //  front of the symbol stream, and then to internally advance to the next
  //  Symbol instance (if not already at the end).  No parameters.
  Symbol * advance() {
    Symbol * toReturn = lastParsedPtr_;

    lastParsedPtr_ = scanner();
    return (toReturn);
  }

};

//  PURPOSE:  To parse non-terminal 'WashVerb' from 'tokenizer'.
void parseWashVerb(TokenStream & tokenizer) {
  //  I.  Application validity check:

  //  II.  Attempt to parse recipe:
  // YOUR CODE HERE

  //  III.  Finished:
}

//  PURPOSE:  To parse non-terminal 'RoomVerb' from 'tokenizer'.
void parseRoomVerb(TokenStream & tokenizer) {
  //  I.  Application validity check:

  //  II.  Attempt to parse recipe:
  // YOUR CODE HERE

  //  III.  Finished:
}

//  PURPOSE:  To parse non-terminal 'WashItem' from 'tokenizer'.
void parseWashItem(TokenStream & tokenizer) {
  //  I.  Application validity check:

  //  II.  Attempt to parse wash list:
  // YOUR CODE HERE

  //  III.  Finished:
}

//  PURPOSE:  To parse non-terminal 'WashList' from 'tokenizer'.
void parseWashList(TokenStream & tokenizer) {
  //  I.  Application validity check:

  //  II.  Attempt to parse wash list:
  // YOUR CODE HERE

  //  III.  Finished:
}

//  PURPOSE:  To parse non-terminal 'RoomItem' from 'tokenizer'.
void parseRoomItem(TokenStream & tokenizer) {
  //  I.  Application validity check:

  //  II.  Attempt to parse wash list:
  // YOUR CODE HERE

  //  III.  Finished:
}

//  PURPOSE:  To parse non-terminal 'RoomList' from 'tokenizer'.
void parseRoomList(TokenStream & tokenizer) {
  //  I.  Application validity check:

  //  II.  Attempt to parse wash list:
  // YOUR CODE HERE

  //  III.  Finished:
}

//  PURPOSE:  To parse non-terminal 'WashSentence' from 'tokenizer'.
void parseWashSentence (TokenStream & tokenizer) {
    //  I.  Application validity check:

    //  II.  Attempt to parse recipe:
    // YOUR CODE HERE

    //  III.  Finished:
  }

//  PURPOSE:  To parse non-terminal 'RoomSentence' from 'tokenizer'.
void parseRoomSentence(TokenStream & tokenizer) {
    //  I.  Application validity check:

    //  II.  Attempt to parse recipe:
    symbol_ty peek = tokenizer.peek();

    if ((peek == VACUUM_KEYWORD_SYM) ||
      (peek == SWEEP_KEYWORD_SYM) ||
      (peek == MOP_KEYWORD_SYM)
    ) {
      parseRoomVerb(tokenizer);

      if (tokenizer.peek() != THE_KEYWORD_SYM) {
        throw "Expected \"the\"";
      }
      delete(tokenizer.advance());

      parseRoomList(tokenizer);

      if (tokenizer.peek() != PERIOD_SYM) {
        throw "Expected \".\"";
      }
      delete(tokenizer.advance());

    } else {
      throw "Expected \"vacuum\", \"sweep\", \"mop\" or end";
    }

    //  III.  Finished:
  }

//  PURPOSE:  To parse non-terminal 'S' from 'tokenizer'.
void parseS(TokenStream & tokenizer) {
  //  I.  Application validity check:

  //  II.  Attempt to parse recipe:
  symbol_ty peek = tokenizer.peek();

  if (peek == END_OF_INPUT_SYM) {
    return;
  } else
  if ((peek == WASH_KEYWORD_SYM) || (peek == SCRUB_KEYWORD_SYM)) {
    parseWashSentence(tokenizer);
    parseS(tokenizer);
  } else
  if ((peek == VACUUM_KEYWORD_SYM) ||
    (peek == SWEEP_KEYWORD_SYM) ||
    (peek == MOP_KEYWORD_SYM)
  ) {
    parseRoomSentence(tokenizer);
    parseS(tokenizer);
  } else {
    throw "Expected \"wash\", \"scrub\", \"vacuum\", \"sweep\", \"mop\" or end";
  }

  //  III.  Finished:
}

//  PURPOSE:  To return a string with the expression to compute, either from
//  the command line or the keyboard.  'argc' tells how many arguments
//  were on the command line and 'argv[]' points to those arguments.
std::string getInput(int argc, char * argv[]) {
  //  I.  Application validity check:

  //  II.  Get input:
  //  II.A.  Handle command line input:
  if (argc > 1)
    return (std::string(argv[1]));

  //  II.B.  Handle keyboard input:
  std::string input;

  std::cout << "Expression to compute: ";
  std::getline(std::cin, input);

  //  III.  Finished:
  return (input);
}

//  PURPOSE:  To get, and attempt to compute, the expression.  The expression
//  may either come from the command line or the keyboard.  'argc' tells
//  how many arguments were on the command line and 'argv[]' points to
//  those arguments.  Returns 'EXIT_SUCCESS' if the expression was
//  successfully parsed and computed or 'EXIT_FAILURE' otherwise.
int main(int argc, char * argv[]) {
  std::string input(getInput(argc, argv));
  InputCharStream charStream(input);
  int status = EXIT_SUCCESS;

  try {
    TokenStream tokenizer(charStream);

    parseS(tokenizer);
    std::cout << "This house looks better already!" << std::endl;
  } catch (const char * messageCPtr) {
    std::cerr << messageCPtr << std::endl;
    status = EXIT_FAILURE;
  }

  return (status);
}
