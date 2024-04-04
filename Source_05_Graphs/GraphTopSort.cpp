#include "GraphTopSort.h"

GraphTopSort::GraphTopSort(int n) : Graph(n)
{ }

// Posebna metoda za dodavanje grane jer je graf usmeren
void GraphTopSort::addEdgeDirected(int u, int v) {
	adj[u].push_back(v);
}

// Topolosko sortiranje (vraca true/false u zavisnosti da li postoji)
bool GraphTopSort::TopSort() {
    // Redosled obilaska cvorova
    vector<int> order(numNodes);

    // Ulazni stepeni cvorova
    vector<int> inputDegree(numNodes, 0);
    for (int i = 0; i < numNodes; i++) {
        for (int neighbor : adj[i]) {
            inputDegree[neighbor]++;
        }
    }

    // Ubacimo u red sve cvorove koji imaju ulazni stepen 0
    queue<int> q;
    for (int i = 0; i < numNodes; i++) {
        if (inputDegree[i] == 0) {
            q.push(i);
        }
    }

    // Promenljiva koja broji koliko smo cvorova do sada obisli
    int count = 0;

    // Sve dok red nije prazan, uzimamo cvor sa pocetka reda
    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        order[count++] = currentNode;

        // Svim susedima trenutnog cvora smanji ulazni stepen za 1
        for (int neighbor : adj[currentNode]) {
            inputDegree[neighbor]--;
            // Ako ulazni stepen suseda posane 0, dodati ga na kraj reda
            if (inputDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (count == numNodes) {
        cout << "Postoji topolosko sortiranje: ";
        for (int i = 0; i < numNodes; i++) {
            cout << order[i] << " ";
        }
        return true;
    }
    else {
        cout << "Ne postoji topolosko sortiranje.";
        return false;
    }
}