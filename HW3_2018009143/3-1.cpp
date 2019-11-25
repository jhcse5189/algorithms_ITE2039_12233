#include <iostream>
#include <fstream>
#include <string>
#include <list>

/* color */
#define WHITE 0
#define GRAY 1
#define BLACK 2

/* classification of edges */
#define TREE 0
#define BACK 1
#define FORWARD 2
#define CROSS 3

/* global variable for timestamps */
int tick;

/* Depth-first search */
class Graph {

/* Vertex struct */
struct Vertex {
    int n;
    int color;
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
    void MakeAdj(int i, int j);
};

Graph::Graph(int v) {
    this->V = v;
    nodes = new Graph::Vertex[v + 1];
    adj = new std::list<int>[v + 1];

    // initialize all vertices from graph
    for (int i = 1; i <= v; i++) {
        nodes[i].n = i;
        nodes[i].color = WHITE;
    }

    // start time from 0
    tick = 0;
}

void Graph::DFS() {
    // if V == WHITE -> DFS_VISIT(G, u);
    for (int i = 1; i <= V; i++) {
        if (nodes[i].color == WHITE) {
            DFS_VISIT(i);
        }
    }
}

void Graph::DFS_VISIT(int u) {

    // WHITE vertex u has just been discovered
    tick++;
    nodes[u].d = tick;
    nodes[u].color = GRAY;

    // explore edge (u, v)
    std::list<int>::iterator v;
    for (v = adj[u].begin(); v != adj[u].end(); v++) {
        if (nodes[*v].color == WHITE) {
            printf("(%d, %d) tree edge\n", u, *v);
            DFS_VISIT(*v);
        } else if (u >= *v) {
            printf("(%d, %d) back edge\n", u, *v);
        } else if (u == 1) {
            printf("(%d, %d) forward edge\n", u, *v);
        } else /* (u < *v) */ {
            printf("(%d, %d) cross edge\n", u, *v);
        }
    }

    // blacken u; it is finished
    nodes[u].color = BLACK;
    tick++;
    nodes[u].f = tick;
}

void Graph::PrintResult(int v) {

    int i, j, key;
    Graph::Vertex node;
    Graph::Vertex* tmp = new Graph::Vertex[v + 1];
    tmp = nodes;

    // p = 1, r = v?
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
void insertion_sort(int* a, int p, int r) {

    int key, i, j;
    for (j = p + 1; j <= r; j++) {

        key = a[j];
        i = j - 1;
        while (a[i] > key && i >= p) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}

void Graph::MakeAdj(int i, int j) {
    adj[i].push_back(j);
}


int main(int argc, char* argv[]) {

    int v, i, j, input;
    std::string inpath = "input3-1.txt";


    // read data from file I/O
    std::fstream inf(inpath);

    // read node #
    inf >> v;
    // construct graph
    Graph g(v);

    for (i = 1; i <= v; i++) {
        j = 1;
        while (j <= v && inf >> input) {
            if (input == 1) {
                g.MakeAdj(i, j);
            }
            j++;
        }
    }

    // DFS
    g.DFS();

    // Print DFS result
    g.PrintResult(v);

    return 0;
}
