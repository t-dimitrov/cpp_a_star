#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

enum class State
{
    Walkable,
    Wall,
    Path,
    OpenSet,
    ClosedSet
};

class Node
{
public:
    bool walkable;
    sf::Vector2f position;
    sf::RectangleShape shape;
    Node* parent;
    std::vector<Node*> neighbours;

    int gCost;
    int hCost;
    int fCost() { return gCost + hCost; }

    int heapIndex;

public:
    Node(sf::Vector2f _position);

    void setState(State state);
};

#endif // NODE_H_INCLUDED
