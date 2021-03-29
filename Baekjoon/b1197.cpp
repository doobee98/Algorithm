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


int V, E;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;

	auto visited = UnionFind(V + 1);
	priority_queue<tpi, vector<tpi>, greater<tpi>> edge_queue;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge_queue.emplace(c, a, b);
	}

	int sum = 0;
	while (!edge_queue.empty()) {
		auto [w, a, b] = edge_queue.top();
		edge_queue.pop();

		if (visited.find(a) == visited.find(b))
			continue;
		
		visited.merge(a, b);
		sum += w;
	}

	cout << sum << endl;
}
