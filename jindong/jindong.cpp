//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
#include <set>
using namespace std;
int main() {
    freopen("../../jindong/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    set<int> st;
    int num1,num2;
    cin>>num1>>num2;
    while (num1--){
        int tempnum;
        cin>>tempnum;
        st.insert(tempnum);
    }
    while (num2--){
        int tempnum;
        cin>>tempnum;
        st.insert(tempnum);
    }
    auto end = --st.end();
    for (auto i = st.begin(); i != end; ++i) {
        cout<<*i<<" ";
    }
   cout<<*end<<endl;

}