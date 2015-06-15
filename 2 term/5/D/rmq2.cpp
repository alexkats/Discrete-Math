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

#define NAME "rmq2"
#define INF (ll) 1e18
#define EPS 0.000000001
#define pb push_back
#define mp make_pair
#define frs first
#define snd second
#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd0(i, n) for (int i = (n - 1); i > -1; i--)
#define repd(i, l, r) for (int i = (r - 1); i > (l - 1); i--)
#define N 100000

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
ll a [N];
pair <ll, ll> t [N * 2];
string s;

void build (int v, int l, int r)
{
	if (l == r)
		t [v] = mp (a [l], 0ll);
	else
	{
		int m = (l + r) >> 1;
		build (v * 2, l, m);
		build (v * 2 + 1, m + 1, r);
		t [v].frs = min (t [v * 2].frs, t [v * 2 + 1].frs);
	}
}

void update_add (int v, int tl, int tr, int l, int r, ll add)
{
	if (l > r)
		return;

	if (tl == l && r == tr)
		t [v].snd += add;
	else
	{
		int tm = (tl + tr) >> 1;
		update_add (v * 2, tl, tm, l, min (tm, r), add);
		update_add (v * 2 + 1, tm + 1, tr, max (tm + 1, l), r, add);
		t [v].frs = min (t [v * 2].frs, t [v * 2 + 1].frs);
	}
}

void update_set (int v, int tl, int tr, int l, int r, ll val)
{
	if (l > r)
		return;

	if (tl == l && r == tr)
		t [v] = val;
	else
	{
		int tm = (tl + tr) >> 1;
		update_set (v * 2, tl, tm, l, min (tm, r), val);
		update_set (v * 2 + 1, tm + 1, tr, max (tm + 1, l), r, val);
		t [v] = min (t [v * 2], t [v * 2 + 1]);
	}
}

ll get (int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return INF + 7;

	if (tl == l && l == tr)
		return t [v];

	int tm = (tl + tr) >> 1;
	return min (get (v * 2, tl, tm, l, min (tm, r)), get (v * 2 + 1, tm + 1, tr, max (tm + 1, l), r));
}	

int main ()
{
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, n)
		scanf (lld, &a [i]);

	build (1, 0, n - 1);

	while (cin >> s)
	{
		if (s == "add")
		{
			int left, right;
			ll val;
			scanf ("%d %d "lld, &left, &right, &val);
			update_add (1, 0, n - 1, --left, --right, val);
			continue;
		}

		if (s == "set")
		{
			int left, right;
			ll val;
			scanf ("%d %d "lld, &left, &right, &val);
			update_set (1, 0, n - 1, --left, --right, val);
			continue;
		}

		if (s == "min")
		{
			int left, right;
			scanf ("%d %d", &left, &right);
			printf (lld"\n", get (1, 0, n - 1, --left, --right));
			continue;
		}
	}	

	return 0;
}	