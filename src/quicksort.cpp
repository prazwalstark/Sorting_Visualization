#include<iostream>
#include<SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;

const int windowWidth = 800;
const int windowHeight = 600;
const int numLines = 100;
const int lineSpacing = 2;
const int lineHeightMax = windowHeight - 20;
const int lineHeightMin = 20;
const int sortSpeed = 10;

struct Line {
    int height;
    int posx;
    RectangleShape rectangle;

    void init(int posx, int height) {
        this->posx = posx;
        this->height = height;

        rectangle.setSize(Vector2f(6, height));
        rectangle.setFillColor(Color::White);
        rectangle.setPosition(posx, windowHeight);
        rectangle.setRotation(180);
    }

    void setColor(Color color) {
        rectangle.setFillColor(color);
    }

    void setPosition(int posx) {
        this->posx = posx;
        rectangle.setPosition(posx, windowHeight);
    }
};

void swap(Line* a, Line* b) {
    Line temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Line arr[], int low, int high) {
    int pivot = arr[high].height;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].height <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Line arr[], int low, int high, RenderWindow& appWindow) {
    if (low < high) {
        int pi = partition(arr, low, high);

        arr[pi].setColor(Color::Red);
        appWindow.clear(Color(25, 25, 112));
        for (int i = 0; i < numLines; i++) {
            appWindow.draw(arr[i].rectangle);
        }
        appWindow.display();
        arr[pi].setColor(Color::White);
        quickSort(arr, low, pi - 1, appWindow);
        quickSort(arr, pi + 1, high, appWindow);
    }
}

void exec_window() {
    RenderWindow appWindow(VideoMode(windowWidth, windowHeight), "Quick Sort");

    srand(time(NULL));

    Line lines[numLines];

    for (int i = 0; i < numLines; i++) {
        int randomh = lineHeightMin + rand() % (lineHeightMax - lineHeightMin);
        int posx = i * (lineSpacing + 6);
        lines[i].init(posx, randomh);
    }

    int low = 0;
    int high = numLines - 1;
    int pi = -1;
    std::vector<std::pair<int, int>> stack;
    stack.push_back(std::make_pair(low, high));

    while (appWindow.isOpen()) {
        Event event;
        while (appWindow.pollEvent(event)) {
            if (event.type == Event::Closed) {
                appWindow.close();
            }
        }

        if (!stack.empty()) {
            low = stack.back().first;
            high = stack.back().second;
            stack.pop_back();

            if (low < high) {
                pi = partition(lines, low, high);
                lines[pi].setColor(Color::Red);
                appWindow.clear(Color(25, 25, 112));
                for (int i = 0; i < numLines; i++) {
                    appWindow.draw(lines[i].rectangle);
                }
                appWindow.display();
                lines[pi].setColor(Color::White);

                stack.push_back(std::make_pair(low, pi - 1));
                stack.push_back(std::make_pair(pi + 1, high));
            }
        }
    }
}