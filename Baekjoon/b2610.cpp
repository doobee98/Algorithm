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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;
	memset(dp, 0x3f, sizeof(int) * 101 * 101);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		dp[x][y] = 1;
		dp[y][x] = 1;
	}

	// 플로이드 와샬
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}


	vector<vector<int>> group_members;
	vector<int> presents;
	bool visited[101] = { false, };
	memset(visited, 0, sizeof(bool) * 101);

	// 그룹 분리
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;

		int id = group_members.size();
		visited[i] = true;

		vector<int> new_group;
		new_group.push_back(i);

		for (int j = i + 1; j <= n; j++) {
			if (dp[i][j] < INF) {
				visited[j] = true;
				new_group.push_back(j);
			}
		}

		group_members.push_back(new_group);
	}

	// 그룹 대표 계산
	for (auto& group : group_members) {
		int group_max_time = INF;
		int group_present = -1;

		for (int present : group) {
			int max_time = 0;
			for (int member : group) {
				if (present == member) continue;
				max_time = max(max_time, dp[member][present]);
			}

			if (group_max_time > max_time) {
				group_max_time = max_time;
				group_present = present;
			}
		}

		presents.push_back(group_present);
	}

	sort(presents.begin(), presents.end());
	cout << group_members.size() << endl;
	for (int present : presents) {
		cout << present << endl;
	}
}
