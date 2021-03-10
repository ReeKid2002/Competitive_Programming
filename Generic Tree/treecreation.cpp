#include<iostream>
#include<vector>
using namespace std;
//template <class T>
class Tree{
    public:
        int data;
        vector<Tree*> child;
        Tree(int data){
            this->data = data;
        }
};
Tree* input_tree(){
    int rootdata;
    cout<<"Enter Data: ";
    cin>>rootdata;
    Tree *root = new Tree(rootdata);
    int n;
    cout<<"Enter No. of Child: ";
    cin>>n;
    for(int i=0;i<n;i++){
        root->child.push_back(input_tree());
    }
    return root;
}
void print_tree(Tree *root){
    cout<<root->data<<": ";
    for(int i=0;i<root->child.size();i++){
        cout<<root->child.at(i)->data<<",";
    }
    for(int i=0;i<root->child.size();i++){
        print_tree(root->child.at(i));
    }
}
int main(){
    Tree *root = input_tree();
    print_tree(root);
    return 0;
}
