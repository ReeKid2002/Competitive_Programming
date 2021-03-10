#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<class type>
class TreeNode{
    public:
        type data;
        vector<TreeNode*> child;
        TreeNode(type data){
            this->data = data;
        }
};
TreeNode<int>* level_order_insert(){
    int root_data;
    cout<<"Enter Root Data: ";
    cin>>root_data;
    TreeNode<int> *root = new TreeNode<int>(root_data);
    queue<TreeNode<int>*> queue_node;
    queue_node.push(root);
    while(!queue_node.empty()){
        TreeNode<int> *front_node = queue_node.front();
        queue_node.pop();
        int no_of_child;
        cout<<"Enter No. of "<<front_node->data<<" Child: ";
        cin>>no_of_child;
        for(int i=0; i<no_of_child;i++){
            int child_data;
            cout<<"Enter Data: ";
            cin>>child_data;
            TreeNode<int> *child_node = new TreeNode<int>(child_data);
            front_node->child.push_back(child_node);
            queue_node.push(child_node);
        }
    }
    return root;
}
void level_order_traversal(TreeNode<int> *root){
    if(root==NULL)
        return;
    queue<TreeNode<int>*> queue_node;
    queue_node.push(root);
    while(!queue_node.empty()){
        TreeNode<int> *temp_node = queue_node.front();
        queue_node.pop();
        cout<<temp_node->data<<": ";
        for(int i=0;i<temp_node->child.size();i++){
            cout<<temp_node->child[i]->data<<" ";
            queue_node.push(temp_node->child[i]);
        }
        cout<<endl;
    }
}
int main(){
    TreeNode<int> *root = level_order_insert();
    level_order_traversal(root);
}
