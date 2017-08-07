//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
   // freopen("../../geohash/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int i = 0;
    int left = -90, right = 90;
    int num;
    cin>>num;
    string str;
    while(i++<6){
        int mid = (left+right)/2 ;
        if(num>=mid){
            str.push_back('1');
            left = mid;
        }
        else{
            str.push_back('0');
            right = mid;
        }
    }
    cout<<str<<endl;
}