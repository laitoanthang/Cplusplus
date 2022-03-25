// Lai Toan Thang
// MSSV: 20280083

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Graph {
    int vertices;
    int* traversed;
    int** adjMatrix;
    Node** adjList;
};

Node* create_Node(int v) {
    Node* new_Node = new Node;
    new_Node->data = v;
    new_Node->next = nullptr;
    return new_Node;
}

Graph* create_graph(int vertices) {
    Graph* graph = new Graph;
    graph->vertices = vertices;
    graph->adjMatrix = new int*[vertices];
    graph->adjList = new Node* [vertices];
    graph->traversed = new int[vertices];
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = new int[vertices];
        graph->adjList[i] = nullptr;
        graph->traversed[i] = 0;
    }
    return graph;
}

void add_edge(Graph* graph, int src, int dest) 
{
    Node* p = create_Node(dest);
    p->next = graph->adjList[src];
    graph->adjList[src] = p;
    graph->adjMatrix[src][dest] = 1;
}

void printadjMatrix(Graph* graph, int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cout << graph->adjMatrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int v = 5;
    Graph* graph = create_graph(v);
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            graph->adjMatrix[i][j] = 0;

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    cout << "Adjacency Matrix:\n";
    printadjMatrix(graph, v);
    return 0;
}