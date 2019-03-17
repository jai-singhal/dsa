#include<bits/stdc++.h>
using namespace std;

vector<int> breakNumber(int n){
	vector<int> numb;
	while(n > 0){
		numb.push_back(n%10);
		n = n/10;
	}
	reverse(numb.begin(), numb.end());
	return numb;
}

int joinNumber(vector<int> numb){
	vector<int>::iterator it; 
	int n = 0;
	for(it = numb.begin(); it != numb.end(); ++it)
		n = n*10 + *it;
	return n;
}

int fun(int n, int d){
	vector<int> numb = breakNumber(n);
	vector<int>::iterator it, itr; 
	int newNumb = n, oldNumb = n;

	for(it = numb.begin(); it != numb.end(); ++it){
		if(*it >= d ){
		    if(*it == d && it == numb.end())
		        break;
		    numb.erase(it);
			numb.push_back(d);
		}
	}
	newNumb = joinNumber(numb);
	return newNumb;
}

int main() {
	int T, N, num, D;
	cin >> T;
	while(T--){
	   cin >> N >> D;
	   cout << fun(N, D) << endl;
	}
	return 0;
}
