#include <SFML/Graphics.hpp>
#include <iostream>

#define WIDE 800
#define HIGH 600

#define TILESIZE 64

int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH),"Your Face looks Like a Tortise");

  sf::Texture enemy_texture;
  if(!enemy_texture.loadFromFile("assets/enemy1.png"))
  {
    std::cout << "Error loading enemy texture!"  << std::endl;
  }

  sf::Sprite enemy;
  enemy.setTexture(enemy_texture);
  enemy.setScale(sf::Vector2f(4,4));
  enemy.setPosition(100,100);

  sf::Font font;
  if(!font.loadFromFile("assets/ARCADECLASSIC.TTF"))
  {
    std::cout << "Error loading font!" << std::endl;
  }
  sf::Text livesDisp;
  livesDisp.setFont(font);
  livesDisp.setCharacterSize(32);
  livesDisp.setColor(sf::Color::Red);

  sf::Texture hero_texture;
  if(hero_texture.loadFromFile("assets/hero.png"))
  {
    std::cout << "Error loading hero texture" << std::endl;
  }
  sf::Sprite hero;
  hero.setTexture(hero_texture);
  hero.setScale(sf::Vector2f(3,3));


  sf::Texture wall_texture;
  if(!wall_texture.loadFromFile("assets/stone_wall.png"))
  {
    std::cout <<"Error loading wall texture!" << std::endl;
  }

  sf::Sprite wall;
  wall.setTexture(wall_texture);
  wall.setScale(sf::Vector2f(5,5));
  wall.setPosition(300,300);



  int enemyDirection = 0;

  int heroSpeed = 1;

  int lives =  3;
  bool takingDamage = false;

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
      if(hero.getGlobalBounds().intersects(wall.getGlobalBounds()))
      {
        hero.move(0,heroSpeed);
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && hero.getPosition().y < HIGH-TILESIZE)
    {
      hero.move(0,heroSpeed);
      if(hero.getGlobalBounds().intersects(wall.getGlobalBounds()))
      {
        hero.move(0,-heroSpeed);
      }
    }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && hero.getPosition().x < WIDE-TILESIZE)
    {
      hero.move(heroSpeed,0);
      if(hero.getGlobalBounds().intersects(wall.getGlobalBounds()))
      {
        hero.move(-heroSpeed,0);
      }
    }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && hero.getPosition().x > 0)
      {
        hero.move(-heroSpeed,0);
        if(hero.getGlobalBounds().intersects(wall.getGlobalBounds()))
        {
          hero.move(heroSpeed,0);
        }
      }
      if(hero.getGlobalBounds().intersects(enemy.getGlobalBounds()))
      {
        if(takingDamage == false)
        {
          lives--;
          takingDamage = true;
        }
      }
      else
      {
        takingDamage = false;
      }

      livesDisp.setString(std::to_string(lives));



    window.clear(sf::Color::Green);
    //Update stuff - This is Aaron
    if(enemyDirection == 0)
    {
      enemy.move(1,0);
    }
    else
    {
      enemy.move(-1,0);
    }

    if(enemy.getPosition().x > 720)
    {
      enemyDirection = 1;
    }

    if(enemy.getPosition().x < 0)
    {
      enemyDirection = 0;
    }







    //Render - this is MEEEEE
    window.draw(enemy);
    window.draw(wall);
    window.draw(hero);
    window.draw(livesDisp);
    window.display();
  }
}
