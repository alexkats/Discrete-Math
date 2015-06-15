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

#define NAME "lis"
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
int a [5000];
int d [5001];
int it [5001];
int prev [5001];

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, n)
		scanf ("%d", &a [i]);

	d [0] = -INF - 2;

	rep (i, 1, (n + 1))
		d [i] = INF + 2;	

	int curr = -1;
	it [0] = -1;	

	rep0(i, n)
	{
		curr = (upper_bound (d, d + n + 1, a [i]) - d);

		if (d [curr - 1] < a [i] && d [curr] > a [i])
		{
			d [curr] = a [i];
			it [curr] = i;
			prev [i] = it [curr - 1];	
		}
	}

	int ans = -1;

	if (d [n] < INF)
	{
		ans = n;
	}
	else
	{	
	rep0(i, n)
		if (d [i] < INF && d [i + 1] > INF)
		{
			ans = i;
			break;
		}
	}	

	printf ("%d\n", ans);

	vector <int> res;
	curr = it [ans];
	res.pb (a [curr]);

	while (1)
	{
		if (prev [curr] == -1)
			break;

		res.pb (a [prev [curr]]);
		curr = prev [curr];
	}

	reverse (res.begin (), res.end ());

	rep0(i, ans)
		printf ("%d ", res [i]);

	printf ("\n");	

	return 0;
}	