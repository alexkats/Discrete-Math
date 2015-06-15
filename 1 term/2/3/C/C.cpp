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

#define NAME "nextchoose"
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
int a [10000];
bool fl = true;

void solve (int a [])
{
	int r = 0;

	rep0(i, k)
	{
		if (a [i] == n - i)
			continue;

		r = i;
		break;
	}

	a [r]++;

	repd0(i, r)
		a [i] = a [i + 1] + 1;

	reverse (a, a + k);

	rep0(i, k)
		printf ("%d ", a [i]);

	printf ("\n");
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &k);

	rep0(i, k)
		scanf ("%d", &a [i]);

	reverse (a, a + k);

	rep0(i, k)
		if (a [i] != n - i)
		{
			fl = false;
			break;
		}

	if (fl)
	{
		printf ("-1\n");
		return 0;
	}

	solve (a);	

	return 0;
}	