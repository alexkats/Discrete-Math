#define NAME "pathmgep"

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

const int N = 2005;

int n, s, f;
vpii g [N];
int d [N];
queue <int> q;

void bfs (int v)
{
    for (int i = 1; i <= n; i++)
        d [i] = INF;

    d [v] = 0;
    q.push (v);

    while (!q.empty ())
    {
        v = q.front ();
        q.pop ();

        for (int i = 0; i < (int) g [v].size (); i++)
            if ((d [v] + g [v][i].snd) < d [g [v][i].frs])
            {
                d [g [v][i].frs] = d [v] + g [v][i].snd;
                q.push (g [v][i].frs);
            }
    }
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d %d %d", &n, &s, &f);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int x;
            scanf ("%d", &x);

            if (x != -1 && i != j)
                g [i].pb (mp (j, x));
        }

    bfs (s);
    printf ("%d\n", (d [f] < INF) ? d [f] : -1);

    return 0;
}
