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
	void merge(int u, int v) {
		// �� ���Ұ� ���� Ʈ���� ��Ʈ ��带 ã�´�.
		u = find(u);
		v = find(v);

		// u �� v �� �̹� ���� Ʈ���� ���ϴ� ��쿡�� ��ġ�� �ʴ´�.
		if (u == v)
			return;
		parent[v] = u;
	}

	// 3. Find (ã��) ����
	// u �� ���� Ʈ���� ��Ʈ ��� ��ȣ�� ��ȯ�Ѵ�.
	int find(int u) {
		// ��Ʈ ���� �θ� ��� ��ȣ�� �ڱ� �ڽ��� ������.
		if (u == parent[u])
			return u;

		// �� ����� �θ� ��带 ã�� �ö󰣴�.
		// ++��ξ���: ���� ����� parent�� �����Ѵ�.
		parent[u] = find(parent[u]);
		return parent[u];
	}
};


int N, M;

void solve() {
	cin >> N >> M;

	auto s = new UnionFind(N + 1);
	vector<int> s_opponent;
	s_opponent.assign(N + 1, -1);

	for (int i = 0; i < M; i++) {
		int flag, a, b;
		cin >> a >> b;

		int parent_a = s->find(a);
		int parent_b = s->find(b);
		if (parent_a == parent_b) {
			cout << 0 << endl;
			return;
		}

		int& opponent_a = s_opponent[parent_a];
		int& opponent_b = s_opponent[parent_b];

		if (opponent_a != -1) {
			s->merge(opponent_a, b);
		}
		else {
			opponent_a = b;
		}

		if (opponent_b != -1) {
			s->merge(opponent_b, a);
		}
		else {
			opponent_b = a;
		}
	}

	cout << 1 << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
