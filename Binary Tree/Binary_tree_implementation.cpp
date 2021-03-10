#include<bits/stdc++.h>
using namespace std;
template<class type>
class BinaryTreeNode{
    public:
        type data;
        BinaryTreeNode *left_child;
        BinaryTreeNode *right_child;
        BinaryTreeNode(type data){
            this->data = data;
            this->left_child = NULL;
            this->right_child = NULL;
        }
        ~BinaryTreeNode(){
            delete left_child;
            delete right_child;
        }
};

void print_binary_tree(BinaryTreeNode<int> *root){
    if(root!=NULL){
        cout<<root->data<<": ";
        if(root->left_child!=NULL)
            cout<<"L->"<<root->left_child->data;
        if(root->right_child!=NULL)
            cout<<" R->"<<root->right_child->data;
        cout<<endl;
        print_binary_tree(root->left_child);
        print_binary_tree(root->right_child);
    }
    else
        return;
}

BinaryTreeNode<int>* Input_into_binary_tree(){
    int data;
    cout<<"Enter Data: ";
    cin>>data;
    if(data==-1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    BinaryTreeNode<int> *left_c = Input_into_binary_tree();
    BinaryTreeNode<int> *right_c = Input_into_binary_tree();
    root->left_child = left_c;
    root->right_child = right_c;
    return root;
}
int main(){
    BinaryTreeNode<int> *root = Input_into_binary_tree();
    print_binary_tree(root);
    delete root;
}
