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


int n, m;
int dp[101][101];
vector<int> path[101][101];
int via[101][101];

vector<int> get_path(int i, int j) {
	if (i == j || via[i][j] == 0)
		return vector<int>();

	auto before_path = get_path(i, via[i][j]);
	before_path.push_back(j);
	return before_path;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;
	memset(dp, 0x3f, sizeof(int) * 101 * 101);
	memset(via, 0, sizeof(int) * 101 * 101);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (dp[a][b] <= c) continue;
		dp[a][b] = c;
		via[a][b] = a;
	}

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 0;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int is_update = dp[i][j] > dp[i][k] + dp[k][j];
				if (!is_update) continue;

				dp[i][j] = dp[i][k] + dp[k][j];
				via[i][j] = via[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == INF) cout << 0 << ends;
			else cout << dp[i][j] << ends;
		}
		cout << endl;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			auto path_ij = get_path(i, j);

			if (path_ij.empty()) {
				cout << 0 << endl;
				continue;
			}

			int path_size = path_ij.size() + 1;
			cout << path_size << ends;

			cout << i << ends;
			for (auto& via : path_ij) {
				cout << via << ends;
			}
			cout << endl;
		}
	}
}
