#include <iostream>
using namespace std;

int main(){
	int N, M;
	int pi, bi;
	cin >> N;
	cin >> M;
	int price[M+1] = {0};
	int max_sum = 0;

	for(int i = 0; i < N; i++){
		cin >> pi;
		cin >> bi;
		if(price[bi] < pi || price[bi] == 0){
			max_sum += pi - price[bi]; 
			price[bi] = pi;
		}
	}
	cout << max_sum << endl;
}