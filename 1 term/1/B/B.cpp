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

#define NAME "bwt"
#define INF 1000000000
#define EPS 0.000000001
#define sqr(a) a*a

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

string s, t [1000] = {""}, r = "";

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> s;

	int n = s.length ();

	t [0] = s;

	for (int i = 1; i < n; i++)
	{
		t [i] = t [i] + t [i - 1][n - 1];

		for (int j = 0; j < (n - 1); j++)
			t [i] = t [i] + t [i - 1][j];		
	}

	sort (t, t + n);

	for (int i = 0; i < n; i++)
		r = r + t [i][n - 1];

	cout << r << endl;	

	return 0;
}	