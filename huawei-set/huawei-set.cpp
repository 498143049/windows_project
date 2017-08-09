//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include <set>

using namespace std;

int main() {
    freopen("../../huawei-set/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int num;
    while (cin >> num) {
        set<int> st;
        while ((bool) (num--)) {
            int tempnum;
            cin >> tempnum;
            st.insert(tempnum);
        }
        auto end = --st.end();
        for (auto i = st.begin(); i != end; ++i) {
            cout << *i << "\n";
        }
        cout << *end << endl;
    }
}