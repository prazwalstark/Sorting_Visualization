#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;
const int window_width = 960;
const int window_height = 600;
sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Selection Sort");
sf::Texture backgroundTexture;
sf::Sprite backgroundSprite(backgroundTexture);
int n = 80;
float recHs[80];
bool sorted = false;

void sortProcess(int index, int minIndex, int i)
{
    // Slow Down Process
    sf::Clock pauseClock;
    sf::Time pauseDuration = sf::seconds(0.08);
    pauseClock.restart();
    while (pauseClock.getElapsedTime() < pauseDuration)
    {
        // Do Nothing but produces delay
    }
    window.clear();
    window.draw(backgroundSprite);
    for (int j = 0; j < n; j++)
    {
        sf::RectangleShape block(sf::Vector2f(10, recHs[j]));
        block.setPosition(j * 12, 600 - recHs[j]);

        // Change color based on index, minIndex  and i
        if (j == index)
        {
            block.setFillColor(sf::Color::Green);
        }
        else if (j == minIndex)
        {
            block.setFillColor(sf::Color::Yellow);
        }
        else
        {
            block.setFillColor(sf::Color::White);
        }

        window.draw(block);
    }
    window.display();
}

void selectionSort(float arr[], int n)
{
    int i, j, minIndex;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        minIndex = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        // Swap the found minimum element with the first element
        std::swap(arr[minIndex], arr[i]);

        sortProcess(i, minIndex, j);
    }
}

int main()
{
        // sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("images/bg-01.png")) {
        cout<<"Error Loading Background";
        window.clear(sf::Color(71, 0, 66));
    }
    backgroundSprite.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));
    backgroundSprite.setPosition(0, 0);
    window.draw(backgroundSprite);
    for (int i = 0; i < n; i++)
    {
        recHs[i] = (rand() % 550);
    }

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                {
                   window.close();
                }
                break;
            }
        }
        if (!sorted)
        {
            sortProcess(0, -1, -1);
            selectionSort(recHs, n);
            sorted = true;
        }
    }
    return 0;
}
