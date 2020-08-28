#include<iostream>
#include<algorithm>
#include<map>
#include<iterator>

using namespace std;

int main(void) {
    int T, N, M, X;
    int* arr1, *arr2;
    cin >> T;
    while(T--){
        map<int, int> xPair;
        map<int, int>::iterator itr;
        
        cin >> N >> M >> X;
        arr1 = new int[N];
        arr2 = new int[M];
        for(int i = 0; i < N; i++)
            cin >> arr1[i];
        
        for(int i = 0; i < M; i++)
            cin >> arr2[i];

        sort(arr2, arr2+M);
        for(int i = 0; i < N; i++){
            if(binary_search(arr2, arr2 + M, X-arr1[i])){
                xPair.insert(pair<int,int>(arr1[i], X-arr1[i]));
            }
        }
        
        if(xPair.size() == 0){
            cout << -1 << endl;
        }
        else{
          for(itr = xPair.begin(); itr != xPair.end(); itr++){
                cout << itr->first << " " << itr->second;
                if(next(itr) != xPair.end())
                    cout << ", ";
                else
                    cout << endl;
            }
        }   

        delete arr1;
        delete arr2;
        
    }
    
	return 0;
}