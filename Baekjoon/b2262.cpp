#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <cmath>
#include <cstring>
#include <numeric>
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

const int MOD = 1000000007; // PLZ check
const ll LMOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1);
const double eps = 1e-10;
const pii dxdy[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };


int n;
vector<int> ids;

int sum = 0;

// return top ranking in range
int solve(int start, int end) {
	if (start == end) return ids[start];

	int min = INF;
	int min_idx = -1;
	for (int i = start; i <= end; i++) {
		if (min > ids[i]) {
			min = ids[i];
			min_idx = i;
		}
	}

	if (start < min_idx)
		sum += solve(start, min_idx - 1) - min;
	if (min_idx < end)
		sum += solve(min_idx + 1, end) - min;

	return min;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		ids.push_back(input);
	}

	solve(0, n - 1);
	cout << sum << endl;
}
