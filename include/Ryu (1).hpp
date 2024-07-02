class Ryu 
{
    private:
    sf::Vector2f position;
    sf::Color color;
    int health; // Salud de Ryu

public:
    Ryu(sf::Vector2f startPos, sf::Color color);

    void move(float offsetX, float offsetY);

    void draw(sf::RenderWindow& window);

    void update();

    void receiveDamage(int amount); // Método para recibir daño

    int getHealth() const; // Método para obtener la salud actual

public:
    Ryu(sf::Vector2f position, sf::Color color) {
        shape.setSize(sf::Vector2f(50, 50));
        shape.setPosition(position);
        shape.setFillColor(color);
    }

    void move(float offsetX, float offsetY) {
        shape.move(offsetX, offsetY);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

private:
    sf::RectangleShape shape;


    private:
    sf::Vector2f position;
    sf::Color color;
    float health;

public:
    Ryu(sf::Vector2f startPosition, sf::Color initialColor)
        : position(startPosition), color(initialColor), health(100) {
    }

    void move(float offsetX, float offsetY) {
        position.x += offsetX;
        position.y += offsetY;
    }

    void update() {
       
};