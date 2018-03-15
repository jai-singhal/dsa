#include<vector>
#include<fstream>
using namespace std;

vector<int> readFileAndMakeVector(){
    vector<int> v;
    int val;
    ifstream infile; 
    infile.open("../data/random_no.txt");
    while(!infile.eof()){
        infile >> val;
        v.push_back(val);
    } 
    return v;
}