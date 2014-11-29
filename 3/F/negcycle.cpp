#define NAME "negcycle"

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

const int INF = (int) 1e9;

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

const int N = 255;

int n;
vpii g [N];
int d [N];
int pr [N];
char bad [N];

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    memset (bad, 0, sizeof (bad));
    memset (pr, -1, sizeof (pr));
    memset (d, 0, sizeof (d));

    scanf ("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int x;
            scanf ("%d", &x);

            if (x == INF)
                continue;

            g [i].pb (mp (j, x));
        }

    for (int it = 1; it <= n; it++)
    {
        char br = 1;

        for (int v = 1; v <= n; v++)
            for (int i = 0; i < (int) g [v].size (); i++)
                if ((d [v] + g [v][i].snd) < d [g [v][i].frs] && d [v] != INF)
                {
                    d [g [v][i].frs] = max (-INF, d [v] + g [v][i].snd);
                    pr [g [v][i].frs] = v;
                    br = 0;

                    if (it == n)
                        bad [g [v][i].frs] = 1;
                }

        if (br)
            break;
    }

    int s = 0;

    for (int i = 1; i <= n; i++)
        if (bad [i])
        {
            s = i;
            break;
        }

    if (!s)
    {
        puts ("NO");
        return 0;
    }

    for (int i = 0; i < n; i++)
        s = pr [s];

    vi ans;
    ans.pb (s);
    int v = pr [s];

    while (v != s)
    {
        ans.pb (v);
        v = pr [v];
    }

    ans.pb (v);
    reverse (ans.begin (), ans.end ());

    puts ("YES");
    printf ("%d\n", (int) ans.size ());

    for (int i = 0; i < (int) ans.size (); i++)
        printf ("%d ", ans [i]);

    puts ("");

    return 0;
}
