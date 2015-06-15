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

#define NAME "mtf"
#define INF 1000000000
#define EPS 0.000000001
#define sqr(a) a*a

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

string s;
char tmp;
int k, q = 0;
char a [27];
bool z [150] = {false};

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> s;

	int n = s.length ();

	for (int i = 0; i < n; i++)
		if (!z [(int) s [i]])
		{
			q++;
			a [q] = s [i];
			z [(int) s [i]] = true;
		}

	sort (a + 1, a + q + 1);

	for (int i = 0; i < n; i++)
	{
		if (a [1] == s [i])
		{
			cout << 1 << " ";
			continue;
		}

		tmp = a [1];

		for (int j = 1; j <= q; j++)
			if (a [j] == s [i])
			{
				k = j;
				break;
			}

		a [1] = s [i];	

		for (int j = (k - 1); j > 1; j--)
			a [j + 1] = a [j];

		a [2] = tmp;

		cout << k << " ";
	}

	cout << endl;	

	return 0;
}	