#include <stdio.h>
#include <malloc.h>

// Experiment 19: Implement graph traversal (DFS & BFS) - (Undirected Graph)

#define MAX_VERTICES 100
#define QUEUE_SIZE 100

struct vertex
{
    int adjacency[MAX_VERTICES];
    int num_neighbors;
};

struct queue
{
    int *Q;
    int front;
    int rear;
    int size;
};

int isEmpty(struct queue *x)
{
    if (x->rear == x->front)
        return 1;
    return 0;
}

int isFull(struct queue *x)
{
    if ((x->rear + 1) % x->size == x->front)
        return 1;
    return 0;
}

int enqueue(struct queue *x, int elem)
{
    if (isFull(x))
    {
        printf("Queue is Full\n");
        return 0;
    }

    x->rear = (x->rear + 1) % x->size;
    x->Q[x->rear] = elem;
    return 1;
}

int dequeue(struct queue *x)
{
    if (isEmpty(x))
    {
        printf("Queue is empty\n");
        return -1;
    }

    x->front = (x->front + 1) % x->size;
    return x->Q[x->front];
}

int visited[MAX_VERTICES];

void BFS(int start, struct vertex *graph, int num_vertices, int num_edges)
{
    for (int i = 0; i < num_vertices; i++)
    {
        visited[i] = 0;
    }

    struct queue Q;
    Q.front = Q.rear = -1;
    Q.size = QUEUE_SIZE;
    Q.Q = (int *)malloc(sizeof(int) * QUEUE_SIZE);
    enqueue(&Q, start);
    visited[start] = 1;

    while (!isEmpty(&Q))
    {
        int u = dequeue(&Q);
        printf("%d ", u);

        for (int i = 0; i < graph[u].num_neighbors; i++)
        {
            int v = graph[u].adjacency[i];
            if (!visited[v])
            {
                enqueue(&Q, v);
                visited[v] = 1;
            }
        }
    }
}

void DFS_helper(int u, struct vertex *graph)
{
    visited[u] = 1;
    printf("%d ", u);

    int toVisit[MAX_VERTICES], n = 0;

    for (int i = 0; i < graph[u].num_neighbors; i++)
    {
        int v = graph[u].adjacency[i];
        if (visited[v] == 0)
        {
            visited[v] = 1;
            toVisit[n++] = v;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int v = toVisit[i];
        DFS_helper(v, graph);
    }

    visited[u] = 2;
}



void DFS(int start, struct vertex *graph, int num_vertices)
{
    for (int i = 0; i < num_vertices; i++)
    {
        visited[i] = 0;
    }

    DFS_helper(start, graph);
}

void showAdjancencyLists(struct vertex *graph, int num_vertices)
{
    printf("Adjacency lists:\n");
    for (int i = 0; i < num_vertices; i++)
    {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph[i].num_neighbors; j++)
        {
            printf("%d ", graph[i].adjacency[j]);
        }
        printf("\n");
    }
}

int main()
{
    int num_vertices, num_edges;
    struct vertex *graph = (struct vertex *)malloc(sizeof(struct vertex) * MAX_VERTICES);
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    //invalid case
    if (num_vertices <= 0 || num_edges < 0)
        return 0;

    printf("\nThe edges are labeled 0 to %d\n", num_vertices - 1);

    for (int i = 0; i < num_edges; i++)
    {
        int u, v;
        printf("Enter an edge (u v): ");
        scanf("%d %d", &u, &v);
        if (u < 0 || u >= num_vertices || v < 0 || v >= num_vertices)  //checking the case
        {
            printf("Invalid edge\n");
            i--;  //decrementing the i
            continue;
        }

        int already_present = 0;
        for (int k = 0; k < graph[u].num_neighbors; k++)
        {
            if (graph[u].adjacency[k] == v)
            {
                already_present = 1;
                break;
            }
        }

        if (already_present)
        {
            printf("This vertices is already present!\n");
            i--;
            continue;
        }

        graph[u].adjacency[graph[u].num_neighbors++] = v;
        graph[v].adjacency[graph[v].num_neighbors++] = u;
    }

    showAdjancencyLists(graph, num_vertices);

    int choice = 1;
    while (choice != 4)
    {
        printf("\nMenu:\n1. Breadth-first search\n2. Depth-first search\n3. Show adjacency Lists\n4. Exit\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int start;
            printf("Enter the starting vertex: ");
            scanf("%d", &start);
            BFS(start, graph, num_vertices, num_edges);
            break;
        }
        case 2:
        {
            int start;
            printf("Enter the starting vertex: ");
            scanf("%d", &start);
            DFS(start, graph, num_vertices);
            break;
        }
        case 3:
            showAdjancencyLists(graph, num_vertices);
            break;
        case 4:
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}