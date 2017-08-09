//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <tuple>
#include <queue>
#include <unordered_map>

using namespace std;
typedef  tuple<int ,char,char,char> position;
bool postionvalue[1025][101][101] = {false};
pair<char,char> move_setp[4]={{1,0},{0,1},{0,-1},{-1,0}};
char ex,ey,ix,iy;
int bsf(vector<string> &ch){
    char xmax,ymax;
    ymax = ch.size();
    xmax = ch[0].size();
    position entry(0,ix,iy,0);
    queue<position> qu; //创建出一个队
    postionvalue[0][ix][iy] = true;
    qu.push(entry);
    while(!qu.empty()){
        position & pos = qu.front();qu.pop();
        if( get<1>(pos)==ex&&get<2>(pos)==ey) return get<3>(pos);
        for(auto smove:move_setp){
            char x = get<1>(pos)+smove.first;char y = get<2>(pos)+smove.second;
            int status = get<0>(pos);char setp = get<3>(pos);
            //访问过的不能再访问
            if(x<0||x>=xmax||y<0||y>=ymax||ch[x][y]=='0') continue;
            if(ch[x][y]>='A'&&ch[x][y]<'Z'){
                if((status&(1<<(ch[x][y]-'A')))==0)
                    continue;  // 没有拿到钥匙弹出
            }
            if(ch[x][y]>='a'&&ch[x][y]<'z'){
                status=status|(1<<(ch[x][y]-'a'));
            }
            if(!postionvalue[status][x][y]){
                postionvalue[status][x][y] = true;
                qu.push(std::make_tuple(status,x,y,(char)(setp+1)));
            }


        }
    }
    return -1;
}


int main() {
    freopen("../../pingduoduo2/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int xmax,ymax;
    cin>>xmax>>ymax;
    vector<string> vt;
    vt.reserve(ymax);
    while(ymax--){
        string s;
        cin>>s;
        vt.push_back(s);
    }
    char count =1;
    for(char j=0;j<vt.size();++j){
        for(char i=0;i<vt[0].size();i++){
            if(vt[i][j]=='2'){
                ix=i;iy = j;
            }
            else if(vt[i][j]=='3'){
                ex=i;ey = j;
            }
        }
    }
    cout<<bsf(vt)<<endl;


}