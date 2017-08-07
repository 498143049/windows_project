//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <string>
#include <sstream>
using namespace std;
class Solution {
public:
    void addPath(){
        stringstream ss;
        for(auto i:t_path){
            ss<<i<<'.';
        }
        string s = ss.str();
        t_ans.push_back(s.substr(0,s.size()-1));
    }
    bool verify(string num,int &t_int) {
        if(num.size()>3) return false;
        int t =  stoi(num);
        if(t_int>=0&&t_int<=255){
            return true;
        }
        else{
            return false;
        }
    }
    void restore(int time, string src, vector<int> &path){
        if(src.size()<(4-time)||src.size()>(12-3*time)) return ;
        if(time==3){
            int t_int = 0;
            if(verify(src,t_int)){
                path.push_back(t_int);
                addPath();
                path.pop_back();
            }
            return ;
        }
        for(int i=1;i<=3;++i){
            int t_int = 0;
            if(verify(src.substr(0,i),t_int)){
                path.push_back(t_int);
                restore(time+1,src.substr(i),path);
                path.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        restore(0,s,t_path);
        return t_ans;
    }
private :
    vector<string>  t_ans;
    vector<int> t_path;
};
int main() {
    Solution st;
    string s = "0000";
    st.restoreIpAddresses(s);
}