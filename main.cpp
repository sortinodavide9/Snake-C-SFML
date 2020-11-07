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
    sf::Clock clockDirection;
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
    int direction;
    sf::Time elapsed= clockSpawn.getElapsedTime();
    sf::Time elapsed2 = clockMovement.getElapsedTime();
    sf::Time elapsed3 = clockDirection.getElapsedTime();
    
    if(elapsed.asSeconds()>2){//spawn system
        sf::CircleShape cerchio(10);
        cerchio.setFillColor(sf::Color(30,144,255));
        cerchio.setPosition(cerchio.getPosition().x+rand() % window.getSize().x,cerchio.getPosition().y+rand()% window.getSize().y);
        players.push_back(cerchio);
        clockSpawn.restart();
        direction=1;
    }
    if(elapsed2.asMilliseconds()>40){//movement system
        window.clear();
        for(auto &i:players){
            if(direction){//se son passati 2 sec
                int temp=rand()%2;
                if(temp==0){
                     i.move(3,0);    
                }
                else{
                    i.move(-3,0);
                }
            }
            std::cout<<direction; 
            window.draw(i);
            if(i.getPosition().x>=window.getSize().x){//se esce fuori dai bordi start
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
            }//se esce fuori dai bordi end
        }
        direction=0;
        window.display();
        clockMovement.restart();
    }//end movement system
    }//window.close()
    return 0;
}
