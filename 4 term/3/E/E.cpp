#define NAME "cycles"

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

bool cmp (pii a, pii b)
{
    return a > b;
}

int n, m;
vpii cost;
set <int> s;

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d %d", &n, &m);
    cost.resize (n);

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf ("%d", &x);
        cost.pb (mp (x, i));
    }

    sort (cost.begin (), cost.end (), cmp);

    for (int i = 0; i < m; i++)
    {
        int k;
        scanf ("%d", &k);
        int mask = 0;

        for (int j = 0; j < k; j++)
        {
            int x;
            scanf ("%d", &x);
            mask |= (1 << (x - 1));
        }

        s.insert (mask);
    }

    int curr = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int mask = curr | (1 << cost [i].snd);
        char good = 0;

        for (set <int> :: iterator it = s.begin (); it != s.end (); it++)
        {
            int mask2 = *it;

            if ((mask & mask2) != mask2)
                continue;

            good = 1;
            break;
        }

        if (good)
            continue;

        curr = mask;
        ans += cost [i].frs;
    }

    printf ("%d\n", ans);

    return 0;
}
