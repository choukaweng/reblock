#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "MyRectangle.h"
#include <iostream>
#include <sstream>  // for ostringstream
#include <vector>

sf::Font loadFont(const std::string& fontFilename = "resources/04b03.ttf")
{
   sf::Font myFont;
   if (!myFont.loadFromFile(fontFilename))
   {
      std::cout << "Can not load font from " << fontFilename << std::endl;
      exit(1);
   }
   return myFont;
}



int main()
{
	// Timer for fixed update
	float fixedTimeStep = 0.02f; // 50 times per second
	sf::Clock fixedUpdateClock;
	float timeElapsedSinceLastFrame = 0;

	// Window creation
   int windowSizeX=768, windowSizeY=640;
   int windowBorderSize = 16;
	sf::RenderWindow window(sf::VideoMode(windowSizeX, windowSizeY), "Red Remover - A block removal game");

	// Set vSync to true (and as a result, we have a cap of 60FPS)
	window.setVerticalSyncEnabled(true);
   window.setActive();

	// Create gravity and world, then assign gravity to world
	b2Vec2 gravity(0.0f, 10.0f);
	b2World world(gravity);

	// A vector/list of boxes
	std::vector<MyRectangle> boxList;
	sf::Vector2f dynamicBoxSize(64,64);

	// Text creation
	sf::Font font = loadFont();
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(16);
	text.setPosition(3, -3);
	text.setColor(sf::Color::White);

	// A buffer to check whether left mouse button has been clicked before or not
	bool leftMousePressed = false;



	//GAME MAP - TZE WEI
	//One Box is 64x64, and the horizontal screen can contain 12 boxes (768)
	//vertical screen can contain 10 boxes (640)


    //map [ column numbers ][ row ]
    // column = windowSizeY/dynamicBoxSize.y;
    // row = windowSizeX/dynamicBoxSize.x;
    /*
      0 = Empty
      1 = Red Box (normal position)
      2 = Blue Box (normal position)
      3 = Red Platform
      4 = Blue Platform
      5 = Red Box (Move half to RIGHT)
      6 = Red Box (Move half to LEFT)
      7 = Blue Box (Move half to RIGHT)
      8 = Blue Box (Move half to LEFT)

    */
    int map[10][12] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 5, 0, 0, 6, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    for(int height = 0; height < 10; height++){
        for(int width = 0; width < 12; width++)
        {
            //standard red
            if(map[height][width] == 1){
                sf::Vector2f pos = sf::Vector2f( width*64 + (dynamicBoxSize.x/2), height*64 + (dynamicBoxSize.y/2) );
                MyRectangle r(world, dynamicBoxSize, pos);
                r.setFillColor(sf::Color(255, 0, 0));
                r.setOutlineThickness(1);
                r.setOutlineColor(sf::Color::Black);
                r.type = "red";
                boxList.push_back(r);
                std::cout << map[height][width] << std:: endl;
            //standard blue
            }else if(map[height][width] == 2){
                sf::Vector2f pos = sf::Vector2f( width*64 + (dynamicBoxSize.x/2), height*64 + (dynamicBoxSize.y/2) );
                MyRectangle r(world, dynamicBoxSize, pos);
                r.type = "blue";
                r.setFillColor(sf::Color(0, 0, 255));
                r.setOutlineThickness(1);
                boxList.push_back(r);
                std::cout << map[height][width] << std:: endl;
            }
            //red platform
            else if(map[height][width] == 3){
                sf::Vector2f pos = sf::Vector2f( width*64 + (dynamicBoxSize.x/2), height*64 + (dynamicBoxSize.y/2) );
                MyRectangle r(world, dynamicBoxSize, pos, 0, false);
                r.setFillColor(sf::Color(150, 0, 0));
                r.setOutlineThickness(1);
                r.type = "red";
                boxList.push_back(r);
                std::cout << map[height][width] << std:: endl;
            //blue platform
            }else if(map[height][width] == 4){
                sf::Vector2f pos = sf::Vector2f( width*64 + (dynamicBoxSize.x/2), height*64 + (dynamicBoxSize.y/2) );
                MyRectangle r(world, dynamicBoxSize, pos, 0, false);
                r.setFillColor(sf::Color(0, 0, 150));
                r.setOutlineThickness(1);
                r.type = "blue";
                boxList.push_back(r);
                std::cout << map[height][width] << std:: endl;
            //standard RED: TO RIGHT
            }else if(map[height][width] == 5){
                sf::Vector2f pos = sf::Vector2f( width*64 + (dynamicBoxSize.x), height*64 + (dynamicBoxSize.y/2) );
                MyRectangle r(world, dynamicBoxSize, pos);
                r.setFillColor(sf::Color(255, 0, 0));
                r.setOutlineThickness(1);
                r.setOutlineColor(sf::Color::Black);
                r.type = "red";
                boxList.push_back(r);
                std::cout << map[height][width] << std:: endl;
            }
            //standard RED: TO LEFT
            else if(map[height][width] == 6){
                sf::Vector2f pos = sf::Vector2f( width*64 , height*64 + (dynamicBoxSize.y/2) );
                MyRectangle r(world, dynamicBoxSize, pos);
                r.setFillColor(sf::Color(255, 0, 0));
                r.setOutlineThickness(1);
                r.setOutlineColor(sf::Color::Black);
                r.type = "red";
                boxList.push_back(r);
                std::cout << map[height][width] << std:: endl;
            }
            //standard BLUE: TO RIGHT
            else if(map[height][width] == 7){
                sf::Vector2f pos = sf::Vector2f( width*64 + (dynamicBoxSize.x), height*64 + (dynamicBoxSize.y/2) );
                MyRectangle r(world, dynamicBoxSize, pos);
                r.setFillColor(sf::Color(0, 0, 255));
                r.setOutlineThickness(1);
                r.setOutlineColor(sf::Color::Black);
                r.type = "blue";
                boxList.push_back(r);
                std::cout << map[height][width] << std:: endl;
            }
            //standard BLUE: TO LEFT
            else if(map[height][width] == 8){
                sf::Vector2f pos = sf::Vector2f( width*64 , height*64 + (dynamicBoxSize.y/2) );
                MyRectangle r(world, dynamicBoxSize, pos);
                r.setFillColor(sf::Color(0, 0, 255));
                r.setOutlineThickness(1);
                r.setOutlineColor(sf::Color::Black);
                r.type = "blue";
                boxList.push_back(r);
                std::cout << map[height][width] << std:: endl;
            }


        }
    }

    //calculate original number of blue boxes
    int blue = 0;
    for(int i = 0; i < boxList.size(); i++){
        if(boxList[i].type == "blue"){
            blue++;
        }
    }

    //game loop
	while(window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event));
		{
			// This is input handling via poll event
			// Do not use this for game input
			// Why? Delay issues
			// READ SFML DOCUMENTATION!
			if(event.type == sf::Event::Closed)
				window.close();
		}

		// This is input handling without poll event
		// READ SFML DOCUMENTATION!
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {


			if(!leftMousePressed)
			{
			    //remove boxes with clicks
                for(int i = 0; i < boxList.size(); i++)
                {
                    sf::FloatRect tempRect = boxList[i].rect_.getGlobalBounds();
                    if(tempRect.contains((sf::Vector2f)sf::Mouse::getPosition(window))){
                        world.DestroyBody(boxList[i].body_);
                        boxList.erase(boxList.begin() + i);
                    }
                }
				leftMousePressed = true;

			}
      }
		else
		{
			leftMousePressed = false;
		}

		// We get the time elapsed since last frame and add it to timeElapsedSinceLastFrame
		timeElapsedSinceLastFrame += fixedUpdateClock.restart().asSeconds();

		// If sufficient time has elapsed, we update the physics
		if(timeElapsedSinceLastFrame >= fixedTimeStep)
		{
			// Step is used to update physics position/rotation
			world.Step(fixedTimeStep, //update frequency
                    8,                //velocityIterations
                    3                 //positionIterations
                   );

			// Update the objects that uses physics
            // check blue boxes
            // check red boxes
            int reds = 0; int blueNow = 0;
			for(int i = 0; i < boxList.size(); i++)
			{
				boxList[i].update();
				if(boxList[i].type == "red"){
                    reds++;
                }else{
                    blueNow++;
                }
                if(boxList[i].rect_.getPosition().y > 640){
                    world.DestroyBody(boxList[i].body_);
                    boxList.erase(boxList.begin() + i);
                }
			}
			if(reds  == 0 && blue == blueNow){
                std::cout << "YOU WIN!" << std::endl;
			}


			// timeElapsedSinceLastFrame can be higher than fixedTimeStep,
			// so we deduct timeElapsedSinceLastFrame with fixedTimeStep
			timeElapsedSinceLastFrame -= fixedTimeStep;
		}

		// Rendering
		window.clear(sf::Color(100, 149, 237));	// CORNFLOWER BLUE!

		// Render all objects
		for(int i = 0; i < boxList.size(); i++)
		{
            window.draw(boxList[i].getShape());
		}
		std::ostringstream boxListStream;
		boxListStream << boxList.size();
		text.setString("Number of boxes: "+boxListStream.str());
		window.draw(text);
		window.display();
	}

	return 0;
}
