//**THE DIAMETER OF BINARY TREE IS THE MAX NO. OF EDGES BETWEEN ANY 2 NODES**//
#include<bits/stdc++.h>
using namespace std;
template<class t>
class BinaryTree{
    public:
        t data;
        BinaryTree *left_child;
        BinaryTree *right_child;
        BinaryTree(t data){
            this->data = data;
            this->left_child = NULL;
            this->right_child = NULL;
        }
        ~BinaryTree(){
            delete left_child;
            delete right_child;
        }
};
BinaryTree<int>* TreeInsertion(){
    int rootdata;
    cout<<"Enter Root Data: ";
    cin>>rootdata;
    queue<BinaryTree<int>*> queue_item;
    BinaryTree<int> *root = new BinaryTree<int>(rootdata);
    queue_item.push(root);
    while(!queue_item.empty()){
        BinaryTree<int> *front_node = queue_item.front();
        queue_item.pop();
        int left_child_data,right_child_data;
        cout<<"Enter Left Child Data of "<<front_node->data<<" : ";
        cin>>left_child_data;
        cout<<"Enter Right Child Data of "<<front_node->data<<" : ";
        cin>>right_child_data;
        if(left_child_data!=-1){
            BinaryTree<int> *left_child = new BinaryTree<int>(left_child_data);
            front_node->left_child = left_child;
            queue_item.push(left_child);
        }
        if(right_child_data!=-1){
            BinaryTree<int> *right_child = new BinaryTree<int>(right_child_data);
            front_node->right_child = right_child;
            queue_item.push(right_child);
        }
    }
    return root;
}
void Display_Binary_Tree(BinaryTree<int> *root){
    if(root==NULL)
        return;
    cout<<root->data<<": ";
    if(root->left_child!=NULL)
        cout<<root->left_child->data<<" ";
    if(root->right_child!=NULL)
        cout<<root->right_child->data;
    cout<<endl;
    Display_Binary_Tree(root->left_child);
    Display_Binary_Tree(root->right_child);
}
int main(){
    BinaryTree<int> *root = TreeInsertion();
    Display_Binary_Tree(root);
}
