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

const int MOD = 1000000007; // PLZ check
const ll LMOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1);
const double eps = 1e-10;
const pii dxdy[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

int n, k;

int d[200002];
priority_queue<pii, vector<pii>, greater<pii>> worklist;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	memset(d, 0x3f, sizeof(int) * 200002);

	const auto isValidX = [](int x) {
		return x >= 0 && x < 200002;
	};

	worklist.emplace(0, n);
	d[n] = 0;

	while (!worklist.empty()) {
		auto [w, x] = worklist.top(); worklist.pop();

		if (d[x] < w) continue;
		if (x == k) break;

		for (auto [dx, dw] : { mk_p(-1, 1), mk_p(1, 1), mk_p(x, 0) }) {
			int new_x = x + dx;
			int new_w = w + dw;

			if (!isValidX(new_x)) continue;
			if (d[new_x] <= new_w) continue;
			d[new_x] = new_w;

			worklist.emplace(new_w, new_x);
		}
	}

	cout << d[k] << endl;
}
