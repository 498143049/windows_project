//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template <typename  c>
void my_sort(c begin,c end){
    typedef  typename iterator_traits<c>::value_type  val_type;  //ubt
    c first = begin;
    ++begin;

    for(;begin!=end;++begin){
         val_type  tempvale = *begin;
        auto t = lower_bound(first,begin,tempvale);
        if(t!=begin){
            copy_backward(t,begin,begin+1);
            *t = tempvale;
        }
    }
}
void insert_sort(vector<int> &vt){
    int size = static_cast<int>(vt.size());
    for(int i=1;i<size;++i) {
        for(int j=i;j>0;j--){
            //内插入
            if(vt[j]<vt[j-1]){
                swap(vt[j], vt[j-1]);
            }
            else{
                break; //插入一次就可以了
            }
        }
    }
    return;
}
void binary_insert_sort(vector<int> &vt){
    int size = static_cast<int>(vt.size());
    for(int i=1;i<size;++i) {
        int temp = vt[i];
                            //找到插入位置
        int left = 0; int right = i;
        while(i>left){
            int mid = left+right/2;
            if(vt[mid]>)
        }
    }
    return;
}
int main() {
    freopen("../../sort/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    vector<int> vt={1,2,10,4,6,5};
   // my_sort(vt.begin(),vt.end());
    insert_sort(vt);
    int a = 4;
}