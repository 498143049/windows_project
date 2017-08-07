//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;
int main() {
    freopen("../../net_15/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    string ss;
    cin>>ss;
    string ss2 = ss;
    int count = 0;
    int count2 = 0;
    int    flag = 1;   //设置标记变量
    for(int i=0;i<ss.size()&&flag;++i){
        flag = 0;
        for (int j = ss.size()-1; j >i ; --j) {
            if(ss[j]>ss[j-1]){
                swap<char>(ss[j],ss[j-1]);
                count++;
                flag =1;
            }
        }
    }
    flag =1;
    for(int i=0;i<ss2.size()&&flag;++i){
        flag = 0;
        for (int j = ss2.size()-1; j >i ; --j) {
            if(ss2[j]<ss2[j-1]){
                swap<char>(ss2[j],ss2[j-1]);
                count2++;
                flag =1;
            }
        }
    }

    cout<<min(count,count2)<<endl;

}