//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    freopen("../../net_8/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int num1,num2,num3,num4;
    cin>>num1>>num2>>num3>>num4;
    int A = num1+num3;
    if((A<0)||(A&1)){
        cout<<"No"<<endl;
        return 0;
    }
    A=A>>1;
    int temB = num3-A;
    int B = num2+num4;
    if((B<0)||(B&1)){
        cout<<"N0"<<endl;
        return 0;
    }
    B=B>>1;
    if(temB!=B){
        cout<<"N0"<<endl;
        return 0;
    }
    int C= num4-B;
    if(C<0){
        cout<<"N0"<<endl;
        return 0;
    }
    cout<<A<<" "<<B<<" "<<C<<endl;
}