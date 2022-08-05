#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;


template <typename T>
class TreeNode{
    public:
        int data;
        vector<TreeNode<int> *> children;

        TreeNode(T data){
            this->data = data;
        }

        ~TreeNode(){
            for(int i=0;i<children.size();i++){
                delete children[i];
            }
        }

      


        
};

TreeNode<int> * takeinputlevelwise(){
    int data;
    cout << "Enter the data:";
    cin >> data;

    TreeNode<int> *root = new TreeNode<int>(data);
    queue<TreeNode<int> *> pending_nodes;
    pending_nodes.push(root);

    while(pending_nodes.size()!=0){

        TreeNode<int> * front = pending_nodes.front();
        pending_nodes.pop();

        int numchild;
        cout << "Enter num of child of parent ->" << front->data << endl;
        cin >> numchild;

        for(int i=0; i<numchild;i++){
            int childdata;
            cout << "Enter the " << i << " th child of " << front->data << endl;
            cin >> childdata;

            TreeNode<int> *child = new TreeNode<int>(childdata);
            
            front->children.push_back(child);
            pending_nodes.push(child);

        }

        }

    return root;

}


TreeNode<int> * takeinput(){
    int data;
    cout << "Enter the parent:";
    cin >> data;

    TreeNode<int> *root = new TreeNode<int> (data);

    int n;
    cout << "Enter the no of  children of :" << data << endl; 
    cin >>n;

    for(int i=0; i<n;i++){
        TreeNode<int> *children = takeinput();
        root->children.push_back(children);

    }

    return root;


}
void printTreelevelwise(TreeNode<int> *root){
    if(root==NULL){
        return;
    }

    queue<TreeNode<int>*> ans;
    ans.push(root);

    while(ans.size()!=0){

        TreeNode<int> *front = ans.front();
        ans.pop();
        cout << front->data << ":";

        for(int i=0;i<front->children.size();i++){
            cout << front->children[i]->data << ",";
            ans.push(front->children[i]);
            
        }
        cout << endl;


    }

}

void printTree(TreeNode<int> *root){

    if(root==NULL){
        return;
    }
    cout << root->data << ":" ;

    for(int i=0;i<root->children.size();i++){
        cout << root->children[i]->data <<",";

    }
    cout << endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }

}

int num_nodes(TreeNode<int>* root){
    int ans=1;
    for(int i=0;i<root->children.size();i++){

        ans += num_nodes(root->children[i]);
    }

    return ans;

}

int maxheight(TreeNode<int> * root){
    int ans = 1;
    int c=0;
    for(int i=0; i<root->children.size();i++){
        
        c = max(c,maxheight(root->children[i]));
        
    }
    ans+=c;

    return ans;
}
void printkdepthnode(TreeNode<int>* root, int k){
    if(k==0){
        cout << root->data << endl;
    }

    for(int i=0;i<root->children.size();i++){
        printkdepthnode(root->children[i],k-1);
    }
}
void printleavenode(TreeNode<int>* root){
    if(root->children.size()==0){
        cout << root->data << endl;
    }

    for(int i=0;i<root->children.size();i++){
        printleavenode(root->children[i]);
    }
}

void deleteTree(TreeNode<int> *root){

    for(int i=0;i<root->children.size();i++){
        deleteTree(root->children[i]);
    }
    delete root;

}

int main(){
    //1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    TreeNode<int> *root = takeinputlevelwise();
    printTreelevelwise(root);
    int numnode;
    numnode = num_nodes(root);
    cout <<"No of Node :"  << numnode << endl;
    cout << "height:"<<maxheight(root) << endl;

    printleavenode(root);
    // deleteTree(root);
    delete root;


    return 0;


}