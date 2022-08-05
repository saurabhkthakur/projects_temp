#include <bits/stdc++.h>

using namespace std;



template <typename T>

class StackusingArray{

    private:
     T *data;
     int next_index;
     int capacity;

    public:

        StackusingArray(){
            data = new T[4];
            next_index=0;
            capacity = 4;
        }


        int size(){
            return next_index;
        }

        bool isEmpty(){
            return next_index==0;
        }


        void push(T d){

            if(next_index == capacity){
               T *newdata = new T[2*capacity];
               for(int i=0; i<capacity; i++){
                   newdata[i] = data[i];
               }

               delete [] data;
               data=newdata;
               capacity = capacity *2;
            }
            data[next_index] = d;
            next_index++;

        }

        T pop(){

            if(next_index == 0){
                cout << " stack is empty" << endl;
                return 0;
            }
            
            
            T element  = data[next_index-1];
            next_index--;
            return element;
        }

        T top(){

            if(next_index == 0){
                cout << " stack is empty" << endl;
                return 0;
            }
            
            
            return data[next_index-1];

        }


};


int main(){


    StackusingArray<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << "top element of stack -->" << s.top() << endl;

    cout << "pop element of stack -->" << s.pop() << endl;

    cout << "stack is Empty -->" << s.isEmpty() << endl;

    cout << "size of stack -->" << s.size() << endl;



}