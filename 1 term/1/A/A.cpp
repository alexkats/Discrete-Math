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

#define NAME "huffman"
#define INF 1000000000000000
#define EPS 0.000000001
#define sqr(a) a*a

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

ll p [1000], s = 0;
int n;

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf ("%I64d", &p [i]);
		s = s + p [i];
	}

	sort (p, p + n);

	while (n != 2)
	{	
		p [0] = p [0] + p [1];
		p [1] = INF;
		s = s + p [0];
		sort (p, p + n);
		n--;
	}

	printf ("%I64d\n", s);	

	return 0;
}	