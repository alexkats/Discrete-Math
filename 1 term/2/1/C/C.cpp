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

#define NAME "choose"
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

int n, k;
int q = 0;
bool z [20] = {false};
int a [20];

void gen (int a [], int prev)
{
	if (q == k)
	{
		rep0(i, q)
			printf ("%d ", a [i]);

		printf ("\n");
			
		return;
	}

	rep(i, (prev + 1), n)
		if (!z [i])
		{
			z [i] = true;
			q++;
			a [q - 1] = i + 1;
			prev = i;
			gen (a, prev);
			q--;
			z [i] = false;
		}
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &k);

	gen (a, -1);

	return 0;
}	