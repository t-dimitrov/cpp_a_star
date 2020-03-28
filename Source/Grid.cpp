#include "Grid.h"

Grid::Grid()
{ }

void Grid::setup(int cols, int rows)
{
    this->cols = cols;
    this->rows = rows;

    grid = std::vector<Node*>(rows * cols);

    static std::minstd_rand randDevice(std::time(nullptr));
    std::uniform_int_distribution<int> dist(0, 100);

    for(int y = 0; y < rows; y++)
    {
        for(int x = 0; x < cols; x++)
        {
            int index = getIndex(x, y, cols);
            grid[index] = new Node(sf::Vector2f(x, y));

            int rand = dist(randDevice);
            if(rand <= 65)
                grid[index]->setState(State::Walkable);
            else
                grid[index]->setState(State::Wall);

            if(x == 0 && y == 0)
                grid[index]->setState(State::Walkable);
            if(x == rows - 1 && y == cols - 1)
                grid[index]->setState(State::Walkable);

            //grid[index]->neighbours = getNeighbors(grid[index]);
        }
    }

    for(int y = 0; y < rows; y++)
    {
        for(int x = 0; x < cols; x++)
        {
            int index = getIndex(x, y, cols);
            grid[index]->neighbours = getNeighbors(grid[index]);
        }
    }
}

std::vector<Node*> Grid::getNeighbors(Node* node)
{
    std::vector<Node*> neighbors;

    for(int y = -1; y <= 1; y++)
    {
        for(int x = -1; x <= 1; x++)
        {
            if(x == 0 && y == 0)
                continue;

            if(x == 0 || y == 0)
            {

                int checkX = node->position.x + x;
                int checkY = node->position.y + y;

                if(checkX >= 0 && checkX < cols && checkY >= 0 && checkY < rows)
                {
                    int index = getIndex(checkX, checkY, cols);
                    if(grid[index]->walkable)
                        neighbors.push_back(grid[index]);
                }

            }
        }
    }

    return neighbors;
}

void Grid::drawGrid(sf::RenderWindow &window)
{
    for(size_t i = 0; i < grid.size(); i++)
        window.draw(grid[i]->shape);
}
