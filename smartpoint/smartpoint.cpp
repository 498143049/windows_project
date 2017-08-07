//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include <cstddef>
#include<vector>
#include<algorithm>
#include <memory.h>
#include <cstdint>
using namespace std;
class object{
public :
    int a;
    int b;
};

// 仔细自考一下，这个类维护一个这块内存的内容
template  <typename T,typename count_type = uint32_t>
class smart_pointsing{
    friend  class smart_point;
public:
    smart_pointsing() {
        target = NULL;
        count =0;
    }
    smart_pointsing(T* dst) {
        count=1;
        target = dst;
    }
    ~smart_pointsing(){
        delete target;
    }
private:
        T * target;
        count_type count;
};
template  <typename  T>
class smart_point{
public:
    smart_point(T * p){
        qd = new smart_pointsing(p);
    }
    ~smart_point(){
        --qd->count;
        if(qd->count==0)
            delete qd;
    }
    //拷贝构造函数
    smart_point(smart_point &copy){
        qd = copy.qd;
        ++qd->count;
    }
    smart_point& operator = (smart_point &copy) {
        ++copy.qd->count;
        //原来的对象做析构处理
        --qd->count;
        if(qd->count == 0)
            delete  qd;
        qd = copy.qd;
        return *this;
    }
    T* operator -> (){
        return qd->target;
    }
    T& operator *(){
        return *(qd->target);
    }
private :
    smart_pointsing * qd;
};

//智能指针的使用
// 有3个智能指针  unique_ptr  shared_ptr
int main() {
    smart_point<object> a(new object());
    //线程安全的考虑
}