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
vector<int> bags;
vector<pii> jewels;						// (weight, value)
priority_queue<pii> jewels_queue;		// (value, weight)


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		jewels.emplace_back(w, v);
	}

	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		bags.push_back(c);
	}

	sort(jewels.begin(), jewels.end());
	sort(bags.begin(), bags.end());

	ll sum = 0;
	int i = 0;
	for (int bag : bags) {
		// bag보다 무게가 크지 않은 jewel들 queue에 넣기
		while (i < n && jewels[i].first <= bag) {
			auto [w, v] = jewels[i];
			jewels_queue.push(mk_p(v, w));
			i++;
		}

		// queue에서 가치가 가장 비싼 jewel 뽑기
		if (jewels_queue.empty()) continue;
		auto [v, w] = jewels_queue.top(); jewels_queue.pop();
		sum += v;
	}

	cout << sum << endl;
}
