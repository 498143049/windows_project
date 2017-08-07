//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//效率为 O(n*m)
pair<bool,int> native(const string &src, const string &par){
    int j,i;
    for( i=0;i<src.size()-par.size()+1;i++){
            for ( j = 1; j < par.size(); j++) {
                if (src[i+j] != par[j]) break;
            }
            if(j==par.size()) return {true,i};
        }
    return {false,0};
};
//暴力搜索最优秀的写法，应该说最符合KMP的模式写的
int ViolentMatch(string s, string p)
{
    int sLen = s.size();
    int pLen = p.size();
    int i = 0;
    int j = 0;
    while (i < sLen && j < pLen) {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            //②如果失配（即S[i]! = P[j]），令i = i - (j - 1)，j = 0
            i = i - j + 1;
            j = 0;
        }
    }
    //匹配成功，返回模式串p在文本串s中的位置，否则返回-1
    if (j == pLen)
        return i - j;
    else
        return -1;
}
pair<bool,int> kmp(const string &src, const string &par){

}
#define use
    string A = "ABABDAAAACAAAABCABAB";
    string B = "AAACAAAA";
    auto s = use(A,B);
    cout<<s.first<<" "<<s.second<<endl;
}