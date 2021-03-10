#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<class T>
class TreeNode{
    public:
    T data;
    vector<TreeNode*> child;
    TreeNode(T data){
        this->data = data;
    }
};
TreeNode<int>* Level_Order_input(){
    int rootdata;
    cout<<"Enter Root Data: ";
    cin>>rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> Nodes_in_Queue;
    Nodes_in_Queue.push(root);
    while(!Nodes_in_Queue.empty()){
        TreeNode<int> *front_node = Nodes_in_Queue.front();
        Nodes_in_Queue.pop();
        int no_of_child;
        cout<<"Enter No. of Child of "<<front_node->data<<": ";
        cin>>no_of_child;
        for(int i=0;i<no_of_child;i++){
            int childdata;
            cout<<"Enter Child Data: ";
            cin>>childdata;
            TreeNode<int> *children = new TreeNode<int>(childdata);
            front_node->child.push_back(children);
            Nodes_in_Queue.push(children);
        }
    }
    return root;
}
void display_tree(TreeNode<int> *root){
    cout<<root->data<<": ";
    for(int i=0;i<root->child.size();i++){
        cout<<root->child[i]->data<<" ";
    }
    cout<<endl;
    for(int i=0;i<root->child.size();i++){
        display_tree(root->child[i]);
    }
}
int main(){
    TreeNode<int> *root = Level_Order_input();
    display_tree(root);
}
