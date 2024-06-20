class Ken
{
public:

    Ken(sf::Vector2f position, sf::Color color)
    {
        shape.setSize(sf::Vector2f(50, 50));
        shape.setPosition(position); // Posición inicial cuadro
        shape.setFillColor(color);

        // Cargar la imagen desde un archivo
        
        if (!texture.loadFromFile("./assets/images/ken2.0.png"))
        {
        
        }
        
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
        window.draw(this->shape);
        window.draw(this->sprite);
    }

    void update(){
        // Actualizar el frame de la animación
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 70) + 1208, 680, 53, 100));
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
    int numFrames = 11; // Número total de frames en la animación
    int frameWidth = 32;
    int frameHeight = 32;

    private:
    sf::Vector2f position;
    sf::Color color;
    float health;

public:
    Ken(sf::Vector2f startPosition, sf::Color initialColor)
        : position(startPosition), color(initialColor), health(100) {
    }

    void move(float offsetX, float offsetY) {
        position.x += offsetX;
        position.y += offsetY;
    }

    void update() {
        // Aquí podrías implementar la lógica de actualización de Ken
    }

    void draw(sf::RenderWindow& window) {
        sf::CircleShape shape(50);
        shape.setFillColor(color);
        shape.setPosition(position);
        window.draw(shape);
    }

    float getHealth() const {
        return health;
    }

    void receiveDamage(int amount) {
        health -= amount;
        // Asegurarse de que la salud no sea menor que 0
        if (health < 0) {
            health = 0;
        }
    }
};
