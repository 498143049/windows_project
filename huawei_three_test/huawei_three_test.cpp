//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include <map>
using namespace std;

string convert(const string s){
    string out;
    int size = s.size();
    int last = 0;
    for(int i=0;i<size;++i) {
        string temp;
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


map<int,string> mp;

int main() {
    string s;
    int point ;
    int countpoint = 0;
    while(getline(cin,s)){
        int size = s.size();
        for(int i=0;i<size;++i){
            if(s[i]=='{'){
                countpoint++;
                if(countpoint==2){
                    point = i+1;
                }
            }
            else if(s[i]=='}'&&countpoint==2){
                string nes2 = s.substr(point,i-point);
                int arrystart = i+2;
                string one =s.substr(arrystart,4);
                string two = s.substr(arrystart+5,4);
                cout<<nes2<<","<<one<<","<<two<<endl;
                break;
            }
        }
    }
}