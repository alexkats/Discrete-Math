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

#define NAME "nextbrackets"
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

int a [100010], n;
int q = 0;
string s;

void solve (int a [], int n)
{
	int r = 0;

	rep0(i, q)
	{
		if (i == 0 && a [i] == (n - 1))
			continue;

		if (i != 0)
			if (a [i] == (a [i - 1] - 2))
				continue;

		r = i;
		break;
	}

	a [r]++;

	repd0(i, r)
		a [i] = a [i + 1] + 1;

	reverse (a, a + q);
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> s;

	int n = s.length ();
	bool fl = true;

	rep0(i, n)
	{
		if (s [i] == '(')
			q++;
		else
			q--;

		if (q > 1)
		{
			fl = false;
			break;
		}
	}

	if (fl)
	{
		cout << "-\n";
		return 0;
	}

	q = 0;

	rep0(i, n)
	{
		if (s [i] == '(')
		{
			q++;
			a [q - 1] = i + 1;
		}
	}

	reverse (a, a + q);

	solve (a, n);

	rep0(i, n)
		s [i] = ')';

	rep0(i, q)
		s [a [i] - 1] = '(';

	cout << s << endl;	

	return 0;
}	