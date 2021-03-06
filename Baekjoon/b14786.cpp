#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <cmath>
#include <cstring>
using namespace std;

#define endl "\n"
#define ends " "
#define mk_p(x,y) make_pair((x), (y))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef unsigned long long ull;

const int MOD = 1000000000; // PLZ check
const ll LMOD = 1000000000;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1);
const long double eps = 1e-20;
const pii dxdy[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };


long double A, B, C;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	long double left = (C - B) / A;
	long double right = (C + B) / A;
	long double mid = -1;

	for (int i = 0; left < right && i < 100000; i++) {
		mid = (left + right) / 2;

		long double v = A * mid + B * (long double)sin(mid);
		if (v > C)
			right = mid - eps;
		else
			left = mid + eps;
	}

	cout << fixed;
	cout.precision(20);
	cout << mid << endl;
}
