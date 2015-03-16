#define NAME "maxflow"

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

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll INFLONG = (ll) 1e18 + 7;

using namespace std;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vi> vvi;
typedef vector <vll> vvll;
typedef vector <char> vc;

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;

typedef vector <pii> vpii;
typedef vector <pil> vpil;
typedef vector <pli> vpli;
typedef vector <pll> vpll;

template <typename T>
T sqr (T a)
{
    return a * a;
}

const int N = 505;

int n, m;
ll c [N][N];
ll f [N][N];
vc used;
vi d, good;

char bfs ()
{
    for (int i = 1; i <= n; i++)
    {
        d [i] = -1;
        used [i] = 0;
    }

    queue <int> q;
    q.push (1);
    d [1] = 0;
    used [1] = 1;
    char exists = 0;

    while (!q.empty ())
    {
        int v = q.front();
        q.pop ();

        for (int i = 1; i <= n; i++)
            if (f [v][i] < c [v][i] && !used [i])
            {
                q.push (i);
                used [i] = 1;
                d [i] = d [v] + 1;

                if (i == n)
                    exists = 1;
            }
    }

    return exists;
}

ll dfs (int v, ll flow)
{
    if (flow == 0)
        return 0;

    if (v == n)
        return flow;

    while (good [v] <= n)
    {
        if (d [good [v]] != d [v] + 1)
        {
            good [v]++;
            continue;
        }

        ll curr = dfs (good [v], min (flow, c [v][good [v]] - f [v][good [v]]));

        if (curr)
        {
            f [v][good [v]] += curr;
            f [good [v]][v] -= curr;
            return curr;
        }

        good [v]++;
    }
    
    return 0ll;
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d %d", &n, &m);
    d.resize (n + 1);
    good.resize (n + 1);
    used.resize (n + 1, 0);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            c [i][j] = 0;
            f [i][j] = 0;
        }

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        scanf ("%d %d %d", &x, &y, &z);
        c [x][y] = z;
    }

    ll ans = 0ll;

    while (bfs ())
    {
        for (int i = 1; i <= n; i++)
            good [i] = 1;

        ll curr = dfs (1, INFLONG);

        while (curr)
        {
            ans += 1ll * curr;
            curr = dfs (1, INFLONG);
        }
    }

    printf (lld"\n", ans);

    return 0;
}
