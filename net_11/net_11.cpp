//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    freopen("../../net_11/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    string s;
    cin>>s;
    int size = s.size();
    char lastchar =s[0];
    int count =1;
    for(int i=1;i<size;++i){
        if(s[i]==lastchar){
            count++;
        } else{
            cout<<count<<lastchar;
            lastchar = s[i];
            count=1;
        }
    }
    cout<<count<<lastchar<<endl;
}