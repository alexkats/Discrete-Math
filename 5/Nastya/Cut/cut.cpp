#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <utility>
#include <time.h>
#include <queue>
#include <vector>
#include <algorithm>

#define na "cut"
#define fori0n for(int i = 0; i < n; i++)
const int infint = 1e9 + 7;

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, m, d[505], vnext[505], g[505][505], flow[505][505];

int bfs (int st) {
    memset(d, -1, sizeof(d));
    queue <int> q;
    q.push(st);
    d[st] = 0;
    while (!q.empty())
    {
        st = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (i == st)
                continue;
            if (flow[st][i] < g[st][i] && d[i] == -1) {
                d[i] = d[st] + 1;
                q.push(i);
            }
        }
    }
    return d[n - 1];
}

void dfs (int v, int &ans, int f) {
    if (v == n - 1 || f == 0) {
        ans = f;
        return;
    }
    for (; vnext[v] < n; vnext[v]++) {
        int i = vnext[v];
        if (d[v] + 1 != d[i])
            continue;
        dfs(i, ans, min(g[v][i] - flow[v][i], f));
        flow[v][i] += ans;
        flow[i][v] -= ans;
        if (ans != 0)
            return;
    }
    ans = 0;
}

bool was[505];
int q = 0;
int res[505];

void dfs_st(int v) {
    was[v] = 1;
    res[q++] = v;
    for (int i = 0; i < n; i++) {
        if (was[i])
            continue;
        if (g[v][i] - flow[v][i] > 0)
            dfs_st(i);
    }
}

int main()
{
    freopen(na".in", "r", stdin);
    freopen(na".out", "w", stdout);

    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = flow[i][j] = 0;
    int tmp1, tmp2, tmp3;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d\n", &tmp1, &tmp2, &tmp3);
        g[tmp1 - 1][tmp2 - 1] = tmp3;
        g[tmp2 - 1][tmp1 - 1] = tmp3;
    }
    while (bfs(0) != -1) {
        memset(vnext, 0, sizeof(vnext));
        while (1) {
            int tmp_ans = 0;
            dfs(0, tmp_ans, infint);
            if (tmp_ans == 0)
                break;
        }
    }
    memset(was, 0, sizeof(was));
    dfs_st(0);
    printf("%d\n", q);
    for (int i = 0; i < q; i++)
        printf("%d ", res[i] + 1);
    printf("\n");

    return 0;
}
