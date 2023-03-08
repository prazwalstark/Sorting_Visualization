#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
const int window_width = 960;
const int window_height = 600;
sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Quick Sort");
sf::Texture backgroundTexture;
sf::Sprite backgroundSprite(backgroundTexture);
int n = 80;
float recHs[80];
bool sorted = false;

void sortProcess(int index, int left, int right, int pivot)
{
    // Slow Down Process
    sf::Clock pauseClock;
    sf::Time pauseDuration = sf::seconds(0.09);
    pauseClock.restart();
    while (pauseClock.getElapsedTime() < pauseDuration)
    {
        // Do Nothing but produces delay
    }
    window.clear();
    window.draw(backgroundSprite);
    for (int i = 0; i < n; i++)
    {
        sf::RectangleShape block(sf::Vector2f(10, recHs[i]));
        block.setPosition(i * 12, 600 - recHs[i]);

        // Change color based on index, pivot  and pointers
        if (i == index)
        {
            block.setFillColor(sf::Color::Green);
        }
        else if (std::round(pivot) == std::round(recHs[i]))
        {
            block.setFillColor(sf::Color::Yellow);
        }
        else if (i == left)
        {
            block.setFillColor(sf::Color::Blue);
        }
        else if (i == right)
        {
            block.setFillColor(sf::Color::Red);
        }
        else
        {
            block.setFillColor(sf::Color::White);
        }

        window.draw(block);
    }
    window.display();
}

void quickSort(float arr[], int left, int right)
{
    int i = left;
    int j = right;
    int k = left;
    float pivot = arr[(left + right) / 2];

    // Dividing into sub arrays
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
        sortProcess(k, i, j, pivot);
        k++;
    }
    // Recursively repeating
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
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
            }
        }
        if (!sorted)
        {
            sortProcess(0, -1, -1, recHs[n/2]);
            quickSort(recHs, 0, n - 1);
            sorted = true;
        }
    }
    return 0;
}
