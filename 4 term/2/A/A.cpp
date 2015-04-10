#define NAME "trie"

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

int n, ans = 1;
char tmp [105];
string s;
int t [20005][26];

void add_suffix (int left)
{
    int curr = 0;

    for (int i = left; i < n; i++)
    {
        int c = (int) (s [i] - 'a');

        if (t [curr][c] == -1)
            t [curr][c] = ans++;

        curr = t [curr][c];
    }
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%s\n", tmp);
    s = (const char*) tmp;
    n = (int) s.length ();

    for (int i = 0; i < 20005; i++)
        memset (t [i], -1, sizeof (t [i]));

    for (int i = 0; i < n; i++)
        add_suffix (i);

    printf ("%d %d\n", ans, ans - 1);
    queue <int> q;
    q.push (0);

    while (!q.empty ())
    {
        int curr = q.front ();
        q.pop ();

        for (int i = 0; i < 26; i++)
            if (t [curr][i] != -1)
            {
                printf ("%d %d %c\n", curr + 1, t [curr][i] + 1, (char) (i) + 'a');
                q.push (t [curr][i]);
            }
    }

    return 0;
}
