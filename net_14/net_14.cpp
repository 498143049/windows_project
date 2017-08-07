//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include <climits>
#include<algorithm>

using namespace std;
int main() {
    freopen("../../net_14/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    vector<int> carx;
    vector<int> cary;
    int targetx, targety;
    int wt,tt;
    int carnum;
    cin>>carnum;
    int tcarnum = carnum;
    carx.reserve(carnum);
    cary.reserve(carnum);
    while(tcarnum--){
        int tnum;
        cin>>tnum;
        carx.push_back(tnum);
    }
    while(carnum--){
        int tnum;
        cin>>tnum;
        cary.push_back(tnum);
    }
    cin>>targetx>>targety>>wt>>tt;
    int minvalue = INT_MAX;
    for(int i=0;i<carx.size();++i){
        int cost = (abs(carx[i])+abs(cary[i]))*wt+(abs(carx[i]-targetx)+abs(cary[i]-targety))*tt;
        minvalue = min(minvalue,cost);
    }

    minvalue=min(minvalue,(abs(targetx)+abs(targety))*wt);
    cout<<minvalue<<endl;

}