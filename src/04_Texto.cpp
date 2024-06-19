#include <SFML/Graphics.hpp>

int main()
{
    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Texto");

    // Cargar la fuente de texto TTF
    sf::Font font;
    if (!font.loadFromFile("./assets/fonts/Sf.ttf"))
    {
        // Manejar el error si no se puede cargar la fuente
        return -1;
    }

    // Cargar una fuente de texto
    sf::Font font2;
    if (!font2.loadFromFile("./assets/fonts/Sf.ttf"))
    {
        // Manejar el error si no se puede cargar la fuente
        return -1;
    }

    // Crear un objeto de texto
    sf::Text text;
    text.setFont(font);
    text.setString("(Chulo de Bad Gyal Playing)");
    text.setCharacterSize(10);
    text.setFillColor(sf::Color::White);

    // Crear un objeto de texto LOTR
    sf::Text text2;
    text2.setFont(font2);
    text2.setString("STREET FIGHTER!");
    text2.setCharacterSize(50);
    text2.setPosition(200, 100);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(text);
        window.draw(text2);
        window.display();
    }

    return 0;
}
