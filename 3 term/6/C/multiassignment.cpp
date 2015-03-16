#define NAME "multiassignment"

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

struct edge
{
    int to, cap, flow, cost, rev;

    edge () {}

    edge (int _to, int _cap, int _flow, int _cost, int _rev)
    {
        to = _to;
        cap = _cap;
        flow = _flow;
        cost = _cost;
        rev = _rev;
    }
};

typedef vector <edge> ve;
typedef vector <ve> vve;

int n, m, k;
vve g;

vll get_potentials ()
{
    vll d (n + 1, LLONG_MAX);
    d [1] = 0ll;

    while (1)
    {
        char found = 0;

        for (int i = 1; i <= n; i++)
            for (int j = 0; j < (int) g [i].size (); j++)
            {
                if (g [i][j].flow >= g [i][j].cap)
                    continue;

                if (d [i] + g [i][j].cost < d [g [i][j].to])
                {
                    d [g [i][j].to] = d [i] + g [i][j].cost;
                    found = 1;
                }
            }

        if (!found)
            break;
    }

    return d;
}

vi res;
vc used;
vvi gg, bad;

char find_matching (int v)
{
    if (used [v])
        return 0;

    used [v] = 1;

    for (int i = 0; i < (int) gg [v].size (); i++)
    {
        if (bad [v][i])
            continue;

        int to = gg [v][i];

        if (!res [to] || find_matching (res [to]))
        {
            res [to] = v;
            return 1;
        }
    }

    return 0;
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d %d", &n, &k);
    g.resize (n * 2 + 3);

    for (int i = 1; i <= n; i++)
    {
        int num_x = (int) g [i + 1].size ();
        int num_y = (int) g [1].size ();
        g [1].pb (edge (i + 1, k, 0, 0, num_x));
        g [i + 1].pb (edge (1, 0, 0, 0, num_y));
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int x;
            scanf ("%d", &x);
            int num_x = (int) g [j + n + 1].size ();
            int num_y = (int) g [i + 1].size ();
            g [i + 1].pb (edge (j + n + 1, 1, 0, x, num_x));
            g [j + n + 1].pb (edge (i + 1, 0, 0, -x, num_y));
        }

    for (int j = 1; j <= n; j++)
    {
        int num_x = (int) g [n * 2 + 2].size ();
        int num_y = (int) g [j + n + 1].size ();
        g [j + n + 1].pb (edge (n * 2 + 2, k, 0, 0, num_x));
        g [n * 2 + 2].pb (edge (j + n + 1, 0, 0, 0, num_y));
    }

    m = n * 2 + 3;
    n = n * 2 + 2;
    vll d (n + 1, LLONG_MAX);
    vi prev_vertex (n + 1, -1);
    vi prev_edge (m + 1, -1);
    ll cost = 0ll;
    ll flow = 0ll;
    vll potentials = get_potentials ();

    while (1)
    {
        set <pli> s;
        s.insert (mp (0ll, 1));
        d [1] = 0ll;

        for (int i = 2; i <= n; i++)
            d [i] = LLONG_MAX;

        while (!s.empty ())
        {
            int v = s.begin () -> snd;
            s.erase (s.begin ());

            for (int i = 0; i < (int) g [v].size (); i++)
            {
                edge &e = g [v][i];
                int u = e.to;

                if (e.flow >= e.cap)
                    continue;

                if (d [v] + (ll) e.cost + potentials [v] - potentials [u] < d [u])
                {
                    s.erase (mp (d [u], u));
                    d [u] = d [v] + (ll) e.cost + potentials [v] - potentials [u];
                    s.insert (mp (d [u], u));
                    prev_vertex [u] = v;
                    prev_edge [u] = i;
                }
            }
        }

        if (d [n] == LLONG_MAX)
            break;

        ll add = LLONG_MAX;

        for (int i = 1; i <= n; i++)
        {
            if ((ull) potentials [i] + (ull) d [i] > LLONG_MAX)
                potentials [i] = LLONG_MAX;
            else
                potentials [i] += d [i];
        }

        for (int v = n; v != 1; v = prev_vertex [v])
        {
            edge &e = g [prev_vertex [v]][prev_edge [v]];
            add = min (add, (ll) (e.cap - e.flow));
        }

        flow += add;

        for (int v = n; v != 1; v = prev_vertex [v])
        {
            edge &e = g [prev_vertex [v]][prev_edge [v]];
            e.flow += (int) add;
            g [v][e.rev].flow -= (int) add;
            cost += add * 1ll * e.cost;
        }
    }

    printf (lld"\n", cost);
    n -= 2;
    n /= 2;
    vpii ans;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < (int) g [i + 1].size (); j++)
        {
            edge &e = g [i + 1][j];
            
            if (e.to > (n + 1) && e.to < (n * 2 + 2) && e.flow > 0)
                ans.pb (mp (i, e.to - n - 1));
        }

    gg.resize (n + 1);
    bad.resize (n + 1);

    for (int i = 0; i < (int) ans.size (); i++)
    {
        gg [ans [i].frs].pb (ans [i].snd);
        bad [ans [i].frs].pb (0);
    }

    vi final_ans (n + 1);

    while (k --> 0)
    {
        res.assign (n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            used.assign (n + 1, 0);
            find_matching (i);
        }

        for (int i = 1; i <= n; i++)
            final_ans [res [i]] = i;

        for (int i = 1; i <= n; i++)
            for (int j = 0; j < (int) gg [i].size (); j++)
                if (gg [i][j] == final_ans [i])
                    bad [i][j] = 1;

        for (int i = 1; i <= n; i++)
            printf ("%d%c", final_ans [i], " \n" [i == n]);
    }

    return 0;
}
