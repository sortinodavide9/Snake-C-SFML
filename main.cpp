#include "headers/Game.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>//debug
#include <vector>
#define AGGIORNAMENTO 80 //ogni quanto si reindirizzano gli oggetti
//variabili globali
sf::Event event;
std::vector <sf::CircleShape> players;
std::vector <sf::CircleShape> enemies;
Game *player;

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(800,600),"sf");
    sf::Clock clockSpawn;//orologio spawn
    sf::Clock clockMovement;//orologio movimento
    while (window.isOpen())
    {
        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                case sf::Event::KeyPressed:
                    if(event.key.code==sf::Keyboard::Escape){
                        window.close();
                    }
                    else if(event.key.code==sf::Keyboard::Right){      
                        
                    }
            }
        }//End event listener
    sf::Time elapsed= clockSpawn.getElapsedTime();
    sf::Time elapsed2= clockMovement.getElapsedTime();
    if(elapsed.asSeconds()>2){//spawn system
        sf::CircleShape cerchio(10);
        cerchio.setFillColor(sf::Color(30,144,255));
        cerchio.setPosition(cerchio.getPosition().x+rand() % window.getSize().x,cerchio.getPosition().y+rand()% window.getSize().y);
        players.push_back(cerchio);
        clockSpawn.restart();
    }
    if(elapsed2.asMilliseconds()>AGGIORNAMENTO){//movement system
        window.clear();
        for(auto &i:players){
            int temp = rand()%2;
            switch(temp){
                case 0:
                    i.move(rand()%80-40,0);//
                case 1:
                     i.move(0,rand()%80-40);
            }
            window.draw(i);
            if(i.getPosition().x>=window.getSize().x){
                i.setPosition(window.getSize().x-100,i.getPosition().y);
            }  
            else if(i.getPosition().x<=0){
                i.setPosition(100,i.getPosition().y);
            }
            else if(i.getPosition().y<=0){
                i.setPosition(i.getPosition().x,100);
            }
            else if(i.getPosition().y>=window.getSize().y){

                i.setPosition(i.getPosition().x,window.getSize().y-100);
            }
        }
        window.display();
        clockMovement.restart();
    }
    }//window.close()
    return 0;
}
