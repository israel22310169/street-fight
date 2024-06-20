#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Ryu.hpp>
#include <Ken.hpp>


double velocidad = 0.1;

int main()
{
    sf::Texture texture;
    if (!texture.loadFromFile("./assets/images/fondo.png"))
    {
        // Manejar el error si no se puede cargar la imagen
        return -1;
    }
    // Crear un sprite y asignarle la textura
    sf::Sprite sprite(texture);

    sf::Music music;
    if (!music.openFromFile("./assets/music/sF.ogg"))
    {
        // Error al cargar el archivo de música
        return -1;
    }

    // Reproducir la música
    music.play();

    // Cargar una fuente de texto
    sf::Font font2;
    if (!font2.loadFromFile("./assets/fonts/Sf.ttf"))
    {
        // Manejar el error si no se puede cargar la fuente
        return -1;
    }
    // Crear un objeto de texto LOTR
    sf::Text text2;
    text2.setFont(font2);
    text2.setString("STREET FIGHTER!");
    text2.setCharacterSize(90);
    text2.setPosition(100, 80);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Street Fighter");

    Ryu ryu(sf::Vector2f(200, 400), sf::Color::Red);
    Ken ken(sf::Vector2f(600, 400), sf::Color::Red);

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            ryu.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            ryu.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            ryu.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            ryu.move(0, velocidad);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            ken.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            ken.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            ken.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            ken.move(0, velocidad);
        }
          // Crear barras de vida para Ryu y Ken
    HealthBar ryuHealthBar(200, 20, sf::Color::Red, sf::Color::Black);
    ryuHealthBar.setPosition(50, 50);

    HealthBar kenHealthBar(200, 20, sf::Color::Blue, sf::Color::Black);
    kenHealthBar.setPosition(550, 50);

    while (window.isOpen()) {
      
        // Actualizar la posición y valor de la barra de vida para Ryu y Ken
        ryuHealthBar.setCurrentValue(ryu.getHealth());
        kenHealthBar.setCurrentValue(ken.getHealth());

        window.clear();
        window.draw(sprite);
        ryu.draw(window);
        ken.draw(window);
        ryuHealthBar.draw(window);
        kenHealthBar.draw(window);
        window.draw(text2);
        window.display();
    
     // Crear barras de vida para Ryu y Ken
    HealthBar ryuHealthBar(200, 20, sf::Color::Red, sf::Color::Black);
    ryuHealthBar.setPosition(50, 50);

    HealthBar kenHealthBar(200, 20, sf::Color::Blue, sf::Color::Black);
    kenHealthBar.setPosition(550, 50);

    while (window.isOpen()) {
        // Código anterior...

        // Actualizar la posición y valor de la barra de vida para Ryu y Ken
        ryuHealthBar.setCurrentValue(ryu.getHealth());
        kenHealthBar.setCurrentValue(ken.getHealth());

        window.clear();
        window.draw(sprite);
        ryu.draw(window);
        ken.draw(window);
        ryuHealthBar.draw(window);
        kenHealthBar.draw(window);
        window.draw(text2);
        window.display();

       
    }
        // Actualizar animacion pikachu
        ryu.update();
        ken.update();

        window.clear();
        window.draw(sprite);
        ryu.draw(window);
        ken.draw(window);
        window.draw(text2);
        window.display();

        if (music.getStatus() != sf::Music::Playing)
        {
            window.close();
        }
    }

    return 0;
}