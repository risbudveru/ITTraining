#include<bits/stdc++.h>

using namespace std;

int N;
string A, B;
int dp[100][100];

int LCS(int i, int j) {
	if (i == -1 || j == -1) {
		return 0;
	}
	if (dp[i][j] != -1) return dp[i][j];
	if (A[i] == B[j]) {
		dp[i][j] = 1 + LCS(i - 1, j - 1);
	} else {
		dp[i][j] = max(LCS(i, j - 1), LCS(i - 1, j));
	}
	return dp[i][j];
}

int main() {
	int N, M;
	cin >> N >> M;
	cin >> A;
	cin >> B;
	for(int i = 0; i < N; i += 1) {
		for(int j = 0; j < M; j += 1) {
			dp[i][j] = -1;	
		}
	}
	cout << LCS(N - 1, M - 1) << endl;
}