#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph
{
    public:
    map<int , bool> visited;
    map<int , list<int> > adj;

    //function to add an egde to the graph.
    void addEdge(int v, int w);

    //DFS traversal of the vertices
    //reachable from v.
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);  // add w to v's list.
}

void Graph::DFS(int v)
{
    //mark the current node as visited
    //and print it.
    visited[v] = true;
    cout<<v<<" ";

    //recur for all the adjacent vertices
    //adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if(!visited[*i])
        DFS(*i);
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(0);

    return 0;
}
