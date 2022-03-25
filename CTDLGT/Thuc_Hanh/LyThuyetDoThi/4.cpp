// Lai Toan Thang
// MSSV: 20280083

#include <iostream>
#include <vector>

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

bool isPath(Graph* graph, int start_vertex, int end_vertex, vector<int>& path)
{
    graph->traversed[start_vertex] = 1;
    path.push_back(start_vertex);
    if (start_vertex == end_vertex)
        return true;
    for (Node* p = graph->adjList[start_vertex]; p != NULL; p = p->next)
    {
        int adjVertex = p->data;
        if (graph->traversed[adjVertex] == 0)
        {
            if (isPath(graph, adjVertex, end_vertex, path))
                return true;
        }
    }
    path.pop_back();
    return false;
}

void printPath(vector<int> const& path)
{
    for (int i = 0; i < path.size() - 1; i++)
    {
        cout << path[i] <<" -> ";
    }
    cout << path[path.size() - 1] << endl;
}

int main() {
    int v = 5;
    int start_vertex, end_vertex;
    vector<int> path;
    Graph* graph = create_graph(v);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    cout << "Danh sach ke cua do thi:\n";
    printAdjList(graph, v);
    cout << "\nNhap dinh bat dau va ket thuc de tim duong di\n";
    cout << "Dinh bat dau = ";
    cin >> start_vertex;
    cout << "Dinh ket thuc = ";
    cin >> end_vertex;
    if (isPath(graph, start_vertex, end_vertex, path))
    {
        cout << "Ton tai duong di tu dinh "<<start_vertex<<" den dinh "<<end_vertex<<"\n";
        cout << "Duong di la: ";
        printPath(path);
    }
    else
        cout << "Khong ton tai duong di tu dinh " << start_vertex << " den dinh " << end_vertex << "\n";
    return 0;
}