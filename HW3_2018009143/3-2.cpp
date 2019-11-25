#include <iostream>
#include <fstream>
#include <string>
#include <list>

/* color */
#define WHITE 0
#define GRAY 1
#define BLACK 2

/* global variable for timestamps */
int tick;

/* Depth-First Search (Undirected) */
class Graph {

/* Vertex struct */
struct Vertex {
    int n;
    int color;
    int component;
    int d;
    int f;
};

    int V;
    Graph::Vertex* nodes;
    std::list<int>* adj;
public:
    Graph(int v);
    void DFS();
    void DFS_VISIT(int u);
    void PrintResult(int v);
    void PrintComponents(int v);
    void MakeAdj(int i, int j);
};

Graph::Graph(int v) {
    this->V = v;
    nodes = new Graph::Vertex[v + 1];
    adj = new std::list<int>[v + 1];

    for (int i = 1; i <= v; i++) {
        nodes[i].n = i;
        nodes[i].color = WHITE;
    }

    // start time from 0
    tick = 0;
}

void Graph::DFS() {

    int i, j;
    for (i = 1, j = 1; i <= V; i++) {
        if (nodes[i].color == WHITE) {
            nodes[i].component = j;
            DFS_VISIT(i);
            j++;
        }
    }
}

void Graph::DFS_VISIT(int u) {

    //std::cout << "(" << u << ")" << std::endl;
    tick++;
    nodes[u].d = tick;
    nodes[u].color = GRAY;

    std::list<int>::iterator v;
    for (v = adj[u].begin(); v != adj[u].end(); v++) {
        if (nodes[*v].color == WHITE) {
            nodes[*v].component = nodes[u].component;
            //std::cout << u << "&" << *v << " share the component " << nodes[u].component << std::endl;
            DFS_VISIT(*v);
        }
    }

    nodes[u].color = BLACK;
    tick++;
    nodes[u].f = tick;
}

void Graph::PrintResult(int v) {

    int i, j, key;
    Graph::Vertex node;
    Graph::Vertex* tmp = new Graph::Vertex[v + 1];

    for (i = 1; i <= v; i++) {
        tmp[i].n = nodes[i].n;
        tmp[i].d = nodes[i].d;
    }
    //tmp = nodes;

    for (j = 2; j <= v; j++) {

        node = tmp[j];
        key = tmp[j].d;
        i = j - 1;
        while (tmp[i].d > key && i >= 1) {
            tmp[i + 1] = tmp[i];
            i--;
        }
        tmp[i + 1] = node;
    }

    for (i = 1; i <= v; i++) {
        std::cout << tmp[i].n << " ";
    }
    std::cout << std::endl;

    delete[] tmp;
}

void Graph::PrintComponents(int v) {

    int i;
    for (i = 1; i <= v; i++) {
        std::cout << i << ": " << nodes[i].component << std::endl;
    }
}

void Graph::MakeAdj(int i, int j) {
    adj[i].push_back(j);
}



int main(int argc, char* argv[]) {

    int v, i, j, count, input;
    std::string inpath = "input3-2.txt";

    // read data from file I/O
    std::fstream inf(inpath);

    // read node #
    inf >> v;
    // construct graph
    Graph g(v);

    for (i = 1; i <= v; i++) {
        j = 1;
        count = 0;
        while (j <= v && inf >> input) {
            count++;
            if (count > i && input == 1) {
                g.MakeAdj(i, j);
                //std::cout << "(" << i << ", " << j << ")" << std::endl;
            }
            j++;
        }
    }

    // DFS
    g.DFS();

    // Print DFS result
    g.PrintResult(v);

    g.PrintComponents(v);

    return 0;
}