#include <iostream>
#include <SFML/Graphics.hpp>
#include "string.h"
#include <algorithm>
int main() {
  int width = 1920;
  int height = 1080;
  float block_size = 0;
  float block_change_speed = 50;
  float speed = 20;
  float x = 0;
  float y = 100;
  sf::Texture texture;
  if (!texture.create(width, height))
    return -1;
  sf::Uint8* pixels = new sf::Uint8[width * height * 4];
  memset(pixels,0,width*height*4);
  sf::Image image;
  sf::Sprite sprite;



  sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");
    sf::Clock clock;
    sf::Clock fps_clock;
    sf::Font font;
    if(!font.loadFromFile("/usr/share/fonts/opentype/noto/NotoSansCJK-Black.ttc")) return -1;
    sf::Text text;
    text.setFont(font);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        memset(pixels,0,width*height*4);
        float elapsed = clock.getElapsedTime().asSeconds();
        x = (int)( elapsed *speed) % width;
        block_size = 200  + std::abs((int)(elapsed * block_change_speed) % 50 -25);

        for(int i = y; i < std::min(height -1, (int)(y + block_size)); ++i){
          for(int j = x; j < std::min(width -1, (int)(x +block_size)); ++j){
            pixels[i*width*4 + j*4] = 255;
            pixels[i*width*4 + j*4 + 3] = 255;
          }
        }

        texture.update(pixels);
        sprite.setTexture(texture);
        window.draw(sprite);
        window.draw(sprite);
        float fps =1 / fps_clock.restart().asSeconds();
        text.setString(std::to_string(fps));
        window.draw(text);
        window.display();
    }

    return 0;
}
