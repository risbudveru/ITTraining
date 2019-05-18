#include<bits/stdc++.h>

using namespace std;

int N;
int A[100];
int pre[100];
int fib_[100] = {-1}; // all -1

int fib(int n) {
	if (n < 2) {
		return 0;
	}
	if (fib_[n] != -1) {
		return fib_[n];
	}
	fib_[n] = fib(n - 1) + fib(n - 2);
	return fib_[n];
}

int main() {

}