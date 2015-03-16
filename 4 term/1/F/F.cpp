#define NAME "period"

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

char tmp [1000005];
string s;
int n;

vi calc ()
{
    vi p (n);
    p [0] = 0;

    for (int i = 1; i < n; i++)
    {
        int k = p [i - 1];

        while (k > 0 && s [i] != s [k])
            k = p [k - 1];

        if (s [i] == s [k])
            k++;

        p [i] = k;
    }

    return p;
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%s\n", tmp);
    s = (const char*) tmp;
    n = (int) s.length ();
    vi ans = calc ();
    int m = 0;

    for (int i = 0; i < n; i++)
        m = max (m, ans [i]);

    if (n % (n - m) == 0)
        printf ("%d\n", n - m);
    else
        printf ("%d\n", n);

    return 0;
}
