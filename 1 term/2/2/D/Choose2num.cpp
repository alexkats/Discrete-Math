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

#define NAME "choose2num"
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

int n, k, a [40];
int curr = 0;
ll m = 0;

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
	rep(i, (prev + 1), a [curr])
		m = m + choose (n - i - 1, k - curr - 1, n - k - i + curr);

	if (curr == (k - 1))
		return;

	curr++;
	solve (a, a [curr - 1]);
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &k);

	rep0(i, k)
	{
		scanf ("%d", &a [i]);
		a [i]--;
	}	

	solve (a, -1);

	printf ("%I64d\n", m);	

	return 0;
}	