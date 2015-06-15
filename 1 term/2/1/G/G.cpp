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

#define NAME "part2sets"
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

vector <int> a [15];
int n, k;
int q = 0;
vector <int> a [15];

void solve (vector <int> a [], int prev)
{
	if (q > k || (q < k && prev == n))
		return;	

	if (q == k && prev == n)
	{
		rep0(i, q)
		{               
			rep0(j, (int) (a [i].size ()))
				printf ("%d ", a [i][j]);

			printf ("\n");
		}

		printf ("\n");

		return;
	}

	rep0(i, q)
	{
		a [i].pb (prev + 1);
		solve (a, prev + 1);
		a [i].pop_back ();
	}

	q++;
	a [q - 1].pb (prev + 1);
	solve (a, prev + 1);
	a [q - 1].pop_back ();
	q--;
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &k);

	solve (a, 0);

	return 0;
}	