#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class GraphDijkstra {
private:
    int V; // Broj cvorova grafa
    vector<vector<pair<int, int>>> adjList; // Lista susedstva

public:
    GraphDijkstra(int vertices) : V(vertices), adjList(V) {
    }

    // Dodaje ivicu izmedju cvorova u i v sa tezinom weight
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({ v, weight });
    }

    // Dajkstrin algoritam
    vector<int> dijkstra(int source) {
        vector<int> dist(V, numeric_limits<int>::max()); // Inicijalizuj sve udaljenosti na beskonacno
        dist[source] = 0; // Udaljenost od pocetnog cvora do samog sebe je 0

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, source }); // Par (udaljenost, cvor)

        while (!pq.empty()) {
            int u = pq.top().second; // Uzmi cvor sa najmanjom udaljenoscu
            pq.pop();

            // Prolazak kroz sve susede cvora u
            for (const auto& neighbor : adjList[u]) {
                int v = neighbor.first; // Susedni cvor
                int weight = neighbor.second; // Tezina ivice u-v

                // Azuriraj udaljenost ako je pronadjen kraci put
                if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({ dist[v], v }); // Dodaj azurirani cvor u red s prioritetom
                }
            }
        }

        return dist;
    }
};

int Dijsktra_main() {
    int V = 6; // Broj cvorova grafa
    GraphDijkstra graph(V);

    // Dodaj ivice grafa
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 3, 6);
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 4, 4);
    graph.addEdge(2, 5, 2);
    graph.addEdge(2, 3, 7);
    graph.addEdge(3, 4, 1);
    graph.addEdge(4, 5, 2);

    int source = 0; // Pocetni cvor

    vector<int> distances = graph.dijkstra(source);

    // Ispis rezultata
    cout << "Najkrace udaljenosti od cvora " << source << " do ostalih cvorova:" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Do cvora " << i << ": " << distances[i] << endl;
    }

    return 0;
}
