//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include <unordered_map>
#include<algorithm>
using namespace std;

int main() {
    freopen("../../net/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int num;
    while (cin>>num){
        vector<int> vt(num,0);
        for(int i=0;i<num;++i)
            cin>>vt[i];

        int left = 0; int right = num-1;
        int count = 0;
        while (left<right){
            if(vt[left]<vt[right]){
                ++left;
                vt[left]+=vt[left-1];
                count++;
            }
            else if(vt[left]>vt[right]){
                --right;
                vt[right]+=vt[right+1];
                count++;
            }
            else {
                ++left;
                --right;
            }
        }
        cout<<count<<endl;

    }
}