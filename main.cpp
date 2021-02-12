#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Majourney");
    sf::Texture texture;
    if (!texture.loadFromFile("Sprites\\Char.png", sf::IntRect(0, 0, 32, 32))){
        window.setTitle("ERROR");
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(2.f, 2.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
