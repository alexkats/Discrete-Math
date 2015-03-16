#define NAME "pathbgep"

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

const int INF = (int) 1e9 + 7;

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

const int N = 30005;

int n, m;
vpii g [N];
int d [N];
set <pii> s;

void dijkstra (int v)
{
    for (int i = 1; i <= n; i++)
        d [i] = INF;

    d [v] = 0;
    s.insert (mp (d [v], v));

    while (!s.empty ())
    {
        v = s.begin () -> snd;
        s.erase (s.begin ());

        for (int i = 0; i < (int) g [v].size (); i++)
            if ((d [v] + g [v][i].snd) < d [g [v][i].frs])
            {
                s.erase (mp (d [g [v][i].frs], g [v][i].frs));
                d [g [v][i].frs] = d [v] + g [v][i].snd;
                s.insert (mp (d [g [v][i].frs], g [v][i].frs));
            }
    }
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        scanf ("%d %d %d", &x, &y, &z);
        g [x].pb (mp (y, z));
        g [y].pb (mp (x, z));
    }

    bfs (1);

    for (int i = 1; i <= n; i++)
        printf ("%d ", (d [i] < INF) ? d [i] : -1);

    puts ("");

    return 0;
}
