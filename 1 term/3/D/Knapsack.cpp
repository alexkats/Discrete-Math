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
int d [1001][10001] = {0};
int m [1000], c [1000];

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &w);

	rep0(i, n)
		scanf ("%d", &m [i]);

	rep0(i, n)
		scanf ("%d", &c [i]);

	rep0(i, (n + 1))
		d [i][0] = 0;

	rep0(i, (w + 1))
		d [0][i] = 0;

	rep(i, 1, (n + 1))
		rep(j, 1, (w + 1))
			d [i][j] = max (d [i - 1][j], ((j >= m [i - 1]) ? d [i - 1][j - m [i - 1]] : -INF) + c [i - 1]);

	int i = n;
	int j = w;
	vector <int> ans;

	while (d [i][j] != 0)
	{
		if (d [i][j] == d [i - 1][j])
		{
			i--;	
			continue;
		}

		ans.pb (i);
		i--;
		j -= m [i];
	}

	reverse (ans.begin (), ans.end ());	

	printf ("%d\n", (int) (ans.size ()));

	rep0(i, (int) (ans.size ()))
		printf ("%d ", ans [i]);

	printf ("\n");	

	return 0;
}	