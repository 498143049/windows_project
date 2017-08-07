//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <set>
using namespace std;
int main() {
    set<int>eg1;
    eg1.insert(1);
    eg1.insert(100);
    eg1.insert(5);
    eg1.insert(1);//元素1因为已经存在所以set中不会再次插入1
    eg1.insert(10);
    eg1.insert(9);
//遍历set，可以发现元素是有序的
    set<int>::iterator set_iter=eg1.begin();
    cout<<"Set named eg1:"<<endl;
    for(;set_iter!=eg1.end();set_iter++) cout<<*set_iter<<" ";
    cout<<endl;
//使用size()函数可以获得当前元素个数
    cout<<"Now there are "<<eg1.size()<<" elements in the set eg1"<<endl;
    if(eg1.find(200)==eg1.end())//find()函数可以查找元素是否存在
        cout<<"200 isn't in the set eg1"<<endl;
}