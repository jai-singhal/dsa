#include <iostream>
#include <map>

/*
Maps are associative containers that store elements in a mapped fashion. 
Each element has a key value and a mapped value. No two mapped values can have same key values.
*/

/*
Functions associated with Map:
begin() – Returns an iterator to the first element in the map
end() – Returns an iterator to the theoretical element that follows last element in the map
size() – Returns the number of elements in the map
max_size() – Returns the maximum number of elements that the map can hold
empty() – Returns whether the map is empty
pair insert(keyvalue,mapvalue) – Adds a new element to the map
erase(iterator position) – Removes the element at the position pointed by the iterator
erase(const g)- Removes the key value ‘g’ from the map
clear() – Removes all the elements from the map
key_comp() / value_comp() – Returns the object that determines how the elements in the map are ordered (‘<' by default)
find(const g) – Returns an iterator to the element with key value ‘g’ in the map if found, else returns the iterator to end
count(const g) – Returns the number of matches to element with key value ‘g’ in the map
lower_bound(const g) – Returns an iterator to the first element that is equivalent to mapped value with key value ‘g’ 
                        or definitely will not go before the element with key value ‘g’ in the map
upper_bound(const g) – Returns an iterator to the first element that is equivalent to mapped value with key value ‘g’
                        or definitely will go after the element with key value ‘g’ in the map
*/

using namespace std;

int main(void){

    map<int, int>myMap;
    
    myMap.insert(pair <int, int> (1, 40));
    myMap.insert(pair <int, int> (2, 420));
    myMap.insert(pair <int, int> (3, 20));
    myMap.insert(pair <int, int> (5, 30));
    myMap.insert(pair <int, int> (5, 1000)); //duplicate key
    myMap.insert(pair <int, int> (6, 4120));
    myMap.insert(pair <int, int> (12, 41240));
    myMap.insert(pair <int, int> (10, 1460));
    myMap.insert(pair <int, int> (8, 4140));

    map<int, int> :: iterator it;

    for(it = myMap.begin(); it != myMap.end(); it++){
        cout << "{" << it->first << ": " << it->second << "}" << endl;
    }

    //removes the elemnt with key = 5
    myMap.erase(5);
    cout << "After erasing the key 5" << endl;
    for(it = myMap.begin(); it != myMap.end(); it++){
        cout << "{" << it->first << ": " << it->second << "}" << endl;
    }

    cout << myMap.find(10)->first;

    return 0;
}