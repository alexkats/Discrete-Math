#define NAME "minimax"

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

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 7;

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
typedef vector <vpii> vvpii;
typedef vector <pil> vpil;
typedef vector <pli> vpli;
typedef vector <pll> vpll;

template <typename T>
T sqr (T a)
{
    return a * a;
}

int n;
vvpii g;
vi res;
vc used;

char find_matching (int v, int cost)
{
    if (used [v])
        return 0;

    used [v] = 1;

    for (int i = 0; i < (int) g [v].size (); i++)
    {
        int to = g [v][i].frs;
        int curr = g [v][i].snd;

        if (curr < cost)
            continue;

        if (!res [to] || find_matching (res [to], cost))
        {
            res [to] = v;
            return 1;
        }
    }

    return 0;
}

char good (int cost)
{
    int ans = 0;
    res.assign (n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        used.assign (n + 1, 0);
        find_matching (i, cost);
        int curr = 0;

        for (int j = 1; j <= n; j++)
            if (res [j])
                curr++;

        ans = max (ans, curr);
    }

    return (ans == n);
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d", &n);
    g.resize (n + 1);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int x;
            scanf ("%d", &x);
            g [i].pb (mp (j, x));
        }

    int ans = 0;
    int left = 0;
    int right = INF;

    while (right - left > 1)
    {
        int middle = (left + right) >> 1;

        if (good (middle))
            left = middle;
        else
            right = middle;
    }

    if (good (right))
        ans = right;
    else
        ans = left;

    printf ("%d\n", ans);

    return 0;
}
