#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    map<int, bool> visited;
    map<int, list<int> > adj;


    void addEdge(int u, int v);

    void DFS(int v);
};


void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);  // add v to u's list
}

void Graph::DFS(int v)
{
    visited[v] = true;
    cout<<v<<" ";

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++)
    if(!visited[*i])
    DFS(*i);
}

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}
