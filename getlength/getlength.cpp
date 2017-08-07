#include<iostream>
#include <string>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    auto single = str.rfind(' ');
    if(single == std::string::npos){
        cout<<str.size()<<endl;
    }
    else {
        cout<<str.size()-single<<endl;
    }
}