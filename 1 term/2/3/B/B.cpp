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

#define NAME "nextperm"
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

int n;
int a [100000];

bool oper (int a, int b)
{
	return a > b;
}	

void solve1 (int a [])
{
	int k = 0;

	rep(i, 1, n)
	{
		if (a [i - 1] > a [i])
			continue;

		k = i;
		break;
	}

	int m = 0;
	int mi = 0;

	rep0(i, k)
		if (a [i] > m && a [i] < a [k])
		{
			m = a [i];
			mi = i;
		}

	swap (a [mi], a [k]);	

	sort (a, a + k);
	reverse (a, a + n);

	rep0(i, n)
		printf ("%d ", a [i] + 1);

	printf ("\n");
}

void solve2 (int ans [])
{
	int k = 0;

	rep(i, 1, n)
	{
		if (ans [i - 1] < ans [i])
			continue;

		k = i;
		break;
	}

	int m = INF;
	int mi = 0;

	rep0(i, k)
		if (ans [i] < m && ans [i] > ans [k])
		{
			m = ans [i];
			mi = i;
		}

	swap (ans [mi], ans [k]);

	sort (ans, ans + k, oper);
	reverse (ans, ans + n);

	rep0(i, n)
		printf ("%d ", ans [i] + 1);

	printf ("\n");
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	int ans [100000];

	rep0(i, n)
	{
		scanf ("%d", &a [i]);	
		a [i]--;
		ans [i] = a [i];
	}

	reverse (a, a + n);
	reverse (ans, ans + n);

	bool z1 = true;
	bool z2 = true;

	rep0(i, n)
		if (a [i] != (n - i - 1))
		{
			z1 = false;
			break;
		}	

	if (z1)
	{
		rep0(i, n)
			printf ("0 ");

		printf ("\n");
	}
	else
		solve1 (a);	

	rep0(i, n)
		if (ans [i] != i)
		{
			z2 = false;
			break;
		}	

	if (z2)
	{
		rep0(i, n)
			printf ("0 ");

		printf ("\n");
	}
	else
		solve2 (ans);

	return 0;
}	