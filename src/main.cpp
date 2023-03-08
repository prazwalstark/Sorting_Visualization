#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include <cmath>



// #include "../include/quicksort.h"
// #include "../include/mergesort.h"



const int window_width = 960;
const int window_height = 600;


using namespace sf;
using namespace std;
sf::RenderWindow window(sf::VideoMode(960, 600), "SORTING VISUALIZER");

int n = 80;
float recHs[80];
bool sorted = false;







//////SELECTION SORT////////

void selectionsortProcess(RenderWindow& window3,int index, int minIndex, int i)
{
    // Slow Down Process
    sf::Clock pauseClock;
    sf::Time pauseDuration = sf::seconds(0.08);
    pauseClock.restart();
    while (pauseClock.getElapsedTime() < pauseDuration)
    {
        // Do Nothing but produces delay
    }
    window3.clear();
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

        window3.draw(block);
    }
    window3.display();
}
void selectionSort(RenderWindow& window3,float arr[], int n)
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

        selectionsortProcess(window3,i, minIndex, j);
    }
}


void exec_window_selection(RenderWindow& window3)
{
    for (int i = 0; i < n; i++)
    {
        recHs[i] = (rand() % 550);
    }

    while (window3.isOpen())
    {
        sf::Event event;

        while (window3.pollEvent(event))
        {
            switch (event.type)
            {

            case sf::Event::Closed:
                window3.close();
            }
        }
        if (!sorted)
        {
            selectionsortProcess(window3,0, -1, -1);
            selectionSort(window3,recHs, n);
            sorted = true;
        }
    }
}












///////MERGE///////
void mergesortProcess(RenderWindow& window2,int index)
{
    //Slow Down Process
    sf::Clock pauseClock;

    sf::Time pauseDuration = sf::seconds(0.05);
    pauseClock.restart();
    while (pauseClock.getElapsedTime() < pauseDuration)
    {
        //Do Nothing but produces delay
    }
    window2.clear();
    for (int i = 0; i < n; i++)
    {
        sf::RectangleShape block(sf::Vector2f(10, recHs[i]));
        block.setPosition(i * 12, 600 - recHs[i]);
        block.setFillColor(sorted || i == index ? sf::Color::Green : sf::Color::White);
        window2.draw(block);
    }
    window2.display();
}

void merge(RenderWindow& window2,float arr[], int l, int m, int r)
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
        mergesortProcess(window2,k);
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        mergesortProcess(window2,k);
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        mergesortProcess(window2,k);
        j++;
        k++;
    }
}

void mergeSort(RenderWindow& window2,float arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(window2,arr, l, m);
        mergeSort(window2,arr, m + 1, r);

        merge(window2,arr, l, m, r);
    }
}

void exec_window_merge(RenderWindow& window2)//window,int window_width,int window_height,int n,bool sorted
{
    for (int i = 0; i < n; i++)
    {
        recHs[i] = (rand() % 550);
    }

    while (window2.isOpen())
    {
        sf::Event event;

        while (window2.pollEvent(event))
        {
            switch (event.type)
            {

            case sf::Event::Closed:
                window2.close();
            }
        }
        if (!sorted)
        {
            mergesortProcess(window2,0);
            mergeSort(window2,recHs, 0, n - 1);
            sorted = true;
        }
    }

}

















//////QUICK//////
void quicksortProcess(RenderWindow &window1,int index, int left, int right, int pivot)
{
    // Slow Down Process
    sf::Clock pauseClock;
    sf::Time pauseDuration = sf::seconds(0.8);
    pauseClock.restart();
    while (pauseClock.getElapsedTime() < pauseDuration)
    {
        // Do Nothing but produces delay
    }
    window1.clear();
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

        window1.draw(block);
    }
    window1.display();
}







void quickSort(RenderWindow& window1,float arr[], int left, int right)
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
        quicksortProcess(window1,k, i, j, pivot);
        k++;
    }
    // Recursively repeating
    if (left < j)
        quickSort(window1,arr, left, j);
    if (i < right)
        quickSort(window1,arr, i, right);
}




//window,int window_width,int window_height,int n,bool sorted
void exec_window_quick(RenderWindow& window1){
    float recHs[80];
    for (int i = 0; i < n; i++)
    {
        recHs[i] = (rand() % 550);
    }

    while (window1.isOpen())
    {
        sf::Event event;

        while (window1.pollEvent(event))
        {
            switch (event.type)
            {

            case sf::Event::Closed:
                window1.close();
            }
        }
        if (!sorted)
        {
            quicksortProcess(window1,0, -1, -1, recHs[n/2]);
            quickSort(window1,recHs, 0, n - 1);
            sorted = true;
        }
    }

}











int main()
{
    // create the main window
    sf::RenderWindow window(sf::VideoMode(960, 600), "SORTING VISUALIZER");

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
                    sf::RenderWindow window2(sf::VideoMode(window_width, window_height), "MERGE SORT");
                    //switch to the merge sort window
                    exec_window_merge(window2);
                }

                if (selectionText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    cout << "Selection button clicked!\n";
                    // switch to the selection sort window
                    sf::RenderWindow window3(sf::VideoMode(window_width, window_height), "MERGE SORT");
                    exec_window_selection(window3);
                }

                if (quicksortText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    cout << "Clicked Quicksort button\n";
                    // switch to the Quicksort window
                    // exec_window_quick();//window_width,window_height
                    // window.close();
                    sf::RenderWindow window1(sf::VideoMode(window_width, window_height), "QUICK SORT");
                    exec_window_quick(window1);
                }

                if (bstText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    cout << "Clicked BST button\n";
                    // switch to the BST window
                    // exec_window_bst();
                }
            }
        }
        
    }
    return 0;
}

