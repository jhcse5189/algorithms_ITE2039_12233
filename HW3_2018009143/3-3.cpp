#include <iostream>
#include <cstdlib>
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

/* global variable for timestamps & check whether given is DAG */
int tick;
int isDag = 1;
std::list<int>* tsort;

/* Depth-First Search (For. topological sort) */
class Graph {

/* Vertex struct */
struct Vertex {
    int n;
    int color;
    int d;
    int f;
    int isStacked;
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
        nodes[i].isStacked = 0;
    }

    // start time from 0
    tick = 0;

    // 
    tsort = new std::list<int>[v + 1];
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
            /* tree edge */
            DFS_VISIT(*v);
        } else if (u >= *v && abs(*v - u) != 1) {
            //std::cout << "(" << u << ", " << *v << ") back edge" << std::endl;
            isDag = 0;
        }
    }

    // blacken u; it is finished
    nodes[u].color = BLACK;
    tick++;
    nodes[u].f = tick;

    // Push node to stack
    //Push(u);
    
    if (nodes[u].isStacked == 0) {
        //std::cout << "push " << u << std::endl;
        tsort->push_front(u);
        nodes[u].isStacked = 1;
    }
}

void Graph::PrintResult(int v) {

    std::cout << isDag << std::endl;
    if (isDag == 0) {
        return;
    }

    std::list<int>::iterator i;
    for (i = tsort->begin(); i != tsort->end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

void Graph::MakeAdj(int i, int j) {
    adj[i].push_back(j);
}



int main(int argc, char* argv[]) {

    int v, i, j, input;
    std::string inpath = "input3-3.txt";


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
