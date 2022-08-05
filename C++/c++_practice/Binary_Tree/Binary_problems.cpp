#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data){
            this->data = data;
            left = NULL;
            right = NULL;

        }

        ~BinaryTreeNode(){
            delete left;
            delete right;
        }
};

template <typename T>
class Node{
    public:
        T data;
        Node *next;


        Node(T data){
            this -> data =data;
            next = NULL;

        }

};
//takeinputlevelwise
BinaryTreeNode<int> * takeinputlevelwise(){
    int rootdata;
    cout << "Enter the root data" << endl;
    cin >> rootdata;
    queue<BinaryTreeNode<int> *> pendingnodes;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int> (rootdata);
    pendingnodes.push(root);

    while(pendingnodes.size()!=0){
        BinaryTreeNode<int> * front = pendingnodes.front();
        pendingnodes.pop();

        int leftchild;
        cout << "Enter the left child of " << front->data << endl;
        cin >> leftchild;

        if(leftchild !=-1){
            BinaryTreeNode<int> *lchild =  new BinaryTreeNode<int>(leftchild);
            front->left = lchild;
            pendingnodes.push(lchild);

        }

        int rightchild;
        cout << "Enter the right child of " << front->data << endl;
        cin >> rightchild;

        if(rightchild !=-1){
            BinaryTreeNode<int> *rchild =  new BinaryTreeNode<int>(rightchild);
            front->right = rchild;
            pendingnodes.push(rchild);

        }
    }


    return root; 

}
//print level wise
void printbinaryTree(BinaryTreeNode<int> * root){
    
    queue<BinaryTreeNode<int> *> ans;
    ans.push(root);

    while(ans.size()!=0){
        BinaryTreeNode<int> * front = ans.front();
        ans.pop();
        cout << front->data << ":" ;
        if(front->left!=NULL){
            cout << "L" << front->left->data << " ";
            ans.push(front->left);}
        
        if(front->right!=NULL){
            cout << "R" << front->right->data << " ";
            ans.push(front->right);}
        
        cout << endl;

    }
}

// find min max from tree 
pair<int,int> min_max(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first = 999999;
        p.second = -99999;
        return p;
    }

    pair<int,int> leftans = min_max(root->left);
    pair<int,int> rightans = min_max(root->right);

    int left_min =  min(root->data, leftans.first);
    int right_min =  min(root->data, rightans.first);

    int left_max =  max(root->data, leftans.second);
    int right_max =  max(root->data, rightans.second);

    pair<int,int> p;
    p.first = min(left_min, right_min );
    p.second = max(left_max ,right_max);

    return p;


}
//sum of all nodes
int sum_of_all_nodes(BinaryTreeNode<int> * root){
    if(root ==NULL){
        return 0;
    }
    int data= root->data;

    int leftans = sum_of_all_nodes(root->left);
    int rightans =  sum_of_all_nodes(root->right);

    return data+leftans+rightans;
}

//node present or not

bool node_search(BinaryTreeNode<int>* root, int x){
    if(root==NULL){
        return false;
    }
    bool ans = false;

    int leftans = node_search(root->left, x);
    int rightans = node_search(root->right, x);

    if(leftans){
        ans = true;
    }
    if(rightans){
        ans=true;
    }

    if(root->data == x){
        return true;
    }
    return ans;
}



int height(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }

    return 1+max(height(root->left), height(root->right));
}


// is balanced
int is_balanced(BinaryTreeNode<int>* root){

    if(root==NULL){
        return 1;
    }

    bool ans = 1;
    int leftheight = height(root->left);
    int rightheight = height(root->right);

    if(abs(leftheight-rightheight) >1){
        ans=0;
    }

    return ans ;

}

// levelwise lined list
/*Given a binary tree, write code to create a separate linked list for each level.
You need to return the array which contains head of each level linked list.*/
vector<Node<int> *> levelwiselinkedlist(BinaryTreeNode<int> * root){

    vector<Node<int>*> v;
    queue<BinaryTreeNode<int>*> pendig_nodes;
    pendig_nodes.push(root);
    Node<int> * head = new Node<int>(root->data);
    v.push_back(head);
    // Node<int> * temp = head;
    Node<int> * prev = head;

     while(pendig_nodes.size()!=0){

        BinaryTreeNode<int>* front = pendig_nodes.front();
        pendig_nodes.pop();
        if(front->left!=NULL){ 
            Node<int> * temp = new Node<int>(front->left->data);
            prev->next = temp;
            prev = temp;
            v.push_back(temp);
            pendig_nodes.push(front->left);
        }
        if(front->right!=NULL){
            Node<int> * temp = new Node<int>(front->right->data);
            prev->next = temp;
            prev = temp;
            v.push_back(temp);
            pendig_nodes.push(front->right);
        }


    }

    return v;

}


void print(Node<int> *head){
    Node<int> *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next ;
    }
    cout << endl;
}

//Mirror
void mirrorBinaryTree(BinaryTreeNode<int>* root) {
   if(root==NULL)
       return;
    BinaryTreeNode<int>* temp=root->left;
    
    root->left=root->right;
    root->right=temp;
    
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    

}
//Zig-Zag Tree

void zigzag(BinaryTreeNode<int> * root){
    
    queue<BinaryTreeNode<int>*> pending_nodes;
    pending_nodes.push(root);
    int count =0;

    while(pending_nodes.size()!=0){

        if(count %2==0){
            BinaryTreeNode<int> * front = pending_nodes.front();
            count << front->data;
            pending_nodes.pop();

            if(front->left!=NULL){
                pending_nodes.push(front->left);
            }
            if(front->right!=NULL){
                pending_nodes.push(front->left);
            }
        }
        
    }

}
int main(){
    BinaryTreeNode<int> * root = takeinputlevelwise();
    printbinaryTree(root);
    // pair<int,int>  p = min_max(root);
    // cout << "Min:" << p.first << endl;
    // cout << "Max" << p.second << endl;
    // cout << "sum of all Node:" << sum_of_all_nodes(root) << endl;
    // cout << "Check Node is present or not:" << node_search(root, 5) << endl;
    // cout << "Check Node is present or not:" << node_search(root, 13) << endl;
    // cout << "Is balanced:" << is_balanced(root) << endl;

    // levelwiselinkedlist(root);

    // vector<Node<int>*> vector_ll_tree = levelwiselinkedlist(root) ;
    // cout << "linkedlist : "<< endl; 
    // print(vector_ll_tree[0]);
    mirrorBinaryTree(root);
    printbinaryTree(root);
    
    delete root;

    return 0;
}


// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 10 -1 -1 -1 -1 -1