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

int n, m, t;
vector <int> g [100000];
vector <int> pr [100000];
int a, b;
char used [100000] = {0};
int sorted [100000];
int d [100000];

void dfs (int v)
{
	used [v] = 1;

	rep0(i, (int) g [v].size ())
		if (!used [g [v][i]])
			dfs (g [v][i]);

	sorted [v] = n - t++ - 1;
}	

void topsort ()
{
	rep0(i, n)
		used [i] = 0;

	t = 0;

	rep0(i, n)
		if (!used [i])
			dfs (i);
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
		pr [b].pb (a);
	}

	topsort ();

	rep0(i, n)
		d [i] = 0;

	int v;	

	rep0(i, n)
		if (sorted [i] == 0)
		{
			v = i;
			break;
		}

	if (v == (n - 1))
	{
		puts ("0");
		return 0;
	}

	d [sorted [v]] = 1;	

	rep(i, v + 1, n)
		rep0(j, (int) pr [sorted [i]].size ())
	{
		d [sorted [i]] += d [pr [sorted [i]][j]];
		d [sorted [i]] %= 1000000007;
	}

	printf ("%d\n", d [n - 1]);	

	return 0;
}	