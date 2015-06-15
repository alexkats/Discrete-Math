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

#define NAME "lcs"
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

int n, m;
int a [2000], b [2000];
int d [2001][2001];

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, n)
		scanf ("%d", &a [i]);

	scanf ("%d", &m);

	rep0(i, m)
		scanf ("%d", &b [i]);

	rep0(i, (n + 1))
	{
		d [i][0] = 0;
		d [0][i] = 0;
	}

	rep(i, 1, (n + 1))
		rep(j, 1, (m + 1))
		{
			if (a [i - 1] == b [j - 1])
				d [i][j] = d [i - 1][j - 1] + 1;
			else
				d [i][j] = max (d [i - 1][j], d [i][j - 1]);
		}

	printf ("%d\n", d [n][m]);

	int curr = d [n][m];
	vector <int> ans;
	int i = n;
	int j = m;

	while (curr != 0)
	{
		if (a [i - 1] == b [j - 1])
		{
			curr--;
			ans.pb (a [i - 1]);
			i--;
			j--;
		}
		else
		{
			if (curr == d [i - 1][j])
				i--;
			else
				j--;
		}
	}

	reverse (ans.begin (), ans.end ());

	rep0(i, d [n][m])
		printf ("%d ", ans [i]);

	printf ("\n");	

	return 0;
}	