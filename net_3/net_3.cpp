//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;
unordered_map<int,int> mp;
int robot(int current,int target){
    if(mp.find(current)!=mp.end()){
        return mp[current];
    }
    if(current==target) return 0;
    if(current>target) return 10000;
    int mintart = 10000;
    for(int i=current-1;i>=2;i--){
        if(current%i==0){
            mintart = min(mintart,robot(current+i,target)+1);
        }
    }
    mp[current]=mintart;
    return mintart;
}
int main() {
    freopen("../../net_3/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int curren,target;
    cin>>curren>>target;
    int t = robot(curren,target);
    if(t<10000) {
        cout << t << endl;
    }
    else{
        cout<<"-1"<<endl;
    }
}