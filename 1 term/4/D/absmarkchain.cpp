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
#include <bitset>
#include <map>
#include <cassert>
#include <ctime>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "absmarkchain"
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

int n, m;
int from [160000], to [160000];
double w [160000];
int pos [400];
char s_abs [400] = {0};
int q_abs = 0;
double R [400][400];
double Q [400][400];
double N [400][400];
double E [400][400];
double G [400][400];

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &m);

	rep0(i, m)
	{
		scanf ("%d%d%lf", &from [i], &to [i], &w [i]);
		from [i]--;
		to [i]--;

		if (from [i] == to [i] && w [i] == 1.0)
		{
			q_abs++;
			s_abs [from [i]] = 1;
		}	
	}

	int none = 0;
	int yeah = 0;

	rep0(i, n)
		s_abs [i] ? pos [i] = none++ : pos [i] = yeah++;

	rep0(i, m)
		s_abs [to [i]] ? (s_abs [from [i]] ? n = n : R [pos [from [i]]][pos [to [i]]] = w [i]) : Q [pos [from [i]]][pos [to [i]]] = w [i];

	rep0(i, n - q_abs)
	{
		N [i][i] = E [i][i] = 1.0;

		rep0(j, n - q_abs)
			E [i][j] -= Q [i][j];
	}

	rep0(i, n - q_abs)
	{
		if (E [i][i] != 1.0)
		{
			double curr = E [i][i];

			rep0(j, n - q_abs)
				E [i][j] /= curr, N [i][j] /= curr;
		}

		rep0(j, n - q_abs)
			if (i != j)
			{
				double curr = E [j][i];

				rep0(k, n - q_abs)
					E [j][k] -= E [i][k] * curr, N [j][k] -= N [i][k] * curr;
			}
	}

	rep0(i, n - q_abs)
		rep0(j, q_abs)
		{
			G [i][j] = 0.0;

			rep0(k, n - q_abs)
				G [i][j] += N [i][k] * R [k][j];
		}

	rep0(i, n)
	{
		double ans = 0.0;	

		if (s_abs [i])
		{	
			rep0(j, n - q_abs)
				ans += G [j][pos [i]];

			ans++;
			ans /= (double) n;
		}

		printf ("%.9lf\n", ans);
	}	

	return 0;
}	