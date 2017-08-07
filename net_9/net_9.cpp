//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void op(vector<int> &vt,int time){
    int size = vt.size();

}
int main() {
    freopen("../../net_9/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int testcase;
    cin>>testcase;
    while (testcase--){
        int num,opcase;
        vector<int> vt;
        cin>>num>>opcase;
        num<<1;
        vt.reserve(num);
        while(num--){
            int temp_num;
            cin>>temp_num;
            vt.push_back(temp_num);
        }


    }
}