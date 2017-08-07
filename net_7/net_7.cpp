//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>
using namespace std;
int main() {
    freopen("../../net_7/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int num;
    cin>>num;
    int max = ceil(num/6.0);
    int min = ceil(num/8.0);
    int found = -1;
    for(int i=min;i<=max;i++){
        int t = num-6*i;
        if(t&1){
            //偶数

        }
        else{
            found=i;
            break;
        }
    }
    cout<<found<<endl;

}