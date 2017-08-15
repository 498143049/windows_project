//
// Created by dubing on 2017/6/28.
// question:
// 
// url:
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("../../toutiao_test1/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int num;
    while (cin>>num){
    if(num==0) return 3;
     vector<int> vt;
    vt.resize(num);
    for (int i = 0; i < num; ++i) {
        cin>>vt[i];
    }
    //选择贪心算法
    sort(vt.begin(),vt.end());
    int count = 0,addcount=0;
    int last;
    for(int i=0;i<num;++i){
        if(count==0){
            ++count;
            last=vt[i];
        }
        else if(count==3){
            count = 0;
            ++count;
            last=vt[i];
        }
        else{
            if(vt[i]-last>10){
                addcount++;
                count++;
                last = min(last+10,vt[i]);
                --i; //回退一部
            }
            else{
                count++;
                last=vt[i];
            }
        }

    }
    addcount+=3-count;
    cout<<addcount<<endl;
    }

}