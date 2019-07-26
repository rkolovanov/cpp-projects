#include "kolib.h"
#include <vector>

template <typename T>
T eulerFunction(T n) {
	T result = n;

	for (T i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	}

	if (n > 1)
		result -= result / n;

	return result;
}

template <typename T>
vector<char> getPrimeNumbers(T n) {
	T n;
	vector<char> prime(n + 1, true);
	prime[0] = prime[1] = false;

	for (int i = 2; i <= n; ++i) {
		if (prime[i])
			if (i * 1ll * i <= n)
				for (int j = i * i; j <= n; j += i)
					prime[j] = false;
	}

	return prime;
}