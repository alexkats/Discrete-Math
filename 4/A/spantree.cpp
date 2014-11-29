#define NAME "spantree"

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

const int INF = 1e9;

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

struct point
{
    double x, y;

    point () {}

    point (double _x, double _y)
    {
        x = _x;
        y = _y;
    }
};

double dist (point a, point b)
{
    return sqrt (sqr (b.x - a.x) + sqr (b.y - a.y));
}

const int N = 5005;

int n;
point points [N];
char used [N];
double d [N];

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    memset (used, 0, sizeof (used));

    scanf ("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        points [i + 1] = point (x, y);
    }

    for (int i = 1; i <= n; i++)
        d [i] = INF;

    d [1] = 0.0;

    for (int it = 0; it < n; it++)
    {
        int v = -1;

        for (int i = 1; i <= n; i++)
            if (!used [i] && (v == -1 || d [i] < d [v]))
                v = i;

        used [v] = 1;

        for (int i = 1; i <= n; i++)
        {
            double res = dist (points [i], points [v]);

            if (!used [i] && res < d [i])
                d [i] = res;
        }
    }

    double ans = 0.0;

    for (int i = 1; i <= n; i++)
        ans += d [i];

    printf ("%.9lf\n", ans);

    return 0;
}
