#define NAME "schedule"

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

bool comp (pii a, pii b)
{
    return a.snd > b.snd;
}

struct cmp
{
    bool operator () (int a, int b)
    {
        return a > b;
    }
};

int n;
vpii v;
set <int, cmp> s;

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d", &n);
    ll ans = 0ll;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf ("%d %d", &a, &b);
        ans += (ll) b;
        v.pb (mp (a, b));
        s.insert (i + 1);
    }

    sort (v.begin (), v.end (), comp);

    for (int i = 0; i < n; i++)
    {
        set <int, cmp> :: iterator it = s.lower_bound (v [i].frs);

        if (it != s.end ())
        {
            s.erase (it);
            ans -= v [i].snd;
        }
        else
            s.erase (s.begin ());
    }

    printf (lld"\n", ans);

    return 0;
}
