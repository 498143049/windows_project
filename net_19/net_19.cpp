#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("../../net_19/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int n = 0;
    cin >> n;
    vector<int> ts(n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> ts[i];
        sum += ts[i];

    }
    vector<vector<int>> dp(2, vector<int>(2 * sum + 1, -1));
    dp[0][sum] = 0;
    vector<int> *dp0 = &(dp[0]);
    vector<int> *dp1 = &(dp[1]);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= 2 * sum; ++j)
        {
            int h = ts[i - 1];
            (*dp1)[j] = (*dp0)[j];
            if (j - h >= 0 && (*dp0)[j - h] != -1)
            {
                (*dp1)[j] = max((*dp1)[j], (*dp0)[j - h]);
            }
            if (j + h <= 2 * sum && (*dp0)[j + h] != -1)
            {
                (*dp1)[j] = max((*dp1)[j], (*dp0)[j + h] + h);
            }
        }
        auto tmp = dp0;
        dp0 = dp1;
        dp1 = tmp;

    }
    if ((*dp0)[sum] == 0)
        cout
                << -1 << endl;
    else cout << (*dp0)[sum] << endl;
    return 0;
}