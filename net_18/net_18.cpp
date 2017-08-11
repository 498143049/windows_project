//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
#include <set>
using namespace std;

void robot(uint8_t num, int &count,vector<set<uint8_t>> &vs,vector<bool> &vt){
    if(num==vs.size()){
        count++;
        return;
    }
    for(auto i:vs[num]){
        if(vt[i]){
            vt[i]=false;
            robot(num+1,count,vs,vt);
            vt[i]=true;
        }
    }
}

int main() {
    freopen("../../net_18/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    //深度优先搜索
    int num;
    cin>>num;
    vector<set<uint8_t>> vset;
    vector<bool> vti(6,true);
    while(num--){
        string s;
        cin>>s;
        set<uint8_t> sets;
        for(auto single :s) {
            sets.insert(single-'0');
        }
        vset.push_back(sets);
    }
    int count = 0;
    robot(0,count,vset,vti);
    cout<<count<<endl;
}