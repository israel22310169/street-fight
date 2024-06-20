class Ryu 
{
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
        // Aquí podrías implementar la lógica de actualización de Ryu
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