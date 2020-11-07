#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>//debug
#include <vector>
#define VELOCITY 200 //diminuire per aumentare
//variabili globali
sf::Text text;
sf::Font font;
sf::RenderWindow window(sf::VideoMode(600,600),"Snake C++/SFML");
sf::Event event;
int size = 1;
sf::RectangleShape cube(sf::Vector2f(50,50));
sf::RectangleShape cubeHead(sf::Vector2f(50,50));
sf::RectangleShape food(sf::Vector2f(50,50));
int direction=0;
sf::Clock movement;
sf::Clock spawn;
void Text(int sizex){
    switch(sizex){
        case 1:
            text.setString("1");
            break;
        case 2:
            text.setString("2");
            break;
        case 3:
            text.setString("3");
            break;
        case 4:
            text.setString("4");
            break;
        case 5:
            text.setString("5");
            break;
        case 6:
            text.setString("6");
            break;
        default:
            text.setString("Too Strong");
            break;
    }
}
struct{
    int x,y;
}p[50];
int main(){ 
    font.loadFromFile("The Bugatten.ttf");
    text.setFont(font);
    text.setCharacterSize(140);
    text.setFillColor(sf::Color::Black);
    text.setPosition(20,-80);
    food.setPosition(window.getSize().x/2, window.getSize().y/2);
    food.setFillColor(sf::Color(0,0,255));
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
        if(elapsed.asMilliseconds()>VELOCITY){
        window.clear(sf::Color(128,128,128));
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
            food.setPosition(randomx, randomy);
            size++;
        }
        for(int i=1;i<=size;i++){
            if(p[0].x == p[i].x && p[0].y == p[i].y)window.close();
        }
        for(int i=size;i>0;i--){
            p[i].x = p[i-1].x;
            p[i].y = p[i-1].y;
        }
        
        
        for(int i=0;i<size;i++){
            if(i == 0){
                cubeHead.setPosition(p[0].x,p[0].y);
                cubeHead.setFillColor(sf::Color(255,0,0));
                window.draw(cubeHead);
            }
            else{
                cube.setPosition(p[i].x,p[i].y);
                window.draw(cube);
            }
                     
        }
        Text(size);
        window.draw(text);
        window.draw(food);
        window.display();
        movement.restart();
    }
    
    }//end game    
    return 0;    
}
    

