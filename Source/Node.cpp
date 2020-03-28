#include "Node.h"

Node::Node(sf::Vector2f newPos)
{
    position = newPos;
    shape.setSize(sf::Vector2f(1, 1));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(position);
    gCost = INFINITY;
    hCost = INFINITY;
    heapIndex = -1;
}

void Node::setState(State state)
{
    switch(state)
    {
        case State::Walkable:
            walkable = true;
            shape.setFillColor(sf::Color::Green);
            break;

        case State::Wall:
            walkable = false;
            shape.setFillColor(sf::Color::Black);
            break;

        case State::Path:
            shape.setFillColor(sf::Color::Blue);
            break;

        case State::OpenSet:
            shape.setFillColor(sf::Color::Cyan);
            break;

        case State::ClosedSet:
            shape.setFillColor(sf::Color::Red);
            break;

        default:
            break;
    }
}
