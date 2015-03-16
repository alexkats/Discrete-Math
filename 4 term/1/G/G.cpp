#define NAME "search4"

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

struct node
{
    int edge [26];
    int go [26];
    vi s;
    int suffix_link;
    int up_link;
    int prev;
    char prev_symbol;
    char end;
};

node t [1000005];
vc found; 
char tmp [1000005];
string tt;
int n, m, depth;

void init ()
{
    memset (t [0].edge, -1, sizeof (t [0].edge));
    memset (t [0].go, -1, sizeof (t [0].go));
    t [0].suffix_link = -1;
    t [0].up_link = -1;
    t [0].prev = -1;
    t [0].prev_symbol = '#';
    t [0].end = 0;
    depth = 1;
}

void add_pattern (string p, int k)
{
    n = (int) p.length ();
    int v = 0;

    for (int i = 0; i < n; i++)
    {
        char c = p [i] - 'a';

        if (t [v].edge [(int) c] == -1)
        {
            memset (t [depth].edge, -1, sizeof (t [depth].edge));
            memset (t [depth].go, -1, sizeof (t [depth].go));
            t [depth].suffix_link = -1;
            t [depth].up_link = -1;
            t [depth].prev = v;
            t [depth].prev_symbol = c;
            t [v].edge [(int) c] = depth++;
        }

        v = t [v].edge [(int) c];
    }

    t [v].end = 1;
    t [v].s.pb (k);
}

int get_suffix_link (int v);
int get_go (int v, char c);
int get_up_link (int v);

int get_suffix_link (int v)
{
    if (t [v].suffix_link != -1)
        return t [v].suffix_link;

    if (!v || !t [v].prev)
        t [v].suffix_link = 0;
    else
        t [v].suffix_link = get_go (get_suffix_link (t [v].prev), t [v].prev_symbol);

    return t [v].suffix_link;
}

int get_go (int v, char c)
{
    if (t [v].go [(int) c] != -1)
        return t [v].go [(int) c];

    if (t [v].edge [(int) c] != -1)
        t [v].go [(int) c] = t [v].edge [(int) c];
    else
        t [v].go [(int) c] = v ? get_go (get_suffix_link (v), c) : 0;

    return t [v].go [(int) c];
}

int get_up_link (int v)
{
    if (t [v].up_link != -1)
        return t [v].up_link;

    int link = get_suffix_link (v);

    if (!link)
        t [v].up_link = 0;
    else if ((int) t [link].s.size ())
        t [v].up_link = link;
    else
        t [v].up_link = get_up_link (link);

    return t [v].up_link;
}

void solve (int k, string tt)
{
    m = (int) tt.length ();
    found.resize (k, 0);
    int v = 0;
    char br = 0;

    for (int i = 0; i < m; i++)
    {
        char c = tt [i] - 'a';
        v = get_go (v, c);
        br = 0;

        for (int u = v; u; u = get_up_link (u))
        {
            for (int j = 0; j < (int) t [u].s.size (); j++)
            {
                if (found [t [u].s [j]])
                    br = 1;
                else
                    found [t [u].s [j]] = 1;

                if (br)
                    break;
            }

            if (br)
                break;
        }
    }

    for (int i = 0; i < k; i++)
        puts (found [i] ? "YES" : "NO");
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    int T;
    scanf ("%d\n", &T);
    init ();
    
    for (int i = 0; i < T; i++)
    {
        scanf ("%s\n", tmp);
        string p = (const char*) tmp;
        add_pattern (p, i);
    }

    scanf ("%s\n", tmp);
    tt = (const char*) tmp;
    solve (T, tt);

    return 0;
}
