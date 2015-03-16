#define NAME "euler"

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

const int N = 1005;

int n, m;
vi g [N];
vi ans;
int used [N][N];
int q [N][N];

void dfs (int v)
{
    for (int i = 0; i < (int) g [v].size (); i++)
    {
        if (used [v][g [v][i]] == q [v][g [v][i]])
            continue;

        used [v][g [v][i]]++;
        used [g [v][i]][v]++;
        dfs (g [v][i]);
    }

    ans.pb (v);
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d", &n);
    int bad = 0;
    int start = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            used [i][j] = q [i][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf ("%d", &x);

        for (int j = 0; j < x; j++)
        {
            int y;
            scanf ("%d", &y);
            g [i].pb (y);
            q [i][y]++;
        }

        if (x % 2 == 1)
        {
            start = i;
            bad++;
        }
    }

    if (bad % 2 == 1)
    {
        puts ("-1");
        return 0;
    }

    dfs (start);
    reverse (ans.begin (), ans.end ());

    printf ("%d\n", (int) ans.size () - 1);

    for (int i = 0; i < (int) ans.size (); i++)
        printf ("%d ", ans [i]);

    puts ("");

    return 0;
}
