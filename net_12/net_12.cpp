//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int getMax_value(vector<vector<int>> vt) {
    vector<vector<int>> vt_value;
    vt_value[0][0] = vt[0][0];
    int D;
    for(int i=0;i<vt.size();++i){
        for(int j=0;j<vt.size();++j){
            if(j<=D)
                vt_value[i][j]+=vt[i][j];
            else
                vt_value[i][j]= max(vt_value[i][j],vt_value[i][j]+vt[i][j]-vt[i][j-D]);
            if(i==j)
        }
    }

}
int main() {
    freopen("../../net_12/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取

}