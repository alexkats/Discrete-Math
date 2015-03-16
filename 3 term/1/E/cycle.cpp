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

#define NAME "cycle"
#define INF (int) 1e9 + 7
#define INFLONG (ll) 1e18 + 7
#define EPS 1e-9
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

using namespace std;

const int N = 100005;

int n, m;
vector <int> g [N];
vector <int> ans;
stack <int> s;
int color [N];
char br, ok;
int start;

void dfs (int v)
{
    if (ok)
        return;

    if (color [v] == 2)
        return;

    color [v] = 1;

    for (int i = 0; i < (int) g [v].size (); i++)
    {
        if (br)
            break;

        if (color [g [v][i]] == 1)
        {
            puts ("YES");
            br = 1;
            start = g [v][i];
            break;
        }

        if (color [g [v][i]] == 2)
            continue;

        if (color [g [v][i]] == 0)
            dfs (g [v][i]);
    }

    if (br && !ok)
    {
        ans.pb (v);

        if (v == start)
            ok = 1;
    }

    color [v] = 2;
}

int main ()
{
    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    memset (color, 0, sizeof (color));

    scanf ("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        g [x].pb (y);
    }

    ok = 0;

    for (int i = 1; i <= n; i++)
    {
        br = 0;
        dfs (i);

        if (ok)
            break;
    }

    if (ok)
    {
        reverse (ans.begin (), ans.end ());

        for (int i = 0; i < (int) ans.size (); i++)
            printf ("%d ", ans [i]);

        printf ("\n");
        return 0;
    }

    puts ("NO");

    return 0;
}
