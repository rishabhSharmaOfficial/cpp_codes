#include <bits/stdc++.h>
using namespace std;
int n, k, a[10000], vis[10000][21][21];
int solve(int i, int k1, int k2)
{
    int j = n - i - 1 - k1 + k2;
    if (i >= j)
        return 0;
    if (vis[i][k1][k2] != -1)
        return vis[i][k1][k2];
    if (k1 + k2 > k)
        return 30;
    if (a[i] == a[j])
        return vis[i][k1][k2] = solve(i + 1, k1, k2);
    return vis[i][k1][k2] = 1 + min(solve(i + 1, k1, k2 + 1), solve(i, k1 + 1, k2));
}
int main()
{
    //freopen("DataSet.txt","r",stdin);
    int t, ans;
    scanf("%d", &t);
    for (int T = 1; T <= t; T++)
    {
        memset(vis, -1, sizeof vis);
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        ans = solve(0, 0, 0);
        if (!ans)
            printf("Case %d: Too easy\n", T);
        else if (ans > k)
            printf("Case %d: Too difficult\n", T);
        else
            printf("Case %d: %d\n", T, ans);
    }
}
