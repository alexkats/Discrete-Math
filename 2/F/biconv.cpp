#define NAME "biconv"

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

const int N = 20005;

int n, m;
vpii g [N];
char used [N];
int ans;
int res [N];
int t [N];
int cnt;
int comp [N * 10];

void dfs (int v, int prev)
{
    used [v] = 1;
    t [v] = ++cnt;
    res [v] = t [v];

    for (int i = 0; i < (int) g [v].size (); i++)
    {
        if (g [v][i].frs == prev)
            continue;

        if (used [g [v][i].frs])
        {
            res [v] = min (res [v], t [g [v][i].frs]);
            continue;
        }
        
        dfs (g [v][i].frs, v);
        res [v] = min (res [v], res [g [v][i].frs]);
    }
}

void dfs2 (int v, int curr, int prev)
{
    used [v] = 1;

    for (int i = 0; i < (int) g [v].size (); i++)
    {
        if (g [v][i].frs == prev)
            continue;

        char ok = 0;

        if ((used [g [v][i].frs] && t [g [v][i].frs] <= t [v]) || (!used [g [v][i].frs] && res [g [v][i].frs] < t [v]))
        {
            comp [g [v][i].snd] = curr;
            ok = 1;
        }

        if (used [g [v][i].frs])
            continue;

        if (!ok)
            comp [g [v][i].snd] = ans;
            
        if (ok)
            dfs2 (g [v][i].frs, curr, v);
        else
            dfs2 (g [v][i].frs, ans++, v);
    }
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    memset (used, 0, sizeof (used));

    scanf ("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        g [x].pb (mp (y, i + 1));
        g [y].pb (mp (x, i + 1));
    }

    cnt = 0;

    for (int i = 1; i <= n; i++)
        if (!used [i])
            dfs (i, -1);

    memset (used, 0, sizeof (used));
    ans = 0;

    for (int i = 1; i <= n; i++)
        if (!used [i])
            dfs2 (i, ++ans, -1);

    ans--;
    printf ("%d\n", ans);

    for (int i = 1; i <= m; i++)
        printf ("%d ", comp [i]);

    puts ("");
    
    return 0;
}
