#include "PathFindingAlgorithm.h"
#include <chrono>

#include "MinHeap.h"

class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_timepoint;

public:
    Timer()
    {
        start_timepoint = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        Stop();
    }

    void Stop()
    {
        auto end_timepoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_timepoint).time_since_epoch().count();
        auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(end_timepoint).time_since_epoch().count();

        auto duration = stop - start;

        double ms = duration * 0.001;

        std::cout << ms << " ms\n";
    }
};

void PathFinder::setup(Grid* _grid, Node* _start, Node* _target)
{
    grid = _grid;
    startNode = _start;
    endNode = _target;

    startNode->gCost = 0;
}

Node* PathFinder::findPath()
{
    Timer timer; // Benchmarking
    Heap openSet(grid->maxSize());
    Heap closedSet(grid->maxSize());

    openSet.add(startNode);

    while(openSet.count() > 0)
    {
        /*
        //Find node with lowest F Cost
        int tempF = INFINITY;
        int lowestF_index = 0;
        for(int i = 0; i < openSet.size(); i++)
        {
            if(openSet[i]->fCost() <  tempF)
            {
                tempF = openSet[i]->fCost();
                lowestF_index = i;
            }
        }
        Node* current = openSet[lowestF_index];
        //------

        //Find current node in open set and remove it
        for(int i = 0; i < openSet.size(); i++)
        {
            if(openSet[i] == current)
            {
                openSet.erase(openSet.begin() + i);
                closedSet.add(current);
            }
        }
        //------
        */
        Node* current = openSet.removeFirst();
        closedSet.add(current);


        if(current == endNode)
        {
            std::cout << "Path Found!\n";

            return current;
        }


        std::vector<Node*> neighbours = current->neighbours;
        for(int i = 0; i < neighbours.size(); i++)
        {
            //bool isInClosed = (std::find(closedSet.begin(), closedSet.end(), neighbours[i]) != closedSet.end());
            //bool isInOpen = (std::find(openSet.begin(), openSet.end(), neighbours[i]) != openSet.end());

            heuristics(current, neighbours[i]);

            int tentative_gScore = current->gCost + heuristics(current, neighbours[i]);

            if(tentative_gScore < neighbours[i]->gCost)
            {
                if(!closedSet.contains(neighbours[i]))
                {
                    neighbours[i]->parent = current;
                    neighbours[i]->gCost = tentative_gScore;

                    if(!openSet.contains(neighbours[i]))
                    {
                        openSet.add(neighbours[i]);
                    }
                }
            }

        }

    }

    std::cout << "PATH NOT FOUND!" << std::endl;
    return nullptr;
}

int PathFinder::heuristics(Node* nodeA, Node* nodeB)
{
    int dstX = abs(nodeB->position.x - nodeA->position.x);
    int dstY = abs(nodeB->position.y - nodeA->position.y);

    return dstX + dstY;
}



