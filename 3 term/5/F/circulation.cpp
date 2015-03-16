#define NAME "circulation"

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

const int INF = (int) 1e9 + 7;

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

const int N = 205;

int n, m;
int c [N][N];
int f [N][N];
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

int dfs (int v, int flow)
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

        int curr = dfs (good [v], min (flow, c [v][good [v]] - f [v][good [v]]));

        if (curr)
        {
            f [v][good [v]] += curr;
            f [good [v]][v] -= curr;
            return curr;
        }

        good [v]++;
    }
    
    return 0;
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d %d", &n, &m);
    d.resize (n + 3);
    good.resize (n + 3);
    used.resize (n + 3, 0);
    vpii g;
    vi l;

    for (int i = 1; i <= n + 2; i++)
        for (int j = 1; j <= n + 2; j++)
        {
            c [i][j] = 0;
            f [i][j] = 0;
        }

    n += 2;

    for (int i = 0; i < m; i++)
    {
        int x, y, a, b;
        scanf ("%d %d %d %d", &x, &y, &a, &b);
        x++;
        y++;
        c [x][y] = b - a;
        c [1][y] += a;
        c [x][n] += a;
        g.pb (mp (x, y));
        l.pb (a);
    }

    int ans = 0;
    
    while (bfs ())
    {
        for (int i = 1; i <= n; i++)
            good [i] = 1;

        int curr = dfs (1, INF);

        while (curr)
        {
            ans += curr;
            curr = dfs (1, INF);
        }
    }

    for (int i = 2; i <= n; i++)
        if (f [1][i] < c [1][i])
        {
            puts ("NO");
            return 0;
        }

    puts ("YES");

    for (int i = 0; i < (int) g.size (); i++)
    {
        int u = g [i].frs;
        int v = g [i].snd;
        int res = f [u][v] + l [i];
        printf ("%d\n", res);
    }

    return 0;
}
