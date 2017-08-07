//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;
template <typename T>
class C{
    T a;
    T b;
};

template <typename T>
class C<T*>{
public:
    T a;
    T b;
    T c;
};
int main() {
    C<int*> cd;
    cd.c=1;
    cout<<cd.c<<endl;

}