#include <bits/stdc++.h>

using namespace std;


class Node{
    public:
        int data;
        Node *next;


        Node(int data){
            this -> data =data;
            next = NULL;

        }

};


Node * take_input(){
    int data;
    cin >> data;
    Node *head = NULL;

    while (data!=-1)
    {
        Node *newnode = new Node(data);
        if(head==NULL){
            head= newnode;
        }
        else{
            Node *temp = head;

            while(temp->next!=NULL){
                temp = temp->next ;
            }
            temp->next = newnode;
        }

        cin >> data;
    }
    return head;
}

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

Node * insertnode(int data, int i, Node *head){
    Node *newnode = new Node(data);

    Node *temp = head;
    int count = 0;


    if(i==0){
        newnode->next = head;
        head = newnode;
        return head;
    }
    
    while(count < i-1 && temp !=NULL){
        temp = temp->next;
        count++;
    }

    if(temp!=NULL){
        newnode->next = temp->next;
        temp->next = newnode;}
    return head;

}

Node * deletenode(int i, Node *head){
    Node * temp = head;
    int count =0;

    if(i==0){
        head = head->next;
        return head;
    }
    while(count < i-1 && temp != NULL){
        temp = temp->next;
        count++;
    }

    if(temp!=NULL){
        Node *a = temp->next;
        Node *b = a->next;

        temp->next = b; 

        delete a;
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

// recursion

void recursive_print(Node *head){

    
    if(head == NULL){
        return;
    }

    cout << head->data << " ";

    recursive_print(head->next);
   

}


Node * inser_node_recursive(int data, int i, Node * head){
    if(head ==NULL)
     return head ;
   
    if(i==0 ){
        Node *newnode = new Node(data);
        newnode->next = head;
        return newnode;
    }


    head->next= inser_node_recursive(data, i-1 , head->next);
    cout << head->data << endl;

    return head;


}

Node * delete_node_recur(Node *head, int pos){
    if(head == NULL){
        return head;
    }

    if(pos ==0){
        head = head->next;
        return head;
    }

    Node *x= delete_node_recur(head->next,pos-1);
    head->next = x;
    // x = head;

    return head;
}

    

Node* insertNodeRec(Node *head, int i, int data) {
   
     if(i==0)
    {
        Node *p=new Node(data);
        p->next=head;
        head =p;
        return p;
    }
    
    if(head==NULL || i<0)
      return head;
    
   
    head->next=insertNodeRec(head->next,i-1,data);
   
    return head;
}


int main(){

    //Node *head = take_input();
    /*
    Iteratively 

    Node *head = take_input_better();
    print(head);
    head = insertnode(99,4,head);
    print(head);

    head = deletenode(4,head);
    print(head);

    */

   //Recursively
   Node *head = take_input_better();
   recursive_print(head);
    cout << endl;

    head = delete_node_recur(head,1);

//    head = insertNodeRec(head,4,99);
   recursive_print(head);








    
    
    /*
    //statically

    Node n1(1);

    Node *head = &n1;

    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);
    // cout <<  n1.data << " " << n1.next  << endl;

    // n1.next = &n2;

    // cout <<  n1.data << " " << n1.next  << endl;

   
    // Dynamically Dynamic allocation jab bhi karte h 2 block of memory create hogi one for
    // pointer(stack) and one for actual data(heap)

    Node *n3 = new Node(10);
    Node *head1 = n3;
    Node *n4 = new Node(20);

    cout << n3->data   << " " << n3->next  << endl;
    

   Node *n6 = new Node(6);
   Node *head1 = n6;
   Node *n7 = new Node(7);
   Node *n8 = new Node(8);
   Node *n9 = new Node(9);
   Node *n10 = new Node(10);

   n6->next = n7;
   n7->next = n8;
   n8->next = n9;
   n9->next = n10;

   print(head1); 
   */
   





    return 0;
}