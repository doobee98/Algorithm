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


int n, k, s;
int dp[401][401];
vector<pii> questions;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	memset(dp, 0, sizeof(int) * 401 * 401);
	cout << dp[400][400] << endl;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		dp[x][y] = -1;
		dp[y][x] = 1;
	}

	cin >> s;
	for (int i = 0; i < s; i++) {
		int x, y;
		cin >> x >> y;
		questions.emplace_back(x, y);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j || j == k || k == i) continue;
				if (dp[i][j] != 0) continue;

				if (dp[i][k] == 1 && dp[k][j] == 1) {
					dp[i][j] = 1;
					dp[j][i] = -1;
				}
			}
		}
	}

	for (auto& [x, y] : questions) {
		cout << dp[x][y] << endl;
	}
}
