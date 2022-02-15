#include <iostream>
#include <climits>
using namespace std;

int findminvertex(int* weights, bool* visited, int n)
{
    int minvertex=-1;
    for(int i=0; i<n; i++)
    {
        if(!visited[i] && (minvertex==-1 || weights[i]<weights[minvertex]))
        {
            minvertex=i;
        }
    }
    return minvertex;
}

void prims(int **edges, int n)
{
    int* parent = new int[n];
    int* weights = new int[n];
    bool* visited = new bool[n];

    for(int i=0; i<n; i++)
    {
        visited[i]=false;
        weights[i]=INT_MAX;
    }

    parent[0] = -1;
    weights[0]  = 0;

    for(int i=0; i<n; i++)
    {
        //find min vertex
        int minvertex = findminvertex(weights, visited, n);
        visited[minvertex]=true;
        //explore unvisited neighbours
        for(int j=0;j<n;j++)
        {
            if(edges[minvertex][j]!=0 && !visited[j])
            {
                if(edges[minvertex][j]<weights[j])
                {
                    weights[j]=edges[minvertex][j];
                    parent[j]=minvertex;
                }
            }
        }
    }

    for(int i=1;i<n;i++)
    {
        if(parent[i]<i)
        cout<<parent[i]<<" "<<i<<" "<<weights[i]<<endl;
        else
        cout<<i<<" "<<parent[i]<<" "<<weights[i]<<endl;
    }
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
    prims(edges,n);

    for(int i=0;i<n;i++)
    {
        delete [] edges[i];
    }
    delete [] edges;

    return 0;
}
