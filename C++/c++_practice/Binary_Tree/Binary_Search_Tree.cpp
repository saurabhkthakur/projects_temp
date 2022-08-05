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

void search_between_range(BinaryTreeNode<int> * root, int k1, int k2){
    
    if(root==NULL){
        return;
    }

     if(root->data >=  k1 && root->data < k2 ){
         cout << root->data << endl;
     }

    if(root->data > k1   ){
        search_between_range(root->left, k1, k2);
    }

    if(root->data <= k2){
        search_between_range(root->right, k1, k2);
    }

}

int minimum(BinaryTreeNode<int> * root){
    if(root==NULL){
        return INT_MAX;
    }

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(BinaryTreeNode<int> * root){
    if(root==NULL){
        return INT_MIN;
    }

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}



bool isBST(BinaryTreeNode<int> * root){
    if(root==NULL){
        return true;
    }

    int leftans = maximum(root->left);
    int rightans = minimum(root->right);

    bool ans = (root->data > leftans) && (root->data <= rightans) && isBST(root->left) && isBST(root->right);
    
    return ans;
    


}

class Bstcheck{
    public:
        bool isBst;
        int maximum;
        int minimum;

};


Bstcheck isBST2(BinaryTreeNode<int>*root){
    if(root== NULL){
        Bstcheck out;
        out.isBst =true;
        out.maximum =INT_MIN;
        out.minimum = INT_MAX;
        return out;
    }


    Bstcheck leftans = isBST2(root->left);
    Bstcheck rightans = isBST2(root->right);

    Bstcheck out;
    out.maximum = max(root->data, max(leftans.maximum,rightans.maximum));
    out.minimum = min(root->data, min(leftans.minimum,rightans.minimum));
    out.isBst = (root->data > leftans.maximum) && (root->data <= rightans.minimum) && leftans.isBst && rightans.isBst;

    return out;



}

bool isBst3(BinaryTreeNode<int> * root, int min = INT_MAX, int max = INT_MIN){
    if(root==NULL){
        return true;
    }

    if(root->data  < min || root->data > max){
        return false;
    }

    bool leftok = isBst3(root->left, min, max=root->data-1);
    bool rightok = isBst3(root->right, root->data, max);

    return leftok && rightok;
  
}


//Binarytree creation using sorted array
BinaryTreeNode<int>* BST_with_sortedarray(int arr[], int start, int end){

    if(start>end){
        return NULL;

    }

    int mid = (start+end)/2;
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(arr[mid]);

    BinaryTreeNode<int> * leftans = BST_with_sortedarray(arr, start, mid-1);
   
    
    BinaryTreeNode<int> * rightans = BST_with_sortedarray(arr, mid+1, end);

     root->left = leftans;
     root->right = rightans;


     return root;


}

class PairNode{
    public:
        Node<int> * head;
        Node<int> * tail;
};

PairNode createLL_from_BST_helper(BinaryTreeNode<int>*root){

    if(root->left==NULL || root->right ==NULL){
        PairNode p;
        Node<int> * node = new Node<int>(root->data);
        p.head = node ;
        p.tail = node;
        return p;
    }

    Node<int> * node = new Node<int>(root->data);
    // Node<int> * prev =head;

    PairNode leftans = createLL_from_BST_helper(root->left);
    PairNode rightans = createLL_from_BST_helper(root->right);

    

    if(leftans.head != NULL ){
        
        leftans.tail->next = node;
        leftans.tail = node;
    }

    if(rightans.head != NULL){

        node->next = rightans.head;
        
    }

    PairNode p;
    p.head = leftans.head;
    p.tail = rightans.tail;

    return p;

}

Node<int> * createLL_from_BST(BinaryTreeNode<int> * root){
    return createLL_from_BST_helper(root).head;
} 


void print(Node<int> *head){
    Node<int> *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next ;
    }
    cout << endl;
}


//vector path of givrn data

vector<int> * pathofgivendata(BinaryTreeNode<int>*root, int data){
    if(root==NULL){
        return NULL;
    }

    if(root->data == data){
        vector<int> * output = new vector<int>;
        output->push_back(data);
        return output;
    }

    vector<int> * leftans = pathofgivendata(root->left, data);
    vector<int> * rightans = pathofgivendata(root->right, data);

    if(leftans != NULL){
        leftans->push_back(root->data);
        return leftans;
        

    }

    if(rightans != NULL){
        rightans->push_back(root->data);
        return rightans;

    }
    else{
        return NULL;
    }

}
// create Binary search tree class

class BST{
    BinaryTreeNode<int> * root;

    public:
        BST(){
            root = NULL;
        }

        ~BST(){
            delete root;
        }

        void deletedata(int data){

        }

        void insertdata(int data){

        }
        private:
            bool hasdata(int data, BinaryTreeNode<int> *node){
                if(node==NULL){
                    return false;
                }

                if(node->data==data){
                    return true;
                }
                else if(data < node->data){
                    hasdata(data, node->left);
                }
                else{
                    hasdata(data, node->right);
                }

            } 

        public:
            bool hasdata(int data){
                return hasdata(data,root);
            }
};


int main(){
    BinaryTreeNode<int> * root = takeinputlevelwise();
    // int arr[6] = {1,2,3,4,5,6};
    // BinaryTreeNode<int> * root = BST_with_sortedarray(arr, 0,5);
    printbinaryTree(root);

    vector<int> * output = pathofgivendata(root, 8);
    for(int i=0; i< output->size();i++){
        cout << output->at(i) << " " ;
    }
    delete output;
    // Node<int> * head =  createLL_from_BST(root);
    // print(head);
    // search_between_range(root, 30,50);
    // cout <<"isBST :" << isBST(root) << endl;
    Bstcheck out = isBST2(root);
    cout <<"isBST :" << out.isBst << endl;
    delete root;

}

//40 30 50 20 35 45 55 -1 -1 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1