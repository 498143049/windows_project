//
// Created by dubing on 2017/6/28.
//
#include <iostream>
#include <algorithm>
using namespace std;
int a[10010];
int main()
{
    int N;
    while (cin >> N)
    {
        for (int i = 0; i < N; ++ i)
        {
            cin >> a[i];
        }
        sort(a,a+N);
        int l = 0,r = N - 1;
        __int64 sum = 0;
        while (l <= r)
        {
            sum += a[r --] - a[l ++];
        }
        cout << sum << endl;
    }
    return 0;
}