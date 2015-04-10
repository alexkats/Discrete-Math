#define NAME "refrain"

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
    int left;
    int right;
    int prev;
    int suffix_link;
    int q;
    int edge [27];

    node ()
    {
        left = -1;
        right = -1;
        prev = -1;
        suffix_link = -1;
        q = -1;
        memset (edge, -1, sizeof (edge));
    }

    node (int _left, int _right, int _prev)
    {
        left = _left;
        right = _right;
        prev = _prev;
        suffix_link = -1;
        q = -1;
        memset (edge, -1, sizeof (edge));
    }

    int len ()
    {
        return right - left;
    }
};

struct state
{
    int v;
    int curr;

    state () {}
    
    state (int _v, int _curr)
    {
        v = _v;
        curr = _curr;
    }
};

int n, m;
int depth;
string s;
node t [400005];
state st0 (0, 0);

int find_q (int v)
{
    if (v == -1)
        return 0;

    if (t [v].q != -1)
        return t [v].q;

    t [v].q = t [v].len () + find_q (t [v].prev);
    return t [v].q;
}

state down (state st, int left, int right)
{
    while (left < right)
        if (st.curr == t [st.v].len ())
        {
            st = state (t [st.v].edge [int (s [left] - 'a') + 1], 0);

            if (st.v == -1)
                return st;
        }
        else
        {
            if (s [t [st.v].left + st.curr] != s [left])
                return state (-1, -1);

            if ((right - left) < t [st.v].len () - st.curr)
                return state (st.v, st.curr + right - left);

            left += t [st.v].len () - st.curr;
            st.curr = t [st.v].len ();
        }

    return st;
}

int split (state st)
{
    if (st.curr == t [st.v].len ())
        return st.v;

    if (st.curr == 0)
        return t [st.v].prev;

    int new_index = depth++;
    t [new_index] = node (t [st.v].left, t [st.v].left + st.curr, t [st.v].prev);
    t [t [st.v].prev].edge [(int) (s [t [st.v].left] - 'a') + 1] = new_index;
    t [new_index].edge [(int) (s [t [st.v].left + st.curr] - 'a') + 1] = st.v;
    t [st.v].prev = new_index;
    t [st.v].left += st.curr;
    find_q (new_index);

    return new_index;
}

int get_suffix_link (int v)
{
    if (t [v].suffix_link == -1)
    {
        if (t [v].prev == -1)
            return 0;

        int go = get_suffix_link (t [v].prev);
        t [v].suffix_link = split (down (state (go, t [go].len ()), t [v].left + (t [v].prev == 0), t [v].right));
    }

    return t [v].suffix_link;
}

void add_suffix (int curr)
{
    while (1)
    {
        state st = down (st0, curr, curr + 1);

        if (st.v != -1)
        {
            st0 = st;
            return;
        }

        int m = split (st0);
        int terminate = depth++;
        t [terminate] = node (curr, n, m);
        t [m].edge [(int) (s [curr] - 'a') + 1] = terminate;
        st0.v = get_suffix_link (m);
        st0.curr = t [st0.v].len ();
        find_q (terminate);

        if (m == 0)
            return;
    }
}

int leaves [400005];
ll ans;
vvi g;
int best_depth;
int pos;
vc used;

void dfs (int v, int depth = 0)
{
    used [v] = 1;

    for (int i = 0; i < (int) g [v].size (); i++)
        if (used [g [v][i]])
            leaves [v] += leaves [g [v][i]];
        else
        {
            dfs (g [v][i], depth + t [g [v][i]].right - t [g [v][i]].left);
            leaves [v] += leaves [g [v][i]];
        }

    if (leaves [v] == 0)
    {
        leaves [v] = 1;

        if (ans < leaves [v] * 1ll * (depth - 1))
        {
            ans = leaves [v] * 1ll * (depth - 1);
            best_depth = depth - 1;
            pos = t [v].right;
        }

        return;
    }

    if (ans < leaves [v] * 1ll * depth)
    {
        ans = leaves [v] * 1ll * depth;
        best_depth = depth;
        pos = t [v].right + 1;
    }
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf ("%d", &x);
        s += (char) (x - 1) + 'a';
    }

    s += (char) ('a' - 1);
    n++;
    depth = 1;
    ans = 0ll;

    for (int i = 0; i < n; i++)
        add_suffix (i);

    used.resize (depth + 1, 0);
    g.resize (depth + 1);

    for (int i = 1; i < depth; i++)
        g [t [i].prev].pb (i);

    dfs (0);
    printf (lld"\n%d\n", ans, best_depth);
    pos -= best_depth;

    for (int i = pos; i < pos + best_depth; i++)
        printf ("%d ", (int) (s [i - 1] - 'a' + 1));

    puts ("");

    return 0;
}
