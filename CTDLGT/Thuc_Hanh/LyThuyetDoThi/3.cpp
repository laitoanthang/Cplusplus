// Lai Toan Thang
// MSSV: 20280083

#include <iostream>
#include <list>
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

Node* create_Node(int v) {
    Node* new_Node = new Node;
    new_Node->data = v;
    new_Node->next = NULL;
    return new_Node;
}

Graph* create_graph(int vertices) {
    Graph* graph = new Graph;
    graph->vertices = vertices;
    graph->adjList = new Node * [vertices];
    graph->traversed = new int[vertices];
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
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
            cout << " -> " << p->data;
            p = p->next;
        }
        cout << endl;
    }
}

// BFS algorithm
void BFS(Graph* graph, int start_vertex)
{
    list<int> queue;
    graph->traversed[start_vertex] = 1;
    queue.push_back(start_vertex);
    while (!queue.empty())
    {
        int current_vertex = queue.front();
        cout << current_vertex << " da duoc duyet\n";
        queue.pop_front();
        for (Node* p = graph->adjList[current_vertex]; p != NULL; p = p->next)
        {
            int adjVertext = p->data;
            if (graph->traversed[adjVertext] == 0)
            {
                graph->traversed[adjVertext] = 1;
                queue.push_back(adjVertext);
            }
        }
    }
}

int main() {
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
    cout << "\nDuyet BFS:\n";
    BFS(graph, 1);
    return 0;
}

// ----------------------- Câu b ------------------------
// Độ phức tạp thời gian của thuật toán BFS được biểu diễn 
// dưới dạng O (V + E), trong đó V là số nút và E là số cạnh.
// 
// Độ phức tạp không gian của thuật toán là O (V)
// 
// // V = 5, E = 6