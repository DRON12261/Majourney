#include "GameState.h"

void GameState::initKeybinds()
{
    std::ifstream ifs("Config/gameStateKeybinds.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        std::string keyValue = "";

        while(ifs >> key >> keyValue)
        {
            this->keybinds[key] = this->supportedKeys->at(keyValue);
        }
    }

    ifs.close();
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) : State(window, supportedKeys, states)
{
    this->initKeybinds();
}

GameState::~GameState()
{

}

//Functions
void GameState::endState()
{
    std::cout << "Ending GameState!\n";
}

void GameState::updateKeybinds(const float& dt)
{
    this->checkForQuit();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
    {
        this->player.move(dt, -1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
    {
        this->player.move(dt, 1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
    {
        this->player.move(dt, 0.f, -1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
    {
        this->player.move(dt, 0.f, 1.f);
    }
}

void GameState::update(const float& dt)
{
    this->updateMousePositions();
    this->updateKeybinds(dt);

    this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
    if (!target)
    {
        target = this->window;
    }

    this->player.render(target);
}
