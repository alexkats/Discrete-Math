#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <utility>
#include <time.h>
#include <queue>
#include <vector>
#include <algorithm>

#define na "decomposition"
#define fori0n for(int i = 0; i < n; i++)
#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif
const long long inflong = 1e15 + 7;

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct edge {
    int f, s;
    ll c, flow;
    edge () {}
    edge (int a, int b, ll d, ll e) {
        f = a;
        s = b;
        c = d;
        flow = e;
    }
};

struct my_ans {
    ll ans1;
    int ans2;
    vector <int> ans3;
    my_ans() {}
    my_ans(ll a, int b, vector <int> c) {
        ans1 = a;
        ans2 = b;
        ans3 = c;
    }
};

int n, m, d[505], vnext[505];
bool was[505];
vector <int> num[505];
vector <edge> g;
vector <my_ans> ans;
vector <int> tmp2_ans;

int bfs (int st) {
    memset(d, -1, sizeof(d));
    queue <int> q;
    q.push(st);
    d[st] = 0;
    while (!q.empty())
    {
        st = q.front();
        q.pop();
        for (int i = 0; i < (int) num[st].size(); i++) {
            int to = g[num[st][i]].s;
            if (g[num[st][i]].flow < g[num[st][i]].c && d[to] == -1) {
                d[to] = d[st] + 1;
                q.push(to);
            }
        }
    }
    return d[n - 1];
}

void dfs (int v, ll &ans, ll f) {
    if (v == n - 1 || f == 0) {
        ans = f;
        return;
    }
    for (; vnext[v] < (int) num[v].size(); vnext[v]++) {
        int i = g[num[v][vnext[v]]].s;
        if (d[v] + 1 != d[i])
            continue;
        dfs(i, ans, min(g[num[v][vnext[v]]].c - g[num[v][vnext[v]]].flow, f));
        int numm = num[v][vnext[v]];
        g[numm].flow += ans;
        numm = (numm % 2 == 0) ? numm + 1 : numm - 1;
        g[numm].flow -= ans;
        if (ans != 0)
            return;
    }
    ans = 0;
}

ll find_decomp(int st) {
    while (true) {
        if (was[st])
            break;
        bool found = 0;
        int fin, numm;
        for (int i = 0; i < (int) num[st].size(); i++)
            if (g[num[st][i]].flow > 0) {
                numm = num[st][i];
                fin = g[num[st][i]].s;
                found = 1;
                break;
            }
        if (!found) {
            if (st == n - 1)
                break;
            else
                return 0;
        }
        tmp2_ans.push_back(numm);
        was[st] = 1;
        st = fin;
    }
    ll tmp_ans = inflong;
    for (size_t i = 0; i < tmp2_ans.size(); i++)
        tmp_ans = min(tmp_ans, g[tmp2_ans[i]].flow);
    for (size_t i = 0; i < tmp2_ans.size(); i++)
        g[tmp2_ans[i]].flow -= tmp_ans;
    return tmp_ans;
}

int main()
{
    freopen(na".in", "r", stdin);
    freopen(na".out", "w", stdout);

    scanf("%d %d\n", &n, &m);
    int tmp1, tmp2, tmp3;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d\n", &tmp1, &tmp2, &tmp3);
        num[tmp1 - 1].push_back(i * 2);
        num[tmp2 - 1].push_back(i * 2 + 1);
        g.push_back(edge(tmp1 - 1, tmp2 - 1, tmp3, 0));
        g.push_back(edge(tmp2 - 1, tmp1 - 1, 0, 0));
    }
    while (bfs(0) != -1) {
        memset(vnext, 0, sizeof(vnext));
        while (1) {
            ll tmp_ans = 0;
            dfs(0, tmp_ans, inflong);
            if (tmp_ans == 0)
                break;
        }
    }
    while (true) {
        memset(was, 0, sizeof(was));
        tmp2_ans.clear();
        ll tmp_ans = find_decomp(0);
        if (tmp_ans == 0)
            break;
        ans.push_back(my_ans(tmp_ans, (int) tmp2_ans.size(), tmp2_ans));
    }
    printf("%d\n", (int) ans.size());
    for (size_t i = 0; i < ans.size(); i++) {
        printf(lld" %d ", ans[i].ans1, ans[i].ans2);
        for (size_t j = 0; j < ans[i].ans2; j++)
            printf("%d ", ans[i].ans3[j] / 2 + 1);
        printf("\n");
    }

    return 0;
}
