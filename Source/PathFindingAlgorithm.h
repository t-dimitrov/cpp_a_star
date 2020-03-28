#ifndef PATHFINDINGALGORITHM_H_INCLUDED
#define PATHFINDINGALGORITHM_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm>

#include "Grid.h"
#include "Node.h"

class PathFinder
{
private:
    Grid* grid;
    Node* startNode;
    Node* endNode;

public:
    PathFinder(Grid* _grid, Node* _start, Node* _target)
    : grid(_grid), startNode(_start), endNode(_target) {}

    void setup(Grid* _grid, Node* _start, Node* _target);

    Node* findPath();
    int heuristics(Node* a, Node* b);

};

#endif // PATHFINDINGALGORITHM_H_INCLUDED
