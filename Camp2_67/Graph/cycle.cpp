#include <bits/stdc++.h>
using namespace std;

void dfs(int start, const  vector<set<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    vector<int> parent(graph.size(), -1);
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (visited[u]) continue;

        visited[u] = true;

        for (auto it = graph[u].rbegin(); it != graph[u].rend(); it++) {
            int v = *it;
            if (!visited[v]) {
                st.push(v);
                parent[v] = u;
            }
            else if (v != parent[u]) {
                cout << "Cycle";
                return;
            }
        }
    }
    cout << "No cycle";
}

int main(void) {
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<set<int>> graph(n);

    char temp;
    while (cin >> temp) {
        if (temp == 's') break;
        int f, l, w; cin >> f >> l >> w;
        graph[f].insert(l); 
    }

    dfs(0, graph);
    return 0;
}
