//
// Created by dubing on 2017/6/28.
// question:
// 
// url:
#include <bits/stdc++.h>
#include <set>
using namespace std;


typedef  pair<int,int> people;


bool cmp(people a, people b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}
int main() {
    freopen("../../didi_one/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int n,m;
    while(cin>>n>>m){
        multiset<int> desks;

        for (int i = 0; i < n; ++i) {
            int ct;
            cin>>ct;
            desks.insert(ct);
        }
        vector<people> peoples;
        for (int j = 0; j < m; ++j) {
            int n,v;
            cin>>n>>v;
            peoples.emplace_back(make_pair(n,v));

        }
        sort(peoples.begin(),peoples.end(),cmp);
        //以消费金额进行贪心
        int count = 0;
        for (int k = 0; k < m; ++k) {
            if(desks.size()==0) break;
            auto i = desks.lower_bound(peoples[k].first);
            if(i!=desks.end()){
                count+=peoples[k].second;
                desks.erase(i);
            }
        }
        cout<<count<<endl;
    }
}