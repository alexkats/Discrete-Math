#define NAME "points"

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

const int N = 20005;

int n, m;
vi g [N];
char used [N];
vi ans;
int res [N];
int t [N];
int cnt;

void dfs (int v, int prev)
{
    used [v] = 1;
    t [v] = ++cnt;
    res [v] = t [v];
    int q = 0;
    char found = 0;

    for (int i = 0; i < (int) g [v].size (); i++)
    {
        if (g [v][i] == prev)
            continue;

        if (used [g [v][i]])
        {
            res [v] = min (res [v], t [g [v][i]]);
            continue;
        }

        dfs (g [v][i], v);
        res [v] = min (res [v], res [g [v][i]]);
        
        if (!found && prev != -1 && t [v] <= res [g [v][i]])
        {
            found = 1;
            ans.pb (v);
            continue;
        }

        if (prev == -1)
            q++;
    }

    if (q > 1)
        ans.pb (v);
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    memset (used, 0, sizeof (used));

    scanf ("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        g [x].pb (y);
        g [y].pb (x);
    }

    cnt = 0;

    for (int i = 1; i <= n; i++)
        if (!used [i])
            dfs (i, -1);

    printf ("%d\n", (int) ans.size ());
    sort (ans.begin (), ans.end ());

    for (int i = 0; i < (int) ans.size (); i++)
        printf ("%d\n", ans [i]);

    return 0;
}
