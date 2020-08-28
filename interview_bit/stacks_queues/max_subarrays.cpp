#include<iostream>
#include<vector>
#include<set>

#include<algorithm>
using namespace std;


int main(void) {
    int T, n, m, x, i;
    cin >> T;
    while(T--){
        vector<int> max_heap;
        vector<int> arr, solution;
        set<int> notin;
        cin >> n >> m;
        for(i = 0; i < n; i++){
            cin >> x;
            arr.push_back(x);
        }
        for(i = 0; i < m; i++){
            max_heap.push_back(arr[i]);
        }

        make_heap(max_heap.begin(), max_heap.end());
        
        solution.push_back(max_heap.front());
        
        for(i = m; i < n; i++){
            notin.insert(arr[i-m]);

            max_heap.push_back(arr[i]);
            push_heap(max_heap.begin(), max_heap.end());
            if(notin.find(max_heap.front()) != notin.end()){
                pop_heap(max_heap.begin(), max_heap.end()); 
                max_heap.pop_back(); 
            }
            
            solution.push_back(max_heap.front());
        }
        for(auto s: solution)
            cout << s << " ";
        cout << endl;
    }
	return 0;
}