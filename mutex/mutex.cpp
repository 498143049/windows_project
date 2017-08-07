//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<thread>
#include <mutex>
#include <chrono>
std::mutex mut;
using namespace std;
void prinf_A(){
    while (true){
        cout<<"A"<<endl;
    }
}
void prinf_B(){
    cout<<"B"<<endl;
}
void prinf_C(){
    cout<<"C"<<endl;
}
int main() {

}