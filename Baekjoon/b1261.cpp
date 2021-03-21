#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <cmath>
using namespace std;

#define endl "\n"
#define ends " "

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

bool maze[102][102] = { { false, }, };
int results[102][102] = { { INF, }, };

priority_queue<tpi, vector<tpi>, greater<tpi>> worklist;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		string input;
		cin >> input;
		for (int j = 1; j <= m; j++) {
			maze[i][j] = input[j - 1] == '1';
			results[i][j] = INF;
		}
	}

	const auto isValidX = [](int x) {
		return x >= 1 && x <= n;
	};
	const auto isValidY = [](int y) {
		return y >= 1 && y <= m;
	};

	worklist.emplace(0, 1, 1);
	results[1][1] = 0;

	while (!worklist.empty()) {
		auto [w, x, y] = worklist.top(); worklist.pop();

		if (results[x][y] < w) continue;

		for (auto [dx, dy] : dxdy) {
			int new_x = x + dx;
			int new_y = y + dy;
			int new_w = w + (maze[new_x][new_y] ? 1 : 0);

			if (!isValidX(new_x) || !isValidY(new_y)) continue;
			if (results[new_x][new_y] <= new_w) continue;
			results[new_x][new_y] = new_w;

			worklist.emplace(new_w, new_x, new_y);
		}
	}

	cout << results[n][m] << endl;
}
