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
#include <map>

void setupMap(sf::RenderWindow& window, ConcreteSimulator* simulator){
    /*
        France ,
        UnitedKingdom,
        UnitedStates,
        SovietUnion,
        Belgium,
        Netherlands,
        
        // Axis
        Germany,
        Italy,
        Japan,
        Romania,
        Hungary,
        Bulgaria,
    */
   
    std::map<int, int> coords = {
        {215, 310}, // France
        {164, 104}, // UnitedKingdom
        {63, 307},  // SovietUnion
        {701, 0},   // UnitedStates
        {342, 305}, // Belgium
        {355, 267}, // Netherlands
        {391, 240}, // Germany
        {381, 431}, // Italy
        {668, 626}, // Japan
        {611, 396}, // Romania
        {546, 401}, // Hungary
        {647, 500}  // Bulgaria
    };
    
    // //for each on enum country
    // for (int it = 0; it < 12; it++){
    // {
    //     CountryName country = static_cast<CountryName>(it);
    //     std::cout << convert_country[country] << std::endl;
    // }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "Memento Mori | Project");
    ConcreteSimulator* simulator = ConcreteSimulator::getInstance();

    //setupMap(window, simulator);
    //simulator->getImagePath(CountryName::Germany)

    sf::Font font;
    if (!font.loadFromFile("../Media/Fonts/Cinzel.ttf"))
        return EXIT_FAILURE;
    sf::Text text("bitaly", font, 50);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //window.draw(sprite);
        window.draw(text);
        window.display();
    }

    return EXIT_SUCCESS;
}
