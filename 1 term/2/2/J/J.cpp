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
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "part2num"
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

int n, q = 0;
string s;
int a [110] = {0};
ll ans [110];
ll d [110][110];
ll res = 0;
int curr = 0;

void solve (int a [], int sum, int prev)
{
	if (sum == 0)
		return;

	if (a [curr] == prev)
	{
		curr++;
		sum -= prev;
		solve (a, sum, prev);
	}
	else
	{
		res += ans [sum - prev] - d [prev - 1][sum - prev];
		solve (a, sum, prev + 1);
	}	
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> s;

	int len = s.length ();

	rep0(i, len)
		if (s [i] == '+')
			q++;
		else
			a [q] = a [q] * 10 + (int) (s [i]) - 48;

	q++;

	rep0(i, q)
		n += a [i];

	rep(i, 1, (n + 1))
		d [0][i] = 0;

	ans [1] = 1;

	rep(i, 1, (n + 1))
		d [i][1] = 1;

	rep(i, 2, (n + 1))
	{
		ans [i] = 0;

		repd(j, (int) (i / 2), i)
			ans [i] += ans [j] - d [i - j - 1][j];

		ans [i]++;	

		rep(j, 1, (int) (i / 2 + 1))
			d [j][i] = d [j - 1][i] + ans [i - j] - d [j - 1][i - j];

		rep(j, (int) (i / 2 + 1), i)
			d [j][i] = d [j - 1][i];

		d [i][i] = d [i - 1][i] + 1;

		rep(j, (i + 1), (n + 1))
			d [j][i] = d [i][i];
	}

/*	if (q == 1)
	{
		printf ("%I64d\n", ans [n] - 1);
		return 0;
	}*/	

	solve (a, n, 1);

	printf ("%I64d\n", res);

	return 0;
}	