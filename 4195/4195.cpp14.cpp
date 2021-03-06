#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

int parent[200000], sizes[200000];

int find(int n) {
	int &p = parent[n];
	if (p == n) return n;
	else return p = find(p);
}

int uni(int p, int q) {
	p = find(p);
	q = find(q);
	if (p == q) return sizes[p];
	parent[q] = p;
	return sizes[p] += sizes[q];
}

int cnt = 0;
unordered_map<string, int> map;

inline int testNadd(const char *s) {
	auto p = map.find(s);
	if (p == map.end()) {
		parent[cnt] = cnt;
		sizes[cnt] = 1;
		map.emplace(s, cnt);
		return cnt++;
	}
	else return p->second;
}

int main() {
	int t, n;
	char a[21], b[21];
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		map.clear();
		cnt = 0;

		for (int i = 0; i < n; i++) {
			scanf("%s%s", a, b);
			auto p = testNadd(a);
			auto q = testNadd(b);
			printf("%d\n", uni(p, q));
		}
	}
}