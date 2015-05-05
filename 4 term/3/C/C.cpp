#define NAME "matching"

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

int n;
vvi g;
vi res;
vc used;

char find_matching (int v)
{
    if (used [v])
        return 0;

    used [v] = 1;

    for (int i = 0; i < (int) g [v].size (); i++)
    {
        int to = g [v][i];

        if (res [to] == -1 || find_matching (res [to]))
        {
            res [to] = v;
            return 1;
        }
    }

    return 0;
}

bool cmp (pii a, pii b)
{
    return a >= b;
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d", &n);
    g.resize (n);
    res.assign (n, -1);
    used.resize (n, 0);
    vpii cost (n);

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf ("%d", &x);
        cost [i] = mp (x, i);
    }

    for (int i = 0; i < n; i++)
    {
        int m;
        scanf ("%d", &m);

        for (int j = 0; j < m; j++)
        {
            int x;
            scanf ("%d", &x);
            g [i].pb (x - 1);
        }
    }

    sort (cost.begin (), cost.end (), cmp);

    for (int i = 0; i < n; i++)
    {
        used.assign (n, 0);
        find_matching (cost [i].snd);
    }

    vi ans (n);

    for (int i = 0; i < n; i++)
        ans [res [i]] = i + 1;

    for (int i = 0; i < n; i++)
        printf ("%d%c", ans [i], " \n" [i == n - 1]);

    return 0;
}
