#include <iostream>
using namespace std;

const int MOD = 10007;

// Function to calculate power of a number modulo MOD
int power_vanshaj(int base, int exp) {
    int result = 1;
    base = base % MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        exp = exp >> 1;
        base = (base * base) % MOD;
    }
    return result;
}

int countIntegersWithAtLeastTwoZeros(int N) {
    if (N < 3) return 0;

    // Total N-digit numbers (excluding those with leading zeros)
    int total = (9 * power_vanshaj(10, N-1)) % MOD;

    // Numbers with no zeros
    int noZeros = (9 * power_vanshaj(9, N-1)) % MOD;

    // Numbers with exactly one zero
    int oneZero = ((N-1) * 9 * power_vanshaj(9, N-2)) % MOD;

    // Numbers with at least two zeros
    int atLeastTwoZeros = (total - noZeros - oneZero) % MOD;
    if (atLeastTwoZeros < 0) {
        atLeastTwoZeros += MOD;
    }

    return atLeastTwoZeros;
}

int main() {
    int N;
    cin >> N;

    int result = countIntegersWithAtLeastTwoZeros(N);
    cout << result << endl;

    return 0;
}
