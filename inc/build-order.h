#ifndef BUILD_ORDER_H
#define BUILD_ORDER_H


#include <iostream>
#include <stdbool.h>
#include <list>


/**
 * Topologically sorts a dependency graph.
 *
 * @param processes the dependency graph
 */
std::list<int> build_order(int **processes, int rows, int cols);


#endif      // BUILD_ORDER_H
