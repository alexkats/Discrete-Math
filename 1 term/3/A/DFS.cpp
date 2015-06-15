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

#define NAME "countpaths"
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

vector <int> g [100000];
int ans = 0;
int n, m;
int a, b;

void dfs (int v)
{
	if (v == n - 1)
	{
		ans++;
		ans %= INF + 7;
		return;
	}	

	rep0(i, (int) g [v].size ())
		dfs (g [v][i]);
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &m);

	rep0(i, m)
	{
		scanf ("%d%d", &a, &b);
		a--;
		b--;
		g [a].pb (b);
	}

	dfs (0);

	printf ("%d\n", ans);	

	return 0;
}	