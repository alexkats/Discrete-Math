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

#define NAME "num2perm"
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

int n, a [20];
ll k, curr;
int q = 0;
bool z [20] = {false};

ll fact (int n)
{
	ll ans = 1;

	rep0(i, n)
		ans = ans * (i + 1);

	return ans;
}	
		
void solve (int a [])
{
	if (q == n)
	{
		rep0(i, q)
			printf ("%d ", a [i] + 1);

		printf ("\n");

		exit (0);
	}	

	if (curr == 0)
	{
		rep0(i, n)
			if (!z [i])
			{
				q++;
				a [q - 1] = i;
				z [i] = true;
				solve (a);
			}
	}

	rep0(i, n)
	{   if (!z [i])
		{
			if (curr - fact (n - q - 1) >= 0)
			{
				curr -= fact (n - q - 1);
				continue;
			}
			else
			{
				q++;
				a [q - 1] = i;
				z [i] = true;
				solve (a);
			}
		}	
	}

	solve (a);
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%I64d", &n, &k);

	curr = k;

	solve (a);

	return 0;
}	