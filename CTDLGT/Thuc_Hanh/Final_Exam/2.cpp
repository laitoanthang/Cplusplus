#include <iostream>
#define INF 99999
#define V 5

using namespace std;

int P[V][V]; //Ma trận lưu các đỉnh liên kết ở trước
int D[V][V]; //Ma trận lưu khoảng cách ngắn nhất giữa các đỉnh

void initializeGraph(int graph[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }
}
void add_edge(int graph[][V], int src, int dest, int weight)
{
    graph[src][dest] = weight;
}

void getPath(int graph[][V], int a, int b) {
    if (P[a][b] == b) {
        cout << b << " ";
        return;
    }
    if (D[a][b] == INF)
    {
        cout << "Khong ton tai" << endl;
        return;
    }
    getPath(graph, a, P[a][b]);
    cout << b << " ";
}

/*void printSolution(int graph[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << "from " << i << " to " << j << " : ";
            if (D[i][j] == INF) {
                cout << "-" << endl;
                continue;
            }
            else {
                cout << D[i][j] << endl;
                getPath(graph, i, j);
                cout << endl;
            }
        }
        cout << endl;
    }
}*/

void floydWarshall(int graph[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            D[i][j] = graph[i][j];
            P[i][j] = i;
        }
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
            }
        }
    }
}

void printGraph(int graph[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] == INF)
                cout << "oo ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int graph[V][V];
    int start, end;
    initializeGraph(graph);

    add_edge(graph, 0, 1, 4);
    add_edge(graph, 0, 2, 9);
    add_edge(graph, 1, 2, 2);
    add_edge(graph, 1, 4, 8);
    add_edge(graph, 2, 3, 2);
    add_edge(graph, 3, 4, 3);

    printGraph(graph);
    floydWarshall(graph);
    cout << "Nhap dinh bat dau va ket thuc de tim duong di ngan nhat: ";
    cin >> start >> end;
    cout << "Duong di ngan nhat tu dinh " << start << " den dinh " << end << ": ";
    getPath(graph, start, end);
    return 0;
}
