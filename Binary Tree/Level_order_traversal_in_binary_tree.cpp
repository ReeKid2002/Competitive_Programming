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
            left_child = NULL;
            right_child = NULL;
        }
        ~BinaryTreeNode(){
            delete left_child;
            delete right_child;
        }
};
BinaryTreeNode<int> *Level_order_input(){
    int dataa;
    cout<<"Enter Root Data: ";
    cin>>dataa;
    if(dataa==-1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(dataa);
    queue<BinaryTreeNode<int>*> queue_item;
    cout<<root->data;
    queue_item.push(root);
    while(!queue_item.empty()){
        BinaryTreeNode<int> *front_node = queue_item.front();
        queue_item.pop();
        int left_child_data,right_child_data;
        cout<<"Enter Left Child Data for "<<front_node->data<<": ";
        cin>>left_child_data;
        cout<<"Enter Right Child Data for "<<front_node->data<<": ";
        cin>>right_child_data;
        if(left_child_data!=-1){
            BinaryTreeNode<int> *left = new BinaryTreeNode<int>(left_child_data);
            front_node->left_child = left;
            queue_item.push(left);
        }
        if(right_child_data!=-1){
            BinaryTreeNode<int> *right = new BinaryTreeNode<int>(right_child_data);
            front_node->right_child = right;
            queue_item.push(right);
        }
    }
    return root;
}

void Level_Order_display(BinaryTreeNode<int> *root){
    if(root!=NULL){
        queue<BinaryTreeNode<int>*> queue_item;
        queue_item.push(root);
        while(!queue_item.empty()){
            BinaryTreeNode<int> *front_node = queue_item.front();
            queue_item.pop();
            cout<<front_node->data<<": ";
            if(front_node->left_child!=NULL){
                cout<<front_node->left_child->data<<" ";
                queue_item.push(front_node->left_child);
            }
            if(front_node->right_child!=NULL){
                cout<<front_node->right_child->data<<" ";
                queue_item.push(front_node->right_child);
            }
            cout<<endl;
        }
    }
}

int main(){
    BinaryTreeNode<int> *root = Level_order_input();
    Level_Order_display(root);
}
