#include <stdio.h>
#include <stdlib.h>

#define MAX 100



struct Edge
{
    int u;
    int v;
    int weight;
};



int parent[MAX];
int rank[MAX];

void makeSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}


int find(int x)
{
    if (parent[x] == x)
        return x;

    parent[x] = find(parent[x]);

    return parent[x];
}


void unionSet(int u, int v)
{
    int rootU = find(u);
    int rootV = find(v);

   
    if (rootU == rootV)
        return;

    if (rank[rootU] < rank[rootV])
    {
        parent[rootU] = rootV;
    }
    else if (rank[rootU] > rank[rootV])
    {
        parent[rootV] = rootU;
    }
    else
    {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}



void sortEdges(struct Edge edges[], int E)
{
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}



void kruskal(struct Edge edges[], int V, int E)
{
    int count = 0;
    int totalCost = 0;

    makeSet(V);

  
    sortEdges(edges, E);

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (int i = 0; i < E; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // Check whether edge creates a cycle
        if (find(u) != find(v))
        {
            printf("%d - %d : %d\n", u, v, weight);

            totalCost += weight;
            count++;

            unionSet(u, v);

           
            if (count == V - 1)
                break;
        }
    }

    printf("Total Cost = %d\n", totalCost);
}


int main()
{
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[MAX];

    printf("Enter edges (u v weight):\n");

    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].weight);
    }

    kruskal(edges, V, E);

    return 0;
}


//home assignment
/* priority queue , union find and all both prims and kruskals */