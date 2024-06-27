#include <SFML/Graphics.hpp>

class MedidorDeVitalidad 
{
private:
    sf::RectangleShape bar;
    float maxWidth;
    float currentValue;
    sf::Color fillColor;
    sf::Color outlineColor;

public:
    MedidorDeVitalidad(float width, float height, sf::Color fill, sf::Color outline) 
        : maxWidth(width), fillColor(fill), outlineColor(outline) {
        bar.setSize(sf::Vector2f(maxWidth, height));
        bar.setFillColor(fillColor);
        bar.setOutlineThickness(2);
        bar.setOutlineColor(outlineColor);
        currentValue = maxWidth; // Inicialmente la barra está llena
    }

    void setPosition(float x, float y) {
        bar.setPosition(x, y);
    }

    void setCurrentValue(float value, float maxHealth) {
        currentValue = (value / maxHealth) * maxWidth;
        if (currentValue < 0) currentValue = 0;
        bar.setSize(sf::Vector2f(currentValue, bar.getSize().y));
    }

    void draw(sf::RenderWindow& window) {
        window.draw(bar);
    }
};