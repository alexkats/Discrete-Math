#define NAME "destroy"

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
#include <climits>
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

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vi> vvi;
typedef vector <vll> vvll;
typedef vector <char> vc;
typedef vector <string> vs;

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;

typedef vector <pii> vpii;
typedef vector <pil> vpil;
typedef vector <pli> vpli;
typedef vector <pll> vpll;

template <typename T>
T sqr (T a)
{
    return a * a;
}

typedef pair <pii, ll> elem;

int n, m;
ll s;
vector <elem> g;
vpii ind;
vi p;

int find_set (int x)
{
    if (x == p [x])
        return x;

    p [x] = find_set (p [x]);
    return p [x];
}

bool cmp (elem a, elem b)
{
    return a.snd > b.snd;
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d %d " lld, &n, &m, &s);
    set <pli> edges;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        ll z;
        scanf ("%d %d " lld, &x, &y, &z);
        g.pb (mp (mp (x, y), z));
        ind.pb (mp (x, y));
        edges.insert (mp (z, i));
    }

    sort (g.begin (), g.end (), cmp);
    p.resize (n + 1);
    vi rg (n + 1, 1);
    set <pli> res;
    vc bad (m, 0);

    for (int i = 1; i <= n; i++)
        p [i] = i;

    for (int i = 0; i < m; i++)
    {
        int u = g [i].frs.frs;
        int v = g [i].frs.snd;
        u = find_set (u);
        v = find_set (v);

        if (u == v)
            continue;

        if (rg [u] < rg [v])
            swap (u, v);

        if (rg [u] == rg [v])
            rg [u]++;

        p [v] = u;
        res.insert (g [i].frs);
    }

    for (int i = 0; i < m; i++)
    {
        int x = ind [i].frs;
        int y = ind [i].snd;

        if (res.find (ind [i]) != res.end ())
        {
            bad [i] = 1;
            continue;
        }

        if (res.find (mp (y, x)) != res.end ())
        {
            bad [i] = 1;
            continue;
        }
    }

    ll ress = 0ll;
    vi ans;

    for (set <pli> :: iterator it = edges.begin (); it != edges.end (); it++)
    {
        if (bad [(*it).snd])
            continue;

        if (ress + ((*it).frs) > s)
            break;

        ress += ((*it).frs);
        ans.pb ((*it).snd + 1);
    }

    sort (ans.begin (), ans.end ());
    printf ("%d\n", (int) ans.size ());

    for (int i = 0; i < (int) ans.size (); i++)
        printf ("%d%c", ans [i], " \n" [i == (int) ans.size () - 1]);

    return 0;
}
