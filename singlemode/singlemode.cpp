//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//产生一个单利

class single{
public:
    static single* getInstance() {
        static  single instance; //将其放在栈上 由程序自动释放
        return &instance;
    }

private:
    single(){};
    single(single &){};
    single &operator=(const single&s){};

};
int main() {

}