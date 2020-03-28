#include "Application.h"

namespace
{
    int GetIndex(int x, int y, int width)
    {
        return y * width + x;
    }
}

void Application::run_algorithm()
{
    grid->setup(1000, 1000);

    int indexStart = GetIndex(0, 0, 1000);
    int indexEnd = GetIndex(999, 999, 1000);
    Node* startingNode = grid->grid[indexStart];
    Node* endingNode = grid->grid[indexEnd];

    PathFinder finder(grid, startingNode, endingNode);

    path_found = finder.findPath();

    if(path_found == nullptr)
        run_algorithm();
    else
    {
        while(path_found->parent != NULL)
        {
            path_found->setState(State::Path);
            path_found = path_found->parent;
        }
    }
}

Application::Application()
:   _window ({WIDTH, HEIGHT}, "A*")
,   _view   (sf::Vector2f(WIDTH/2 - WIDTH/2 + 500, HEIGHT/2 - HEIGHT/2 + 500), sf::Vector2f(WIDTH, HEIGHT))
{
    std::cout << "Press 'R' to re-run the algorithm!\n\n";
    _window.setFramerateLimit(60);
    _window.setView(_view);

    grid->setup(1000, 1000);

    int indexStart = GetIndex(0, 0, 1000);
    int indexEnd = GetIndex(999, 999, 1000);
    Node* startingNode = grid->grid[indexStart];
    Node* endingNode = grid->grid[indexEnd];

    PathFinder finder(grid, startingNode, endingNode);

    path_found = finder.findPath();

    if(path_found == nullptr)
        run_algorithm();
    else
    {
        while(path_found->parent != NULL)
        {
            path_found->setState(State::Path);
            path_found = path_found->parent;
        }
    }
}

void Application::run()
{
    //Clear -> update -> draw -> display -> poll events
    while(_window.isOpen())
    {
        _window.clear(sf::Color::Black);
        update();
        //_window.draw();
        _window.display();
        pollEvents();
    }
}

void Application::pollEvents()
{
    sf::Event e;
    while(_window.pollEvent(e))
    {
        if(e.type == sf::Event::Closed)
        {
            _window.close();
        }
        if(e.type == sf::Event::KeyPressed)
        {
            if(e.key.code == sf::Keyboard::R)
                run_algorithm();
        }
    }
}

void Application::update()
{
    grid->drawGrid(_window);

    /*
    if(path_found != nullptr)
    {
        if(clock.getElapsedTime().asSeconds() > time_threshhold){
            startNode->setState(State::Path);
            if(path_found->parent != NULL)
            {
                path_found->setState(State::Path);
                path_found = path_found->parent;
            }

            time_threshhold = clock.getElapsedTime().asSeconds() + 0.0001f;
        }
    }
    */
}
