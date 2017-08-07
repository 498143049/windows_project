#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
inline void op_change(vector<int> &array,const int &num1,const int &num2) {
    array[num1-1] = num2;
}
inline void op_max(vector<int> &array,const int &num1,const int &num2) {
    if(num1>num2){
        cout<<*max_element(array.begin()+num2-1,array.begin()+num1)<<endl;
    }
    else if(num2==num1){
        cout<<array[num1-1]<<endl;
    }
    else
        cout<<*max_element(array.begin()+num1-1,array.begin()+num2)<<endl;
}
int main() {
    freopen("../test/a.in","r",stdin); //输入重定向，输入数据将从in.txt文件中读取
    vector<int> array;
    int num;
    int line;
    cin>>num;
    cin>>line;

    while(num--){
        int tnum;
        cin>>tnum;
        array.push_back(tnum);
    }
    while(line--){
        int tnum1, tnum2;
        char op;
        cin>>op;
        cin>>tnum1;
        cin>>tnum2;
        if( op=='Q'){
            op_max(array,tnum1,tnum2);
        }
        else {
            op_change(array,tnum1,tnum2);
        }
    }
    return 0;
}