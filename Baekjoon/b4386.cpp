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

const int MOD = 1000000000; // PLZ check
const ll LMOD = 1000000000;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1);
const double eps = 1e-10;
const pii dxdy[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };


// ��ó: https://bowbowbow.tistory.com/26
struct UnionFind {
	vector<int> parent;
	UnionFind(int n) : parent(n) {
		// 1. �ʱ�ȭ
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	// 2. Union (��ġ��) ����
	// u �� ���� Ʈ���� v �� ���� Ʈ���� ��ģ��.
	// u�� parent�� ������ tree�� parent�� �ȴ�.
	bool merge(int u, int v) {
		// �� ���Ұ� ���� Ʈ���� ��Ʈ ��带 ã�´�.
		u = find(u);
		v = find(v);

		// u �� v �� �̹� ���� Ʈ���� ���ϴ� ��쿡�� ��ġ�� �ʴ´�.
		if (u == v)
			return false;
		parent[v] = u;
		return true;
	}

	// 3. Find (ã��) ����
	// u �� ���� Ʈ���� ��Ʈ ��� ��ȣ�� ��ȯ�Ѵ�.
	int find(int u) {
		// ��Ʈ ���� �θ� ��� ��ȣ�� �ڱ� �ڽ��� ������.
		if (u == parent[u])
			return u;

		// �� ����� �θ� ��带 ã�� �ö󰣴�.
		parent[u] = find(parent[u]);
		return parent[u];
	}
};


int N;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vector<pair<double, double>> stars_pos;
	stars_pos.assign(N + 1, { 0.0, 0.0 });

	for (int i = 1; i <= N; i++) {
		double x, y;
		cin >> x >> y;
		stars_pos[i] = { x, y };
	}

	auto visited = UnionFind(N + 1);
	typedef tuple<double, int, int> tdedge;
	priority_queue<tdedge, vector<tdedge>, greater<tdedge>> edge_queue;

	for (int i = 1; i <= N - 1; i++) {
		for (int j = i + 1; j <= N; j++) {
			auto [xi, yi] = stars_pos[i];
			auto [xj, yj] = stars_pos[j];
			double d = sqrt(pow(xi - xj, 2) + pow(yi - yj, 2));
			edge_queue.emplace(d, i, j);
		}
	}

	double sum = 0;
	while (!edge_queue.empty()) {
		auto [d, i, j] = edge_queue.top();
		edge_queue.pop();

		if (visited.find(i) == visited.find(j))
			continue;

		visited.merge(i, j);
		sum += d;
	}

	cout << fixed;
	cout.precision(2);
	cout << sum << endl;
}
