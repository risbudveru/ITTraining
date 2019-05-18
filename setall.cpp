#include<bits/stdc++.h>

using namespace std;

int N;
int A[100];
int time[100];
int set_all, time_all;
int global_counter;

int set(int x, int v) {
	A[x] = v;
	time[x] = global_counter;
	global_counter += 1;
}

int get(int x) {
	if (time_all > time[x])
		return set_all;
	return A[x];
}

int set_all(int v) {
	set_all = v;
	time_all = global_counter;
	global_counter += 1;
}

int main() {
}