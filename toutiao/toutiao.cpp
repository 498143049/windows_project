//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    freopen("../../toutiao/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int num;
    cin>>num;
    vector<int> num_array;
    num_array.reserve(num);
    while(num--){
        int t;
        cin>>t;
        num_array.push_back(t);
    }
    sort(num_array.begin(),num_array.end());
    int pointone=0;
    int count = 0;
    while(pointone<num_array.size()-1){
        if(num_array.size()==pointone+1) {
            count += 2;
            break;
        }

        if(num_array[pointone]-num_array[pointone-1]>=10){
            pointone++;
        } else{
            //考虑重中间插入一个数
            pointone++;
            count+=2;
            continue;
        }

        if(num_array[pointone]-num_array[pointone-1]>=10) {
            pointone++;
        }
        else{
            pointone++;
            count+=1;
        }
    }
    cout<<count<<endl;

}