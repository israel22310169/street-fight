#include <SFML/Graphics.hpp>

class Ryu
{
public:
    Ryu(sf::Vector2f position, sf::Color color)
        : health(100) // Inicializa la salud de Ryu
    {
        shape.setSize(sf::Vector2f(50, 50));
        shape.setPosition(position); // Posición inicial cuadro
        shape.setFillColor(color);

        // Cargar la imagen desde un archivo
        sf::Image imagenBase;
        if (!imagenBase.loadFromFile("./assets/images/ryu.png"))
        {
            // Manejar el error
        }
        imagenBase.createMaskFromColor(sf::Color(0, 0, 0));
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
            sprite.setTextureRect(sf::IntRect((currentFrame * 70) + 1, 0, 56, 100));
            clock.restart();
        }
    }

    void receiveDamage(int amount)
    {
        health -= amount;
        if (health < 0)
        {
            health = 0;
        }
    }

    int getHealth() const
    {
        return health;
    }

private:
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.1f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 4; // Número total de frames en la animación
    int frameWidth = 32;
    int frameHeight = 32;
    int health; // Atributo para la salud de Ryu
};