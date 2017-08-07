//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool is_per(long int t){
    for(int i=2;i<t;i++){
        if(t%i == 0){
            return false;
        }
    }
    return true;
}
vector<int> per_array(int k){
    vector<int> st(1,2);
    for(int i=3;i<k;i++){
        if(is_per(i)){
            st.push_back(i);
        }
    }
    return std::move(st);
}
int main() {
    freopen("../../prie/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int n;
    cin>>n;
    vector<int> st = per_array(n);
    //问题转化为 2sum 问题
    int t1 = 0 , t2 = st.size()-1;
    int count = 0;
    while(t1<=t2){
        if(st[t1]+st[t2]==n){
            count++;
            t1++;
            t2--;
        }
        else if(st[t1]+st[t2]>n){
            t2--;
        }
        else if(st[t1]+st[t2]<n){
            t1++;
        }
    }
    cout<<count<<endl;

}