#include<bits/stdc++.h>

using namespace std;

int N;
int A[100];
int pre[100];

int query(int l, int r) {
	if (l == 0) return pre[r];
	return pre[r] - pre[l - 1];
}

int main() {
	pre[0] = A[0];
	for(int i = 1; i < N; i += 1) {
		pre[i] = pre[i - 1] + A[i]
	}
}