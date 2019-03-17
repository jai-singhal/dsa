#include <iostream>
using namespace std;

int main() {
	int T, N, num, posCount = 0, negCount = 0;
	cin >> T;
	while(T--){
		posCount = 0;
		negCount = 0;
	   cin >> N;
	   for(int i = 0; i < N; i++){
	       cin >> num;
	       if(num > 0)
	       		posCount++;
	       	else
	       		negCount++;
	   }
	   if(posCount == 0 || negCount == 0)
            cout << N << " " << N << endl;
	   else if(posCount > negCount)
			cout << posCount << " " << negCount << endl;
		else
			cout << negCount << " " << posCount << endl;
	}
	return 0;
}
