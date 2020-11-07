#include <SFML/Graphics.hpp>
#include <iostream>//debug
#include <vector>
//variabili globali
sf::RenderWindow window(sf::VideoMode(600,600),"Snake C++/SFML");
sf::Event event;
sf::RectangleShape food(sf::Vector2f(50,50));
sf::Clock movimento;
sf::Clock spawn;
int size = 3;
int direction = 0; // 0 destra, 1 sinistra, 2 su, 3 giu
sf::RectangleShape head(sf::Vector2f(50,50));
struct{
    int x,y;
}p[10];
int main(){  
    food.setPosition(-333,-333);
    while (window.isOpen()){
        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                case sf::Event::KeyPressed:
                    if(event.key.code==sf::Keyboard::Escape){
                        window.close();
                    }
                    else if(event.key.code==sf::Keyboard::Right){      
                        
                        direction=0;
                    }
                    else if(event.key.code==sf::Keyboard::Left){      
                        
                        direction=1;
                    }
                    else if(event.key.code==sf::Keyboard::Up){ //2 su    
                        direction=2;
                    }
                    else if(event.key.code==sf::Keyboard::Down){ //3 giu     
                        direction=3;
                    }
                    
            }
        }//End event listener
        
        sf::Time elapsed = movimento.getElapsedTime();
        sf::Time elapsed2 = spawn.getElapsedTime();
        
        if(elapsed.asSeconds()>0.2){
            window.clear();
            if(direction==0)p[0].x+=50;
            else if(direction==1)p[0].x-=50;
            else if(direction==2)p[0].y-=50;
            else if(direction==3)p[0].y+=50;
            for(int i=size;i>0;i--){
                p[i].x = p[i-1].x;
                p[i].y = p[i-1].y;
            }
            for(int i=0;i<size;i++){
                head.setPosition(p[i].x,p[i].y);
                window.draw(head);
            }
            window.draw(food);
            window.display();
            movimento.restart();
    }
    if(p[0].x==food.getPosition().x && p[0].y == food.getPosition().y){
        size+=1;
        food.setPosition(23,34);
    }
    if(elapsed2.asSeconds()>5){
            food.setPosition(150,50);
            spawn.restart();
            std::cout<<"PASS";
        }
    }//window.close()
    return 0;
}//fine Main()
    

