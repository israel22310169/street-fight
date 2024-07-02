#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Ryu.hpp>
#include <Ken.hpp>
#include <MedidorDeVitalidad.hpp>

double velocidad = 0.1;
int damageAmount = 10;

int main()
{
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Street Fighter");

    Ryu ryu(sf::Vector2f(200, 400), sf::Color::Red);
    Ken ken(sf::Vector2f(600, 400), sf::Color::Blue);

    MedidorDeVitalidad medidorRyu(200, 20, sf::Color::Red, sf::Color::Black);
    medidorRyu.setPosition(50, 50);

    MedidorDeVitalidad medidorKen(200, 20, sf::Color::Blue, sf::Color::Black);
    medidorKen.setPosition(550, 50);

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

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }

            
            if (evento.type == sf::Event::KeyPressed) {
                if (evento.key.code == sf::Keyboard::R) {
                    ken.receiveDamage(damageAmount);
                }
                if (evento.key.code == sf::Keyboard::K) {
                    ryu.receiveDamage(damageAmount);
                }
            }
        }

        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            ryu.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            ryu.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            ryu.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            ryu.move(0, velocidad);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            ken.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            ken.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            ken.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            ken.move(0, velocidad);
        }

        ryu.update(); // Actualizar estado de Ryu
        ken.update(); // Actualizar estado de Ken

        // Actualizar los medidores de vitalidad
        medidorRyu.setCurrentValue(ryu.getHealth(), 100); // salud máxima es 100
        medidorKen.setCurrentValue(ken.getHealth(), 100); 

        ventana.clear();
        
        ventana.draw(sprite);
        ryu.draw(ventana);
        ken.draw(ventana);
        medidorRyu.draw(ventana);
        medidorKen.draw(ventana);
        ventana.display();
    }

    return 0;
}