#include<bits/stdc++.h>

using namespace std;

int N;
int X[100];
int ans[100];

void sol(int l, int r, int mn, int mx) {
	if(l == r) {
		return;
	}
	int cur_index = (l + r) / 2;
	if(mn <= X[cur_index] && X[cur_index] <= mx) {
		ans[cur_index] = 1;
	}
	sol(l, (l + r) / 2,      mn,                       min(mx, X[(l + r) / 2]));
	sol((l + r) / 2 + 1, r,  max(mn, X[(l + r) / 2]),  mx);
}

int main() {
	cin >> N;
	for(int i = 0; i < N; i += 1) {
		cin >> X[i];
	}
	sol(0, N, 0, 100);
	for(int i = 0; i < N; i += 1) {
		cout << ans[i] << " ";
	}
	 cout << endl;
}