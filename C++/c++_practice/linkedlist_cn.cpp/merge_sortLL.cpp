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


int find_mid(Node *head){

    Node * slow = head;
    Node * fast = head->next;
    int count = 0;
    while(fast != NULL ){
        if (fast->next==NULL){
            break;
        }
        slow = slow->next;
        count++;
        fast = fast->next->next;
    }

    
    return count;
}

// 2-4-5-6-79
// 2-4-5 
// 2-4
// 2
Node * merge_sort1(Node *head, int mid){

    if(head == NULL){
        return head;
    }

    Node *temp = head;
    // Node *tail1 = head;

    
    // Node *tail2 = head;

    while(mid-1 >= 0 ){

        temp = temp->next ;
    }
    Node *head2 = temp->next;
    temp->next = NULL;

  
    // if(head2->next == NULL){
    //     return head2;
    // }

    
    head = merge_sort1(head , find_mid(head));


    head2 = merge_sort1(head2 , find_mid(head2));

    return merge_sorted_LL(head,head2);


    // return head1;
    // head2->next = merge_sort(head2 , find_mid(head2));
}


// int length(Node *head) {
   
//     int count=0;
//     while(head)
//     {
//         count++;
//         head=head->next;
//     }
//     return count;
// }

Node* mergeSort(Node *head) {
    //write your code here
   if(head==NULL|| head->next==NULL)
        {return head;}
     
     //breaking node into two half  
    Node *p=head;
    for(int i=0;i<find_mid(head);i++)
    {
        p=p->next;
    }
    Node *head1=p->next;
    p->next=NULL;
    
  head=mergeSort(head);
    head1=mergeSort(head1);
    
    return merge_sorted_LL(head,head1);

    
}


int main(){

    Node * head1 = take_input_better();
    print(head1);
    Node * head3 = mergeSort(head1);
    print(head3);
    return 0;
}