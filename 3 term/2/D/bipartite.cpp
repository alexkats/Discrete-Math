#define NAME "bipartite"

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

const int N = 100005;

int n, m;
vi g [N];
char used [N];
char br;
int res [N];

void dfs (int v, int curr = 0)
{
    used [v] = 1;
    res [v] = curr;

    for (int i = 0; i < (int) g [v].size (); i++)
    {
        if (br)
            break;

        if (used [g [v][i]])
        {
            if (res [g [v][i]] == curr)
            {
                br = 1;
                break;
            }

            continue;
        }

        if (!used [g [v][i]])
            dfs (g [v][i], (curr + 1) % 2);
    }
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    memset (used, 0, sizeof (used));

    scanf ("%d %d", &n, &m);
    br = 0;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        g [x].pb (y);
        g [y].pb (x);

        if (x == y)
            br = 1;
    }

    if (br)
    {
        puts ("NO");
        return 0;
    }

    for (int i = 1; i <= n; i++)
        if (!used [i])
            dfs (i);

    puts (!br ? "YES" : "NO");

    return 0;
}
