//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;
int main() {
    freopen("../../net_23/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int testcase;
    cin>>testcase;
    while(testcase--){
        int n,k;
        cin>>n>>k;
        vector<int> vt(2*n,0);
        for (int i = 0; i < 2*n; ++i) {
            cin>>vt[i];
        }
        while (k--) {
            vector<int> vt2(2 * n, 0);
            for (int i = 0; i < 2 * n; i = i + 2) {
                vt2[i] = vt[i / 2];
                vt2[i + 1] = vt[i / 2 + n];
            }
            vt.swap(vt2);
        }
        for(int i=0;i<2*n-1;i++){
            cout<<vt[i]<<" ";
        }
        cout<<vt.back()<<endl;

    }
}