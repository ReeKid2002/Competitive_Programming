#include<iostream>
using namespace std;
void print(int *p){
    (*p)++;
}
void sum(int a[],int si){
    cout<<sizeof(a)<<endl;
    int sum = 0;
    for(int i=0;i<si-4;i++){
        sum+=*(a+i);
    }
    cout<<sum<<endl;
}
int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<a<<endl;
    cout<<sizeof(a)<<endl;
    sum(a+4,10);

    //int *p = &a;
    //cout<<*p<<endl;
    //print(p);
    //cout<<*p<<endl;
    return 0;
}
