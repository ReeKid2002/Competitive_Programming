#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    for(int i=0;i<10;i++){
        cout<<v.capacity()<<"\t";
        v.push_back(i+1);
        cout<<v.size()<<endl;
    }
    return 0;
}
