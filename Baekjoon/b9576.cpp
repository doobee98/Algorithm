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


void run() {
	int n, m;
	vector<pii> requests;
	bool visited[1001] = { false, };

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		requests.emplace_back(a, b);
	}

	sort(requests.begin(), requests.end(), [](pii& p1, pii& p2) {
		if (p1.second == p2.second)
			return p1.first < p2.first;
		return p1.second < p2.second;
	});

	int count = 0;
	for (auto [from, to] : requests) {
		for (int i = from; i <= to; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			count++;
			break;
		}
	}
	cout << count << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_count;
	cin >> test_count;

	for (int i = 0; i < test_count; i++) {
		run();
	}
}
