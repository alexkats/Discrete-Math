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

#define NAME "matching"
#define INF 1000000000
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

int n, x, y, W;
ll a [100001] = {0}, b [100001] = {0}, c [100001] = {0};
vector <pair <int, int> > w [100001];
bool used [100001] = {false};

void dfs (int v)
{
	used [v] = true;

	rep0(i, int (w [v].size ()))
	{
		if (!used [w [v][i].first])
		{
			dfs (w [v][i].first);
			b [v] += max (a [w [v][i].first], b [w [v][i].first]);
		}
	}

	rep0(i, int (w [v].size ()))
	{
		if (!used [w [v][i].first])
			a [v] = max (a [v], (w [v][i].second + b [v] + b [w [v][i].first] - max (a [w [v][i].first], b [w [v][i].first])));
	}

	c [v] = max (a [v], b [v]);
	used [v] = false;
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, n - 1)
	{
		scanf ("%d%d%d", &x, &y, &W);
		w [x].pb (mp (y, W));
		w [y].pb (mp (x, W));
	}

	dfs (1);

	printf ("%I64d\n", c [1]);	

	return 0;
}	