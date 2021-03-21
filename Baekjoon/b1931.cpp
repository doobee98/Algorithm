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


int n;
vector<pll> meetings;
vector<ll> recent_end_times;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		ll from, to;
		cin >> from >> to;
		meetings.emplace_back(from, to);
	}

	sort(meetings.begin(), meetings.end(), [](pll& m1, pll& m2) {
		auto& [from1, to1] = m1;
		auto& [from2, to2] = m2;
		if (to1 < to2) return true;
		if (to1 > to2) return false;
		return from1 < from2;
	});

	int first_end_time = meetings[0].second;
	recent_end_times.push_back(first_end_time);

	for (int i = 1; i < n; i++) {
		auto& [from, to] = meetings[i];
		ll recent_end_time = recent_end_times.back();
		if (from >= recent_end_time)
			recent_end_times.push_back(to);
	}

	cout << recent_end_times.size() << endl;
}
