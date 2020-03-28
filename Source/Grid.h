#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include <iostream>
#include <vector>

#include "Node.h"
#include <random>

namespace
{
    int getIndex(int x, int y, int width)
    {
        return y * width + x;
    }
}

class Grid
{
private:
    int cols, rows;

public:
    Grid();
    void setup(int cols, int rows);
    std::vector<Node*> getNeighbors(Node* node);
    void drawGrid(sf::RenderWindow &window);

    std::vector<Node*> grid;

    int maxSize() { return cols * rows; }
};

#endif // GRID_H_INCLUDED
