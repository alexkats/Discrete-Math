#define NAME "chinese"

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

typedef pair <pii, int> elem;
const int N = 1005;

int n, m;
vector <elem> g;
char used [N];
int comp [N];
int min_weight [N];
stack <int> s;
int ind [N];
int cnt;

void dfs (int v, vvi gr)
{
    used [v] = 1;

    for (int i = 0; i < (int) gr [v].size (); i++)
        if (!used [gr [v][i]])
            dfs (gr [v][i], gr);
}

char exists (int v, int n, vector <elem> g)
{
    vvi gr (n + 1);

    for (int i = 0; i < (int) g.size (); i++)
    {
        int x = g [i].frs.frs;
        int y = g [i].frs.snd;
        gr [x].pb (y);
    }

    memset (used, 0, sizeof (used));
    dfs (v, gr);

    for (int i = 1; i <= n; i++)
        if (!used [i])
            return 0;

    return 1;
}

void cond_dfs (vvi &gr, int v)
{
    if (used [v])
        return;

    used [v] = 1;

    for (int i = 0; i < (int) gr [v].size (); i++)
        if (!used [gr [v][i]])
            cond_dfs (gr, gr [v][i]);

    s.push (v);
}

void cond_topsort (int n, vvi &gr)
{
    for (int i = 1; i <= n; i++)
        cond_dfs (gr, i);

    for (int i = 1; i <= n; i++)
    {
        ind [i] = s.top ();
        s.pop ();
    }
}

void cond_dfs2 (vvi &gr, int v, int x) 
{
    if (used [v])
    {
        cnt--;
        return;
    }

    used [v] = 1;
    comp [v] = x;

    for (int i = 0; i < (int) gr [v].size (); i++)
        if (!used [gr [v][i]])
            cond_dfs2 (gr, gr [v][i], x);
}

int condensation (int n, vector <elem> zero_weight)
{
    vvi gr (n + 1);
    vvi gr2 (n + 1);

    for (int i = 0; i < (int) zero_weight.size (); i++)
    {
        int x = zero_weight [i].frs.frs;
        int y = zero_weight [i].frs.snd;
        gr [x].pb (y);
        gr2 [y].pb (x);
    }

    memset (used, 0, sizeof (used));
    cond_topsort (n, gr);
    memset (used, 0, sizeof (used));
    cnt = 1;
    
    for (int i = 1; i <= n; i++)
        cond_dfs2 (gr2, ind [i], cnt++);

    return cnt - 1;
}

ll solve (int v, int n, vector <elem> &g)
{
    ll ans = 0ll;

    for (int i = 1; i <= n; i++)
        min_weight [i] = INF;

    for (int i = 0; i < (int) g.size (); i++)
        min_weight [g [i].frs.snd] = min (min_weight [g [i].frs.snd], g [i].snd);

    for (int i = 1; i <= n; i++)
        ans += (i == v) ? 0ll : (ll) min_weight [i];

    vector <elem> zero_weight;

    for (int i = 0; i < (int) g.size (); i++)
        if (g [i].snd == min_weight [g [i].frs.snd])
            zero_weight.pb (mp (g [i].frs, 0));

    if (exists (v, n, zero_weight))
        return ans;

    int components = condensation (n, zero_weight);
    vector <elem> new_g;

    for (int i = 0; i < (int) g.size (); i++)
        if (comp [g [i].frs.frs] != comp [g [i].frs.snd])
            new_g.pb (mp (mp (comp [g [i].frs.frs], comp [g [i].frs.snd]), g [i].snd - min_weight [g [i].frs.snd]));

    ans += solve (comp [v], components, new_g);
    return ans;
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
        g.pb (mp (mp (x, y), z));
    }

    if (!exists (1, n, g))
    {
        puts ("NO");
        return 0;
    }

    puts ("YES");
    printf (lld"\n", solve (1, n, g));

    return 0;
}
