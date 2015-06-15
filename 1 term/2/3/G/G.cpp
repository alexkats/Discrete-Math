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

#define NAME "nextpartition"
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

string s;
int n, q = 0, a [100000];
bool fl = false;

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> s;

	int len = s.length ();

	rep0(i, len)
	{
		if (s [i] == '=')
		{
			fl = true;
			continue;
		}

		if (s [i] == '+')
		{
			q++;
			continue;
		}	
			
		if (!fl)
			n = n * 10 + (int) (s [i]) - 48;

		if (fl)
			a [q] = a [q] * 10 + (int) (s [i]) - 48;
	}

	q++;

	if (q == 1)
	{
		cout << "No solution" << endl;
		return 0;
	}

	if ((a [q - 1] - a [q - 2]) >= 2)
	{
		a [q - 2]++;
		int sum = a [q - 1] - 1;
		int m = a [q - 2];

		while (sum != 0)
		{
			if (m * 2 <= sum)
			{
				a [q - 1] = m;
				q++;
				sum -= m;
			}
			else
			{
				a [q - 1] = sum;
				q++;
				sum = 0;
			}	
		}

		q--;
	}
	else
	{
		q--;
		a [q - 1] += a [q];
	}	

	printf ("%d=%d", n, a [0]);

	rep0(i, (q - 1))
		printf ("+%d", a [i + 1]);

	printf ("\n");	

	return 0;
}	