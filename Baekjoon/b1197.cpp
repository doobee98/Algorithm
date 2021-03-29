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


// 출처: https://bowbowbow.tistory.com/26
struct UnionFind {
	vector<int> parent;
	UnionFind(int n) : parent(n) {
		// 1. 초기화
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	// 2. Union (합치기) 연산
	// u 가 속한 트리와 v 가 속한 트리를 합친다.
	// u의 parent가 합쳐진 tree의 parent가 된다.
	bool merge(int u, int v) {
		// 각 원소가 속한 트리의 루트 노드를 찾는다.
		u = find(u);
		v = find(v);

		// u 와 v 가 이미 같은 트리에 속하는 경우에는 합치지 않는다.
		if (u == v)
			return false;
		parent[v] = u;
		return true;
	}

	// 3. Find (찾기) 연산
	// u 가 속한 트리의 루트 노드 번호를 반환한다.
	int find(int u) {
		// 루트 노드는 부모 노드 번호로 자기 자신을 가진다.
		if (u == parent[u])
			return u;

		// 각 노드의 부모 노드를 찾아 올라간다.
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
