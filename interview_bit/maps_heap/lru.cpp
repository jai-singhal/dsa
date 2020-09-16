#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

class LRUCache{
    private:
        int csize;
        int pagefaults;
        list<int> dequeue;
        unordered_map<int, list<int>::iterator > mq;  

    public:

        LRUCache(int c){
            this->csize = c;
            this->pagefaults = 0;
        }
    
        void refer(int x){
            if(mq.find(x) == mq.end()){
                if(dequeue.size() == csize){
                    int last = dequeue.back();
                    dequeue.pop_back();
                    mq.erase(last);
                }
                this->pagefaults++;
            }
            else{
                dequeue.erase(mq[x]);
            }
            dequeue.push_front(x);
            mq[x] = dequeue.begin();
        }

        void display(void){
            for(auto a: this->dequeue){
                cout << a << " ";
            }
            cout << endl;
        }
        int getPageFaults(){
            return this->pagefaults;
        }
};

int main(){
    LRUCache ca(4); 
  
    ca.refer(1); 
    ca.refer(2); 
    ca.refer(3); 
    ca.refer(1); 
    ca.refer(4); 
    ca.refer(5); 
    ca.display(); 
    cout << ca.getPageFaults() << endl;
    return 0;
}
