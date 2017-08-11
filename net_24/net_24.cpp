#include <iostream>
#include <deque>
using namespace std;

int main()
{
    freopen("../../net_24/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int n, k;
    cin >> k;
    while (k > 0)
    {
        deque<int> q;
        k--;
        cin >> n;
        for (int i = n; i > 0; i--)
        {
            q.push_front(i);
            int t = q.back();
            q.pop_back();
            q.push_front(t);
        }
        for (int i = 0; i < q.size()-1; i++)
            cout << q[i] << " ";
        cout <<q.back()<< endl;
    }
}