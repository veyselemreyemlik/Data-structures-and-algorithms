#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100; // grafın maksimum büyüklüğü

class Graph {
private:
    // grafı tutan vektörler
    vector<int> adj[MAXN]; // yayılım listesi
    bool visited[MAXN]; // ziyaret edilen düğümleri tutan dizi

public:
    // grafın öğelerini ekleme ve silme işlemlerini yapacak fonksiyonlar
    void addEdge(int u, int v);
    void removeEdge(int u, int v);

    // graf üzerinde düğümler arasında yol bulma işlemini yapacak fonksiyon
    void dfs(int u);
};

// grafın bir öğesi ekleme fonksiyonu
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// grafın bir öğesi silme fonksiyonu
void Graph::removeEdge(int u, int v) {
    // yayılım listesinden düğümleri silme
    adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
    adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
}

// graf üzerinde düğümler arasında yol bulma fonksiyonu
void Graph::dfs(int u) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    Graph g;

    // grafın öğelerini ekleme
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);


}