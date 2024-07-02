int main() {
    // Código anterior...

    // Crear barras de vida para Ryu y Ken
    HealthBar ryuHealthBar(200, 20, sf::Color::Red, sf::Color::Black);
    ryuHealthBar.setPosition(50, 50);

    HealthBar kenHealthBar(200, 20, sf::Color::green, sf::Color::Black);
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

        // Código anterior...
    }

    return 0;
}