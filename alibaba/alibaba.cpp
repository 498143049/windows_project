//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include <deque>
#include<algorithm>
#include <climits>
#include <numeric>
using namespace std;
int main() {
    freopen("../../alibaba/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    long int x;long int y;
    cin>>x>>y;
    deque<int> dq;
    dq.push_back(2);
    dq.push_back(2);
    dq.push_back(1);
    dq.push_back(1);
    for(int i=3;i<=y;i++){
        int count=0;
        int takecount  = 0;
        bool takeout = false;
        for(int c=0;c<dq.size();++c){
            ++dq[c];
            if(dq[c]<x){
                if(dq[c]>=2){
                    count++;
                }
            }
            else if(dq[c]>=x){
                takeout = true;
            }
        }
        for(int j=0;j<count;++j){
            dq.push_back(1);
        }
        if(count>=10||takeout){
            dq.pop_front();
            dq.pop_front();
            dq.pop_front();
            dq.pop_front();
        }
    }
    cout<<accumulate(dq.begin(),dq.end(),0)<<endl;
}