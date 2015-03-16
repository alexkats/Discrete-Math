#define NAME "z"

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

char s [1000005];
vi ans;
int n;

vi calc (char* s)
{
	int left = 0;
	int right = 0;
	vi z (n);

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
	
	return z;
}

int main ()
{
    srand (time (0));

    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

	scanf ("%s\n", s);
	n = strlen (s);
	ans = calc (s);

	for (int i = 1; i < n; i++)
		printf ("%d%c", ans [i], " \n" [i == n - 1]);

    return 0;
}
