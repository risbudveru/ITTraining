#include<bits/stdc++.h>

using namespace std;

// f(x) = ans for subtree rooted at x

int f[100];

void sol(int current, int parent) {
	for(auto child: graph[current]) {
		if (child != parent) {
			sol(child, current);
		}
	}
	int c1 = A[current], c2 = 0; // c1 = pickup, c2 = dont
	for(auto child: graph[current]) {
		if (child != parent) {
			for(auto grandchild: graph[child]) {
				if (grandchild != current) {
					c1 += f[grandchild];
				}
			}
			c2 += f[child];
		}
	}
	f[current] = max(c1, c2);  
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
	cout << f[0] << endl;
}