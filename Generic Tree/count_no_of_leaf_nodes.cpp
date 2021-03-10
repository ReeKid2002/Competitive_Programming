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

TreeNode<int> *Insert_into_tree(){
        int root_data;
        cout<<"Enter Root Data: ";
        cin>>root_data;
        TreeNode<int> *root = new TreeNode<int>(root_data);
        queue<TreeNode<int>*> entry_queue;
        entry_queue.push(root);
        while(!entry_queue.empty()){
            TreeNode<int> *temp_node = entry_queue.front();
            entry_queue.pop();
            int no_of_child_node;
            cout<<"Enter number of child node for "<<temp_node->data<<": ";
            cin>>no_of_child_node;
            for(int i=0;i<no_of_child_node;i++){
                int child_data;
                cout<<"Enter Child Data for "<<temp_node->data<<": ";
                cin>>child_data;
                TreeNode<int> *temp_child = new TreeNode<int>(child_data);
                temp_node->child.push_back(temp_child);
                entry_queue.push(temp_child);
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

int count_no_of_leaf_node(TreeNode<int> *root){
    int no_of_leaf_node = 0;
    if(root->child.size()==0){
        return no_of_leaf_node+1;
    }
    for(int i=0;i<root->child.size();i++){
        no_of_leaf_node+=count_no_of_leaf_node(root->child[i]);
    }
    return no_of_leaf_node;
}
int main(){
    TreeNode<int> *root = Insert_into_tree();
    display_tree(root);
    cout<<"Number of Leaf Node: "<<count_no_of_leaf_node(root);
    return 0;
}
