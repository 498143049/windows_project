//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int robot(int input){
    if(input==1) return 1;
    else if(input ==2) return 2;
    else if(input ==3) return 4;
    else if(input ==4) return 6;
    else if(input ==5) return 12;
    long int  result = 2;
    for(int i=3;i<=input;i++){
        result=result*result;


        result%=1000000007;
    }
    return  result;
}
int main() {
    //    freopen("../../newtest2/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int input;
    cin>>input;
   cout<<robot(input)<<endl;

}