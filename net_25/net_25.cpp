#include <stdio.h>
inline long long
max(long long a, long long b)
{
    return (a > b ? a : b);
}
inline long long min(long long a, long long b) { return (a > b ? b : a); }

int main()
{
    freopen("../../net_25/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取 ，
    int N, K, D, i, j, k;
    long long stu[51], fm[11][51], fn[11][51], ans;
    while (~scanf("%d", &N))
    {
        for (i = 0; i < N; scanf("%lld", &stu[++i]))
            ;
        scanf("%d %d", &K, &D);
        for (i = 0; i <= K; ++i)
            for (j = 0; j <= N; fm[i][j] = fn[i][j] = 0, ++j)
                ;
        for (i = 1, ans = ~0LL; i <= N; ++i)
        {
            fm[1][i] = fn[1][i] = stu[i];
            for (k = 2; k <= K; ++k)
            {
                for (j = i - 1; j > 0 && i - j <= D; --j)
                {
                    fm[k][i] = max(fm[k][i], max(fm[k - 1][j] * stu[i], fn[k - 1][j] * stu[i]));
                    fn[k][i] = min(fn[k][i], min(fn[k - 1][j] * stu[i], fm[k - 1][j] * stu[i]));
                }
            }
            ans = max(ans, fm[K][i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}