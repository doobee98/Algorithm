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
		// ++��ξ���: ���� ����� parent�� �����Ѵ�.
		parent[u] = find(parent[u]);
		return parent[u];
	}
};


int G, P;


int solve() {
	auto s = UnionFind(G + 1);

	for (int i = 0; i < P; i++) {
		int gi;
		cin >> gi;

		int parent_gi = s.find(gi);

		if (parent_gi == 0) {
			return i;
		}

		s.merge(parent_gi - 1, parent_gi);
	}
	return P;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> G;
	cin >> P;

	cout << solve() << endl;
}