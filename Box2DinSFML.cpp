#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "MyRectangle.h"
#include "MyCircle.h"
#include <iostream>
#include <sstream>  // for ostringstream
#include <vector>
#include <windows.h>

//TGD 2251 - Game Physics
//PROJECT #1 - RE:Block
//Wee Tze Wei - 1131122882
//Chou Ka Weng - 1132700796



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
bool mapGenerated = false;



void generateMap(double map[20][24], b2World &world, std::vector<MyRectangle> &boxList, std::vector<MyCircle> &ballList)
{
    sf::Vector2f dynamicBoxSize(32,32);
    sf::Vector2f platformSize(64,16);
    for(int height = 0; height < 20 ; height++){
        for(int width = 0; width < 24; width++)
        {
            //standard red
            if(map[height][width] == 1){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (dynamicBoxSize.x/2), height*dynamicBoxSize.y + (dynamicBoxSize.y/2) );
                MyRectangle r(world, dynamicBoxSize, pos);
                r.setFillColor(sf::Color(255, 0, 0));
                r.setOutlineThickness(1);
                r.setOutlineColor(sf::Color::Black);
                r.type = "red";
                boxList.push_back(r);

            }
            //standard blue
            else if(map[height][width] == 2){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (dynamicBoxSize.x/2), height*dynamicBoxSize.y + (dynamicBoxSize.y/2) );
                MyRectangle r(world, dynamicBoxSize, pos);
                r.type = "blue";
                r.setFillColor(sf::Color(0, 0, 255));
                r.setOutlineThickness(1);
                boxList.push_back(r);

            }
            //standard RED: TO LEFT
            else if(map[height][width] == 3){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x, height*dynamicBoxSize.y + (dynamicBoxSize.y/2) );
                MyRectangle r(world, dynamicBoxSize, pos);
                r.setFillColor(sf::Color(255, 0, 0));
                r.setOutlineThickness(1);
                r.setOutlineColor(sf::Color::Black);
                r.type = "red";
                boxList.push_back(r);

            }
             //standard RED: TO RIGHT
            else if(map[height][width] == 4){

                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (dynamicBoxSize.x), height*dynamicBoxSize.y + (dynamicBoxSize.y/2) );
                MyRectangle r(world, dynamicBoxSize, pos);
                r.setFillColor(sf::Color(255, 0, 0));
                r.setOutlineThickness(1);
                r.setOutlineColor(sf::Color::Black);
                r.type = "red";
                boxList.push_back(r);

            }
            //standard BLUE: TO LEFT
             else if(map[height][width] == 5){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x , height*dynamicBoxSize.y + (dynamicBoxSize.y/2) );
                MyRectangle r(world, dynamicBoxSize, pos);
                r.type = "blue";
                r.setFillColor(sf::Color(0, 0, 255));
                r.setOutlineThickness(1);
                boxList.push_back(r);

            }
             //standard BLUE: TO RIGHT
            else if(map[height][width] == 6){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + dynamicBoxSize.x, height*dynamicBoxSize.y + (dynamicBoxSize.y/2) );
                MyRectangle r(world, dynamicBoxSize, pos);
                r.type = "blue";
                r.setFillColor(sf::Color(0, 0, 255));
                r.setOutlineThickness(1);
                boxList.push_back(r);

            }
             //BLUE Ball
            else if(map[height][width] == 7){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (dynamicBoxSize.x/2), height*dynamicBoxSize.y + (platformSize.y/2)  );
                MyCircle c(world, 16, pos);
                c.setFillColor(sf::Color(0, 0, 255));
                c.setOutlineThickness(1);
                c.setOutlineColor(sf::Color::Black);
                c.type = "blue";
                ballList.push_back(c);
            }

            //RED Ball
            else if(map[height][width] == -7){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (dynamicBoxSize.x/2), height*dynamicBoxSize.y + (platformSize.y/2)  );
                MyCircle c(world, 16, pos);
                c.setFillColor(sf::Color(255, 0, 0));
                c.setOutlineThickness(1);
                c.setOutlineColor(sf::Color::Black);
                c.type = "red";
                ballList.push_back(c);

            }

            //Platform
            else if(map[height][width] == 8){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (dynamicBoxSize.x/2), height*dynamicBoxSize.y + (dynamicBoxSize.y/4) );
                MyRectangle r(world, sf::Vector2f(dynamicBoxSize.x, platformSize.y), pos, 0, false);
                r.setFillColor(sf::Color(0, 0, 0));
                r.setOutlineThickness(1);
                r.type = "platform";
                boxList.push_back(r);
            }
             else if(map[height][width] == 8.1){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (dynamicBoxSize.x/2), height*dynamicBoxSize.y + (dynamicBoxSize.y/2) );
                MyRectangle r(world, sf::Vector2f(dynamicBoxSize.x, platformSize.y), pos, 0, false);
                r.setFillColor(sf::Color(0, 0, 155));
                r.setOutlineThickness(1);
                r.type = "Xplatform";
                boxList.push_back(r);

            }
            //Long Platform
            else if(map[height][width] == 9){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (platformSize.x/2), height*dynamicBoxSize.y + (platformSize.y/2) );
                MyRectangle r(world, platformSize, pos, 0, false);
                r.setFillColor(sf::Color(0, 0, 0));
                r.setOutlineThickness(1);
                r.type = "platform";
                boxList.push_back(r);

            }


            //Long Dynamic Platform
            else if(map[height][width] == -9){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (platformSize.x/2), height*dynamicBoxSize.y + (platformSize.y/2) );
                MyRectangle r(world, platformSize, pos);
                r.setFillColor(sf::Color(0, 0, 0));
                r.setOutlineThickness(1);
                r.type = "platform";
                boxList.push_back(r);

            }
            //Tilted Platform
             else if(map[height][width] == 10){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (platformSize.x/2), height*dynamicBoxSize.y + (platformSize.y/2) );
                MyRectangle r(world, platformSize, pos, 9.89, false);
                r.setFillColor(sf::Color(0, 0, 0));
                r.setOutlineThickness(1);
                r.type = "platform";
                boxList.push_back(r);
            }

            else if(map[height][width] == -10){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (platformSize.x/2), height*dynamicBoxSize.y + (platformSize.y/2) );
                MyRectangle r(world, platformSize, pos, -9.9, false);
                r.setFillColor(sf::Color(0, 0, 0));
                r.setOutlineThickness(1);
                r.type = "platform";
                boxList.push_back(r);
            }

        }
        mapGenerated = true;
      }

}



