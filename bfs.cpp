#include<bits/stdc++.h>

using namespace std;

vector<int> graph[100];
int visited[100];
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
	queue<int> explore;
	explore.push(0);
	visited[0] = 1;
	while (!explore.empty()) {
		int cur = explore.front();
		cout << cur + 1	 << endl;
		explore.pop();
		for(auto neighbour: graph[cur]) {
			if(visited[neighbour] != 1)
				explore.push(neighbour);
			visited[neighbour] = 1;
		}
	}
}