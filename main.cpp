#include <SFML/Graphics.hpp>
#include <iostream>//debug
#include <vector>
//variabili globali
sf::RenderWindow window(sf::VideoMode(600,600),"Snake C++/SFML");
sf::Event event;
std::vector <sf::RectangleShape> lista;
sf::Clock movimento;
int direction = 0; // 0 destra,1 sinistra, 2 su, 3 giu
int main(){   
    sf::RectangleShape snake(sf::Vector2f(50,50));
    snake.setFillColor(sf::Color(255,0,0));
    lista.push_back(snake);
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
                        if(direction!=0)direction=0;
                    }
                    else if(event.key.code==sf::Keyboard::Left){      
                        if(direction!=1)direction=1;
                    }
                    else if(event.key.code==sf::Keyboard::Up){ //2 su    
                        if(direction!=2)direction=2;
                    }
                    else if(event.key.code==sf::Keyboard::Down){ //3 giu     
                        if(direction!=3)direction=3;
                    }
            }
        }//End event listener
        sf::Time elapsed = movimento.getElapsedTime();
        
        if(elapsed.asSeconds()>=0.7){//movimento snake
            window.clear();
            for(auto &i: lista){
                switch(direction){
                    case 0://destra
                        i.setPosition(i.getPosition().x+50,i.getPosition().y);
                        break;
                    case 1://sinistra
                        i.setPosition(i.getPosition().x-50,i.getPosition().y);
                        break;
                    case 2://su
                        i.setPosition(i.getPosition().x,i.getPosition().y-50);
                        break;
                    case 3://giù
                        i.setPosition(i.getPosition().x,i.getPosition().y+50);
                        break;
                }//fine switch
                window.draw(i);
                window.display();
                movimento.restart();//reset clock movimento
            }//fine movimento
            
        }//fine movimento snake
    }//window.close()
    return 0;
}//fine Main()
    

