/**
//  Kruskal para MST en O(E logE)
**/
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
        sz.assign(n, 1);
    }
    int find(int i) {
        return (parent[i] == i) ? i : parent[i] = find(parent[i]);
    }
    bool join(int i, int j) {
        int root_i = find(i), root_j = find(j);
        if (root_i != root_j) {
            if (sz[root_i] < sz[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
            return true;
        }
        return false;
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const { return w < other.w; }
};

// Retorna el peso total del MST. Llena 'mst_edges' con las aristas elegidas.
long long kruskal(int n, vector<Edge>& edges, vector<Edge>& mst_edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    long long total_weight = 0;
    mst_edges.clear();

    for (const auto& e : edges) {
        if (dsu.join(e.u, e.v)) {
            total_weight += e.w;
            mst_edges.push_back(e);
        }
    }
    return total_weight; // Si mst_edges.size() < n - 1, el grafo era disconexo
}
