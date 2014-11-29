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

#define NAME "cond"
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

const int N = 20005;

int n, m;
int curr;
vector <int> g [N];
vector <int> g2 [N];
stack <int> s;
int ind [N];
char used [N];
int comp [N];

void dfs (int v)
{
    if (used [v])
        return;

    used [v] = 1;

    for (int i = 0; i < (int) g [v].size (); i++)
        if (!used [g [v][i]])
            dfs (g [v][i]);

    s.push (v);
}

void topsort ()
{
    for (int i = 1; i <= n; i++)
        dfs (i);

    for (int i = 1; i <= n; i++)
    {
        ind [i] = s.top ();
        s.pop ();
    }
}

void dfs2 (int v, int x)
{
    if (used [v])
    {
        curr--;
        return;
    }

    used [v] = 1;
    comp [v] = x;

    for (int i = 0; i < (int) g2 [v].size (); i++)
        if (!used [g2 [v][i]])
            dfs2 (g2 [v][i], x);
}

void solve ()
{
    curr = 1;

    for (int i = 1; i <= n; i++)
        dfs2 (ind [i], curr++);

    printf ("%d\n", curr - 1);

    for (int i = 1; i <= n; i++)
        printf ("%d ", comp [i]);

    puts ("");
}

int main ()
{
    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    memset (used, 0, sizeof (used));

    scanf ("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        g [x].pb (y);
        g2 [y].pb (x);
    }

    topsort ();
    memset (used, 0, sizeof (used));
    solve ();

    return 0;
}
