//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include <unordered_map>
#include<algorithm>
using namespace std;
int robot(vector<int> vt){

}
int main() {
    freopen("../../net/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int num;
    cin>>num;
    vector<int> vt;
    vt.reserve(num);
    unordered_map<vector<int>,int> map;
    while(num--){
        int t;
        cin>>t;
        vt.push_back(t);
    }


}