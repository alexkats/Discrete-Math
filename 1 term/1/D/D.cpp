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
#include <ctype.h>

#define NAME "lzw"
#define INF 1000000000
#define EPS 0.000000001
#define sqr(a) a*a

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

int num;
string d [10000], t = "", s;
int q = 0;
bool flag = false;

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	cin >> s;

	int n = s.length ();		

	for (int i = 0; i < n; i++)
	{
		flag = false;

		t = t + s [i];

		if (t.length () == 1)
		{
			flag = true;
			num = (int) t [0] - 97;
		}	

		if (!flag)
			for (int j = 0; j < q; j++)
				if (t == d [j])
				{
					flag = true;
					num = j + 26;
					break;
				}

		if (flag)
			continue;

		d [q] = t;
		q++;
		cout << num << " ";
		t = s [i];
		num = (int) t [0] - 97;
	}

	cout << num << endl;	

	return 0;
}	