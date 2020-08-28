#include<iostream>
#include<map>
#include<vector>

using namespace std;

vector<int> findSubstring(string A, const vector<string> &B) {
    map<string, int> words;
    vector<int> solution;
    int a_size = A.length();
    int total_words = B.size();
    for(auto word: B){
        if(words.find(word) == words.end())
            words.insert({word, 1});
        else
            words[word]++;
    }

    int wlen = B[0].length();
    for(int i = 0; i <= a_size - wlen*total_words; i++){
        int count = 0;
        int j = i;
        map<string, int> wfounds;
        while(words.find(A.substr(j, wlen)) != words.end()){
            string w = A.substr(j, wlen);
            if(wfounds.find(w) == wfounds.end())
                wfounds.insert({w, 1});
            else
                wfounds[w]++;
                
           if(wfounds[w] > words[w])
                break; 
            count++;
            if(count == total_words){
                solution.push_back(i);
                break;
            }
            j += wlen;
        }
    }
    
    return solution;
}
