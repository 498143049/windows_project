//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;
string convert(const string s){
    string out;
    int size = s.size();
    int last = 0;
    for(int i=0;i<size;++i) {
        string temp;
        if(s[i] == 32){
            last++;
            continue;

        }
        if (s[i] == ',') {
            string s2 = s.substr(last,i-last);
            last = i+1;
            out.push_back(s2[3]);
            if(s2[2]!='F'){
                out.push_back(s2[2]);
            }
        }
    }
    string s2 = s.substr(last,size-last);
    out.push_back(s2[3]);
    if(s2[2]!='F'){
        out.push_back(s2[2]);
    }
    return out;
}


int main() {
    string s;
    freopen("../../huawei_two_test/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    while (getline(cin,s)){
    cout<<out(s)<<endl;
    }
}