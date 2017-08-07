//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long int countdouble(long int num){
    if(num<2) return 0;
    if(num==2) return 1;
    if(num&1) {
        //基数
        num--;
    }
    int count=0;
    for(int i=2;i<=num;i+=2){
        int tnum = i;
        while (1){
             tnum = tnum>>1;
            if(tnum&1){
                count+=tnum;
                break;
            }
        }

    }
    return count;

}
long int numsingle(long int num){
    if(!num&1){
        //偶数
        num--;
    }
    return (num+1)*(num+1)/4;

}
long int countnum(long int num){
    return countdouble(num)+numsingle(num);
}
int main() {
    freopen("../../net_6/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int num;
    cin>>num;
    cout<<countnum(num)<<endl;
}