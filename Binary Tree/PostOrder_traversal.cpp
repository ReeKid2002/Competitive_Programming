#include<bits/stdc++.h>
using namespace std;
template<class type>
class BinaryTreeNode{
    public:
        type data;
        BinaryTreeNode<type> *left_child;
        BinaryTreeNode<type> *right_child;
        BinaryTreeNode(type data){
            this->data = data;
            left_child = NULL;
            right_child = NULL;
        }
        ~BinaryTreeNode(){
            delete left_child;
            delete right_child;
        }
};
BinaryTreeNode<int>* Input_into_binary_tree_using_level_order_insertion(){
    int root_data;
    cout<<"Enter Root Data: ";
    cin>>root_data;
    if(root_data==-1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(root_data);
    queue<BinaryTreeNode<int>*> queue_item;
    queue_item.push(root);
    while(!queue_item.empty()){
        BinaryTreeNode<int> *front_element = queue_item.front();
        queue_item.pop();
        int left_cdata,right_cdata;
        cout<<"Enter "<<front_element->data<<" Left Child Data: ";
        cin>>left_cdata;
        cout<<"Enter "<<front_element->data<<" Right Child Data: ";
        cin>>right_cdata;
        if(left_cdata!=-1){
            BinaryTreeNode<int> *left = new BinaryTreeNode<int>(left_cdata);
            front_element->left_child = left;
            queue_item.push(left);
        }
        if(right_cdata!=-1){
            BinaryTreeNode<int> *right = new BinaryTreeNode<int>(right_cdata);
            front_element->right_child = right;
            queue_item.push(right);
        }
    }
    return root;
}
void Level_order_Display(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> queue_item;
    queue_item.push(root);
    while(!queue_item.empty()){
        BinaryTreeNode<int> *front_node = queue_item.front();
        queue_item.pop();
        cout<<front_node->data<<": ";
        if(front_node->left_child!=NULL){
            cout<<"L->"<<front_node->left_child->data<<" ";
            queue_item.push(front_node->left_child);
        }
        if(front_node->right_child!=NULL){
            cout<<"R->"<<front_node->right_child->data;
            queue_item.push(front_node->right_child);
        }
        cout<<endl;
    }
 }
void Post_Order_traversal(BinaryTreeNode<int> *root){
    if(root==NULL)
        return;
    Post_Order_traversal(root->left_child);
    Post_Order_traversal(root->right_child);
    cout<<root->data<<" ";
}
 int main(){
    BinaryTreeNode<int> *root = Input_into_binary_tree_using_level_order_insertion();
    Level_order_Display(root);
    Post_Order_traversal(root);
 }

