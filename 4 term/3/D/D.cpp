#define NAME "check"

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

int n, m;
vvi g;
set <int> s;

char checking (int pattern, int curr)
{
    int res = pattern ^ curr;
    int ans = curr & res;

    return (ans == 0);
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d %d", &n, &m);
    g.resize (m);
    char good = 0;

    for (int i = 0; i < m; i++)
    {
        int k;
        scanf ("%d", &k);
        int mask = 0;

        for (int j = 0; j < k; j++)
        {
            int x;
            scanf ("%d", &x);
            g [i].pb (x - 1);
            mask |= (1 << (x - 1));
        }

        s.insert (mask);

        if (k == 0)
            good = 1;
    }

    if (!good || m == 0)
    {
        puts ("NO");
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        int mask = 0;

        for (int j = 0; j < (int) g [i].size (); j++)
            mask |= (1 << g [i][j]);

        int r = n;

        for (int curr = 0; curr < (1 << r); curr++)
        {
            if (!checking (mask, curr))
                continue;

            if (s.find (curr) == s.end ())
            {
                puts ("NO");
                return 0;
            }
        }
    }

    for (int i = 0; i < m - 1; i++)
        for (int j = i + 1; j < m; j++)
        {
            int mask1 = 0;
            int mask2 = 0;
            int n1 = (int) g [i].size ();
            int n2 = (int) g [j].size ();

            if (n1 == n2)
                continue;

            for (int ii = 0; ii < n1; ii++)
                mask1 |= (1 << g [i][ii]);

            for (int ii = 0; ii < n2; ii++)
                mask2 |= (1 << g [j][ii]);

            int i1 = i;
            int j1 = j;

            if (n1 < n2)
            {
                swap (n1, n2);
                swap (mask1, mask2);
                swap (i1, j1);
            }

            good = 0;

            for (int ii = 0; ii < n1; ii++)
            {
                int num = g [i1][ii];

                if (mask2 & (1 << num))
                    continue;

                int mask = mask2 | (1 << num);

                if (s.find (mask) != s.end ())
                {
                    good = 1;
                    break;
                }
            }

            if (!good)
            {
                puts ("NO");
                return 0;
            }
        }

    puts ("YES");

    return 0;
}
