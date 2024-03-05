#include <vector>
using namespace std;

vector<int> eratosthenesSieve(int n) {
    vector<int> primes; // Vektor prostih brojeva
    vector<bool> sieve(n + 1, true); // Inicijalizujemo sve brojeve kao potencijalno proste
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) {
            primes.push_back(i);
            // Ako je trenutni broj oznacen kao prost, oznacavamo sve njegove multiple kao slozene
            for (int j = 2; i * j <= n; j++) {
                sieve[i * j] = false;
            }
        }
    }
    // U trenutnoj implementaciji vracamo vektor prostih brojeva,
    // Moguce je vratiti i vektor sieve ukoliko je to potrebno
    return primes;
}