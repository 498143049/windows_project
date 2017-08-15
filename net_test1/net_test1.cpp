//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;

#include <deque>

int main() {
    freopen("../../net_test1/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取

    int num;
    cin>>num;
    vector<int> array(num);
    for (int i = 0; i < num; ++i) {
        cin>>array[i];
    }
    deque<int> dq;
    if(!(num&0x01)){
    for(int i=0;i<num;++i){
        if(i&0x1){
            dq.push_front(array[i]);
        }
        else{
            dq.push_back(array[i]);
        }
    }
    }
    else {
        for(int i=0;i<num;++i){
            if(i&0x1){
                dq.push_back(array[i]);

            }
            else{
                dq.push_front(array[i]);
            }
        }
    }
    for(int j=0;j<num-1;++j){
        cout<<dq[j]<<" ";
    }
    cout<<dq.back()<<endl;
    

}