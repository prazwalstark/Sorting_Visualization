#include <SFML/Graphics.hpp>
#include <iostream>
#include </home/pstark/Documents/Codes/Sorting_Visualization/include/quicksort.h>
using namespace std;

int main()
{
    // create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SORTING VISUALIZER");

    // set the background color to gray
    window.clear(sf::Color(71,0,66));

    // set the font
    sf::Font font;
    if (!font.loadFromFile("/home/pstark/Documents/Codes/Sorting_Visualization/font/ArialTh.ttf"))
    {
        cout << "Error loading font\n";
        return 1;
    }

    // set the text color to yellow
    sf::Color textColor = sf::Color::White;

    // create the merge button
    sf::Text mergeText("Merge Sort", font, 50);
    mergeText.setOrigin(mergeText.getLocalBounds().width / 2, mergeText.getLocalBounds().height / 2);
    mergeText.setPosition(window.getSize().x / 2, window.getSize().y / 2 - 100);
    mergeText.setFillColor(textColor);

    // create the selection button
    sf::Text selectionText("Selection Sort", font, 50);
    selectionText.setOrigin(selectionText.getLocalBounds().width / 2, selectionText.getLocalBounds().height / 2);
    selectionText.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    selectionText.setFillColor(textColor);

    // create the quicksort button
    sf::Text quicksortText("Quick Sort", font, 50);
    quicksortText.setOrigin(quicksortText.getLocalBounds().width / 2, quicksortText.getLocalBounds().height / 2);
    quicksortText.setPosition(window.getSize().x / 2, window.getSize().y / 2 + 100);
    quicksortText.setFillColor(textColor);

    // create the BST button
    sf::Text bstText("BST", font, 50);
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

            // check if the mouse is clicked
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (mergeText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    cout << "Merge button clicked!\n";
                    //switch to the merge sort window
                }

                if (selectionText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    cout << "Selection button clicked!\n";
                    // switch to the selection sort window
                }

                if (quicksortText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    cout << "Clicked Quicksort button\n";
                    // switch to the Quicksort window
                    exec_window();
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


