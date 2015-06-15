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

#define NAME "brackets2num2"
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

string s;
ll ans, d [50][50];

void solve (int n, string s)
{
	int q = 0;
	int qr = 0;
	char r [50];

	rep0(i, n)
	{
		if (s [i] == '(')
		{
			r [qr] = '(';
			q++;
			qr++;
			continue;
		}

		ans += d [n - i - 1][q + 1] * (1 << ((n - i - q - 2) / 2));
		
		if (s [i] == ')')
		{
			q--;
			qr--;
			continue;
		}
		
		if (qr > 0 && r [qr - 1] == '(')
			ans += d [n - i - 1][q - 1] * (1 << ((n - i - q) / 2));

		if (s [i] == '[')
		{
			r [qr] = '[';
			q++;
			qr++;
			continue;
		}

		ans += d [n - i - 1][q + 1] * (1 << ((n - i - q - 2) / 2));
		q--;
		qr--;
	}	

	printf ("%I64d\n", ans);
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> s;

	d [0][0] = 1;

	int n = s.length ();

	rep(i, 1, n)
		d [0][i] = 0;

	rep(i, 1, n)
	{
		d [i][0] = d [i - 1][1];

		rep(j, 1, n)
			d [i][j] = d [i - 1][j - 1] + d [i - 1][j + 1];
	}

	ans = 0;

	solve (n, s);

	return 0;
}	