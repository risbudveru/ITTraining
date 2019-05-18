#include<bits/stdc++.h>

using namespace std;

vector<int> graph[100];

int furthest_node(int current, int parent) {
	int furthest_distance = 0;
	for(auto child: graph[current]) {
		if (child != parent) {
			furthest_distance = max(furthest_distance, furthest_node(child, current));
		}
	}
	return furthest_distance + 1;
}

int main() {
	int N;
	cin >> N;
	int M = N - 1;
	while(M--) {
		int u, v;
		cin >> u >> v;
		u -= 1;
		v -= 1;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int ans = 0;
	for(int i = 0; i < N; i += 1) {
		ans = max(ans, furthest_node(i, -1));
	}
	cout << ans - 1 << endl;
}