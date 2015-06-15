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

#define NAME "brackets2num"
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

ll ans = 0;
ll d [50][50];
string s;

void solve (int n, string s)
{
	int q = 0;

	rep0(i, n)
		if (s [i] == '(')
			q++;
		else
		{
			ans += d [n - i - 1][q + 1];
			q--;
		}

	printf ("%I64d\n", ans);
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> s;

	int n = s.length ();

	d [0][0] = 1;

	rep(i, 1, n)
		d [0][i] = 0;

	rep(i, 1, n)
	{
		d [i][0] = d [i - 1][1];

		rep(j, 1, n)
			d [i][j] = d [i - 1][j - 1] + d [i - 1][j + 1];
	}

	solve (n, s);

	return 0;
}	