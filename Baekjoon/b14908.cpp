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
pii works[1001];
vector<int> path;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int t, s;
		cin >> t >> s;
		works[i] = mk_p(t, s);
		path.push_back(i);
	}

	sort(path.begin(), path.end(), [](int i1, int i2) {
		auto& [t1, s1] = works[i1];
		auto& [t2, s2] = works[i2];
		int waiting_time1 = s1 * t2;
		int waiting_time2 = s2 * t1;

		if (waiting_time1 == waiting_time2)
			return i1 < i2;
		return waiting_time1 > waiting_time2;
	});

	for (int n : path) {
		cout << n << ends;
	}	
	cout << endl;
}
