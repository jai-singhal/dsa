#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

int min(int x, int y, int z) { 
    return min(min(x, y), z); 
} 
  
 
  
// Driver program 
int main() 
{ 
    // your code goes here 
    string str1 = "sunday"; 
    string str2 = "saturday"; 
  
    cout << editDist(str1, str2, str1.length(), str2.length()); 
  
    return 0; 
} 