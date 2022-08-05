#include <bits/stdc++.h>

using namespace std;

// # include vector
# define ll long long
# define pb push_back


class Dynamic_array{

    int *data;
    int next_index;
    int capacity;

    public:

        Dynamic_array(){
            data = new int[5];
            next_index=0;
            capacity=0;
        }
        // const because we dont want d2 to get change

        Dynamic_array(Dynamic_array const &d2){
            // this->data = d2.data; //shallow copy we should avoid this
            //deep copy
            this->data = new int[d2.capacity];
            for(int i=0; i<d2.next_index; i++){
                data[i] = d2.data[i];
            }
            this->next_index = d2.next_index;
            this->capacity = d2.capacity;
        }

        void operator=(Dynamic_array const &d2){
            
            this->data = new int[d2.capacity];
            for(int i=0; i<d2.next_index; i++){
                data[i] = d2.data[i];
            }
            this->next_index = d2.next_index;
            this->capacity = d2.capacity;

        }



        void print(){
            
            for(int i=0;i<next_index;i++){
                    cout <<  data[i] << " ";
                }
                cout << endl;
        }


        void add(int element){

            if(next_index==capacity){
                int *newdata = new int[2*capacity];
                for(int i=0;i<next_index;i++){
                    newdata[i] = data[i];
                }
                delete [] data;
                data = newdata;
                capacity = 2*capacity;
            }

            data[next_index] = element;
            next_index++;
            
        }

        void add(int i, int element){
            if(i < next_index){
                data[i] = element;
            }
            else if(i==next_index){
                add(element);
            }
            else{
                return;
            }

        }

        int get(int i){
            if(i< next_index){
                return data[i];
            }
            else{
                return -1;
            }
        }

};

int main(){

    Dynamic_array d1;
    d1.add(20);
    d1.add(10);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    d1.print();
    Dynamic_array d2(d1);
    Dynamic_array d3;
    d3=d1;
    d1.add(0,100);
    d1.print();
    d2.print();
    d3.print();






    return 0;
}