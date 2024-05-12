#include<stdio.h>
#include <stdbool.h>
#define V 5

int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0},
    };

bool isSafe(int v, int *path, int pos)
{
    if(!graph[path[pos - 1]][v])
        return false;
    for(int i = 0; i < pos; i++)
    {
        if(path[i] == v)
            return false;
    }
    return true;
}

bool hamCycleUtil(int *path, int pos)
{
    if(pos == V)
    {
        if(graph[path[pos-1]][path[0]])
            return true;
        else
            return false;
    }

    for(int v = 1; v < V; v++)
    {
        if(isSafe(v, path, pos)){
            path[pos] = v;
            if(hamCycleUtil(path, pos + 1))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

void printSolution(int path[])
{
    printf("Solution Exists: \n");
    for(int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);
}

bool hamCycle()
{
    int path[V];
    for(int i = 0; i < V; i++)
        path[i] = -1;
    
    path[0] = 0;
    if(hamCycleUtil(path, 1) == false){
        printf("Solution does not exist");
        return false;
    }
    printSolution(path);
    return true;
}

int main()
{
    hamCycle(graph);
    return 0;
}