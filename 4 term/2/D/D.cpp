#define NAME "automaton"

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

struct state
{
    int length;
    int suffix_link;
    map <char, int> edge;
};

int n;
char tmp [100005];
string s;
state st [200005];
int depth, curr;
pii ans;
vi res;

void build (char c)
{
    int now = depth++;
    st [now].length = st [curr].length + 1;
    int v;

    for (v = curr; v != -1 && st [v].edge.count (c) == 0; v = st [v].suffix_link)
    {
        st [v].edge [c] = now;
        ans.snd++;
    }

    if (v == -1)
        st [now].suffix_link = 0;
    else
    {
        int r = st [v].edge [(int) c];

        if (st [v].length + 1 == st [r].length)
            st [now].suffix_link = r;
        else
        {
            int new_node = depth++;
            st [new_node].length = st [v].length + 1;
            st [new_node].suffix_link = st [r].suffix_link;
            st [new_node].edge = st [r].edge;
            ans.snd += st [r].edge.size ();
            
            while (v != -1 && st [v].edge [(int) c] == r)
            {
                st [v].edge [(int) c] = new_node;
                v = st [v].suffix_link;
            }

            st [r].suffix_link = new_node;
            st [now].suffix_link = new_node;
        }
    }

    curr = now;
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%s\n", tmp);
    s = (const char*) tmp;
    n = (int) s.length ();

    depth = 1;
    curr = 0;
    st [0].length = 0;
    st [0].suffix_link = -1;

    ans = mp (0, 0);

    for (int i = 0; i < n; i++)
        build (s [i]);

    ans.frs = depth;
    printf ("%d %d\n", ans.frs, ans.snd);

    for (int i = 0; i < ans.frs; i++)
        for (map <char, int> :: iterator j = st [i].edge.begin (); j != st [i].edge.end (); j++)
                printf ("%d %d %c\n", i + 1, j -> second + 1, j -> first);

    for (int i = curr; i != -1; i = st [i].suffix_link)
        res.pb (i);

    printf ("%d\n", (int) res.size ());

    for (int i = 0; i < (int) res.size (); i++)
        printf ("%d%c", res [i] + 1, " \n" [i == (int) res.size ()]);

    return 0;
}
