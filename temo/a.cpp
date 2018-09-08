#include <iostream>
#include <vector>
#include <unistd.h>
#include <getopt.h>
#include <algorithm>

using namespace std;

// sort the data read from standard input
void sortdata(bool numeric, bool reverse);

int main(int argc, char *argv[]) {

  const char *param = argv[0]; //This field is the name of the option. It is a string. 

  // options
  //Flag variables to tell SortData method which task to perform
  bool numeric = false;
  bool reverse = false;
  
  struct option opts[] = {
    {"numeric", no_argument, NULL, 'n'},
    {"reverse", no_argument, NULL, 'r'},
    {"output", required_argument, NULL, 'o'},
    {"version", no_argument, NULL, 'v'},
    {"help", no_argument, NULL, 'h'},
    {NULL, 0, NULL, 0}
  };

  int ch;
   // When getopt returns -1, indicating no more options are present, the loop terminates.
  // parse the argument options - By Passing the Argument values and Options
  while ((ch = getopt_long(argc, argv, "nro:vh", opts, NULL)) != -1) {
    switch (ch) {
      case 'n':
        numeric = true;
        break;

      case 'r':
        reverse = true;
        break;

      case 'o':
        // open the output file and redirect it as
        // the standard output
        
        if (freopen(optarg, "w", stdout) == NULL) {
          fprintf(stderr, "Could not write into file %s\n", optarg);
        }
        break;

      case 'v':
        printf("Version: 1.0\n");
        return 0;

      case 'h':
        // display help message
        printf("Usage: %s\n", param);
        printf("       --version | -v: display current version\n");
        printf("       --numeric | -n: sort numerically\n"); // cout
        printf("       --reverse | -r: display result in reversed order\n");
        printf("       --output  | -o: save output into file\n");
        return 0;
    }
  }

  sortdata(numeric, reverse);

  return 0;
}

// sort the data read from standard input
void sortdata(bool numeric, bool rev) {
  vector<string> lines;
  // read data from the standard input until end of file
  string line;
  while (getline(cin, line)) {
    lines.push_back(line);
  }

  if (numeric) {
    // numeric sorting is required, parse the first column
    // as the number to sort
    vector<pair<int, string>> data;

    for (int i = 0; i < lines.size(); i++) {
      line = lines[i];
      //atoi -> Converts String to Integer
      int value = atoi(line.c_str());
      /*
      15, 15 Huseen null
      12, 12 Gaurav null
      122, 122 HH null
      14, 14 David asdsd
      */
      data.push_back(make_pair(value, line));
    }
    // sort the data and put it back to the lines vector
    sort(data.begin(), data.end());
    /*
      12, 12 Gaurav null
      14, 14 David asdsd
      15, 15 Huseen null
      122, 122 HH null
      */
    
    lines.clear();
    for (int i = 0; i < data.size(); i++) {
      lines.push_back(data[i].second);
    }
  } else {
    // sort the data as strings
    sort(lines.begin(), lines.end());
  }

  // reverse the lines if required
  if (rev) {
    reverse(lines.begin(), lines.end());
  }

  // save the output to the output stream
  for (int i = 0; i < lines.size(); i++) {
      cout << lines[i] << endl;
  }
}
