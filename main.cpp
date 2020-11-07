#include <SFML/Graphics.hpp>
#include <iostream>//debug
#include <vector>
//variabili globali
sf::RenderWindow window(sf::VideoMode(600,600),"Snake C++/SFML");
sf::Event event;
sf::CircleShape food(20);
std::vector <sf::RectangleShape> lista;
sf::Clock movimento;
int direction = 0; // 0 destra, 1 sinistra, 2 su, 3 giu

void spawnObjects(){
    int randomx = rand()%window.getSize().x;
    int randomy = rand()%window.getSize().y;
}

int main(){   
    sf::RectangleShape snake(sf::Vector2f(50,50));
    snake.setFillColor(sf::Color(255,0,0));
    lista.push_back(snake);
    food.setPosition(300,50);
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
                    else if(event.key.code==sf::Keyboard::Key::A){ //a    
                        window.draw(food);
                    }
            }
        }//End event listener

        sf::Time elapsed = movimento.getElapsedTime();//timer per il movimento
        if(elapsed.asSeconds()>=0.7){//movimento snake
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
                window.draw(food);
                window.draw(i);
                window.display();
                window.clear();
                movimento.restart();//reset clock movimento
            }  
        }//fine movimento snake  
        //collisione snake-cibo
        if(lista[0].getPosition().x == food.getPosition().x && lista[0].getPosition().y == food.getPosition().y){
            window.close();
        }//fine collisione snake-cibo
        
        
    }//window.close()
    return 0;
}//fine Main()
    

