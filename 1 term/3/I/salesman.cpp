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

int n, m, a, b, c;
int w [18][18];
int d [262143][18];

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &m);

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

	rep0(mask, (1 << n))
		rep0(i, n)
		{
			d [mask][i] = INF;

			if (((1 << i) | mask) == (1 << i) && ((1 << i) & mask))
			{
				d [mask][i] = 0;
				continue;
			}

			if ((1 << i) & mask)
			{
				rep0(j, n)
					if (w [i][j] < INF)
						d [mask][i] = min (d [mask][i], d [mask ^ (1 << i)][j] + w [i][j]);

				continue;
			}	
		}

	int ans = INF;

	rep0(i, n)
		ans = min (ans, d [(1 << n) - 1][i]);

	if (ans < INF)
		printf ("%d\n", ans);
	else
		puts ("-1");	

	return 0;
}	