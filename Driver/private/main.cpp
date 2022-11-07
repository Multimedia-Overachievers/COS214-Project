#include <SFML/Graphics.hpp>
#include <iostream>
#include "../public/ConcreteSimulator.h"

// ================== Global Variables ==================

int year = 1936;
int month = 0;

// ------------------ Colours ------------------

sf::Color offBlack = sf::Color(38, 37, 34);
sf::Color waterColour = sf::Color(69, 153, 186);

// ================== Helper/Set-up functions ==================

sf::Text* createText(std::string text, int size, int x, int y, FontType fontType, sf::Color colour) {
    sf::Font* font = new sf::Font();
    switch(fontType)
    {
        default: case FontType::Literata:
            font->loadFromFile("../Media/Fonts/Literata.ttf"); // Secondary text font
            break;
        case FontType::Cinzel:
            font->loadFromFile("../Media/Fonts/Cinzel.ttf"); // Title font
            break;
        case FontType::Alegreya:
            font->loadFromFile("../Media/Fonts/Alegreya.ttf"); // Main text font
            break;
    }
    
    //create text
    sf::Text* textPtr = new sf::Text();
    textPtr->setFont(*font);
    textPtr->setString(text);
    textPtr->setCharacterSize(size);
    textPtr->setFillColor(colour);
    textPtr->setPosition(x, y);

    return textPtr;
}

/**
 * @brief Function which takes in a string and wraps it to a certain width
 * 
 * @param text 
 * @param length 
 * @return std::string 
 */
std::string wrapText(std::string text, int length) {
    // Put words from string into array
    std::vector<std::string> words;
    std::string word = "";
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') {
            words.push_back(word);
            word = "";
        } else {
            word += text[i];
        }
    }
    words.push_back(word);
    
    // Wrap words into lines
    std::string wrappedText = "";
    int lineLength = 0;
    for (int i = 0; i < words.size(); i++) {
        if (lineLength + words[i].length() > length) {
            wrappedText += "\n";
            lineLength = 0;
        }
        wrappedText += words[i] + " ";
        lineLength += words[i].length() + 1;
    }

    return wrappedText;
    
}

void setupMap(sf::RenderWindow& window, ConcreteSimulator* simulator, FactionName factionTurn)
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

    //setup the date window
    std::string date = std::to_string(year) + " " + convert_month[month];
    window.draw(*createText(date, 24, 44, 545, FontType::Cinzel, offBlack));

    // List of things for attackAction output
    std::string action = wrapText(simulator->messageMap["Action"] + simulator->messageMap["Result"], 36);
    window.draw(*createText(action, 21, 47, 587, FontType::Alegreya, offBlack));


    std::cout << "HERE" << std::endl;
    // Current faction
    Faction* faction = simulator->getFaction(factionTurn);
    std::string factionName = convert_faction[faction->getName()];
    // Get total number of troops in every country

    std::cout << "HERE2" << std::endl;
    int totalTroops = 0;
    for (int i = 0; i < faction->getStrength(); i++) {
        totalTroops += faction->getCountry(i)->getNumTroops();
          std::cout << "HERE" << 3+i << std::endl;
    }
      std::cout << "HERE3" << std::endl;
    // Get total number of countries owned
    int totalCountries = faction->getStrength();


    std::cout << "FACTION: " << faction << std::endl;
    std::cout << "FACTION NAME: " << factionName << std::endl;
    window.draw(*createText(factionName, 36, 206, 750, FontType::Alegreya, offBlack));

    // Current state of faction
    
    std::string state = convert_stance[faction->getStanceType()];
    state = "In " + state.substr(0, state.length() - 6) + " state";
    std::cout << "STATE: " << state << std::endl;
    window.draw(*createText(state, 21, 206, 789, FontType::Alegreya, offBlack));

    // Current number of countries in faction
    std::string countries = "Countries: " + std::to_string(totalCountries);
    std::cout << "COUNTRIES: " << countries << std::endl;
    window.draw(*createText(countries, 21, 206, 814, FontType::Alegreya, offBlack));

    // Current number of troops in faction
    std::string troops = "Troops: " + std::to_string(totalTroops);
    std::cout << "TROOPS: " << troops << std::endl;
    window.draw(*createText(troops, 21, 206, 840, FontType::Alegreya, offBlack));

    // Print out the countries in both the Axis and Allies

    Faction* axis = simulator->getFaction(Axis);
    Faction* allies = simulator->getFaction(Allies);
    for (int i = 0; i < axis->getStrength(); i++) {
        std::string country = convert_country[axis->getCountry(i)->getName()];
        std::cout << country << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < allies->getStrength(); i++) {
        std::string country = convert_country[allies->getCountry(i)->getName()];
        std::cout << country << " ";
    }
    std::cout << std::endl;
        
        
}

/**
 * @brief Increments the turn by one by changing the month and year
 * 
 */
void incrementTurn()
{
    month++;
    if(month == 12)
    {
        month = 0;
        year++;
    }
}

/**
 * @brief Handles the methods which need to be called each round
 * 
 * @param simulator 
 * @param factionTurn 
 */
void nextRound(ConcreteSimulator* simulator, FactionName factionTurn)
{
    Faction* faction = simulator->getFaction(factionTurn);
    simulator->messageMap["Faction"] = convert_faction[factionTurn];
    simulator->notify(faction);
    faction->notify();

    // If the faction is the Axis, then increment the turn
    if(factionTurn == FactionName::Axis)
    {
        incrementTurn();
    }
}

int main()
{
    //======================== SFML Variable setup ========================
    sf::RenderWindow window(sf::VideoMode(900, 900), "Memento Mori | Project");
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(4.0f);
    
    //======================== Simulator Setup ========================
    ConcreteSimulator* simulator = ConcreteSimulator::getInstance();
    const int MAX_TURNS = 48;
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

            if(currentTurn == MAX_TURNS || simulator->gameOver()) // TODO: ADD THE WIN CONDITION
            {
                std::cout << "Game Over" << std::endl;
                window.close();
            }

            window.clear(waterColour);
            
            setupMap(window, simulator, factionTurn);
            window.draw(*createText("Europe", 50, 10, 10, FontType::Cinzel, sf::Color::White));

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
//Fixed Thomas' citations to be in Harvard
//Added facade description
//Added Mediator and and Facade Interrelationships
//Updated functional requirements

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
// Added activity diagrams to docs
// Added communication diagrams to docs
// Finished up documentation
// Added citations to docs

// Dhairiya
// Updated previous state diagram in docs