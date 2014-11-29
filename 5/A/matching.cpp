#define NAME "matching"

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

const int N = 405;

int n, m, k;
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

    scanf ("%d %d %d", &n, &m, &k);
    d.resize (n + m + 3);
    good.resize (n + m + 3);
    used.resize (n + m + 3, 0);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            c [i][j] = 0;
            f [i][j] = 0;
        }

    for (int i = 0; i < k; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        x++;
        y += n + 1;
        c [x][y] = 1;
    }

    for (int i = 2; i <= n + 1; i++)
        c [1][i] = 1;

    for (int i = n + 2; i <= n + m + 1; i++)
        c [i][n + m + 2] = 1;

    n += m + 2;
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

    printf ("%d\n", ans);

    return 0;
}
