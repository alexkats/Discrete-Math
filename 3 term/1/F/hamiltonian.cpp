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

#define NAME "hamiltonian"
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
char br;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

void dfs (int v)
{
    if (color [v] == 1)
        return;

    color [v] = 1;

    for (int i = 0; i < (int) g [v].size (); i++)
    {
        if (color [g [v][i]] >= 1)
            continue;

        if (color [g [v][i]] == 0)
            dfs (g [v][i]);
    }

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

int main ()
{
    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    memset (color, 0, sizeof (color));
    memset (ind, -1, sizeof (ind));

    scanf ("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf ("%d %d", &x, &y);
        g [x].pb (y);
    }

    topsort ();

    if (ind [n] == -1)
    {
        puts ("NO");
        return 0;
    }

    for (int i = 1; i < n; i++)
    {
        char found = 0;

        for (int j = 0; j < (int) g [ind [i]].size (); j++)
            if (g [ind [i]][j] == ind [i + 1])
            {
                found = 1;
                break;
            }

        if (!found)
        {
            puts ("NO");
            return 0;
        }
    }

    puts ("YES");

    return 0;
}
