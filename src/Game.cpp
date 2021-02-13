#include "Game.h"

//Static functions

//Initializer functions
void Game::initWindow()
{
    std::ifstream ifs("Config/window.ini");

    std::string title = "None";
    sf::VideoMode windowBounds(1280, 720);
    unsigned framerateLimit = 120;
    bool vertSyncEnabled = false;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> windowBounds.width >> windowBounds.height;
        ifs >> framerateLimit;
        ifs >> vertSyncEnabled;
    }

    ifs.close();

    this->window = new sf::RenderWindow(windowBounds, title);
    this->window->setFramerateLimit(framerateLimit);
    this->window->setVerticalSyncEnabled(vertSyncEnabled);
}

void Game::initKeys()
{
    std::ifstream ifs("Config/supportedKeys.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        int keyValue = 0;

        while(ifs >> key >> keyValue)
        {
            this->supportedKeys[key] = keyValue;
        }
    }

    ifs.close();

    //DEBUG
    for (auto i : this->supportedKeys)
    {
        std::cout << i.first << " " << i.second << "\n";
    }
}

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
}
//Constructor/destructor
Game::Game()
{
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game()
{
    delete this->window;

    while(!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

//Functions
void Game::endApplication()
{
    std::cout << "Ending Application!\n";
}

void Game::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();

    //system("cls");
    //std::cout << this->dt << "\n";
}

void Game::updateSFMLEvents()
{
    while(this->window->pollEvent(this->sfEvent))
    {
        if(this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    //Application end
    else
    {
        this->endApplication();
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();

    //Render things
    if (!this->states.empty())
    {
        this->states.top()->render(this->window);
    }

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}
