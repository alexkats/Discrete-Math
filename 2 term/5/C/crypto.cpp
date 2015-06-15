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
#include <ctime>
#include <cctype>
#include <cassert>
#include <memory>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "crypto"
#define INF 1000000000
#define EPS 0.000000001
#define pb push_back
#define mp make_pair
#define frs first
#define snd second
#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd0(i, n) for (int i = (n - 1); i > -1; i--)
#define repd(i, l, r) for (int i = (r - 1); i > (l - 1); i--)
#define N 200000

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

int r;

struct Matrix
{
	int n;
	int element [2][2];

	Matrix ()
	{
		n = 2;
		memset (element, 0, sizeof (element));
	}

	Matrix (int val)
	{
		n = 2;
		memset (element, val, sizeof (element));
	}	

	Matrix operator * (const Matrix &A)
	{
		Matrix ans = Matrix ();

		rep0(i, n)
			rep0(j, n)
				rep0(k, n)
					ans.element [i][j] += (1ll * element [i][k] * A.element [k][j]) % r;

		return ans;	
	}
};

Matrix t [N * 2] = {Matrix ()};
Matrix A [N] = {Matrix ()};
int n, m;

void build (int v, int l, int r)
{
	if (l == r)
		t [v] = A [l];
	else
	{
		int m = (l + r) >> 1;
		build (v * 2, l, m);
		build (v * 2 + 1, m + 1, r);
		t [v] = t [v * 2] * t [v * 2 + 1];
	}
}

Matrix get (int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return Matrix (0);

	if (tl == l && r == tr)
		return t [v];	

	int tm = (tl + tr) >> 1;

	if (r <= tm)
		return get (v * 2, tl, tm, l, min (tm, r));

	if (l > tm)
		return get (v * 2 + 1, tm + 1, tr, max (tm + 1, l), r);	

	return (get (v * 2, tl, tm, l, min (tm, r)) * get (v * 2 + 1, tm + 1, tr, max (tm + 1, l), r));
}	

int main ()
{
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d %d %d", &r, &n, &m);

	rep0(i, n)
	{
		rep0(j, 2)
			rep0(k, 2)
				scanf ("%d", &A [i].element [j][k]);

		scanf ("\n");
	}

	build (1, 0, n - 1);

	rep0(i, m)
	{
		int left, right;	
		scanf ("%d %d", &left, &right);
		Matrix ans = get (1, 0, n - 1, --left, --right);

		rep0(j, 2)
		{
			rep0(k, 2)
				printf ("%d ", ans.element [j][k]);

			printf ("\n");
		}

		printf ("\n");
	}	

	return 0;
}	