#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "PathFindingAlgorithm.h"

constexpr int WIDTH = 1000, HEIGHT = 1000;

class Application
{
    private:
        void pollEvents();
        void update();
        sf::RenderWindow _window;
        sf::View _view;

        float time_threshhold = clock.getElapsedTime().asSeconds() + 2;

        void run_algorithm();

    public:
        Application();

        void run();

    public:
        Grid* grid;

        Node* path_found = nullptr;
        sf::Clock clock;
};

#endif // APPLICATION_H_INCLUDED
