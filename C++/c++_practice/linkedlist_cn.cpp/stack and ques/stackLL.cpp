#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node{
    public:
     T data;
     Node<T> *next;

     Node(T data){
         this->data = data;
         next =NULL;
     }

};

template <typename T>
class StackusingLL{
    private:
        Node<T> * head;
        int size;

    public:
        StackusingLL(){
            head = NULL;
            size=0;
        }

        
        int getsize(){
            return size;
        }

        int isEmpty(){
            return size == 0;
        }


        void push(T data){
            Node<T> *newnode = new Node<T>(data);
            if(head==NULL){
                head = newnode;
                size++;
            }
            else{
                newnode->next =head;
                head = newnode;
                size++;

            }
        }

        T pop(){

            if(head == NULL){
                return 0;
            }
            
            T data = head->data;
            head= head->next;
            size --;
            

            return data;


        }



        T top(){
            return head->data;
        }

    


};

int main(){

    StackusingLL<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << "top element of stack -->" << s.top() << endl;

    cout << "pop element of stack -->" << s.pop() << endl;

    cout << "stack is Empty -->" << s.isEmpty() << endl;

    cout << "size of stack -->" << s.getsize()<< endl;

    return 0;
}