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

class Pair{
    public:
        Node *head;
        Node *tail;
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

Pair reverse_LL2(Node *head){
    if(head==NULL || head->next ==NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallans = reverse_LL2(head->next);
    smallans.tail->next = head;
    head->next = NULL;

    Pair ans;
    ans.head = smallans.head;
    ans.tail = head;
    return ans;


}


Node * reverse_LL_better(Node * head){
    return reverse_LL2(head).head;
}

Node * reverse_LL(Node * head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }


    //assuming the we 2-3-4-5-null  we get correcr ans of recurrsion 5-4-3-null from recurssion solve for 1 case

    Node * smallans = reverse_LL(head->next);

    Node * temp = smallans;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = head;
    head->next = NULL;

    return smallans;

}

int main(){

    Node * head1 = take_input_better();
    print(head1);
    Node * head3 = reverse_LL_better(head1);
    print(head3);
    return 0;
}