void reset(b2World &world, std::vector<MyRectangle> &boxList, std::vector<MyCircle> &ballList)
{
    for(int i=0; i<boxList.size(); i++)
    {
        world.DestroyBody(boxList[i].body_);
    }
    for(int i=0; i<ballList.size(); i++)
    {
        world.DestroyBody(ballList[i].body_);
    }
    boxList.clear();
    ballList.clear();
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
	sf::RenderWindow window(sf::VideoMode(windowSizeX, windowSizeY), "RE:Block - A block removal game");

	// Set vSync to true (and as a result, we have a cap of 60FPS)
	window.setVerticalSyncEnabled(true);
    window.setActive();

	// Create gravity and world, then assign gravity to world
	b2Vec2 gravity(0.0f, 10.0f);
	b2World world(gravity);

	// A vector/list of boxes
	std::vector<MyRectangle> boxList;
	std::vector<MyCircle> ballList;


	// Text creation
	sf::Font font = loadFont();
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(16);
	text.setPosition(3, -3);
	text.setColor(sf::Color::White);

	//Winning Text Creation
	sf::Text WinText;
	WinText.setFont(font);
	WinText.setCharacterSize(50);
	WinText.setPosition(windowSizeX/2.8, windowSizeY/3);
	WinText.setColor(sf::Color::White);

    //Instruction Text
    sf::Text InsText;
	InsText.setFont(font);
	InsText.setCharacterSize(25);
	InsText.setPosition(windowSizeX/8, windowSizeY/6);
	InsText.setColor(sf::Color::White);

	// A buffer to check whether left mouse button has been clicked before or not
	bool leftMousePressed = false;
    bool mapGenerated = false;
    bool gameOver = false;
    double map [20][24];
    int level = 1;
    sf::Text btnText1, btnText2, btnText3;

    /*
      0 = Empty
      1 = Red Box (normal position)
      2 = Blue Box (normal position)
      3 = Red Box (Move half to LEFT)
      4 = Red Box (Move half to RIGHT)
      5 = Blue Box (Move half to LEFT)
      6 = Blue Box (Move half to RIGHT)
      7 = Blue Ball
      -7 = Red Ball
      8 = Platform
      8.1 = Clickable Platform
      9 = Long Platform
      -9 = Long Dynamic Platform
      10 = Tilted Long Platform (clockwise)
      -10 = Tilted Long Platform (anti-clockwise)

    */
     double map1[20][24] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 4, 0, 3, 4, 0, 3, 4, 0, 3, 4, 0, 3, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 8.1, 0, 8.1, 8.1, 0, 8.1, 8.1, 0, 8.1, 8.1, 0, 8.1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    double map2[20][24] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 8.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, -9, 0, -9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 8, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 9, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -10, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 9, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

     double map3[20][24] = {
        {0, 0, -7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 8.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -9, 0, -9, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, -10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
bool gameStart = false;

while(window.isOpen())
{

while(!gameOver)
{


 if(!gameStart)
 {

    switch(level)
    {
        case 1:
            for(int i=0; i<20; i++)
            {
                for(int j=0; j<20; j++)
                {
                    map[i][j] = map1[i][j];
                }
            }
             gameStart = true;
            break;

        case 2:
            for(int i=0; i<20; i++)
            {
                for(int j=0; j<20; j++)
                {
                    map[i][j] = map2[i][j];
                }
            }
             gameStart = true;
            break;

        case 3:
            for(int i=0; i<20; i++)
            {
                for(int j=0; j<20; j++)
                {
                    map[i][j] = map3[i][j];
                }
            }
             gameStart = true;
            break;

        default:
            gameStart = true;
            break;
    }
    std::cout<<"Fetching Map from Hogwarts....."<<std::endl;
 }


    //calculate original number of blue boxes
    int blue = 0;
    for(int i = 0; i < boxList.size(); i++){
        if(boxList[i].type == "blue"){
            blue++;
        }
    }

    //game loop

       if(!mapGenerated)
       {
          generateMap(map,world,boxList,ballList);
          mapGenerated = true;
          std::cout<<"Maps succefully generated."<<std::endl;
       }


		sf::Event event;
		while (window.pollEvent(event));
		{
			// This is input handling via poll event
			if(event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {


			if(!leftMousePressed)
			{
			    //remove boxes with clicks
                for(int i = 0; i < boxList.size(); i++)
                {   if(boxList[i].type != "red" && boxList[i].type != "platform")
                    {

                        sf::FloatRect tempRect = boxList[i].rect_.getGlobalBounds();
                        if(tempRect.contains((sf::Vector2f)sf::Mouse::getPosition(window))){
                        world.DestroyBody(boxList[i].body_);
                        boxList.erase(boxList.begin() + i);
                        }

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
			world.Step(fixedTimeStep, 8, 3);

			// Update the objects that uses physics
            // check blue boxes
            // check red boxes
            int red = 0;
			for(int i = 0; i < boxList.size(); i++)
			{
				boxList[i].update();
				if(boxList[i].type == "red"){
                    red++;
                }
                if(boxList[i].rect_.getPosition().y > 640){
                    world.DestroyBody(boxList[i].body_);
                    boxList.erase(boxList.begin() + i);
                }
			}

			for(int i = 0; i < ballList.size(); i++)
            {
                ballList[i].update();
                if(ballList[i].type == "red"){
                    red++;
                }
                if(ballList[i].circle.getPosition().y > 640){
                    world.DestroyBody(ballList[i].body_);
                    ballList.erase(ballList.begin() + i);
                }

            }


            if(red  == 0 ){
                std::cout << "YOU WIN!" << std::endl;
                WinText.setString("YOU WIN!");
                gameOver = false;
                gameStart = false;
                mapGenerated = false;



			}
			else
            {
                WinText.setString("");
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

		for(int i = 0; i < ballList.size(); i++)
		{

            window.draw(ballList[i].getShape());
		}

		InsText.setString("Remove red blocks / balls from the scene.");
		window.draw(WinText);
        window.draw(InsText);

		window.display();

		if(!gameStart)
        {
            Sleep(2000);
            reset(world,boxList,ballList);
            level++;
        }


        if(level > 3)
        {
           level = 1;
        }



	}

}
	return 0;
}
