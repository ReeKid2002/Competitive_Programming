#include<iostream>
#include<vector>
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

TreeNode<int>* level_order_insertion(){
    int root_data;
    cout<<"Enter Data: ";
    cin>>root_data;
    TreeNode<int> *root = new TreeNode<int>(root_data);
    int no_of_child;
    cout<<"Enter No. of "<<root->data<<" Child: ";
    cin>>no_of_child;
    for(int i=0;i<no_of_child;i++){
        root->child.push_back(level_order_insertion());
    }
    return root;
}

void level_order_traversal(TreeNode<int> *root){
    if(root!=NULL){
        cout<<root->data<<": ";
        for(int i=0;i<root->child.size();i++){
            cout<<root->child[i]->data<<" ";
        }
        cout<<endl;
        for(int i=0;i<root->child.size();i++){
            level_order_traversal(root->child[i]);
        }
    }
}

int main(){
    TreeNode<int> *root = level_order_insertion();
    level_order_traversal(root);
}
