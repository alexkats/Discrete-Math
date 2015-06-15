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

#define NAME "brackets"
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

bool wrong (string s)
{
	int n = (int) s.length ();
	int q = 0;

	rep0(i, n)
	{
		if (s [i] == '(')
			q++;
		else
			q--;

		if (q < 0)
			return true;
	}

	if (q != 0)
		return true;
	else
		return false;
}

void gen (string s)
{
	if ((int) s.length () == n)
	{
		if (!wrong (s))
			cout << s << endl;
	
		return;
	}

	gen (s + '(');
	gen (s + ')');
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);
	n *= 2;

	gen ("");

	return 0;
}	