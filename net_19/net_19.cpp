//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include <numeric>
#include<algorithm>
#include <climits>
using namespace std;

int max_value = -1;
vector<int> vt;
int testnum1;
int sum;
void robot(int time,int sum1, int sum2){
    if(sum1>500000||sum2>500000||sum1>sum/2||sum2>sum/2) return;
    if(sum1==sum2&&sum1!=0){
        max_value = max(max_value,sum1);
    }
    if(time>=testnum1) return;;
    robot(time+1,sum1,sum2); //忽视
    robot(time+1,sum1+vt[time],sum2);
    robot(time+1,sum1,sum2+vt[time]);
}
int main() {
    freopen("../../net_19/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int testnum;
    cin>>testnum;
    testnum1 = testnum;
    vt.reserve(testnum);
    while(testnum--){
        int tempnum;
        cin>>tempnum;
        vt.push_back(tempnum);
    }
     sum = accumulate(vt.begin(),vt.end(),0);

    robot(0,0,0);
    cout<<max_value<<endl;
}