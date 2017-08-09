//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;

string out(string s){
    int size = s.size();
    if(size==0)
        return  "!error";
    string out;
    char lastchar = 0;
    int lastcharcount = 0;
    for(int i=0;i<size;++i){
        if(s[i]>='a'&&s[i]<='z'){
            if(lastchar==s[i]){
                ++lastcharcount;
                if(lastcharcount>2){
                    return "!error";
                }

            } else {
                lastchar = s[i];
                lastcharcount = 1;
            }
            out.push_back(s[i]);
        }
        else if(s[i]>='1'&&s[i]<='9'){
            int count = s[i]-'0';
            i++;
            while(s[i]>='0'&&s[i]<='9'){
                count = count*10+s[i]-'0';
                i++;
            }
            if(count<=2) return "!error";
            if(lastchar==s[i]) return "!error";
            if(s[i]==s[i+1]) return "!error";
            if(s[i]<'a'||s[i]>'z') return "!error";
            while (count--){
                out.push_back(s[i]);
            }

        }
        else {
            return  "!error";
        }
    }
    return out;
}
int main() {
    freopen("../../huawei_one_test/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    string s;

    while (getline(cin,s)){
        cout<<out(s)<<endl;
    }
}