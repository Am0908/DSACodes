#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
 public:
 int source;
 int dest;
 int weight;
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int findparent(int v, int *parent)
{
    if(parent[v] == v)
    return v;

    return findparent(parent[v], parent);

}

void krushkals(Edge *input, int n, int E)
{
    // sort the input array in ascending order based on weights
    sort(input, input + E, compare);

    Edge *output = new Edge[n-1];

    int *parent = new int[n];

    for(int i = 0; i < n; i++)
    parent[i] = i;

    int count = 0;
    int i = 0;
    while(count != n-1)
    {
        Edge currentEdge = input[i];

        // check if we can add the current edge in MST or not.
        int sourceparent = findparent(currentEdge.source, parent);
        int destparent = findparent(currentEdge.dest, parent);

        if(sourceparent != destparent)
        {
            output[count] = currentEdge;    // add the edge to MST
            count++;                        // increase the count of edges
            parent[sourceparent] = destparent;
        }
        i++;
    }

    for(int i = 0;i < n-1; i++)
    {
        if(output[i].source < output[i].dest)
        cout << output[i].source <<" "<< output[i].dest <<" "<< output[i].weight << endl;

        else
        cout << output[i].dest <<" "<< output[i].source <<" "<< output[i].weight << endl;
    }
}

int main()
{
    int n, E;
    cin >> n >>E;
    // n-> total no. of vertices
    //E -> Total no. of edges
    Edge* input = new Edge[E];

    for(int i = 0; i < E; i++)
    {
        int s, d, w;
        cin >> s >> d >>w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    cout<<"\nOutput\n\n";
    krushkals(input, n, E);

    return 0;
}
