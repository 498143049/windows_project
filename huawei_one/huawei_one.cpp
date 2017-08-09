//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <deque>
#include <climits>
using namespace std;
int main() {
    freopen("../../huawei_one/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取

    int num;
    while ( cin>>num){
    if(num>=1000){
        num = 1000;
    }
    vector<int> vt(num,0);
   for(int i=0;i<num;++i){
       vt[i]=i;
   }
    deque<int> dq(vt.begin(),vt.end());
    while (dq.size()!=1){
        int num1 = dq.front();
        dq.push_back(num1);
        dq.pop_front();

        int num2 = dq.front();
        dq.push_back(num2);
        dq.pop_front();

        dq.pop_front();
    }
    cout<<dq.front()<<endl;
    }
}