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

#define NAME "markchain"
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

struct Matrix
{
    int n;
	double el [100][100];

	Matrix () {n = 0, memset (el, 0, sizeof (el));}

	Matrix (int N)
	{
		n = N;
		memset (el, 0, sizeof (el));
	}

	Matrix operator * (const Matrix &A)
	{
		Matrix ans (n);

		rep0(i, n)
			rep0(j, n)
				rep0(k, n)
					ans.el [i][j] += el [i][k] * A.el [k][j];

		return ans;
	}
};

char good (Matrix A, Matrix prev)
{
	if (fabs (A.el [0][0] - prev.el [0][0]) < EPS)
		return 1;

	return 0;
}	

int n;

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	Matrix P (n);
	Matrix A (n);

	rep0(i, n)
		rep0(j, n)
			scanf ("%lf", &P.el [i][j]);

	A = P;	

	while (1)
	{
		if (good (A * P, A))
			break;

		A = A * P;
	}

	A = A * P;

	rep0(i, n)
		printf ("%.9lf\n", A.el [0][i]);	

	return 0;
}	