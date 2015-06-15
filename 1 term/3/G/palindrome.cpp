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
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "palindrome"
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
string t = "";
int d [2001][2001] = {0};

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> s;

	int n = (int) (s.length ());

	if (n == 1)
	{
		cout << 1 << endl << s << endl;
		return 0;
	}	

	rep(i, 1, (n + 1))
		d [i][i] = 1;		

	int i = 1;
	int j = 2;	
	int prev = 2;

	while (1)
	{
		if (s [i - 1] == s [j - 1])
			d [i][j] = d [i + 1][j - 1] + 2;
		else
			d [i][j] = max (d [i + 1][j], d [i][j - 1]);	

		if (i == 1 && j == n)
			break;	

		if (j == n)
		{
			j = prev + 1;	
			prev++;
			i = 1;
			continue;
		}	

		i++;
		j++;	
	}

	printf ("%d\n", d [1][n]);	

	int curr = d [1][n];
	i = 1;
	j = n;

	while (curr != 0)
	{
		if (s [i - 1] == s [j - 1])
		{
			t += s [i - 1];

			if (curr == 1)
			{
				curr = 0;
			}
			else
			{
				curr -= 2;
				i++;
				j--;
			}
		}
		else
		{
			if (curr == d [i + 1][j])
				i++;
			else
				j--;
		}
	}

	rep0(i, (int) (d [1][n] / 2))
		t += t [(int) (d [1][n] / 2) - i - 1];

	cout << t << endl;	

	return 0;
}	