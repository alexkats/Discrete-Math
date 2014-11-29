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

#define NAME "topsort"
#define INF (int) (1e9 + 7)
#define INFLONG (ll) (1e18 + 7)
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

using namespace std;

const int N = 100005;

int n, m;
vector <int> g [N];
int ind [N];
stack <int> s;
int color [N];

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

char br;

void dfs(int v)
{
    if (color [v] == 2)
        return;

    color [v] = 1;

    for (int i = 0; i < (int) g [v].size(); i++)
    {
        if (br)
            break;

        if (color [g [v][i]] == 1)
        {
            puts ("-1");
            br = 1;
            break;
        }

        if (color [g [v][i]] == 2)
            continue;

        if (color [g [v][i]] == 0)
            dfs (g [v][i]);
    }

    color [v] = 2;
    s.push (v);
}

void topsort()
{
    for (int i = 1; i <= n; i++)
    {
        br = 0;
        dfs (i);
        
        if (br)
            return;
    }

    for (int i = 1; i <= n; i++)
    {
        ind [i] = s.top ();
        s.pop ();
    }
}

int main ()
{
    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    memset (color, 0, sizeof (color));

    scanf ("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf ("%d %d", &x, &y);
        g [x].pb (y);
    }

    topsort ();

    if (br)
        return 0;

    for (int i = 1; i <= n; i++)
        printf ("%d ", ind [i]);

    printf ("\n");

    return 0;
}
