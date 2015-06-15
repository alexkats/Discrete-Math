#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <ctime>
#include <cctype>
#include <cassert>
#include <memory>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "rsq"
#define INF 1000000000
#define EPS 0.000000001
#define pb push_back
#define mp make_pair
#define frs first
#define snd second
#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd0(i, n) for (int i = (n - 1); i > -1; i--)
#define repd(i, l, r) for (int i = (r - 1); i > (l - 1); i--)
#define N 500000

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

int n;
int t [N * 2];
string s;
int a [N];

void build (int v, int l, int r)
{
	if (l == r)
		t [v] = a [l];
	else
	{
		int m = (l + r) >> 1;
		build (v * 2, l, m);
		build (v * 2 + 1, m + 1, r);
		t [v] = t [v * 2] + t [v * 2 + 1];
	}
}

void update (int v, int l, int r, int key, int val)
{
	if (l == r)
	{
		t [v] = val;
		return;
	}	

	int m = (l + r) >> 1;

	if (key <= m)
		update (v * 2, l, m, key, val);
	else
		update (v * 2 + 1, m + 1, r, key, val);

	t [v] = t [v * 2] + t [v * 2 + 1];
}

int get (int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return 0;

	if (tl == l && r == tr)
		return t [v];

	int tm = (tl + tr) >> 1;
	return (get (v * 2, tl, tm, l, min (tm, r)) + get (v * 2 + 1, tm + 1, tr, max (tm + 1, l), r));
}	

int main ()
{
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, n)
		scanf ("%d", &a [i]);

	build (1, 0, n - 1);

	while (cin >> s)
	{
		if (s == "sum")
		{
			int left, right;
			scanf ("%d %d", &left, &right);
			printf ("%d\n", get (1, 0, n - 1, --left, --right));
		}
		else
		{
			int key, val;
			scanf ("%d %d", &key, &val);
			update (1, 0, n - 1, --key, val);
		}
	}	

	return 0;
}	