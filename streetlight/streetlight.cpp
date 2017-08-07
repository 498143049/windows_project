//
// Created by dubing on 2017/6/28.
//  question url :https://www.nowcoder.com/question/next?pid=710847&qid=26023&tid=9061578
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <iomanip>
using namespace std;
int main() {
    freopen("../../streetlight/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int nums, mile;
    cin>>nums>>mile;
    vector<int> vt(nums,0);
    int i = 0;
    while(i++<nums){
        int temp;
        cin>>temp;
        vt[i-1] = temp;
    }
    sort(vt.begin(),vt.end());
    double midR = vt[0]-0;
    for(int i = 1;i<nums;i++){
        midR = max((vt[i]-vt[i-1])/2.0,midR);
    }
    midR = max(midR,(double)(mile-vt[nums-1]));
    cout<<fixed<<setprecision(2)<<midR<<endl;
}