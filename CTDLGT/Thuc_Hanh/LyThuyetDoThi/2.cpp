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
    Node** adjList;
};

Node* create_Node(int v) 
{
    Node* new_Node = new Node;
    new_Node->data = v;
    new_Node->next = nullptr;
    return new_Node;
}

Graph* create_graph(int vertices) 
{
    Graph* graph = new Graph;
    graph->vertices = vertices;
    graph->adjList = new Node * [vertices];
    graph->traversed = new int[vertices];
    for (int i = 0; i < vertices; i++) {
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
}

void printAdjList(Graph* graph, int v)
{
    for (int i = 0; i < v; i++)
    {
        Node* p = graph->adjList[i];
        cout << "Dinh: " << i << "\n" << i;
        while (p)
        {
            cout <<" -> " << p->data;
            p = p->next;
        }
        cout << endl;
    }
}

// DFS algo
void DFS(Graph* graph, int start_vertex) 
{
    graph->traversed[start_vertex] = 1;
    cout << start_vertex << " da duoc duyet\n";
    for (Node* p = graph->adjList[start_vertex]; p != nullptr; p = p->next)
    {
        int adjVertex = p->data;
        if (graph->traversed[adjVertex] == 0)
        {
            graph->traversed[adjVertex] = 1;
            DFS(graph, adjVertex);
        }
    }
}

int main() 
{
    int v = 5;
    Graph* graph = create_graph(v);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    cout << "Danh sach ke cua do thi:\n";
    printAdjList(graph, v);
    cout << "\nDuyet DFS:\n";
    DFS(graph, 1);
    return 0;
}

// --------------------------- Câu b ------------------------------
// Độ phức tạp thời gian của thuật toán DFS được biểu diễn 
// dưới dạng O(V + E), trong đó V là số nút và E là số cạnh.
// 
// The space complexity of the algorithm is O(V).
// 
// V = 5, E = 6