#include<iostream>
#include <algorithm>
#include <cmath>


using namespace std;

struct island{
    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    int index;
    int distance;
};

bool compare(island lhs, island rhs) {
    return lhs.distance < rhs.distance;
}

int min_of_four(int a, int b, int c, int d){
    if(a < b && a < c && a < d) return a;
    else if(b < a && b < c && b < d) return b;
    else if(c < a && c < b && c < d) return c;
    else return d;
}

int main(){
    int N;
    int wx, wy;
    cin >> N;
    island arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i].x1 >> arr[i].y1 >> arr[i].x3 >> arr[i].y3;
        arr[i].x2 = arr[i].x1+1;
        arr[i].y2 = arr[i].y1;
        arr[i].x4 = arr[i].x3-1;
        arr[i].y4 = arr[i].y3;
        arr[i].index = i+1;
    }

    cin >> wx >> wy;

    for(int i = 0; i < N; i++){
        arr[i].distance = min_of_four(
            abs(arr[i].x1 - wx) + abs(arr[i].y1 - wy),
            abs(arr[i].x2 - wx) + abs(arr[i].y2 - wy),
            abs(arr[i].x3 - wx) + abs(arr[i].y3 - wy),
            abs(arr[i].x4 - wx) + abs(arr[i].y4 - wy)
        );
    }
    sort(arr, arr+N, compare);

    for(int i = 0; i < N; i++){
        cout << arr[i].index;
        if(i != N-1)
            cout << " ";
    }

    return 0;
}

/*

2
0 0 1 1
0 3 1 4
0 0


3
1 1 0 0
1 2 2 3
3 0 4 1
0 4

*/
