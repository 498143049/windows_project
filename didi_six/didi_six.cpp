//
// Created by dubing on 2017/6/28.
// question:
// 
// url:
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("../../didi_six/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
     int num,target;
    while (cin>>num>>target){
        vector<int> vt(num);
        vector< long long> vt2(target+1);
        for (int i = 0; i < num; ++i) {
            cin>>vt[i];
        }
        vt2[0] = 1;
        vt2[vt[0]]=1;
        for (int k = 1; k <num; ++k) {
            for (int j = target; j >=vt[k]; --j) {
                    vt2[j]+=vt2[j-vt[k]];
            }
        }
        cout<<vt2.back()<<endl;
    }
}