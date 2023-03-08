#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;

const int window_width = 960;
const int window_height = 600;
sf::RenderWindow window(sf::VideoMode(window_width,window_height), "Merge Sort");
int n = 80;
float recHs[80];
bool sorted = false;

void sortProcess(int index)
{
    //Slow Down Process
    sf::Clock pauseClock;

    sf::Time pauseDuration = sf::seconds(0.05);
    pauseClock.restart();
    while (pauseClock.getElapsedTime() < pauseDuration)
    {
        //Do Nothing but produces delay
    }
    window.clear();
    for (int i = 0; i < n; i++)
    {
        sf::RectangleShape block(sf::Vector2f(10, recHs[i]));
        block.setPosition(i * 12, 600 - recHs[i]);
        block.setFillColor(sorted || i == index ? sf::Color::Green : sf::Color::White);
        window.draw(block);
    }
    window.display();
}

void merge(float arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    std::vector<float> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l.to.r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        sortProcess(k);
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        sortProcess(k);
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        sortProcess(k);
        j++;
        k++;
    }
}

void mergeSort(float arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
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
            sortProcess(0);
            mergeSort(recHs, 0, n - 1);
            sorted = true;
        }
    }
    return 0;
}