//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>
using namespace std;
int main() {
    freopen("../../net_2/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int num;//计算出等于2个平方想加，即二分法
    cin>>num;
    if(num==0) return 0;
    int left  =  1;
    int right = sqrt(num);
    int count = 0;
    int   count2=0;
    if(right*right==num){
        count2=4;
    }

    while(right>=left){
        int tempnum = right*right+left*left;
        if(tempnum==num){
            if(left==right){
                count++;
            }
            else{
                count+=2;
            }

            left++;
            right--;
        }
        else if(tempnum>num){
            right--;
        }
        else {
            left++;
        }
    }
    cout<<count*4+count2;
}