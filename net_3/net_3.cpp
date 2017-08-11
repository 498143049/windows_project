//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;
unordered_map<int,int> mp;
int robot(int current,int target){
    if(mp.find(current)!=mp.end()){
        return mp[current];
    }
    if(current==target) return 0;
    if(current>target) return 10000;
    int mintart = 10000;
    for(int i=2;i*i<=current;i++){
        if(current%i==0){
            mintart = min(mintart,robot(current+i,target)+1);
            mintart = min(mintart,robot(current+current/i,target)+1);
        }
    }
    mp[current]=mintart;
    return mintart;
}
int main() {
    freopen("../../net_3/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int curren,target;
    cin>>curren>>target;
    int t = robot(curren,target);
    if(t<10000) {
        cout << t << endl;
    }
    else{
        cout<<"-1"<<endl;
    }
}
//#include <queue>
//int main() {
//    freopen("../../net_3/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
//    int curren,target;
//    cin>>curren>>target;
//    int count=0;
//    queue<int> qu;
//    vector<bool> visited(target+1, false);
//    qu.push(curren);
//    visited[curren] = false;
//    while (!qu.empty()){
//        int size = qu.size();
//        count++;
//        while (size--){
//            int i = qu.front();
//            visited[i] = true;
//            qu.pop();
//            if(i==target){
//                cout<<count-1<<endl;
//                return 0;
//            }
//            else if(i<target){
//                for(int j=2;j*j<=i;j++) {
//                    if(i%j==0) {
//                        if((i+j)<=target){
//                        if(!visited[i+j])
//                            qu.push(i+j);
//                        }
//                        if((i+i/j)<=target){
//                            if(!visited[i+i/j])
//                                qu.push(i+i/j);
//                        }
//                    }
//                }
//            }
//
//        }
//    }
//    cout<<-1<<endl;
//
//}
