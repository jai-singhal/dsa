#include <iostream>
#include <fstream>
#include <cstdlib>
#define MAX 10000

using namespace std;

int main(){
    ofstream outfile;
    outfile.open("random_no.txt");
    int i=0;
    while(i < 1000){
        outfile << rand()%MAX + 1 << " ";
        i++;
    }

    outfile.close();

    return 0;
}