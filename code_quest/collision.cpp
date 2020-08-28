#include<iostream>
#include<cmath>
#include <map>
#include <iterator>
using namespace std;


int main(){
    int C, x, y, v, t, d;
    cin >> C;
    map<float, int> collisons;
    for(int i = 1; i <= C; i++){
        cin >> x >> y >> v;
        d = sqrt(pow(x, 2) + pow(y, 2));
        t = ceilf((d/v)*100)/100;
        if(collisons.find(t) != collisons.end()){
            collisons.at(t) += 1;
        }
        else
           collisons.insert(pair<float, int>(t, 1));
    }

    int totalCollisions = 0;
    map<float, int>::iterator itr;
    for (itr = collisons.begin(); itr != collisons.end(); ++itr) {
        totalCollisions += (itr->second)*(itr->second-1)/2;
    }
    cout << totalCollisions << endl;
    return 0;
}

/*
5
5 12 1
16 63 5
-10 24 2
7 24 2
-24 7 2

 */
