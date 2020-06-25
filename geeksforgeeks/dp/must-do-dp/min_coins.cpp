#include <iostream>
using namespace std;

int main() {
	//code
	int T, N;
	int changes[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	cin >> T;
	while(T--){
	    cin >> N;
	    const int total_changes = sizeof(changes)/sizeof(int);
	    int demoniations[total_changes] = {0,};
	    int temp = N;
	    int j=total_changes - 1;
	    while(temp != 0){
	        while(changes[j] > temp){
	            j--;
	        }
	        temp = temp-changes[j];
	        demoniations[j]++;
	    }
	    for(int k = total_changes - 1; k >= 0; k--){
            while(demoniations[k]-- > 0)
                cout << changes[k] << " ";
	    }
	    
	}
	return 0;
}