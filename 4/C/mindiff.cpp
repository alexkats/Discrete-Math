#define NAME "mindiff"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <ctime>
#include <cctype>
#include <cassert>
#include <memory>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define pb push_back
#define mp make_pair
#define frs first
#define snd second

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const int INF = (int) 2e9 + 7;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vi> vvi;
typedef vector <vll> vvll;
typedef vector <bool> vb;

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;

typedef vector <pii> vpii;
typedef vector <pil> vpil;
typedef vector <pli> vpli;
typedef vector <pll> vpll;

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

template <typename T>
T sqr (T a)
{
    return a * a;
}

typedef pair <pii, int> elem;
const int N = 1005;

int n, m;
vector <elem> g;
int p [N];
int rg [N];

bool cmp (elem a, elem b)
{
    return a.snd < b.snd;
}

int find_set (int x)
{
    if (x == p [x])
        return x;

    p [x] = find_set (p [x]);
    return p [x];
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    memset (rg, 1, sizeof (rg));

    scanf ("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        scanf ("%d %d %d", &x, &y, &z);
        g.pb (mp (mp (x, y), z));
    }

    sort (g.begin (), g.end (), cmp);

    for (int i = 1; i <= n; i++)
        p [i] = i;

    int ans = INF;
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
            p [j] = j;

        memset (rg, 1, sizeof (rg));
        int max_edge;
        int q = 0;

        for (int j = i; j < m; j++)
        {
            int u = g [j].frs.frs;
            int v = g [j].frs.snd;
            int cost = g [j].snd;
            u = find_set (u);
            v = find_set (v);

            if (u == v)
                continue;

            if (rg [u] < rg [v])
                swap (u, v);

            if (rg [u] == rg [v])
                rg [u]++;

            max_edge = cost;
            q++;
            p [v] = u;
        }

        if (q != (n - 1))
            continue;

        ans = min (ans, max_edge - g [i].snd);
    }

    if (ans == INF)
    {
        puts ("NO");
        return 0;
    }

    puts ("YES");
    printf ("%d\n", ans);

    return 0;
}
