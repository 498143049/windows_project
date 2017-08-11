//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;
int solve(vector<int> &vt,int bag){
    auto  size = static_cast<int>(vt.size());
    vector<int> temp_value(bag+1,0);
    for(int i=0;i<size;++i){
        for(int j=bag;j>=vt[i];--j){    //从后往前是0,1 背包问题， 重前往后是完全背包问题。
            if(j>=vt[i]){
                temp_value[j]=max(temp_value[j],vt[i]+temp_value[j-vt[i]]);
            }
        }
    }
    return temp_value.back();

}
int main() {
    freopen("../../net_20/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int nums,sum = 0;
    cin>>nums;
    vector<int> vt(nums,0);
    for(int i=0;i<nums;++i){
        cin>>vt[i];
        vt[i]=vt[i]/1024;
        sum+=vt[i];
    }
    cout<<sum<<endl;
    cout<<sum-solve(vt,sum/2)<<endl;
}