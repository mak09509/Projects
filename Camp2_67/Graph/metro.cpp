#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

pair<vector<int>, int> bfs(int start, int stop, const vector<set<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    vector<int> distance(graph.size(), INT_MAX);
    vector<int> parent(graph.size(), -1);
    vector<int> reversed_path;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    distance[start] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto it : graph[u]) {
            int v = it;
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
                distance[v] = distance[u] + 1;
            }
        }
    }
    
    int u = stop;
    while (u != -1) {
        reversed_path.push_back(u);
        u = parent[u];
    }
    return {reversed_path, distance[stop]};
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> zone(n);
    for (auto& it : zone) {
        cin >> it;
        if (it == 1 || it == 2) it = 1;
        if (it == 3 || it == 4 || it == 5) it = 2;
    }
    vector<set<int>> graph(n); 
    
    char temp;
    while (cin >> temp) {
        if (temp == 's') break;
        int f, l; cin >> f >> l;
        graph[f].insert(l);
    }

    while (cin >> temp) {
        if (temp == 'q') break;
        int start, stop; cin >> start >> stop;

        auto reverse_path = bfs(start, stop, graph);
        cout << reverse_path.second;

        if (temp == 'b') {
            if ((zone[start] == 1 && zone[stop] == 2) || (zone[start] == 2 && zone[stop] == 1)) {
                cout << " N";
            } else cout << " Y";
        }
        else {
            cout << " Y";
        }

        cout << ": ";
        for (auto it = reverse_path.first.rbegin(); it != reverse_path.first.rend(); it++) {
            cout << *it << " -> ";
        }
        cout << endl;
    }
    return 0;
}
