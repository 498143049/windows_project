//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <set>
#include <map>
using namespace std;
class myclass{
public:
    string name;
    string value;
public:
    myclass(string tname, string tvalue):name(tname),value(tvalue){

    }
};
struct comp {
    typedef myclass value_type;
    bool operator () (const value_type & ls, const value_type &rs) {
        return ls.name < rs.name || (ls.name == rs.name && ls.value < rs.value);
    }
};
int main() {
    freopen("../../set/data/a.in", "r", stdin);
    map<myclass, int, comp> map;
    string str;
    while(getline(cin,str)){
        size_t found1 = str.find_last_of('\\');
        size_t found2 = str.find_first_of(' ');
        string s1 = str.substr(found1 + 1, found2 - found1-1);
        string s2 = str.substr(found2+1, str.size() - found2);
        map[myclass(s1, s2)]++;
    }
    for(auto s: map){
        if(s.first.name.size()>16){
            cout<<s.first.name.substr(s.first.name.size()-16,s.first.name.size())<<" "<<s.first.value<<" "<<s.second<<endl;
        }
        else{
            cout<<s.first.name<<" "<<s.first.value<<" "<<s.second<<endl;
        }
    }

}