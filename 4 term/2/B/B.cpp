#define NAME "array"

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
char tmp [400005];
string s;
vi ans;

void solve ()
{
    ans.resize (n);
    vi q (max (n, 27), 0);
    vi res (n, 0);
    vi tmp_ans (n, 0);
    vi tmp_res (n, 0);
    
    for (int i = 0; i < n; i++)
        q [(int) (s [i] - 'a') + 1]++;

    for (int i = 1; i < 27; i++)
        q [i] += q [i - 1];

    for (int i = 0; i < n; i++)
    {
        int j = (int) (s [i] - 'a') + 1;
        ans [q [j] - 1] = i;
        q [j]--;
    }

    int curr = 0;

    for (int i = 1; i < n; i++)
    {
        if (s [ans [i]] != s [ans [i - 1]])
            curr++;

        res [ans [i]] = curr;
    }

    for (int k = 1; k < n; k <<= 1)
    {
        fill (q.begin (), q.end (), 0);
        fill (tmp_res.begin (), tmp_res.end (), 0);

        for (int i = 0; i < n; i++)
        {
            tmp_ans [i] = ans [i] - k + n;
            tmp_ans [i] %= n;
            q [res [tmp_ans [i]]]++;
        }

        for (int i = 1; i <= curr; i++)
            q [i] += q [i - 1];

        for (int i = (n - 1); i > -1; i--)
        {
            int j = res [tmp_ans [i]];
            ans [q [j] - 1] = tmp_ans [i];
            q [j]--;
        }

        curr = 0;

        for (int i = 1; i < n; i++)
        {
            int m1 = (ans [i] + k);
            int m2 = (ans [i - 1] + k);
            m1 %= n;
            m2 %= n;

            if (res [ans [i]] != res [ans [i - 1]] || res [m1] != res [m2])
                curr++;

            tmp_res [ans [i]] = curr;
        }

        res = tmp_res;
    }
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%s\n", tmp);
    s = (const char*) tmp;
    s += (char) ('a' - 1);
    n = (int) s.length ();

    solve ();

    for (int i = 1; i < n; i++)
        printf ("%d%c", ans [i] + 1, " \n" [i == n - 1]);

    return 0;
}
