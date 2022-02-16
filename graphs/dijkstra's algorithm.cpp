#include <iostream>
#include <climits>
using namespace std;

int findminvertex(int* distance, bool* visited, int n)
{
    int minvertex = -1;
    for(int i=0; i<n; i++)
    {
        if(!visited[i] && (minvertex == -1 || distance[i] < distance[minvertex]))
        minvertex=i;
    }
    return minvertex;
}

void dijkstra(int** edges, int n)
{
    int* distance = new int[n];
    bool* visited = new bool[n];

    for(int i=0;i<n;i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    distance[0] = 0;

    for(int i=0;i<n-1;i++)
    {
        int minvertex = findminvertex(distance, visited, n);
        visited[minvertex] = true;
        for(int j=0; j<n; j++)
        {
            if(!visited[j] && edges[minvertex][j] != 0)
        {
            int dist = distance[minvertex] + edges[minvertex][j];
            if(dist<distance[j])
            distance[j] = dist;
        }
        }
    }

    cout<<"shortest distance of the vertices from 0\n";

    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }

    delete [] visited;
    delete [] distance;
}

int main()
{
    int n,e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        edges[i][j]=0;
    }

    for(int i=0;i<e;i++)
    {
        int f,s,weight;
        cin>>f>>s>>weight;
        edges[f][s]=weight;
        edges[s][f]=weight;
    }

    cout<<endl;
    dijkstra(edges,n);

    for(int i=0;i<n;i++)
    {
        delete [] edges[i];
    }
    delete [] edges;

    return 0;

    return 0;
}
