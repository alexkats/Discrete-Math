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
#include <map>
#include <cassert>
#include <ctime>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "optimalcode"
#define INF 1000000000000000000
#define EPS 0.000000001
#define sqr(a) a*a
#define mp make_pair
#define pb push_back
#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd0(i, n) for (int i = (n - 1); i > -1; i--)
#define repd(i, l, r) for (int i = (r - 1); i > (l - 1); i--)	

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

int n;
int f [2001];
int t [2001][2001];
ll d [2001][2001];
int cut [2001][2001];
string p [10000];

void build (int v, int l, int r)
{
	if (l == r)
		p [v] = "";
	else
	{
		int m = (l + r) / 2;
		build (v * 2, l, m);
		build (v * 2 + 1, m + 1, r);
		p [v] = p [v * 2] + p [v * 2 + 1];
	}
}

void update (int v, int l, int r, int upd_l, int upd_r, char val)
{
	if (upd_l > r || upd_r < l)
		return;	

	if (l == upd_l && r == upd_r)
		p [v] += val;
	else
	{
		int m = (l + r) / 2;
		update (v * 2, l, m, upd_l, min (m, upd_r), val);
		update (v * 2 + 1, m + 1, r, max (m + 1, upd_l), upd_r, val);
	}
}

string ans;

string get (int v, int l, int r, int key)
{
	if (l > key || r < key)
		return "";

	if (l == r)
		return p [v];
	else
	{
		int m = (l + r) / 2;

		if (key <= m)
			return p [v] + get (v * 2, l, m, key);
		else
			return p [v] + get (v * 2 + 1, m + 1, r, key);	
	}
}

void solve (int left, int right)
{
	if (left == right)
		return;

	update (1, 1, n, left, cut [left][right], '0');
	update (1, 1, n, cut [left][right] + 1, right, '1');
	solve (left, cut [left][right]);
	solve (cut [left][right] + 1, right);
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep(i, 1, n + 1)
		scanf ("%d", &f [i]);

	if (n == 1)
	{
		puts ("0");
		return 0;
	}	

	rep(i, 1, n + 1)
		rep(j, 1, n + 1)
			if (i > j)
				t [i][j] = 0;
			else
				t [i][j] = t [i][j - 1] + f [j];

	rep(i, 1, n + 1)
		rep(j, 1, n + 1)
			d [i][j] = INF;
	
	rep(i, 1, n + 1)
	{
		cut [i][i] = i;
		d [i][i] = 0;
	}	

	int i = 1;
	int j = 2;
	int prev = 2;

	build (1, 1, n);

	while (1)
	{
		rep(k, cut [i][j - 1], cut [i + 1][j] + 1)
		{
			if (k < j && d [i][j] >= (d [i][k] + d [k + 1][j]))
			{
				d [i][j] = min (d [i][j], d [i][k] + d [k + 1][j]);
				cut [i][j] = k;
			}
		}	

		d [i][j] += t [i][j];

		if (i == 1 && j == n)
			break;

		if (j == n)
		{
			i = 1;
			j = prev + 1;
			prev++;
			continue;
		}

		i++;
		j++;
	}

	printf ("%I64d\n", d [1][n]);

	solve (1, n);	

	rep0(i, n)
	{
		ans = "";
		printf ("%s\n", get (1, 1, n, i + 1).c_str ());
	}	

	return 0;
}	