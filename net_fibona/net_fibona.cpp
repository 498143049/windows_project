//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;
int main() {
    freopen("../../net_fibona/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int target;
    cin>>target;
    vector<int> vt(3);
    vt[0] = 0;
    vt[1] = 1;
    long int i=2;
    for(;;++i){
        vt[i%3] = vt[(i-1)%3]+vt[(i-2)%3];
        if(vt[i%3]>target){
            break;
        }
    }
    cout<<min((vt[i%3]-target),(target-vt[(i-1)%3]))<<endl;

}