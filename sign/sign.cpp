//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
union sign{
        unsigned  int a[32];
        bool c[1024]={false};
    };
int main() {


    int a; int b;
    cin>>a;
    cin>>b;
    sign st;
    st.c[a-1]=true;
    if(b>1024||b<=0) {
        cout<<-1<<endl;
    }
    else{
        if(st.c[b-1]==true)
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }

}