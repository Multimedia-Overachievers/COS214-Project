#include <iostream>
#include "../public/ConcreteSimulator.h"


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


#include <SFML/Graphics.hpp>

void setupMap(sf::RenderWindow& window, ConcreteSimulator* simulator){  
    float x[] = {215, 164, 63, 701, 342, 355, 391, 381, 668, 611, 546, 647};
    float y[] = {310, 104, 307, 0, 305, 267, 240, 431, 626, 396, 401, 500};
    
    for(int i = 0; i < 12; i++){
        sf::Texture texture;
        texture.loadFromFile(simulator->getImagePath((CountryName)i));
        sf::Sprite sprite(texture);

        sprite.setPosition(x[i], y[i]);
        window.draw(sprite);
    }

    //setup neutral teritory image
    sf::Texture texture;
    texture.loadFromFile("../Media/Neutral.png");
    sf::Sprite sprite(texture);
    sprite.setPosition(373, 0);
    window.draw(sprite);
}

void swapFactions(ConcreteSimulator* simulator){
    //random number between 0 and 12
    int random = rand() % 12;
    if(simulator->countries[random]->getOwner() == FactionName::Allies){
        simulator->countries[random]->setOwner(FactionName::Axis);
        simulator->captureCountry(simulator->countries[random], simulator->getFaction(Axis));
    }
    else{
        simulator->countries[random]->setOwner(FactionName::Allies);
        simulator->captureCountry(simulator->countries[random], simulator->getFaction(Allies));
    }
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "Memento Mori | Project");

    ConcreteSimulator* simulator = ConcreteSimulator::getInstance();

    sf::Font font;
    if (!font.loadFromFile("../Media/Fonts/Cinzel.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Europe 1936", font, 50);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {   
            static bool lock = false;
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left && lock != true) 
                {
                    swapFactions(simulator);
                    lock = true;
                }   
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    lock = false; 
                }
            }
        }

        sf::Color color(255, 255, 255);
        window.clear(color);
        setupMap(window, simulator);
        window.draw(text);
        window.display();
    }

    return EXIT_SUCCESS;
}
