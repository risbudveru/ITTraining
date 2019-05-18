#include<bits/stdc++.h>

using namespace std;

int N;
string A;
int dp[100][100];

int LPS(int i, int j) {
	if (i == j) {
		return 1;
	}
	if (dp[i][j]) return dp[i][j];
	if (A[i] == A[j]) {
		dp[i][j] = 2 + LPS(i + 1, j - 1);
	} else {
		dp[i][j] = max(LPS(i, j - 1), LPS(i + 1, j));
	}
	return dp[i][j];
}

int main() {
	int N;
	cin >> N;
	cin >> A;
	cout << LPS(0, N - 1) << endl;
}