#include <iostream>
#include <iterator> 
#include <map> 
#include <cmath>
using namespace std;

int count = 0;


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


void countPerfectCubesCombUtil(map<int, int> *prime_factors, map<int, int> temp, 
							int l, int r, int index){
	map<int, int>::iterator itr; 

	if(index == 4){ // r = 4
		int isPerfectcube = true;
		for (itr = temp.begin(); itr != temp.end(); ++itr)
    		if(itr->second != 3)
    			isPerfectcube = false;

    	if(isPerfectcube)
			count++;
	}

	for(int i = l; i <= r; i++){
		// take it
		for (itr = prime_factors[i].begin(); itr != prime_factors[i].end(); ++itr){
			if(temp.find(itr->first) == temp.end()) // key not present
				temp.insert(pair<int, int>(itr->first, itr->second));
			else
				temp[itr->first] += itr->second;
		}

    	// recurisivly do for all the primefactors
		countPerfectCubesCombUtil(prime_factors, temp, i+1, r, index + 1);

		// leave it
		for (itr = prime_factors[i].begin(); itr != prime_factors[i].end(); ++itr)
    		temp[itr->first] -= itr->second;

	}
}


int countPerfectCubesComb(map<int, int> *prime_factors, int N){
	map<int, int> temp;
	countPerfectCubesCombUtil(prime_factors, temp, 0, N-1, 1);
}


int main(){
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

	// Part 2: Recursivly find the pairs of perfect cube
	countPerfectCubesComb(prime_factors, N);
	cout << count << endl;
}