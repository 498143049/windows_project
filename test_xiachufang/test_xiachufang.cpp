﻿//
// Created by dubing on 2017/6/28.
// question:
// 
// url:
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("../../test_xiachufang/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
        set<string> st;
        string s;
        while(cin>>s){
            st.insert(s);
        }
        cout<<st.size()<<endl;
}