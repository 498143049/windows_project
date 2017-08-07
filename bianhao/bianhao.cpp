//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 int  encode(string str)
{
     int index = 0;
     int factor[] = {1+25+25*25+25*25*25, 1+25+25*25, 1+25, 1};
    for(int i=0;i<str.size();i++) {
        index += factor[i] * (str[i] - 'a');
    }
    return index + (str.size() - 1);
}
int main() {
   // freopen("../../bianhao/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    string str;
    cin>>str;
    cout << encode(str) << endl;

}
