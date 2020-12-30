#include "build-order.h"


#include <iostream>
#include <stdbool.h>
#include <list>
#include <set>

using namespace std;

/** Vists nodes and marks them. */
void visit(int process, int **processes, int rows, int cols,
           set<int> &temp_marked_nodes,
           set<int> &perm_marked_nodes,
           list<int> &order)
{
    if (temp_marked_nodes.find(process) != temp_marked_nodes.end()) {
        cout << "ERROR: Cycle in the dependency list. Exiting...\n";
        exit(-1);
    }

    /* Temp mark a non-marked node and visits its dependencies */
    if (perm_marked_nodes.find(process) == perm_marked_nodes.end()) {
        temp_marked_nodes.insert(process);
        for (int i = 0; i < cols; i++) {
            int p = processes[process][i];
            if (p != -1) visit(p, processes, rows, cols,
                               temp_marked_nodes,
                               perm_marked_nodes,
                               order);
        }
        perm_marked_nodes.insert(process);
        temp_marked_nodes.erase(process);
        order.push_back(process);
    }
}

list<int> build_order(int **processes, int rows, int cols)
{
    set<int> temp_marked_nodes;
    set<int> perm_marked_nodes;
    list<int> order;

    for (int i = 0; i < rows; i++) {
        visit(i, processes, rows, cols,
              temp_marked_nodes,
              perm_marked_nodes,
              order);
    }

    return order;
}
