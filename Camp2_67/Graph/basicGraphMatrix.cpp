#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void dfs(int start, const vector<set<int>>& adj){
    vector<bool> visited(adj.size(), false);
    stack<int> st;
    st.push(start);
    
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (visited[u]) continue;

        visited[u] = true;
        cout << u << " ";
        
        for (auto it = adj[u].rbegin(); it != adj[u].rend(); it++) {
            int v = *it;
            if (!visited[v]) st.push(v);
        }
    }
    cout << endl;
}

void bfs(int start, vector<set<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (visited[u]) continue;

        visited[u] = true;
        cout << u << " ";

        for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
            int v = *it;
            if (!visited[v]) q.push(v);
        }
    }
    cout << endl;
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<set<int>> adj(n);
    
    char temp;
    while (cin >> temp){
        if (temp == 's') break;
        int f, l, w; cin >> f >> l >> w;
        adj[f].insert(l);
    }

    while (cin >> temp){
        if (temp == 'q') break;
        int num; cin >> num;
        if (temp == 'd') dfs(num, adj);
        if (temp == 'b') bfs(num, adj);
    }
    return 0;
}
