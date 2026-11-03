
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100;

int n, m;
vector<pair<int, int>> adj[MAX];
vector<bool> used;
vector<int> eulerPath;

void findEuler(int u) {
    while (!adj[u].empty()) {
        auto edge = adj[u].back();
        adj[u].pop_back();

        int v = edge.first;
        int id = edge.second;

        if (used[id]) continue;

        used[id] = true;
        findEuler(v);
    }

    eulerPath.push_back(u);
}

int main() {
    ifstream fin("data.txt");

    if (!fin) {
        cout << "Cannot open data.txt\n";
        return 1;
    }

    fin >> n;

    int u, v;
    m = 0;

    while (fin >> u >> v) {
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid vertex.\n";
            return 1;
        }

        adj[u].push_back({v, m});
        adj[v].push_back({u, m});
        m++;
    }

    fin.close();

    vector<int> degree(n, 0);
    int odd = 0;
    int start = -1;

    for (int i = 0; i < n; i++) {
        degree[i] = (int)adj[i].size();

        if (degree[i] % 2 == 1) {
            odd++;
            start = i;
        }

        if (degree[i] > 0 && start == -1)
            start = i;
    }

    cout << "=== EULER ===\n";

    if (odd != 0 && odd != 2) {
        cout << "No Euler path or circuit.\n";
        return 0;
    }

    if (m == 0) {
        cout << "Euler path: ";
        if (n > 0) cout << 0;
        cout << '\n';
        cout << "Euler circuit exists.\n";
        return 0;
    }

    used.assign(m, false);

    findEuler(start);
    reverse(eulerPath.begin(), eulerPath.end());

    if ((int)eulerPath.size() != m + 1) {
        cout << "No Euler path or circuit.\n";
        return 0;
    }

    cout << "Euler path: ";

    for (int i = 0; i < (int)eulerPath.size(); i++) {
        if (i > 0) cout << " -> ";
        cout << eulerPath[i];
    }

    cout << '\n';

    if (odd == 0)
        cout << "Euler circuit exists.\n";
    else
        cout << "Euler circuit does not exist.\n";

    return 0;
}
