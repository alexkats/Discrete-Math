#define NAME "path"

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

const ll INFLONG = (ll) 5e18 + 7;

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

const int N = 2005;

int n, m, s;
vpil g [N];
ll ans [N];
char used [N];
char bad [N];

void dfs (int v)
{
    used [v] = 1;

    for (int i = 0; i < (int) g [v].size (); i++)
        if (!used [g [v][i].frs])
            dfs (g [v][i].frs);
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    memset (used, 0, sizeof (used));
    memset (bad, 0, sizeof (bad));

    scanf ("%d %d %d", &n, &m, &s);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        ll z;
        scanf ("%d %d "lld, &x, &y, &z);
        g [x].pb (mp (y, z));
    }

    for (int i = 1; i <= n; i++)
        ans [i] = INFLONG;

    ans [s] = 0ll;

    for (int it = 1; it <= 10000; it++)
    {
        char br = 1;

        for (int v = 1; v <= n; v++)
            for (int i = 0; i < (int) g [v].size (); i++)
                if ((ans [v] + g [v][i].snd) < ans [g [v][i].frs] && ans [v] != INFLONG)
                {
                    ans [g [v][i].frs] = max (-INFLONG, ans [v] + g [v][i].snd);
                    br = 0;

                    if (it == 10000)
                        bad [g [v][i].frs] = 1;
                }

        if (br)
            break;
    }

    for (int i = 1; i <= n; i++)
        if (!used [i] && bad [i])
            dfs (i);

    for (int i = 1; i <= n; i++)
        if (used [i])
            puts ("-");
        else if (ans [i] == INFLONG)
            puts ("*");
        else
            printf (lld"\n", ans [i]);

    return 0;
}
