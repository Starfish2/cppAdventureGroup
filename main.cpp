#include <SFML/Graphics.hpp>
#include <iostream>

#define WIDE 800
#define HIGH 600

#define TILESIZE 64

int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH),"Your Face looks Like a Tortise");

  sf::CircleShape circle(40);
  circle.setFillColor(sf::Color::Red);
  circle.setPosition(100,100);

  sf::Texture hero_texture;
  if(hero_texture.loadFromFile("assets/hero.png"))
  {
    std::cout << "Error loading hero texture" << std::endl;
  }
  sf::Sprite hero;
  hero.setTexture(hero_texture);
  hero.setScale(sf::Vector2f(2,2));





  int circleDirection = 0;

  int heroSpeed = 1;

  int points =  10;

//Game Loop
  while(window.isOpen())
  {
    //Handles Events
    sf::Event event;
    while(window.pollEvent(event))
    {
      //Close Event
      if(event.type == sf::Event::Closed)
      {
        window.close();
      }

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && hero.getPosition().y > 0)
    {
      hero.move(0,-heroSpeed);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && hero.getPosition().y < HIGH-TILESIZE)
    {
      hero.move(0,heroSpeed);
    }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && hero.getPosition().x < WIDE-TILESIZE)
    {
      hero.move(heroSpeed,0);
    }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && hero.getPosition().x > 0)
      {
        hero.move(-heroSpeed,0);
      }

      if(hero.getGlobalBounds().intersects(circle.getGlobalBounds()))
      {
        std::cout << "Touching!" << std::endl;
      }
      else
      {
        std::cout << "You are not touching" << std::endl;
      }




    window.clear(sf::Color::Green);
    //Update stuff - This is Aaron
    if(circleDirection == 0)
    {
      circle.move(1,0);
    }
    else
    {
      circle.move(-1,0);
    }

    if(circle.getPosition().x > 720)
    {
      circleDirection = 1;
    }

    if(circle.getPosition().x < 0)
    {
      circleDirection = 0;
    }







    //Render - this is MEEEEE
    window.draw(hero);
    window.draw(circle);
    window.display();
  }
}
