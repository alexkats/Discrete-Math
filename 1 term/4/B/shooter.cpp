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

#define NAME "shooter"
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

int n, m, k;
double p [10000];
double curr;
double ans;
double s = 0.0;

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%d%d", &n, &m, &k);

	rep0(i, n)
	{
		scanf ("%lf", &p [i]);
		curr = 1.0;
		
		rep0(j, m)
			curr *= (1.0 - p [i]);

		s += curr;	
	}

	ans = 0.0;

	if (s == 0.0)
	{
		printf ("%.15lf\n", ans);
		return 0;
	}	

	curr = 1.0;

	rep0(i, m)
		curr *= (1.0 - p [k - 1]);

	ans = curr / s;

	printf ("%.15lf\n", ans);	

	return 0;
}	