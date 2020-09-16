#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>   
#include <cstdio>  

using namespace std;

// This function breaks the line into words seperated with space
// For example: 01110 00110 11111 11110 11100 01100 
// the above line will break all the binary numbers sepearted by space
// used for both files pairs and ct1

/*
    Arg: Takes the vector of strings 
    Returns vector of vector of strings of token of each line
*/
vector < vector<string> > createTokens(vector <string> pairs){
    vector < vector<string> > allTokens;
    vector<string>::iterator ptr;
    for (ptr = pairs.begin(); ptr != pairs.end(); ptr++){
        vector <string> tokens;
        stringstream check1(*ptr);
        string intermediate;

        while(getline(check1, intermediate, ' ')){
            tokens.push_back(intermediate);
        }
        allTokens.push_back(tokens);
    }
    return allTokens;
}

// This function reads the pairs.txt line by line and then it divides each token seperated with space.
/*
    Arg: None
    Returns tokens(word seperated by space) of each lines
*/
vector < vector <string> > readingPairs(){
    vector <string> pairs;
    string line;
    ifstream infile;

    infile.open("pairs.txt"); 
    while(getline(infile, line)){
        pairs.push_back(line);
    }
    infile.close();

    vector < vector <string> > tokens = createTokens(pairs);
    return tokens;
}

// This function reads the ct1.txt line by line and then it divides each token seperated with space.
/*
    Arg: None
    Returns tokens(word seperated by space) of each lines
*/
vector < vector <string> > readingCypherText(){
    vector < vector <string> > CypherText;
    vector <string> CypherTextSt;
    string text;
    string line;
    ifstream infile;

    infile.open("ct1.txt"); 

    while(getline(infile, line)){
        CypherTextSt.push_back(line);
    }
    infile.close();

    CypherText = createTokens(CypherTextSt);
    return CypherText;
}


// Function to convert binary to decimal
/*
    Arg: Binary in string
    Returns intger decimial equivalent of given binary number
*/
int binaryToDecimal(string n){
    string num = n;
    int dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i=len-1;i>=0;i--){
        if (num[i] == '1')        
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}


//
/*
    Arg: 
        1. plainText(string): Raw string inputted from user.
        2. para(int):    Paragraph Number
        3. start(int):   Starting character for given paragraph
        4. allCypherText(vector < vector<string> >) all the words generated by function
*/

void fun(string plainText, int para, int start, vector < vector<string> > allCypherText, vector < vector<string> > allTokens){
    string encodeEq;
    int eq;
    char ch;
    int i;
    for(i = 0; i < plainText.length(); i++){
        if(plainText[i] == ' ')
            ch = '_';
        else
            ch = tolower(plainText[i]);

        encodeEq = allCypherText[para][start + i];
        eq = binaryToDecimal(encodeEq);

        bool isFound = false;
        for(int j = 0; j < allTokens[eq].size(); j++){
            if(allTokens[eq][j][0] == ch){
                isFound = true;
                cout << allTokens[eq][j][1];
            }
            else if (allTokens[eq][j][1] == ch){
                isFound = true;
                cout << allTokens[eq][j][0];
            }
        }
        if(!isFound){
            cout << endl << "No matching found for " << ch << " " << encodeEq << " " << i << endl;
        }
    }
    cout << endl;
}


int main(){
    vector < vector<string> > allTokens;
    vector < vector<string> > allCypherText;
    
    allTokens = readingPairs();
    allCypherText = readingCypherText();

    string text, para, startingChar;
    int t, p;

    cout << "Enter the para Number: ";
    getline (cin, para);
    stringstream readInt1(para);
    readInt1 >> p;

    cout << "Enter the starting char: ";
    getline (cin, startingChar);
    stringstream readInt2(startingChar);
    readInt2 >> t;

    cout << "Enter the raw Plain Text: ";
    getline (cin, text);

    cout << "Output: " << endl;
    fun(text, p, t, allCypherText, allTokens);

    // for(int i = 0; i < allCypherText.size(); i++){
    //     for(int j = 0; j < allCypherText[i].size(); j++){
    //         cout << allCypherText[i][j] << "\t\t";
    //     }
    //     cout << endl << endl << endl;
    // }

    return 0;
}