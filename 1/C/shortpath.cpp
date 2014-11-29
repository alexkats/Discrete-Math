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

#define NAME "shortpath"
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

int n, m, st, fin;
vector < pair <int, int> > g [N];
int ans;
stack <int> s;
int ind [N];
char used [N];
int sz;

void dfs (int v)
{
    if (used [v])
        return;

    used [v] = 1;

    for (int i = 0; i < (int) g [v].size (); i++)
        if (!used [g [v][i].frs])
            dfs (g [v][i].frs);

    s.push (v);
}

void topsort ()
{
    dfs (st);

    while (!s.empty ())
    {
        ind [++sz] = s.top ();
        s.pop ();
    }
}

int d [N];
int new_ind [N];

void solve ()
{
    sz = 0;
    d [1] = 0;
    char ok = 0;
    topsort ();

    for (int i = 1; i <= sz; i++)
    {
        new_ind [ind [i]] = i;
        d [i + 1] = INF;

        if (ind [i] == fin)
            ok = 1;
    }

    if (!ok)
    {
        puts ("Unreachable");
        return;
    }

// 1 3 4
    for (int i = 1; i <= sz; i++)
        for (int j = 0; j < (int) g [ind [i]].size (); j++)
            d [new_ind [g [ind [i]][j].frs]] = min (d [new_ind [g [ind [i]][j].frs]], d [i] + g [ind [i]][j].snd);

    if (d [new_ind [fin]] == INF)
        puts ("Unreachable");
    else
        printf ("%d\n", d [new_ind [fin]]);
}


int main ()
{
    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d %d %d %d\n", &n, &m, &st, &fin);

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        scanf ("%d %d %d\n", &x, &y, &z);
        g [x].pb (mp (y, z));
    }

    solve ();

    return 0;
}
