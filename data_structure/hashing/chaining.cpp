#include<iostream>
#include<list>
using namespace std;

class Hash{
    private:
        int BUCKET;
        list<int>* table;

    public:
        Hash(int bucket){
            this->BUCKET = bucket;
            this->table = new list<int>[bucket];
        }
         // inserts a key into hash table
        void insertItem(int x){
            int index = hashFunction(x);
            this->table[index].push_back(x);
        }

        // deletes a key from hash table
        void deleteItem(int key){
            cout << endl << "Deletion of key == " << key << " called!!" << endl;
            int index = hashFunction(key);
            list <int> :: iterator it;
            for(it = table[index].begin(); it != table[index].end(); it++){
                if(*it == key)
                    break;
            }
            if(it != table[index].end())
                table[index].erase(it);
        }

        // hash function to map values to key
        int hashFunction(int x) {
            return (x % BUCKET);
        }

        void displayHash(){
            cout << endl << "////////////////////// Hash //////////////////" << endl;
            for(int i = 0; i < this->BUCKET; i++){
                cout << i << " ";
                list <int> :: iterator it;
                for(it = table[i].begin(); it != table[i].end(); ++it)
                    cout << "-> " << *it ;
                cout << endl;
            }
            cout << "//////////////////////////////////////////////" << endl;
        }
};

int main(void){
    // array that contains keys to be mapped
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a)/sizeof(a[0]);

    Hash h(7); // 7 is BUCKET SIZE

    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);

    h.displayHash();
    h.deleteItem(8);

    h.displayHash();
    return 0;
}
