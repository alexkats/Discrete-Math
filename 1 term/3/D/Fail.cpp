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

#define NAME "knapsack"
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

int n, w;
int m [1000];
int c [1000];
int d [10001][1001] = {0};
vector <int> ans;

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &w);

	rep0(i, n)
		scanf ("%d", &m [i]);

	rep0(i, n)
		scanf ("%d", &c [i]);

	d [0][0] = 0;

	rep(i, 1, (w + 1))
	{
		rep(j, 1, (n + 1))
		{
			d [i][j] = max (d [((i - m [j]) >= 0 ? (i - m [j]) : 0)][j - 1] + 1, d [i - 1][j - 1]);

			if (max (d [((i - m [j]) >= 0 ? (i - m [j]) : 0)][j - 1] + 1, d [i - 1][j - 1]) == d [i - 1][j - 1])
				1;
			else
				ans.pb (j);	
					
		}
	}

	printf ("%d\n", d [w][n]);

	rep0(i, d [w][n])
		printf ("%d ", ans [i]);

	printf ("\n");	

	return 0;
}	