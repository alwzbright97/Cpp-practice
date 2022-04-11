#include <iostream>
#include <cmath>

int main() {
	int t, n;
	int m;
	std::cin >> t;

	bool* PrimeArray = new bool[10001];
	PrimeArray[0] = false;
	PrimeArray[1] = false;

	for (int i = 2; i <= 10001; i++) {
		PrimeArray[i] = true;
	}

	for (int i = 2; i <= std::sqrt(10001); i++) {
		if (PrimeArray[i]) {
			for (int j = i * i; j <= 10001; j += i) {
				PrimeArray[j] = false;
			}
		}
	}

	int k, si;

	for (int i = 0; i < t; i++) {
		std::cin >> n;

		m = n / 2;
        
        if (m % 2 == 0) si = 1;
        else si = 2;

		if (PrimeArray[m]) {
			std::cout << m << " " << m << "\n";
		}
		else {
			for (k = si; k < m; k += 2) {
				if (PrimeArray[m - k] && PrimeArray[m + k]) break;
			}
			std::cout << m - k << " " << m + k << "\n";
		}
	}
}