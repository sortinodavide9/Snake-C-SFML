#include <SFML/Graphics.hpp>
#include <iostream>//debug
#include <vector>
//variabili globali
sf::RenderWindow window(sf::VideoMode(600,600),"Snake C++/SFML");
sf::Event event;
int size = 1;
sf::RectangleShape cube(sf::Vector2f(50,50));
sf::RectangleShape food(sf::Vector2f(50,50));
int direction=0;
sf::Clock movement;
sf::Clock spawn;
struct{
    int x,y;
}p[50];
int main(){  
    food.setPosition(window.getSize().x/2, window.getSize().y/2);
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
        }//end event listener
    sf::Time elapsed = movement.getElapsedTime();
    sf::Time elapsed2 = spawn.getElapsedTime();
    if(elapsed.asSeconds()>0.2){
        window.clear();
        if(direction==0)p[0].x+=50;
        if(direction==1)p[0].x-=50;
        if(direction==2)p[0].y-=50;
        if(direction==3)p[0].y+=50;
        if(p[0].x > window.getSize().x || p[0].x<0 || p[0].y > window.getSize().y || p[0].y < 0)window.close();
        if(p[0].x == food.getPosition().x && p[0].y == food.getPosition().y){
            int tempx = rand() % 11;
            int tempy = rand() % 11;
            int randomx = tempx * 50;
            int randomy = tempy * 50;
            std::cout<<"randomx-> "<<randomx<<"\n"<<randomy<<"\n"<<tempx<<"\n"<<tempy<<"\n";
            food.setPosition(randomx, randomy);
            size++;
        }
        for(int i=size;i>0;i--){
            p[i].x = p[i-1].x;
            p[i].y = p[i-1].y;
        }
        for(int i=0;i<size;i++){
            cube.setPosition(p[i].x,p[i].y);
            window.draw(cube);
        }
        window.draw(food);
        window.display();
        movement.restart();
    }
    
    }//end game    
    return 0;    
}
    

