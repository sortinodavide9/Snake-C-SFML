#include <SFML/Graphics.hpp>
#include <iostream>//debug
#include <vector>
//variabili globali
sf::RenderWindow window(sf::VideoMode(600,600),"Snake C++/SFML");
sf::Event event;
sf::RectangleShape food(sf::Vector2f(50,50));
sf::Clock movimento;
int direction = 0; // 0 destra, 1 sinistra, 2 su, 3 giu
sf::RectangleShape head(sf::Vector2f(50,50));
int main(){   
    head.setFillColor(sf::Color(255,0,0));
    
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
        
        sf::Time elapsed = movimento.getElapsedTime();//timer per il movimento
        if(elapsed.asSeconds()>=0.2){//movimento snake    
            window.clear();
            if(direction == 0 )head.setPosition(head.getPosition().x+50,head.getPosition().y);
            if(direction == 1 )head.setPosition(head.getPosition().x-50,head.getPosition().y);
            if(direction == 2 )head.setPosition(head.getPosition().x,head.getPosition().y-50);
            if(direction == 3 )head.setPosition(head.getPosition().x,head.getPosition().y+50);  
            window.draw(head);
            window.draw(food);
            window.display();
            movimento.restart();
        }//fine movimento snake 

        //collisione snake-cibo:
        if(head.getPosition().x == food.getPosition().x && head.getPosition().y == food.getPosition().y){
            std::cout<<"touch";
            food.setPosition(200,100);
        }//fine collisione snake-cibo
        
    }//window.close()
    return 0;
}//fine Main()
    

