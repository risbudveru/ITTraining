#include<bits/stdc++.h>

using namespace std;

// f(x) = ans for subtree rooted at x if you do not pick up from x
// g(x) = ans for subtree rooted at x if you pick up from x

int f[100], g[100];

void sol(int c, int p) {
	for(auto x: graph[c]) {
		if (x != p) {
			sol(x, c);
		}
	}
	g[c] = A[c];
	for(auto x: graph[c]) {
		if (x != p) {
			g[c] += f[x];
			f[c] += max(f[x], g[x]);
		}
	}
}

int A[100];
vector<int> graph[100];

int main() {
	int N;
	cin >> N;
	for(int i = 0; i < N; i += 1) {
		cin >> A[i];
	}
	int M = N - 1;
	while(M--) {
		int u, v;
		cin >> u >> v;
		u -= 1;
		v -= 1;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	sol(0, -1);
	cout << max(f[0], g[0]) << endl;
}