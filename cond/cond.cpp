#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;
mutex m;
condition_variable cond;

int flag=0;

void fun(int id){
    for (int j = 0; j < 50; ++j) {
        unique_lock<mutex> lk(m);
        int LOOP=1;
        while(id!=flag)              //一定要用循环判断，若是if多个阻塞线程唤醒后同时处于临界区
            cond.wait(lk);
        if(flag==1) LOOP=2;
        for(int i=0;i<LOOP;i++) {
            cout << (unsigned char) ('A' + id) << " ";
        }
        flag=(flag+1)%2;
        cond.notify_all();
    }

}
int main(){
    thread B(fun,0);
    fun(1);
    cout<<endl;
    B.join();
    return 0;
}  