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

#define NAME "levenshtein"
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

string s, t;
int d [5001][5001];

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> s;
	cin >> t;

	int n = (int) (s.length ());
	int m = (int) (t.length ());

	rep0(i, (n + 1))
		d [i][0] = i;

	rep0(i, (m + 1))
		d [0][i] = i;

	rep(i, 1, (n + 1))
		rep(j, 1, (m + 1))
			if (s [i - 1] == t [j - 1])
				d [i][j] = d [i - 1][j - 1];
			else
				d [i][j] = min (d [i - 1][j], min (d [i][j - 1], d [i - 1][j - 1])) + 1;

	printf ("%d\n", d [n][m]);	

	return 0;
}	