#include <bits/stdc++.h>
using namespace std;

void printSolution(int path[]);

// Hàm kiểm tra nếu đỉnh v có thể được thêm vào vị trí 'pos'
bool isSafe(int v, bool graph[][100], int path[], int pos)
{
    // Kiểm tra nếu đỉnh này là đỉnh kề của đỉnh vừa được thêm vào
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Kiểm tra nếu đỉnh đã được đưa vào đường đi trước đó
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Hàm đệ quy để giải bài toán chu trình Hamilton
bool hamCycleUtil(bool graph[][100], int path[], int pos, int V)
{
    // Trường hợp cơ sở: Nếu tất cả các đỉnh đã được đưa vào chu trình
    if (pos == V)
    {
        // Kiểm tra nếu có cạnh nối từ đỉnh cuối cùng đến đỉnh đầu tiên
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;

    }

    // Thử các đỉnh khác làm ứng viên tiếp theo trong chu trình Hamilton
    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            // Đệ quy để xây dựng phần còn lại của đường đi
            if (hamCycleUtil(graph, path, pos + 1, V) == true)
                return true;

            // Nếu việc thêm đỉnh v không dẫn đến giải pháp, loại bỏ đỉnh đó
            path[pos] = -1;
        }
    }

    return false;
}

// Hàm giải bài toán chu trình Hamilton
bool hamCycle(bool graph[][100], int V)
{
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;
    if (hamCycleUtil(graph, path, 1, V) == false)
    {
        cout << "\nSolution does not exist";
        return false;
    }

    printSolution(path);
    return true;
}

// Hàm in ra giải pháp
void printSolution(int path[])
{
    cout << "Solution Exists: Following is one Hamiltonian Cycle \n";
    for (int i = 0; i < 5; i++)
        cout << path[i] << " ";

    cout << path[0] << " ";
    cout << endl;
}

int main()
{
    int V, E;

    // Nhập số đỉnh và số cạnh
    cout << "Nhập số đỉnh (V): ";
    cin >> V;
    cout << "Nhập số cạnh (E): ";
    cin >> E;

    bool graph[100][100] = {0};

    cout << "Nhập các cạnh (u, v) với u, v là các đỉnh có sẵn trong đồ thị:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cout << "Cạnh thứ " << i + 1 << ": ";
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // Vì đồ thị vô hướng
    }

    // Gọi hàm giải chu trình Hamilton
    hamCycle(graph, V);

    return 0;
}
