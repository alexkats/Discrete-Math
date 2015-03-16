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

#define NAME "game"
#define INF (int) 1e9 + 7
#define INFLONG (ll) 1e18 + 7
#define EPS 1e-9
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

const int N = 100005;

int n, m, s;
vector <int> g [N];
char color [N];
int ans;

void dfs (int v, int res)
{
    for (int i = 0; i < (int) g [v].size (); i++)
        dfs (g [v][i], (res + 1) % 2);

    if ((int) g [v].size () == 0)
        ans = min (ans, res);
}

int main ()
{
    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    memset (color, 0, sizeof (color));

    scanf ("%d %d %d", &n, &m, &s);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        g [x].pb (y);
    }

    ans = 1;
    dfs (s, 1);

    if (ans == 0)
        printf ("First ");
    else
        printf ("Second ");

    puts ("player wins");

    printf ("%.3lf\n", (double) clock () / CLOCKS_PER_SEC);
    return 0;
}
