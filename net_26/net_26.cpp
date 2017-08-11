//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
#include <set>
#include <iterator>
using namespace std;
int robot(int num,long &target,vector<int> &vt){
//    if(vt[num]!=0){
//        target=target-
//    }
}


int main() {
    freopen("../../net_26/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int num; long count;
    cin>>num>>count;
    vector<int> vt(num);
    set<int> st;
    set<int> contain;
    set<int> candicate;
    for(int i=0;i<num;++i){
        st.insert(i+1);
        cin>>vt[i];
        if(vt[i]!=0){
            contain.insert(vt[i]);  //含有的集合
        }
    }
    set_difference(st.begin(),st.end(),contain.begin(),contain.end(),inserter(candicate,candicate.begin()));  //获取set后

    for(int i=num-1;num>=0;num++){


    }
}