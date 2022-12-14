#include <iostream>
#include "../public/ConcreteSimulator.h"
#include "../../Creation/public/Simulation.h"
#include "../../Creation/public/Logs.h"

#include <SFML/Graphics.hpp>

// ================== Global Variables ==================
int year = 1936;
int month = 0;
bool sandbox = false;

// ================== Global Sprites ==================
sf::Sprite* undoSprite;
sf::Sprite* playSprite;
sf::Sprite* pauseSprite;
sf::Sprite* fastForwardSprite;
sf::Sprite** countrySprites = new sf::Sprite*[12];

sf::Sprite* sandboxAddSprite;
sf::Sprite* sandboxAdd10Sprite;
sf::Sprite* sandboxSubSprite;
sf::Sprite* sandboxSub10Sprite;
sf::Sprite* sandboxSwapSprite;

sf::FloatRect sandboxSubBounds;
sf::FloatRect sandboxSub10Bounds;
sf::FloatRect sandboxAddBounds;
sf::FloatRect sandboxAdd10Bounds;
sf::FloatRect sandboxSwapBounds;

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

void setupMap(sf::RenderWindow& window, ConcreteSimulator* simulator, FactionName factionTurn, bool paused)
{  
    std::cout << "In setupMap" << std::endl;
    float x[] = {215, 164, 63, 701, 342, 355, 391, 381, 622, 611, 546, 647};
    float y[] = {310, 104, 307, 0, 305, 267, 238, 431, 596, 396, 401, 499};
    
    for(int i = 0; i < 12; i++)
    {
        sf::Texture texture;
        texture.loadFromFile(simulator->getImagePath((CountryName)i));
        countrySprites[i] = new sf::Sprite(texture);
        countrySprites[i]->setPosition(x[i], y[i]);
        window.draw(*countrySprites[i]);
    }

    //setup neutral teritory image
    sf::Texture neutralTexture;
    neutralTexture.loadFromFile("../Media/Neutral.png");
    sf::Sprite sprite(neutralTexture);
    sprite.setPosition(373, 0);
    window.draw(sprite);

    std::cout << "about to get next action" << std::endl;
    // -----setup the action window -----
    sf::Texture actionTexture;
    actionTexture.loadFromFile(simulator->getImagePath(simulator->getNextAction()));
    sf::Sprite actionSprite(actionTexture);
    actionSprite.setPosition(13, 527);
    window.draw(actionSprite);

    // ----- setup the date window -----
    std::string date = std::to_string(year) + " " + convert_month[month];
    window.draw(*createText(date, 24, 44, 545, FontType::Cinzel, offBlack));

    // ----- List of things for attackAction output -----
    std::string action = wrapText(simulator->messageMap["Action"] + simulator->messageMap["Result"], 36);
    window.draw(*createText(action, 21, 47, 587, FontType::Alegreya, offBlack));

    // ----- Faction Details -----
    Faction* faction = simulator->getFaction(factionTurn);
    std::string factionName = convert_faction[faction->getName()];
    // Get total number of troops in every country
    int totalTroops = 0;
    for (int i = 0; i < faction->getStrength(); i++) {
        totalTroops += faction->getCountry(i)->getNumTroops();
    }
    // Get total number of countries owned
    int totalCountries = faction->getStrength();
    window.draw(*createText(factionName, 36, 206, 750, FontType::Alegreya, offBlack));

    // Current state of faction
    std::string state = convert_stance[faction->getStanceType()];
    state = "In " + state.substr(0, state.length() - 6) + " state";
    window.draw(*createText(state, 21, 206, 789, FontType::Alegreya, offBlack));

    // Current number of countries in faction
    std::string countries = "Countries: " + std::to_string(totalCountries);
    window.draw(*createText(countries, 21, 206, 814, FontType::Alegreya, offBlack));
    
    // Current number of troops in faction
    std::string troops = "Troops: " + std::to_string(totalTroops);
    window.draw(*createText(troops, 21, 206, 840, FontType::Alegreya, offBlack));


    // ----- Render buttons -----
    cout << "Paused? " << paused << endl;
    if(sandbox)
    {
        window.draw(*undoSprite);
    }
    window.draw(*playSprite);
    window.draw(*pauseSprite);
    window.draw(*fastForwardSprite);
        
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
void nextRound(ConcreteSimulator* simulator, FactionName factionTurn, Logs* logs, Simulation* simulation)
{
    // Save state to memento
    if(sandbox)
    {
        std::cout << "Saving state" << std::endl;
        logs->createLog(simulation->saveLog());
        std::cout << "State saved" << std::endl;
    }

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

void showDevMenu(sf::RenderWindow& window, Country* country, ConcreteSimulator* simulator)
{
    std::cout << "In showDevMenu showing country " << convert_country[country->getName()] << std::endl;
    sf::Texture sandboxMenu;
    sandboxMenu.loadFromFile("../Media/SandboxMenu.png");
    sf::Sprite sandboxMenuSprite(sandboxMenu);
    sandboxMenuSprite.setPosition(466, 751);
    window.draw(sandboxMenuSprite);

    // Country name
    std::string countryName = convert_country[country->getName()];
    window.draw(*createText(countryName, 27, 561, 766, FontType::Alegreya, offBlack));
    
    // Num of troops
    window.draw(*createText("Troops", 17, 523, 815, FontType::Alegreya, offBlack));
    int numTroops = country->getNumTroops();
    std::string troops = std::to_string(numTroops);
    window.draw(*createText(troops, 17, 543, 840, FontType::Alegreya, offBlack));
    
    // Num troops controls
    sf::Texture sandboxSub;
    sandboxSub.loadFromFile("../Media/SandboxSub.png");
    sandboxSubSprite = new sf::Sprite(sandboxSub);
    sandboxSubSprite->setPosition(513, 844);
    window.draw(*sandboxSubSprite);
    sandboxSubBounds = sandboxSubSprite->getGlobalBounds();

    sf::Texture sandboxSub10;
    sandboxSub10.loadFromFile("../Media/SandboxSub10.png");
    sandboxSub10Sprite = new sf::Sprite(sandboxSub10);
    sandboxSub10Sprite->setPosition(495, 844);
    window.draw(*sandboxSub10Sprite);
    sandboxSub10Bounds = sandboxSub10Sprite->getGlobalBounds();

    sf::Texture sandboxAdd;
    sandboxAdd.loadFromFile("../Media/SandboxAdd.png");
    sandboxAddSprite = new sf::Sprite(sandboxAdd);
    sandboxAddSprite->setPosition(572, 844);
    window.draw(*sandboxAddSprite);
    sandboxAddBounds = sandboxAddSprite->getGlobalBounds();

    sf::Texture sandboxAdd10;
    sandboxAdd10.loadFromFile("../Media/SandboxAdd10.png");
    sandboxAdd10Sprite = new sf::Sprite(sandboxAdd10);
    sandboxAdd10Sprite->setPosition(589, 844);
    window.draw(*sandboxAdd10Sprite);
    sandboxAdd10Bounds = sandboxAdd10Sprite->getGlobalBounds();
    
    // AciveFaction
    window.draw(*createText("Faction", 17, 635, 815, FontType::Alegreya, offBlack));
    std::string activeFaction = convert_faction[country->getOwner()];
    window.draw(*createText(activeFaction, 17, 632, 844, FontType::Alegreya, offBlack));

    sf::Texture sandboxSwap;
    sandboxSwap.loadFromFile("../Media/SandboxSwap.png");
    sandboxSwapSprite = new sf::Sprite(sandboxSwap);
    sandboxSwapSprite->setPosition(680, 844);
    window.draw(*sandboxSwapSprite);
    sandboxSwapBounds = sandboxSwapSprite->getGlobalBounds();
}

int main()
{
    // ----- Prompt the user to enter sandbox or simulation mode -----
    std::cout << "\n\n\n\n=========================================================" << std::endl;
    std::cout << "|   Would you like to play in sandbox mode? (y/n)       |" << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::string input;
    std::cin >> input;
    if(input == "y")
    {
        sandbox = true;
    }

    //======================== SFML Variable setup ========================
    sf::RenderWindow window(sf::VideoMode(900, 900), "Memento Mori | Project");
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    float speed = 2.0f;
    sf::Time timePerFrame = sf::seconds(speed);

    //======================== Sprite setup ========================
    sf::Texture undoTexture;
    undoTexture.loadFromFile("../Media/Undo.png");
    undoSprite = new sf::Sprite(undoTexture);
    undoSprite->setPosition(37, 27);
    sf::FloatRect undoBounds = undoSprite->getGlobalBounds();

    sf::Texture playTexture;
    playTexture.loadFromFile("../Media/Play.png");
    playSprite = new sf::Sprite(playTexture);
    playSprite->setPosition(81, 27);
    playSprite->move(-100, -100);

    sf::Texture pauseTexture;
    pauseTexture.loadFromFile("../Media/Pause.png");
    pauseSprite = new sf::Sprite(pauseTexture);
    pauseSprite->setPosition(81, 27);

    sf::Texture fastForwardTexture;
    fastForwardTexture.loadFromFile("../Media/FastForward.png");
    fastForwardSprite = new sf::Sprite(fastForwardTexture);
    fastForwardSprite->setPosition(123, 27);
    sf::FloatRect fastForwardBounds = fastForwardSprite->getGlobalBounds();

    //======================== Simulator Setup ========================
    ConcreteSimulator* simulator = ConcreteSimulator::getInstance();
    Simulation* simulation = new Simulation(simulator->getFaction(Allies), simulator->getFaction(Axis));
    Logs* logs = new Logs();
    const int MAX_TURNS = 48;
    int currentTurn = 0;
    FactionName factionTurn = Allies;
    bool isPaused = false;
    int activeCountry = -1;

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
                        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                        sf::FloatRect playBounds = playSprite->getGlobalBounds();
                        sf::FloatRect pauseBounds = pauseSprite->getGlobalBounds();
                        

                        //bind all the sprites of countries
                        for(int i = 0; i < 12; i++)
                        {
                            sf::FloatRect countryBounds = countrySprites[i]->getGlobalBounds();
                            if(countryBounds.contains(mouse))
                            {
                                if(sandbox)
                                {
                                    activeCountry = i;
                                }
                            }
                        }

                        if(sandboxSubBounds.contains(mouse) && sandbox && activeCountry != -1){
                            simulator->countries.at(activeCountry)->removeTroops(1);
                        }

                        if(sandboxSub10Bounds.contains(mouse) && sandbox && activeCountry != -1){
                            simulator->countries.at(activeCountry)->removeTroops(10);
                        }

                        if(sandboxAddBounds.contains(mouse) && sandbox && activeCountry != -1){
                            simulator->countries.at(activeCountry)->addTroops(1);
                        }

                        if(sandboxAdd10Bounds.contains(mouse) && sandbox && activeCountry != -1){
                            simulator->countries.at(activeCountry)->addTroops(10);
                        }

                        if(sandboxSwapBounds.contains(mouse) && sandbox && activeCountry != -1){
                            if(simulator->countries.at(activeCountry)->getOwner() == Allies){
                                simulator->countries.at(activeCountry)->setOwner(Axis);
                            } else {
                                simulator->countries.at(activeCountry)->setOwner(Allies);
                            }
                            simulator->countries.at(activeCountry)->notify();
                        }
                    
                        if (undoBounds.contains(mouse) && sandbox)
                        {
                            cout << "Undo button pressed" << endl;
                            simulation->loadLog(logs->getLog());
                            timePerFrame = sf::seconds(2.0f);
                            if(!isPaused)
                            {
                                isPaused = true;
                                playSprite->move(100, 100);
                                pauseSprite->move(-100, -100);
                            } 
                            // roll back the date by one
                            if(factionTurn == Axis)
                            {
                                month--;
                                if(month == -1)
                                {
                                    month = 11;
                                    year--;
                                }
                            } 
                            // roll back the faction turn
                            if(factionTurn == Allies)
                            {
                                factionTurn = Axis;
                            }
                            else
                            {
                                factionTurn = Allies;
                            }
                        }
             
                        if (playBounds.contains(mouse))
                        {
                            cout << "PLAY BUTTON PRESSED" << endl;
                            timePerFrame = sf::seconds(2.0f);
                            activeCountry = -1;
                            isPaused = false;
                            playSprite->move(-100, -100);
                            pauseSprite->move(100, 100);
                        }
                        if (pauseBounds.contains(mouse))
                        {
                            cout << "PAUSE BUTTON PRESSED" << endl;
                            timePerFrame = sf::seconds(0.2f);
                            isPaused = true;
                            pauseSprite->move(-100, -100);
                            playSprite->move(100, 100);    
                        }
               
                        if (fastForwardBounds.contains(mouse))
                        {
                            cout << "Fast Forward button pressed" << endl;
                            timePerFrame = sf::seconds(0.4f);
                            if(isPaused)
                            {
                                activeCountry = -1;
                                isPaused = false;
                                playSprite->move(-100, -100);
                                pauseSprite->move(100, 100);
                            }
                        }
                        window.clear(waterColour);
                        std::cout << "about to enter setup Map" << std::endl;
                        setupMap(window, simulator, factionTurn, isPaused);
                        window.display();
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
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Space)
                    {
                        isPaused = !isPaused;
                    }
                    break;
                default:
                    break;
            }
        }

        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;
            window.clear(waterColour);

            if(!isPaused) {
                nextRound(simulator, factionTurn, logs, simulation);
                if (factionTurn == Allies) factionTurn = Axis;
                else factionTurn = Allies;
                std::cout << "Turn " << currentTurn << " complete." << std::endl;
                currentTurn++;

                if(currentTurn == MAX_TURNS || simulator->gameOver())
                {
                    std::cout << "Game Over" << std::endl;
                    window.close();
                }

            }
            setupMap(window, simulator, factionTurn, false);
            
            if(sandbox && activeCountry != -1){
                showDevMenu(window, simulator->countries.at(activeCountry), simulator);
            }
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