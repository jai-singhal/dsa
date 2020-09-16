#include<iostream>
#include<vector>

using namespace std;

class Heap{
    private:
        vector<int> heap;
        int size;
    public:
        Heap(vector<int> v){
            heap = v;
            size = v.size();
            make_heap();
        }
        int parent(int i){
            if(i == 0)  return -1;
            return (i+1)/2 - 1;
        }
        int lchild(int i){
            return 2*i+1;
        }
        int rchild(int i){
            return 2*i+2;
        }
        void swap(int i, int j){
            int temp;
            temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
        }
        void heapify(int i){
            while(i < size){
                if(lchild(i) >= size || rchild(i) >= size)
                    break;
                if(heap[lchild(i)] < heap[rchild(i)] && heap[lchild(i)] < heap[i]){
                    swap(lchild(i), i);
                    i = lchild(i);
                }
                else if(heap[lchild(i)] > heap[rchild(i)] && heap[rchild(i)] < heap[i]){
                    swap(rchild(i), i);
                    i = rchild(i);
                }
                else
                    break;
            }
        }

        void make_heap(){
            for(int i = size/2; i >= 0; i--){
                heapify(i);
            }
        }

        int extract_min(){
            int min_ = heap[0];
            swap(0, size-1);
            size--;
            heapify(0);
            return min_;
        }
        void print(){
            for(int i = 0; i < size; i++)
                cout << heap[i] << " ";
            cout << endl;
        }
};

int main(){
    vector<int> arr = {10, 2, 3, 5, 6, 1, 6, 2, 4};
    Heap h(arr);
    h.print();
    h.extract_min();
    h.print();
    h.extract_min();
    h.print();

}