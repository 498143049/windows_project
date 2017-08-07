//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
using namespace std;
struct postion{
    int bx;
    int by;
    int sx;
    int sy;
    postion(int x,int y,int bx,int by):bx(bx),by(by),sx(x),sy(y){};
};
uint8_t  tx,ty;
pair<int ,int> b[]={{0,1},{1,0},{0,-1},{-1,0}};
int x_length;
int y_length;
int max_step(vector<vector<char>> &map,postion s){
    queue<postion> qu;
    int array[10][10][10][10];
    qu.push(s);
    array[s.bx][s.by][s.sx][s.sy] = 1;
    while(!qu.empty()){
        auto single  = qu.front();
        qu.pop();

        auto  panduan = [&](int sx,int sy, int bx, int by){
            return sx<0||sy<0||bx<0||by<0||sx>=x_length||sy>=y_length||bx>=x_length||by>=y_length||map[sx][sy]=='#'||map[bx][by]=='#'||array[sx][sy][bx][by]!=0;
        };
        if(single.bx == tx&&single.by == ty) return array[single.bx][single.by][single.sx][single.sy]-1;
        //探索步骤
        for(auto sb :b){
            //判断人是否可达
            uint8_t x = single.sx+sb.first;
            uint8_t y = single.sy+sb.second;
            if(panduan(x,y,single.bx,single.by)) continue; //不可达
            //判断人和箱子是否重合
            if(x==single.bx && y==single.by){
                //箱子按照原位置变换
                int tbx = single.bx+sb.first;
                int tby = single.by+sb.second;
                if(panduan(x,y,tbx,tby)) continue;
                array[x][y][tbx][tby]=array[single.sx][single.sy][single.bx][single.by]+1;
                qu.push(postion(x,y,tbx,tby));
            } else{
                int tbx = single.bx;
                int tby = single.by;
                if(panduan(x,y,tbx,tby)) continue;
                array[x][y][tbx][tby]=array[single.sx][single.sy][single.bx][single.by]+1;
                qu.push(postion(x,y,tbx,tby));

            }
        }
        return -1;
    }




}

int main() {
    freopen("../../net_13/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取


}