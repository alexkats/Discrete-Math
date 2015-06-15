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

#define NAME "matrix"
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
int a [400], b [400];
int d [401][401];
int pos [401][401];
string ans [401][401];
int cur = -1;

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, n)
		scanf ("%d%d", &a [i], &b [i]);

	rep(i, 1, (n + 1))
	{
		ans [i][i] = 'A';
		d [i][i] = 0;
	}	

	rep(l, 2, (n + 1))
		rep(i, 1, (n - l + 2))
		{
			int j = i + l - 1;
			d [i][j] = INF;

			rep(k, i, j)
			{
				int curr = d [i][j];
				d [i][j] = min (d [i][j], d [i][k] + d [k + 1][j] + a [i - 1] * b [k - 1] * b [j - 1]);
				
				if (curr != d [i][j])
					cur = k;
			}

			ans [i][j] = '(' + ans [i][cur] + ans [cur + 1][j] + ')';	
		}

	cout << ans [1][n] << endl;	

	return 0;
}	