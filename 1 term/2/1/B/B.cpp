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

#define NAME "permutations"
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
bool z [10] = {false};
int q = 0;

void gen (string s)
{
	if (q == n)
	{
		cout << s << endl;
		return;
	}

	rep0(i, n)
		if (!z [i])
		{
			z [i] = true;
			char c = (char) (i + 49);
			s = s + c + " ";
			q++;
			gen (s);
			int k = (int) s.length ();
			s = s.substr (0, (k - 2));
			q--;
			z [i] = false;
		}
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	gen ("");

	return 0;
}	