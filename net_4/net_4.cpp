//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>
using namespace std;
long int getnum(int num){
    if(num==3){
        return 21;
    }
    else if(num==0){
        return 0;
    }
    else if(num==1){
        return 3;
    }
    else if(num==2){
        return 9;
    }
    else {
        return pow(3,num)-6*pow(3,num-3)*(num-2);
    }
}
int main() {
    freopen("../../net_4/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int num;
    while(cin>>num){
        cout<<getnum(num)<<endl;
    }
}