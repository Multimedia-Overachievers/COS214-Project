#include <SFML/Graphics.hpp>
#include <iostream>
#include "../public/ConcreteSimulator.h"

void setupMap(sf::RenderWindow& window, ConcreteSimulator* simulator)
{  
    float x[] = {215, 164, 63, 701, 342, 355, 391, 381, 668, 611, 546, 647};
    float y[] = {310, 104, 307, 0, 305, 267, 238, 431, 626, 396, 401, 499};
    
    for(int i = 0; i < 12; i++)
    {
        sf::Texture texture;
        texture.loadFromFile(simulator->getImagePath((CountryName)i));
        sf::Sprite sprite(texture);

        sprite.setPosition(x[i], y[i]);
        window.draw(sprite);
    }

    //setup neutral teritory image
    sf::Texture neutralTexture;
    neutralTexture.loadFromFile("../Media/Neutral.png");
    sf::Sprite sprite(neutralTexture);
    sprite.setPosition(373, 0);
    window.draw(sprite);

    //setup the action window
    sf::Texture actionTexture;
    actionTexture.loadFromFile(simulator->getImagePath(simulator->getNextAction()));
    sf::Sprite actionSprite(actionTexture);
    actionSprite.setPosition(13, 527);
    window.draw(actionSprite);
    
}

void nextRound(ConcreteSimulator* simulator, FactionName factionTurn)
{
    Faction* faction = simulator->getFaction(factionTurn);
    simulator->notify(faction);
    faction->notify();
}

sf::Text* createText(std::string text, int size, int x, int y, FontType fontType){
    sf::Font* font = new sf::Font();
    switch(fontType)
    {
        default: case FontType::Literata:
            font->loadFromFile("../Media/Fonts/Literata.ttf");
            break;
        case FontType::Cinzel:
            font->loadFromFile("../Media/Fonts/Cinzel.ttf");
            break;
        case FontType::Alegreya:
            font->loadFromFile("../Media/Fonts/Alegreya.ttf");
            break;
    }
    
    //create text
    sf::Text* textPtr = new sf::Text();
    textPtr->setFont(*font);
    textPtr->setString(text);
    textPtr->setCharacterSize(size);
    textPtr->setFillColor(sf::Color::White);
    textPtr->setPosition(x, y);

    return textPtr;
}

int main()
{
    //======================== SFML Variable setup ========================
    sf::RenderWindow window(sf::VideoMode(900, 900), "Memento Mori | Project");
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.0f);
    
    //======================== Simulator Setup ========================
    ConcreteSimulator* simulator = ConcreteSimulator::getInstance();
    const int MAX_TURNS = 20;
    int currentTurn = 0;
    FactionName factionTurn = Allies;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {   
            static bool lock;
            switch (event.type)
            {
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left && lock != true) 
                    {
                        lock = true;
                    }   
                    break;
                case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        lock = false; 
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }

        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;
            nextRound(simulator, factionTurn);
            if (factionTurn == Allies) factionTurn = Axis;
            else factionTurn = Allies;
            std::cout << "Turn " << currentTurn << " complete." << std::endl;
            currentTurn++;

            if(currentTurn == MAX_TURNS)
            {
                std::cout << "Game Over" << std::endl;
                window.close();
            }

            window.clear(sf::Color(69, 153, 186));
            setupMap(window, simulator);
            window.draw(*createText("Europe", 50, 10, 10, FontType::Cinzel));

            window.display();
        }


    }

    return EXIT_SUCCESS;
}

//Keelan
//finished class diagram
//Split up individual patterns and placed in docs
//Updated class diagram
//Recorded video voiceover
//Finished video

//Tayla 
//Finished Composite Pattern and added to docs
//Finished Iterator Pattern and added to docs
// Added Thomas's research to docs
// Modified research slightly to match
// Prettified docs
// Reformatted docs, added updated class diagrams, prettified docs
// Updated country class diagram and added to docs
// Added more Object Diagrams to docs
// Added more Sequence Diagrams to docs

// Dhairiya
// Updated previous state diagram in docs