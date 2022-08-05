#include <bits/stdc++.h>
#include <vector>
#include <queue>
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

int numnode(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }

    return 1 + numnode(root->left) + numnode(root->right);

}

int height(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0 ;
    }

    return 1+max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int> * root){
    if(root==NULL){
        return 0;
    }

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2,option3));
}

pair<int,int> heightdiameter(BinaryTreeNode<int> * root){
    if(root==NULL){
        pair<int,int> p ;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int,int> leftans = heightdiameter(root->left);
    pair<int,int> rightans= heightdiameter(root->right);

    int ld =  leftans.second;
    int rd = rightans.second;
    int lh = leftans.first;
    int rh = rightans.first;

    int height = 1+ max(lh,rh);
    int diameter = max(lh+rh, max(ld,rd));
    pair<int,int> p ;
    p.first = height;
    p.second = diameter;

    return p;

    
}
int main(){
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int> *root = takeinputlevelwise();
    printbinaryTree(root);
    cout << "num node" << numnode(root) << endl;
    delete root;

}