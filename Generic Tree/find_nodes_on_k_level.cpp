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
        ~TreeNode(){
            for(int i=0;i<this->child.size();i++){
                delete this->child[i];
            }
            cout<<"Element "<<this->data<<" Deleted!"<<endl;
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

void display_level_element(TreeNode<int> *root,int k_level){

    if(root==NULL){
        cout<<"No Element Present of "<<k_level<<" level"<<endl;
        return ;
    }

    if(k_level==0){
        cout<<"Element at "<<k_level<<" level: "<<root->data<<endl;
        return ;
    }
    else
        for(int i=0;i<root->child.size();i++){
            display_level_element(root->child[i],k_level-1);
        }
}
int main(){
    TreeNode<int> *root = Insert_into_tree();
    display_tree(root);
    cout<<"Enter a level: ";
    int level;
    cin>>level;
    display_level_element(root,level);
    delete root;
    return 0;
}
