#include<iostream>
#include<SFML/Graphics.hpp>
#include</home/pstark/Documents/Codes/Sorting_Visualization/include/quicksort.h>
using namespace std;
using namespace sf;

int randomh=0;
int part=1;
int ite=0;
int major=0,cont=0,lims=199;

struct data{
    int height;
    int posx;
}line[200];

void exec_window(){
    RenderWindow appWindow(VideoMode(800,600),"Quick Sort");
    Event appEvent;
    // For adding background texture
    Texture fondot;
    fondot.loadFromFile("/home/pstark/Documents/Codes/Sorting_Visualization/images/fondo1.png");
    Sprite fondo(fondot);
    
    RectangleShape rectangle(Vector2f(4,178));
    rectangle.setFillColor(Color(255,255,255));
    
    srand(time(NULL));

    while(appWindow.isOpen()){
        while(appWindow.pollEvent(appEvent)){
            if(appEvent.type==Event::Closed) appWindow.close();
        }


        if(part==2){
            if(line[ite].height<line[ite+1].height){
                major = line[ite].height;
                line[ite].height = line[ite+1].height;
                line[ite+1].height = major;
            }
        }
        if(part==1){
            for(int i=0;i<200;i++)
            {
                randomh=1+rand()%(600);
                line[i].posx=i;
                line[i].height=randomh;
                if(i==199)part=2;
            }
        }

        appWindow.clear(Color::Black);
        // draw texture to background
        appWindow.draw(fondo);

        for(int i=0;i<200;i++){
            rectangle.setFillColor(Color(0,255,255));
            if(i==ite)rectangle.setFillColor(Color(255, 105, 180));
            rectangle.setPosition(line[i].posx,600);
            rectangle.setSize(Vector2f(8,line[i].height));
            rectangle.setRotation(180);
            appWindow.draw(rectangle);
        }
        appWindow.display();
        ite++;
        if(ite>=lims){
            ite=0;
            cont++;
            lims--;
        }
    }
}