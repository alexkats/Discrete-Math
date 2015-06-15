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

#define NAME "num2choose"
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

int n, k;
ll m, curr;
int q = 0;
int a [40];

ll choose (ll a, ll b, ll c)
{
	ld ans = 1;

	for (int i = max (b, c) + 1; i <= a; i++)
		ans = ans * i;

	if (max (b, c) == b)
		for (int i = 1; i <= c; i++)
			ans = double (double (ans) / double (i));
	else
		for (int i = 1; i <= b; i++)
			ans = double (double (ans) / double (i));

	return (ll) ans;	
}

void solve (int a [], int prev)
{
	if (q == k)
	{
		rep0(i, q)
			printf ("%d ", a [i] + 1);

		printf ("\n");

		exit (0);
	}

	if (curr == 0)
	{
	    q++;
	    a [q - 1] = prev + 1;
	    solve (a, prev + 1);
	}

	rep(i, (prev + 1), n)
	{
		if (curr - choose (n - i - 1, k - q - 1, n - k - i + q) >= 0)
		{
			curr -= choose (n - i - 1, k - q - 1, n - k - i + q);
			continue;
		}
		else
		{
			q++;
			a [q - 1] = i;
			solve (a, i);
		}
	}
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%d%I64d", &n, &k, &m);

	curr = m;

	solve (a, -1);

	return 0;
}	