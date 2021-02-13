#include "MainMenuState.h"

void MainMenuState::initFonts()
{
    if(!this->font.loadFromFile("Fonts/MainMenuFont.ttf"))
    {
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }
}

void MainMenuState::initKeybinds()
{
    std::ifstream ifs("Config/mainMenuStateKeybinds.ini");

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

void MainMenuState::initButtons()
{
    this->buttons["GAME_STATE"] = new Button(100, 100, 150, 50, &this->font, "New Game",
                                       sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));

    this->buttons["EXIT"] = new Button(100, 200, 150, 50, &this->font, "Exit Game",
                                       sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) : State(window, supportedKeys, states)
{
    this->initFonts();
    this->initKeybinds();
    this->initButtons();

    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
    for (auto i = this->buttons.begin(); i != this->buttons.end(); ++i)
    {
        delete i->second;
    }
}

//Functions
void MainMenuState::endState()
{
    std::cout << "Ending MainMenuState!\n";
}

void MainMenuState::updateKeybinds(const float& dt)
{
    this->checkForQuit();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {

    }
}

void MainMenuState::updateButtons()
{
    for (auto &i : this->buttons)
    {
        i.second->update(this->mousePosView);
    }

    if (this->buttons["GAME_STATE"]->isPressed())
    {
        this->states->push(new GameState(this->window, this->supportedKeys, this->states));
    }

    if (this->buttons["EXIT"]->isPressed())
    {
        this->quit = true;
    }
}

void MainMenuState::update(const float& dt)
{
    this->updateMousePositions();
    this->updateKeybinds(dt);
    this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
    for (auto &i : this->buttons)
    {
        i.second->render(target);
    }
}

void MainMenuState::render(sf::RenderTarget* target)
{
    if (!target)
    {
        target = this->window;
    }

    target->draw(this->background);

    this->renderButtons(target);
}
