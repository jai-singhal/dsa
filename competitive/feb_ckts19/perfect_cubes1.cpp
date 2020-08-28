#include <iostream>
#include <iterator> 
#include <map> 
#include <cmath>
using namespace std;

map<int, int> primeFrequencyMap(int* facts, int m){ 
	map<int, int> factors;
	int n;
	for(int j = 0; j < m; j++){
		n = facts[j];
		
		if(n%2 == 0){
			factors.insert(pair<int, int>(2, 0));
		    while (n%2 == 0){ 
		    	factors[2] += 1;
		        n = n/2; 
		    }
		}
	    for (int i = 3; i <= sqrt(n); i = i+2) {
	    	if(n%i == 0){
	    		factors.insert(pair<int, int>(i, 0)); 
		        while (n%i == 0) {
			        factors[i] += 1;
	            	n = n/i; 
	        	}
	    	}
	    }
	    if (n > 2)
	        factors.insert(pair<int, int>(n, 1));
	}

    return factors;
} 


int getPerfectCubesCombination(map<int, int> *prime_factors, map<int, int> temp, 
							int l, int r, int depth){

	static int count = 0;
	map<int, int>::iterator itr; 
	if(depth == 4){
		int isPerfectcube = true;
		for (itr = temp.begin(); itr != temp.end(); ++itr){
			// cout << itr->first << " " << itr->second << endl;
    		if(itr->second != 3){
    			isPerfectcube = false;
    		}
    	}
    	// cout << endl << endl;

    	if(isPerfectcube){
			count++;
			for (itr = temp.begin(); itr != temp.end(); ++itr){
				cout << itr->first << " " << itr->second << endl;
	    	}
	    	cout << endl << endl;
			// cout << "Yes" << endl;
    	}
	}

	for(int i = l; i < r; i++){
		// take it

		for (itr = prime_factors[i].begin(); itr != prime_factors[i].end(); ++itr){
			if(temp.count(itr->first))
				temp[itr->first] += itr->second;
			else
	    		temp.insert(pair<int, int>(itr->first, itr->second));
		}

    	// recurisivly do for all the primefactors
		getPerfectCubesCombination(prime_factors, temp, i+1, r, depth++);

		// leave it
		for (itr = prime_factors[i].begin(); itr != prime_factors[i].end(); ++itr)
    		temp[itr->first] -= itr->second;

	}
	return count;
}

int main(){
// for (itr = prime_factors[i].begin(); itr != prime_factors[i].end(); ++itr) { 
//        cout << itr->first 
//            << '\t' << itr->second << '\n'; 
//   	}

	// Part 1: Create hash map of frequencies	
	int N, M;
	cin >> N;
	map<int, int> prime_factors[N];
	map<int, int>::iterator itr; 

	for (int i = 0; i < N; ++i){
		cin >> M;
		int facts[M];
		for (int j = 0; j < M; ++j){
			cin >> facts[j];
		}
		prime_factors[i] = primeFrequencyMap(facts, M);
	}

	map<int, int> temp;
	int count = getPerfectCubesCombination(prime_factors, temp, 0, N, 0);
	cout << count << endl;
}

// 10
// 3 1 2 3
// 5 2 4 12 11 20
// 3 6 1 6
// 2 1 1
// 2 1 1
// 4 6 2 1 2
// 5 11 22 11 22
// 2 1 11
// 3 11 1 22
// 4 5 1 6 2