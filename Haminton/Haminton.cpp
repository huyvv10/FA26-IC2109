
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAX = 100;

int n;
vector<int> adj[MAX];
vector<int> path;
bool visited[MAX];
bool found = false;

void findHamilton(int u, int start) {
    if (found) return;

    // All vertices have been visited.
    if ((int)path.size() == n) {
        // Check whether the last vertex connects
        // back to the starting vertex.
        for (int v : adj[u]) {
            if (v == start) {
                path.push_back(start);
                found = true;
                return;
            }
        }
        return;
    }

    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            path.push_back(v);

            findHamilton(v, start);

            if (found) return;

            path.pop_back();
            visited[v] = false;
        }
    }
}

int main() {
    ifstream fin("data.txt");

    if (!fin) {
        cout << "Cannot open data.txt\n";
        return 1;
    }

    fin >> n;

    int u, v;

    while (fin >> u >> v) {
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid vertex.\n";
            return 1;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fin.close();

    cout << "=== HAMILTON ===\n";

    if (n <= 0) {
        cout << "Invalid number of vertices.\n";
        return 1;
    }

    for (int i = 0; i < n; i++)
        visited[i] = false;

    path.push_back(0);
    visited[0] = true;

    findHamilton(0, 0);

    if (found) {
        cout << "Hamilton cycle: ";

        for (int i = 0; i < (int)path.size(); i++) {
            if (i > 0) cout << " -> ";
            cout << path[i];
        }

        cout << '\n';
    } else {
        cout << "No Hamilton cycle found.\n";
    }

    return 0;
}
