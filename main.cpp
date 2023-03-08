#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    // create the main window
    sf::RenderWindow window(sf::VideoMode(960, 600), "SORTING VISUALIZER");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("images/bg.png")) {
        cout<<"Error Loading Background";
        window.clear(sf::Color(71, 0, 66));
    }
    sf::Sprite backgroundSprite(backgroundTexture);
    backgroundSprite.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));
    backgroundSprite.setPosition(0, 0);
    window.draw(backgroundSprite);
    // set the font
    sf::Font font;
    if (!font.loadFromFile("font/SpongeboyMeBob.ttf"))
    {
        cout << "Error loading font\n";
        return 1;
    }

    // set the text color to yellow
    sf::Color textColor = sf::Color::White;

    // create the merge button
    sf::Text mergeText("Merge Sort", font, 35);
    mergeText.setOrigin(mergeText.getLocalBounds().width / 2, mergeText.getLocalBounds().height / 2);
    mergeText.setPosition(window.getSize().x / 2, window.getSize().y / 2 - 100);
    mergeText.setFillColor(textColor);

    // create the selection button
    sf::Text selectionText("Selection Sort", font, 33);
    selectionText.setOrigin(selectionText.getLocalBounds().width / 2, selectionText.getLocalBounds().height / 2);
    selectionText.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    selectionText.setFillColor(textColor);

    // create the quicksort button
    sf::Text quicksortText("Quick Sort", font, 35);
    quicksortText.setOrigin(quicksortText.getLocalBounds().width / 2, quicksortText.getLocalBounds().height / 2);
    quicksortText.setPosition(window.getSize().x / 2, window.getSize().y / 2 + 100);
    quicksortText.setFillColor(textColor);

    // create the BST button
    sf::Text bstText("BST", font, 33);
    bstText.setOrigin(bstText.getLocalBounds().width / 2, bstText.getLocalBounds().height / 2);
    bstText.setPosition(window.getSize().x / 2, window.getSize().y / 2 + 200);
    bstText.setFillColor(textColor);

    // draw the text on the window
    window.draw(mergeText);
    window.draw(selectionText);
    window.draw(quicksortText);
    window.draw(bstText);

    // display the window
    window.display();

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            // check if the mouse is clicked
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (mergeText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    cout << "Merge button clicked!\n";
                    system("g++ -I ./src/include -L ./src/lib -o mergeSort mergeSort.cpp -lsfml-graphics -lsfml-window -lsfml-system");
                    system("mergeSort");
                    // window.close();
                }

                if (selectionText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    cout << "Selection button clicked!\n";
                    cout << "Merge button clicked!\n";
                    system("g++ -I ./src/include -L ./src/lib -o selectionSort selectionSort.cpp -lsfml-graphics -lsfml-window -lsfml-system");
                    system("selectionSort");
                }

                if (quicksortText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    cout << "Clicked Quicksort button\n";
                    cout << "Merge button clicked!\n";
                    system("g++ -I ./src/include -L ./src/lib -o quickSort quickSort.cpp -lsfml-graphics -lsfml-window -lsfml-system");
                    system("quickSort");
                }

                if (bstText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    cout << "Clicked BST button\n";
                    // switch to the BST window
                }
            }
        }
    }
    return 0;
}
