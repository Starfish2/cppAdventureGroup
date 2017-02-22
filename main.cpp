#include <SFML/Graphics.hpp>

#define WIDE 800
#define HIGH 600

int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH),"Your Face looks Like a Tortise");

  sf::CircleShape circle(40);
  circle.setFillColor(sf::Color::Red);
  circle.setPosition(1,1);

  int circleDirection = 0;

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
    window.draw(circle);
    window.display();
  }
}
