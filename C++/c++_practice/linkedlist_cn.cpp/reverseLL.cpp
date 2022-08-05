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


Node * reverse_LL(Node * head){
    //base case
    if(head==NULL && head->next==NULL){
        return;
    }


    //assuming the we 2-3-4-5-null  we get correcr ans of recurrsion 5-4-3-null from recurssion solve for 1 case

    Node * smallans = reverse_LL(head->next);

    Node * temp = smallans;
    while(temp->next!=Null){
        temp = temp->next;
    }

    temp->next = head;
    head->next = NULL;

    return head;

}

int main(){

    Node * head1 = take_input_better();
    print(head1);
    head3 = reverse_LL(head1);
    print(head3);
    return 0;
}