//
// Created by dubing on 2017/6/28.
// question:
// 
// url:
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("../../toutiao_test3/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    long  m,n;
    while(cin>>n>>m){
        //先统计含有首字母含1的有多个数字
        string s = to_string(n);
        long int count = 0;
        if(s[0]==1){
            count+=n-(s.size()-1)*10;
        }else{
            count+=pow(9,s.size()-1);
        }


    }
}