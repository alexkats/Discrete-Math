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

#define NAME "vectors"
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

int solve (int k)
{
	int d [20];

	d [0] = 1;
	d [1] = 1;

	rep(i, 1, k)
		d [i + 1] = d [i] + d [i - 1];

	return d [k];
}

void gen(string s, int prev)
{
	if ((int) s.length () == n)
	{
		cout << s << endl;
		return;
	}

	gen (s + '0', 0);	

	if (prev != 1)
		gen(s + '1', 1);	
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	int ans = solve (n + 1);

	printf ("%d\n", ans);

	gen ("", -1);	

	return 0;
}	