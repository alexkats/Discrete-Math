#define NAME "search3"

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
string s, p, t;

void calc (string s, vi& z)
{
	int n = (int) s.length ();
	z.resize (n, 0);
	int left = 0;
	int right = 0;

	for (int i = 1; i < n; i++)
	{
		if (i <= right)
			z [i] = min (z [i - left], right - i + 1);

		while ((z [i] + i) < n && s [z [i]] == s [z [i] + i])
			z [i]++;

		if ((z [i] + i - 1) > right)
		{
			left = i;
			right = z [i] + i - 1;
		}
	}
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

	scanf ("%s\n", tmp);
	p = (const char*) tmp;
	scanf ("%s\n", tmp);
	t = (const char*) tmp;
	s = p + "#" + t;
	vi ans1;
	calc (s, ans1);
    vi ans2; 
    reverse (p.begin (), p.end ());
    reverse (t.begin (), t.end ());
    s = p + "#" + t;
    calc (s, ans2);
    vi final_ans;

    for (int i = (int) p.length () + 1; i < (int) s.length () - (int) p.length () + 1; i++)
        if (ans1 [i] + ans2 [(int) s.length () - i + 1] + 1 >= (int) p.length ())
            final_ans.pb (i - (int) p.length ());

    printf ("%d\n", (int) final_ans.size ());

    for (int i = 0; i < (int) final_ans.size (); i++)
        printf ("%d%c", final_ans [i], " \n" [i == (int) final_ans.size () - 1]);

    return 0;
}
