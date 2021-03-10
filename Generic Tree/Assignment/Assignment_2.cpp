/*
Given a tree and an integer x, find and return the number of nodes which contains data greater than x.
Input format: The first line of input contains data of the nodes of the tree in level order form.
The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node.
The data of the nodes of the tree is separated by space.
The following line contains an integer, that denotes the value of x.
Output Format : The first and only line of output prints the count of nodes greater than x.
Constraints:
Time Limit: 1
Sample Input sec 1 : 10 3 20 30 40 2 40 50 0 0 0 0 35 Sample Output 1 : 3
Sample Input 2 : 10 3 20 30 40 2 40 50 0 0 0 0 10 Sample Output 2: 5
*/
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
    int Root_data;
    cout<<"Enter Root Data: ";
    cin>>Root_data;
    TreeNode<int> *root = new TreeNode<int>(Root_data);
    queue<TreeNode<int>*> queue_item;
    queue_item.push(root);
    while(!queue_item.empty()){
        TreeNode<int> *front_node = queue_item.front();
        queue_item.pop();
        int no_of_child;
        cout<<"Enter No. of child for "<<front_node->data<<": ";
        cin>>no_of_child;
        for(int i=0;i<no_of_child;i++){
            int child_data;
            cout<<"Enter Child Data for "<<front_node->data<<": ";
            cin>>child_data;
            TreeNode<int> *child_node = new TreeNode<int>(child_data);
            front_node->child.push_back(child_node);
            queue_item.push(child_node);
        }
    }
    return root;
}
void display_tree(TreeNode<int> *root){
    queue<TreeNode<int>*> queue_item;
    queue_item.push(root);
    while(!queue_item.empty()){
        TreeNode<int> *front_node = queue_item.front();
        queue_item.pop();
        cout<<front_node->data<<": ";
        for(int i=0;i<front_node->child.size();i++){
            cout<<front_node->child[i]->data<<" ";
            queue_item.push(front_node->child[i]);
        }
        cout<<endl;
    }
}
void Number_greater_Than(TreeNode<int> *root,int num){
    int count_num = 0;
    queue<TreeNode<int>*> queue_item;
    queue_item.push(root);
    while(!queue_item.empty()){
        TreeNode<int> *front_node = queue_item.front();
        queue_item.pop();
        if(front_node->data>num)
            count_num++;
        for(int i=0;i<front_node->child.size();i++){
            queue_item.push(front_node->child[i]);
        }
    }
    cout<<"Number Greater Than "<<num<<": "<<count_num<<endl;
}
int main(){
    TreeNode<int> *root = Input_into_tree();
    display_tree(root);
    int number;
    cout<<"Enter The Number: ";
    cin>>number;
    Number_greater_Than(root,number);
}
