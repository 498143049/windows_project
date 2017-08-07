#include <iostream>
using namespace std;
bool is_per(long int t){
    for(int i=2;i<t;i++){
        if(t%i == 0){
            return false;
        }
    }
    return true;
}
long int next_per(long int t){
    while(!is_per(++t));
    return t;
}
int main() {
    long int num;
    cin>>num;
    long int initp = 2;
    while(num>1){
        if(num%initp == 0){
            cout<<initp;
            num=num/initp;
        }
        else{
            initp = next_per(initp);
        }
    }
    cout<<endl;
    return 0;
}