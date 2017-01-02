#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "MyRectangle.h"
#include "MyCircle.h"

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
bool mapGenerated = false;

void generateUI()
{
    sf::Font font = loadFont();
    sf::RectangleShape lvlOneBtn = sf::RectangleShape(sf::Vector2f(100,200));
    sf::Text lvlOneBtnTxt;
    lvlOneBtnTxt.setFont(font);
	lvlOneBtnTxt.setCharacterSize(16);
	lvlOneBtnTxt.setPosition(150,150);
	lvlOneBtnTxt.setColor(sf::Color::Black);
	lvlOneBtnTxt.setString("LEVEL ONE");
	lvlOneBtn.setFillColor(sf::Color(255, 255, 255));
    lvlOneBtn.setOutlineThickness(1);
    lvlOneBtn.setOutlineColor(sf::Color::Black);



}

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

                std::cout << map[height][width] << std:: endl;

            }
            //standard blue
            else if(map[height][width] == 2){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (dynamicBoxSize.x/2), height*dynamicBoxSize.y + (dynamicBoxSize.y/2) );
                MyRectangle r(world, dynamicBoxSize, pos);
                r.type = "blue";
                r.setFillColor(sf::Color(0, 0, 255));
                r.setOutlineThickness(1);
                boxList.push_back(r);
                std::cout << map[height][width] << std:: endl;
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
                std::cout << map[height][width] << std:: endl;
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

                std::cout << map[height][width] << std:: endl;

            }
            //standard BLUE: TO LEFT
             else if(map[height][width] == 5){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x , height*dynamicBoxSize.y + (dynamicBoxSize.y/2) );
                MyRectangle r(world, dynamicBoxSize, pos);
                r.type = "blue";
                r.setFillColor(sf::Color(0, 0, 255));
                r.setOutlineThickness(1);
                boxList.push_back(r);
                std::cout << map[height][width] << std:: endl;
            }
             //standard BLUE: TO RIGHT
            else if(map[height][width] == 6){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + dynamicBoxSize.x, height*dynamicBoxSize.y + (dynamicBoxSize.y/2) );
                MyRectangle r(world, dynamicBoxSize, pos);
                r.type = "blue";
                r.setFillColor(sf::Color(0, 0, 255));
                r.setOutlineThickness(1);
                boxList.push_back(r);
                std::cout << map[height][width] << std:: endl;
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

                std::cout << map[height][width] << std:: endl;
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

                std::cout << map[height][width] << std:: endl;
            }


            //Platform
            else if(map[height][width] == 8){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (dynamicBoxSize.x/2), height*dynamicBoxSize.y + (dynamicBoxSize.y/4) );
                MyRectangle r(world, sf::Vector2f(dynamicBoxSize.x, platformSize.y), pos, 0, false);
                r.setFillColor(sf::Color(0, 0, 0));
                r.setOutlineThickness(1);
                r.type = "platform";
                boxList.push_back(r);
                std::cout << map[height][width] << std:: endl;

            }
             else if(map[height][width] == 8.1){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (dynamicBoxSize.x/2), height*dynamicBoxSize.y + (dynamicBoxSize.y/2) );
                MyRectangle r(world, sf::Vector2f(dynamicBoxSize.x, platformSize.y), pos, 0, false);
                r.setFillColor(sf::Color(0, 0, 155));
                r.setOutlineThickness(1);
                r.type = "Xplatform";
                boxList.push_back(r);
                std::cout << map[height][width] << std:: endl;

            }
            //Long Platform
            else if(map[height][width] == 9){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (platformSize.x/2), height*dynamicBoxSize.y + (platformSize.y/2) );
                MyRectangle r(world, platformSize, pos, 0, false);
                r.setFillColor(sf::Color(0, 0, 0));
                r.setOutlineThickness(1);
                r.type = "platform";
                boxList.push_back(r);
                std::cout << map[height][width] << std:: endl;

            }


            //Long Dynamic Platform
            else if(map[height][width] == -9){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (platformSize.x/2), height*dynamicBoxSize.y + (platformSize.y/2) );
                MyRectangle r(world, platformSize, pos);
                r.setFillColor(sf::Color(0, 0, 0));
                r.setOutlineThickness(1);
                r.type = "platform";
                boxList.push_back(r);
                std::cout << map[height][width] << std:: endl;

            }
            //Tilted Platform
             else if(map[height][width] == 10){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (platformSize.x/2), height*dynamicBoxSize.y + (platformSize.y/2) );
                MyRectangle r(world, platformSize, pos, 9.9, false);
                r.setFillColor(sf::Color(0, 0, 0));
                r.setOutlineThickness(1);
                r.type = "platform";
                boxList.push_back(r);
                std::cout << map[height][width] << std:: endl;

            }

            else if(map[height][width] == -10){
                sf::Vector2f pos = sf::Vector2f( width*dynamicBoxSize.x + (platformSize.x/2), height*dynamicBoxSize.y + (platformSize.y/2) );
                MyRectangle r(world, platformSize, pos, -9.9, false);
                r.setFillColor(sf::Color(0, 0, 0));
                r.setOutlineThickness(1);
                r.type = "platform";
                boxList.push_back(r);
                std::cout << map[height][width] << std:: endl;

            }




        }
        mapGenerated = true;
      }

}


void reset(std::vector<MyRectangle> &boxList, std::vector<MyCircle> &ballList, bool &gameOver)
{

    boxList.clear();
    ballList.clear();
    gameOver = false;
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

	// A buffer to check whether left mouse button has been clicked before or not
	bool leftMousePressed = false;
    bool mapGenerated = false;
    bool gameOver = false;
    double map [20][24];

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
      3 = Red Box (Move half to LEFT)
      4 = Red Box (Move half to RIGHT)
      5 = Blue Box (Move half to LEFT)
      6 = Blue Box (Move half to RIGHT)
      7 = Blue Ball
      -7 = Red Ball
      8 = Platform
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
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
bool gameStart = false;
while(!gameOver)
{


 if(!gameStart)
 {
    int choice;
    std::cout<<"WHICH MAP?"<<std::endl;
    std::cin>>choice;

    switch(choice)
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


       if(!mapGenerated)
       {
          generateMap(map,world,boxList,ballList);
          mapGenerated = true;
       }


		sf::Event event;
		while (window.pollEvent(event));
		{
			// This is input handling via poll event
			// Do not use this for game input
			// Why? Delay issues
			// READ SFML DOCUMENTATION!
//			if(event.type == sf::Event::Closed)
//				window.close();
		}





		// This is input handling without poll event
		// READ SFML DOCUMENTATION!
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
			world.Step(fixedTimeStep, //update frequency
                    8,                //velocityIterations
                    3                 //positionIterations
                   );

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
                std::cout<<"RESTART? (Y/N)"<<std::endl;
                char ans;
                std::cin>>ans;

                if(ans == 'N')
                {
                    gameOver = true;
                }
                else
                {
                    gameStart = false;
                    mapGenerated = false;
                    reset(boxList, ballList, gameOver);
                }

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



		std::ostringstream boxListStream;
		boxListStream << boxList.size();
		text.setString("Number of boxes: "+boxListStream.str());
		window.draw(text);
		window.display();
	}


	return 0;
}
