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



Node * merge_sorted_LL(Node* head1, Node * head2){
    Node *final_head = NULL;
    Node *final_tail = NULL;

    while(head1!=NULL && head2 != NULL){

        if(final_head ==NULL && final_tail ==NULL){
            if(head1->data <= head2->data){
                final_head = head1;
                final_tail = head1;
                head1 = head1->next;
            }
            else{
                final_head = head2;
                final_tail = head2;
                head2 = head2->next;
            }

        }


        else if(head1->data <= head2->data){

            
            final_tail->next = head1;
            final_tail = head1;
            head1 = head1->next ;
        }
        else{
            final_tail->next = head2;
            final_tail = head2;
            head2 = head2->next;
        }

    }

    if(head1!=NULL){
        final_tail->next= head1;
    }
     if(head2!=NULL){
         final_tail->next= head2;
        
    }

    return final_head;




    
}

int main(){

    Node * head1 = take_input_better();
    print(head1);
    Node * head2 = take_input_better();
    print(head2);
    Node * head3 = merge_sorted_LL(head1, head2);
    print(head3);
    return 0;
}