#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int M, N;
	cin >> M >> N;
	bool* isPrime = new bool[N + 1];
	for (int i = 0; i < N + 1; i++) {
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i <= sqrt(N); i++) {
		if (isPrime[i]) {
			for (int j = i * 2; j <= N; j += i) isPrime[j] = false;
		}
	}
	for (int i = M; i <= N; i++) {
		if (isPrime[i]) cout << i << "\n";
	}
	return 0;
}