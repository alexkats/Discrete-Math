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

#define NAME "nextmultiperm"
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

void solve (int a [])
{
	int k = 0;

	rep(i, 1, n)
	{
		if (a [i - 1] <= a [i])
			continue;

		k = i;
		break;
	}

	int m = INF;
	int mi = 0;

	rep0(i, k)
		if (a [i] < m && a [i] > a [k])
		{
			m = a [i];
			mi = i;
		}

	swap (a [mi], a [k]);

	sort (a, a + k, oper);
	reverse (a, a + n);

	rep0(i, n)
		printf ("%d ", a [i]);

	printf ("\n");
}

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, n)
		scanf ("%d", &a [i]);

	bool fl = true;	

	rep0(i, (n - 1))
		if (a [i] < a [i + 1])
			fl = false;

	if (fl)
	{
		rep0(i, n)
			printf ("0 ");

		printf ("\n");

		return 0;
	}

	reverse (a, a + n);

	solve (a);	

	return 0;
}	