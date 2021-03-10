//Given a generic tree and an integer x, check if x is present in the given tree or not.
//Return true if x is present, return false otherwise.
//Input format : The first line of input contains data of the nodes of the tree in level order form.
//The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node.
//The data of the nodes of the tree is separated by space. The following line contains an integer, that denotes the value of x.
//Output format : The first and only line of output contains true, if x is present and false, otherwise.
//Constraints:
//Time Limit: 1
//Sample Input sec 1 : 10 3 20 30 40 2 40 50 0 0 0 0 40 Sample Output 1 : true
//Sample Input 2 : 10 3 20 30 40 2 40 50 0 0 0 0 4 Sample Output 2: false
#include<bits/stdc++.h>
using namespace std;
template<class type>
class TreeNode{
    public:
        type data;
        vector<TreeNode<type>*> child;
        TreeNode(type data){
            this->data = data;
        }
};
TreeNode<int>* Input_into_tree(){
    int root_data;
    cout<<"Enter Data: ";
    cin>>root_data;
    TreeNode<int> *root = new TreeNode<int>(root_data);
    int no_of_child;
    cout<<"Enter No of children for "<<root->data<<" : ";
    cin>>no_of_child;
    for(int i=0;i<no_of_child;i++){
        root->child.push_back(Input_into_tree());
    }
    return root;
}

void Tree_traversal(TreeNode<int> *root){
    cout<<root->data<<": ";
    for(int i=0;i<root->child.size();i++){
        cout<<root->child[i]->data<<" ";
    }
    cout<<endl;
    for(int i=0;i<root->child.size();i++){
        Tree_traversal(root->child[i]);
    }
}
bool find_item_from_tree(TreeNode<int> *root,int item_to_be_found){
    if(root==NULL)
        return false;
    queue<TreeNode<int>*> queue_item;
    queue_item.push(root);
    while(!queue_item.empty()){
        TreeNode<int> *front_node = queue_item.front();
        queue_item.pop();
        if(front_node->data==item_to_be_found)
            return true;
        for(int i=0;i<front_node->child.size();i++){
            queue_item.push(front_node->child[i]);
        }
    }
    return false;
}
int main(){
    TreeNode<int> *root = Input_into_tree();
    Tree_traversal(root);
    int element;
    cout<<"Enter Element to check: ";
    cin>>element;
    bool check = find_item_from_tree(root,element);
    if(check)
        cout<<"Element Present";
    else
        cout<<"Not Present";
}
