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


int n, m, t, d;
int positions[25][25];
int results_up[25][25];
int results_down[25][25];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> t >> d;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;

		for (int j = 0; j <= m; j++) {
			char c = input[j];
			int h = c <= 'Z' ? c - 'A' : c - 'a' + 26;
			positions[i][j] = h;
		}
	}
	memset(results_up, 0x3f, sizeof(int) * 25 * 25);
	memset(results_down, 0x3f, sizeof(int) * 25 * 25);

	const auto isValidX = [](int x) {
		return x >= 0 && x < n;
	};

	const auto isValidY = [](int y) {
		return y >= 0 && y < m;
	};

	// 위로 올라가는 경우
	priority_queue<tpi, vector<tpi>, greater<tpi>> worklist;
	worklist.emplace(0, 0, 0);
	results_up[0][0] = 0;

	while (!worklist.empty()) {
		auto [w, x, y] = worklist.top(); worklist.pop();

		if (results_up[x][y] < w) continue;

		for (auto [dx, dy] : dxdy) {
			int new_x = x + dx;
			int new_y = y + dy;
			if (!isValidX(new_x) || !isValidY(new_y)) continue;

			int h = positions[x][y];
			int new_h = positions[new_x][new_y];
			if (abs(new_h - h) > t) continue;

			int dw = h >= new_h ? 1 : pow(new_h - h, 2);
			int new_w = w + dw;

			if (results_up[new_x][new_y] <= new_w) continue;
			results_up[new_x][new_y] = new_w;

			worklist.emplace(new_w, new_x, new_y);
		}
	}

	// 아래로 내려가는 경우 (간선 방향을 반대로)
	worklist.emplace(0, 0, 0);
	results_down[0][0] = 0;

	while (!worklist.empty()) {
		auto [w, x, y] = worklist.top(); worklist.pop();

		if (results_down[x][y] < w) continue;

		for (auto [dx, dy] : dxdy) {
			int new_x = x + dx;
			int new_y = y + dy;
			if (!isValidX(new_x) || !isValidY(new_y)) continue;

			int h = positions[x][y];
			int new_h = positions[new_x][new_y];
			if (abs(new_h - h) > t) continue;

			// 간선 방향을 반대로 - cost 함수를 반대로
			int dw = h <= new_h ? 1 : pow(h - new_h, 2);
			int new_w = w + dw;

			if (results_down[new_x][new_y] <= new_w) continue;
			results_down[new_x][new_y] = new_w;

			worklist.emplace(new_w, new_x, new_y);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << positions[i][j] << ends;
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << results_up[i][j] << ends;
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << results_down[i][j] << ends;
		}
		cout << endl;
	}
	cout << endl;

	int max_h = positions[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int h = positions[i][j];
			int w = results_up[i][j] + results_down[i][j];
			bool is_timeout = w > d;

			if (!is_timeout && max_h < h)
				max_h = h;
		}
	}

	cout << max_h << endl;
}
