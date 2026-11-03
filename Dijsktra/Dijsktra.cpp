#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max() / 2;

// Tim duong di ngan nhat tu dinh nguon s den tat ca cac dinh
void Dijkstra(const vector<vector<int>>& a, int n, int s) {
    vector<int> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);

    // Khoi tao
    dist[s] = 0;

    // Lap toi da n lan
    for (int i = 1; i <= n; i++) {
        int u = -1;
        int minDist = INF;

        // Tim dinh chua xet co khoang cach nho nhat
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        // Khong con dinh nao co the den duoc
        if (u == -1) {
            break;
        }

        // Danh dau dinh u da duoc xu ly
        visited[u] = true;

        // Cap nhat khoang cach den cac dinh ke voi u
        for (int v = 1; v <= n; v++) {
            if (!visited[v] &&
                a[u][v] != 99 &&
                dist[u] + a[u][v] < dist[v]) {

                dist[v] = dist[u] + a[u][v];
                parent[v] = u;
            }
        }
    }

    // In ket qua
    cout << "\nDinh nguon: " << s << "\n";
    cout << "Ket qua duong di ngan nhat:\n\n";

    for (int v = 1; v <= n; v++) {
        cout << "Den dinh " << v << ": ";

        if (dist[v] == INF) {
            cout << "Khong co duong di\n";
            continue;
        }

        cout << "Khoang cach = " << dist[v];
        cout << ", Duong di = ";

        // Truy vet duong di tu v ve s
        vector<int> path;

        for (int cur = v; cur != -1; cur = parent[cur]) {
            path.push_back(cur);
        }

        // Dao nguoc de duoc duong di tu s den v
        reverse(path.begin(), path.end());

        for (int i = 0; i < (int)path.size(); i++) {
            if (i > 0) {
                cout << " -> ";
            }
            cout << path[i];
        }

        cout << "\n";
    }
}

int main() {
    ifstream fin("data.txt");

    if (!fin.is_open()) {
        cout << "Khong the mo file data.txt!\n";
        return 1;
    }

    int n;
    fin >> n;

    if (n <= 0) {
        cout << "So dinh khong hop le!\n";
        return 1;
    }

    // Doc ma tran ke, su dung chi so tu 1 den n
    vector<vector<int>> a(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!(fin >> a[i][j])) {
                cout << "Du lieu ma tran khong hop le!\n";
                return 1;
            }
        }
    }

    fin.close();

    // Nhap dinh nguon
    int s;
    cout << "Nhap dinh nguon (1.." << n << "): ";
    cin >> s;

    if (s < 1 || s > n) {
        cout << "Dinh nguon khong hop le!\n";
        return 1;
    }

    Dijkstra(a, n, s);

    return 0;
}