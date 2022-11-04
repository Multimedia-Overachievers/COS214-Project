// #include <iostream>

// #include "../public/ConcreteSimulator.h"

// int main() 
// {
//     // === Variables ===
//     const int MAX_TURNS = 20;
//     FactionName factionTurn = Allies;

//     // === Create the simulator ===
//     ConcreteSimulator* simulator = ConcreteSimulator::getInstance();

//     // === Main Loop ===
//     for (int i = 0; i < MAX_TURNS; i++)
//     {
//         Faction* faction = simulator->getFaction(factionTurn);
//         simulator->notify(faction);
//         faction->notify();

//         std::cout << "Turn " << i << " complete." << std::endl;
        
//         // Switch turn
//         if (factionTurn == Allies)
//         {
//             factionTurn = Axis;
//         }
//         else
//         {
//             factionTurn = Allies;
//         }
//     }

//     return 0;
// }

// // Misc commits for progress tracking
// // Started class diagram implementation




#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}