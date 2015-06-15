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

#define NAME "salesman"
#define INF 2000000000
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

char used [18] = {0};
int n, m, a, b, c;
int w [18][18];
char ok = 0;
int d [18][262143];

void dfs (int v)
{
	if (ok)
		return;

	used [v] = 1;

	rep0(i, n)
		if (w [v][i] < INF)
		{
			if (!used [i])
			{
				dfs (i);
			}
			else
			{
				bool fl = 1;
			
				rep0(j, n)
					if (!used [j])
					{
						fl = 0;
						break;
					}
   	
					if (fl)
				{
					ok = 1;
					return;
				}	
			}
		}	

	used [v] = 0;
}

int solve (int curr, int mask)
{
	if (d [curr][mask] < INF)
		return d [curr][mask];

	rep0(i, n)
	{
		if (w [curr][i] < INF && (mask & (1 << i)))
			d [curr][mask] = min (d [curr][mask], solve (i, mask ^ (1 << i)) + w [curr][i]);
	}

	return d [curr][mask];
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &m);

	if (n == 1)
	{
		puts ("0");
		return 0;
	}	

	rep0(i, n)
		rep0(j, n)
			w [i][j] = INF;

	rep0(i, m)
	{
		scanf ("%d%d%d", &a, &b, &c);
		a--;
		b--;
		w [a][b] = c;
		w [b][a] = c;
	}

	dfs (0);

	if (!ok)
	{
		puts ("-1");
		return 0;
	}	

	rep0(i, n)
		rep0(j, (1 << n))
			d [i][j] = INF;

	
	rep0(i, n)
		d [i][0] = 0;

	int ans = solve (0, (1 << n) - 2);

	printf ("%d\n", ans);	

	return 0;
}	