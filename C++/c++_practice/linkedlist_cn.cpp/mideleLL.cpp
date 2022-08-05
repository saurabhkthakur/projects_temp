#include <bits/stdc++.h>

using namespace std;


class Node{
    public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        next = NULL;

    }
};


Node * take_input_better(){
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data!=-1)
    {
        Node *newnode = new Node(data);
        if(head==NULL){
            head= newnode;
            tail = newnode;
        }
        else{
            
            tail->next = newnode;
            tail = tail->next;

        }

        cin >> data;
    }
    return head;
    
}


void print(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next ;
    }
    cout << endl;
}

int find_mid(Node *head){

    Node * slow = head;
    Node * fast = head->next;
 
    while(fast != NULL ){
        if (fast->next==NULL){
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    
    return slow->data;
    

    // if(fast->next == NULL){
    //     return slow->data;
    // }
}



int main(){

    Node * head = take_input_better();
    print(head);

    int mid = find_mid(head);
    cout << mid ;

    return 0;
}

