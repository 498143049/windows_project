//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void robot(vector<int> &vt,int start){
    for(int i=start;i<vt.size()/(start+1);++i){
        vt[2*i]=i;
    }
}
int main() {
    freopen("../../net_10/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int testcase;
    cin>>testcase;
    while(testcase--){
        int num;
        cin>>num;
    };
}