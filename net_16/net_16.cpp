//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
#include <stack>
#include <queue>
using namespace std;
int main() {
    freopen("../../net_16/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int nums;
    if(nums==0) return 0;
    stack<int> st;
    cin>>nums;
    while(nums--){
        int tnum;
        cin>>tnum;
        st.push(tnum);
    }
    int arry[1001]={0};
    stack<int> st2;
    while (!st.empty()){
        int t = st.top();
        st.pop();
        if(!arry[t]){
            arry[t] = 1;
            st2.push(t);
        }
    }
    while (st2.size()>1){
        int t = st2.top();
        st2.pop();
        cout<<t<<" ";
    }
    cout<<st2.top();
    cout<<endl;
}