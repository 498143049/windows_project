//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int get_min_sub(string &src) {
   //由于减少必须是偶次数减少，而且必须满足
    int i = src.size()/2 -1;
    for(;i>0;--i) {
        int j=0;
        for(;j<i;++j){
            if(src[(j+i)]!=src[j]){
                break;
            }
        }
        if(j==i){
            return i*2;
        }
    }
    return 0;
}
int main() {
    //   freopen("../../newtest/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    string str;
    cin>>str;
    cout<<get_min_sub(str)<<endl;
}