#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <climits>
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

int v, e;
int k;
vector<pii> adj[20002];
vector<int> min_weights;
priority_queue<pii, vector<pii>, greater<pii>> worklist;	// pair<weight, vertex_number>


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;
	min_weights.assign(v + 1, INT_MAX);

	cin >> k;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({ v, w });
	}

	worklist.push({ 0, k });
	min_weights[k] = 0;

	while (!worklist.empty()) {
		const auto& current = worklist.top();
		int cur_w = current.first;
		int cur_v = current.second;
		worklist.pop();

		if (min_weights[cur_v] < cur_w) continue;

		for (const auto& edge : adj[cur_v]) {
			int next_v = edge.first;
			int next_w = cur_w + edge.second;

			if (min_weights[next_v] <= next_w) continue;

			min_weights[next_v] = next_w;
			worklist.push({ next_w, next_v });
		}
	}

	for (int i = 1; i <= v; i++) {
		int min_w = min_weights[i];

		if (min_w == INT_MAX) cout << "INF" << endl;
		else cout << min_w << endl;
	}
}
