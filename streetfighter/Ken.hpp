#include <SFML/Graphics.hpp>

class Ken
{
public:
    Ken(sf::Vector2f position, sf::Color color)
    {
        shape.setSize(sf::Vector2f(50, 50));
        shape.setPosition(position); // Posición inicial cuadro
        shape.setFillColor(color);



        // Cargar la imagen desde un archivo

        sf::Image imagenBase;
        if (!imagenBase.loadFromFile("./assets/images/ken2.0.png"))
        {
            
        }
        imagenBase.createMaskFromColor(sf::Color(0,0,160));

        texture.loadFromImage(imagenBase);


        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
    }

    void move(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
        shape.move(offsetX, offsetY);
    }

    void draw(sf::RenderWindow &window)
    {
        //window.draw(this->shape);
        window.draw(this->sprite);
    }

    void update()
    {
        // Actualizar el frame de la animación
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 70) + 1483, 680, 53, 100));
            clock.restart();
        }
    }

private:
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.1f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 9; // Número total de frames en la animación
    int frameWidth = 32;
    int frameHeight = 32;
};
