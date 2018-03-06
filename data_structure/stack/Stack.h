template <typename T>

class Stack{
    int capacity;
    int* array;
    int top;
    
public:
    Stack(int capacity=20){
        this->capacity = capacity;
        this->top = -1;
        this->array = new T[capacity];
    }

    void push(T val){
        if(this->top >= this->capacity){
            //cout << "Stack Overflow" << endl;
            return;
        }
        this->array[++this->top] = val;
    }

    T pop(){
        if(this->top <= 0){
          //  cout << "Stack Underflow" << endl;
            return -1;
        }
        return this->array[top--];
    }

    int top_of_stack(){
        return this->array[top]; 
    }

    bool is_empty(){
        return this->top <= 0;
    }

};