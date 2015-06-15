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

#define NAME "nextvector"
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

string solve1 (string s)
{
	int n = s.length ();

	rep0(i, n)
		if (s [i] == '0')
			s [i] = '1';
		else
		{
			s [i] = '0';
			break;
		}

	rep0(i, n / 2)
		swap (s [i], s [n - i - 1]);

	return s;	
}

string solve2 (string s)
{
	int n = s.length ();

	rep0(i, n)
		if (s [i] == '1')
			s [i] = '0';
		else
		{
			s [i] = '1';
			break;
		}

	rep0(i, n / 2)
		swap (s [i], s [n - i - 1]);

	return s;	
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> s;

	int n = s.length ();

	rep0(i, n / 2)
		swap (s [i], s [n - i - 1]);

	bool z0 = false;
	bool z1 = false;
	string ans1 = "";
	string ans2 = "";	

	rep0(i, n)
	{
		if (s [i] != '0')
			z0 = true;

		if (s [i] != '1')
			z1 = true;
	}	

	if (!z0)
		ans1 = "-";
	else
		ans1 = solve1 (s);

	if (!z1)
		ans2 = "-";
	else
		ans2 = solve2 (s);

	cout << ans1 << endl;
	cout << ans2 << endl;	

	return 0;
}	