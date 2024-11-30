#include "Game.h"

Game::Game(App* app) 
{
	HP = 3; 
	coins = 5; 
	this->CurrentApp = app; 
}

void Game::init()
{
	if (!fontMenu.loadFromFile("font/arial/arial_light.ttf"))
	{
		std::cout << "Error Font" << std::endl;
	}
	if (!textureMap.loadFromFile("image/selfmadetilemap.png"))
	{
		std::cout << "Error Texture" << std::endl;
	};
	float posx = CurrentApp->getWindow().getSize().x / 2; // Middle of window on axis X
	float posy = CurrentApp->getWindow().getSize().y / 2; // Middle of window on axis Y

	// Setting Background
	bg = new Background(0, 0, textureMap, 1 * 8, 2 * 8, 8, posx * 2, posy * 2);
	VisualEntityList.push_back(bg);

	//Setting GameScreen size
	float GameScreen = 16 * 32; // entire Map is a square of 16 tiles with tiles of 32 pixels. 
	float GameScreenX = posx - (GameScreen / 2); 
	float GameScreenY = posy - (GameScreen / 2);

	//Background (Border) 
	bg = new Background(GameScreenX -4, GameScreenY -4, textureMap, 0 * 8, 2 * 8, 8, GameScreen+8, GameScreen+8);
	VisualEntityList.push_back(bg);

	//Background Screen of game
	bg = new Background(GameScreenX, GameScreenY, textureMap, 1 * 8, 3 * 8, 8, GameScreen,GameScreen);
	VisualEntityList.push_back(bg);

	// LIFE TEXT 
	bg = new Background(GameScreenX, GameScreenY - 4 - 96, textureMap, 4 * 8, 0 * 8, 8, 32*4, 32);
	bg->setVisual(textureMap, 8 * 8, 0 * 8, 8*4, 8, 32*4, 32);
	VisualEntityList.push_back(bg);

	//Hearts
	bg = new Background(GameScreenX +8, GameScreenY -4  - 64, textureMap, 6 * 8, 4 * 8, 8, 32, 32);
	VisualEntityList.push_back(bg);

	//Hearts
	bg = new Background(GameScreenX +32 +16, GameScreenY - 4 - 64, textureMap, 6 * 8, 4 * 8, 8, 32, 32);
	VisualEntityList.push_back(bg);

	//Hearts
	bg = new Background(GameScreenX + 64 + 24, GameScreenY - 4 - 64, textureMap, 7 * 8, 4 * 8, 8, 32, 32);
	VisualEntityList.push_back(bg);

	//Coins
	bg = new Background(GameScreenX + 64 + 24+ 128, GameScreenY - 4 - 64, textureMap, 6 * 8, 5 * 8, 8, 32, 32);
	VisualEntityList.push_back(bg);

	//Coins Value
	texts = new Text(GameScreenX + 256 , GameScreenY - 12 - 64, fontMenu, 32);
	texts->setText(std::to_string(coins));
	VisualEntityList.push_back(texts);


	// Setting Paths
	path = new Path(GameScreenX, GameScreenY+32*5 , textureMap, 0);
	VisualEntityList.push_back(path); 
	itinerary.push_back(path);

	path = new Path(GameScreenX +32 * 6, GameScreenY + 32 * 5, textureMap, 0);
	VisualEntityList.push_back(path);
	itinerary.push_back(path);

	path = new Path(GameScreenX + 32 * 6, GameScreenY + 32 * 2, textureMap, 0);
	VisualEntityList.push_back(path);
	itinerary.push_back(path);

	path = new Path(GameScreenX + 32 * 8, GameScreenY + 32 * 2, textureMap, 0);
	VisualEntityList.push_back(path);
	itinerary.push_back(path);

	path = new Path(GameScreenX + 32 * 8, GameScreenY + 32 * 7, textureMap, 0);
	VisualEntityList.push_back(path);
	itinerary.push_back(path);

	path = new Path(GameScreenX + 32 * 2, GameScreenY + 32 * 7, textureMap, 0);
	VisualEntityList.push_back(path);
	itinerary.push_back(path);

	path = new Path(GameScreenX + 32 * 2, GameScreenY + 32 * 10, textureMap, 0);
	VisualEntityList.push_back(path);
	itinerary.push_back(path);

	path = new Path(GameScreenX + 32 * 15, GameScreenY + 32 * 10, textureMap, 0);
	VisualEntityList.push_back(path);
	itinerary.push_back(path);

	updatePath();

	// MOBS
	e = new Mob(GameScreenX, GameScreenY + 32 * 5, textureMap, 6 * 8, 3 * 8, 8, 32, 32, 10, 100, &itinerary);
	VisualEntityList.push_back(e);
	mobmanager.push_back(e);


	e = new Mob(GameScreenX, GameScreenY + 32 * 5, textureMap, 6 * 8, 2 * 8, 8, 32, 32, 10, 25, &itinerary);
	VisualEntityList.push_back(e);
	mobmanager.push_back(e);

	//Tower
	tower = new Tower(GameScreenX + 32 * 5, GameScreenY + 32 * 4, textureMap, 1, &mobmanager, &VisualEntityList);
	VisualEntityList.push_back(tower);

	//btn
	bg = new Background(GameScreenX, GameScreenY + GameScreen + 16, textureMap, 0 * 8, 4 * 8, 16, 64, 64);
	VisualEntityList.push_back(bg);

	// towerpic
	bg = new Background(GameScreenX + 16, GameScreenY + GameScreen + 16 + 12, textureMap, 8 * 8, 2 * 8, 8, 32, 32);
	VisualEntityList.push_back(bg);

	//Cost Coins
	bg = new Background(GameScreenX, GameScreenY + GameScreen + 16 + 12 + 64, textureMap, 7 * 8, 5 * 8, 8, 32, 32);
	VisualEntityList.push_back(bg);

	//Coins Value
	texts = new Text(GameScreenX + 40, GameScreenY + +GameScreen + 20  + 64, fontMenu, 32);
	texts->setText(std::to_string(3));
	VisualEntityList.push_back(texts);

	//btn
	bg = new Background(GameScreenX + 96, GameScreenY + GameScreen + 16, textureMap, 0 * 8, 4 * 8, 16, 64, 64);
	VisualEntityList.push_back(bg);

	// towerpic
	bg = new Background(GameScreenX + 112, GameScreenY + GameScreen + 16 + 12, textureMap, 7 * 8, 3 * 8, 8, 32, 32);
	VisualEntityList.push_back(bg);

	//Cost Coins
	bg = new Background(GameScreenX + 96, GameScreenY + GameScreen + 16 + 12 + 64, textureMap, 7 * 8, 5 * 8, 8, 32, 32);
	VisualEntityList.push_back(bg);

	//Coins Value
	texts = new Text(GameScreenX + 96 + 40, GameScreenY + +GameScreen + 20 + 64, fontMenu, 32);
	texts->setText(std::to_string(5));
	VisualEntityList.push_back(texts);
}

void Game::updatePath()
// function to update visual of corner path
// Originally I wanted this function to be used if I managed to implement a feature of putting down walls. The game would have then to recalculate the path and then change the sprite accordingly. 
{
	int sizeofiti = itinerary.size();

	for (int i = 0; i <  itinerary.size(); i++) {

		if (i == sizeofiti-1) { // if Last itinerary 
			if (itinerary[i]->getPosition().x == itinerary[i - 1]->getPosition().x) { // if last itinerary is on the same position on the axis of X as previous itinerary  
				//then I set sprit of horizontal path
				itinerary[i]->updateVisualPath(1);
			}
			else {
				// otherwise vertical path
				itinerary[i]->updateVisualPath(2);
			}

			fillPath(i);
		}
		else if (i == 0) { // if first itinerary 
			if (itinerary[i]->getPosition().x == itinerary[i + 1]->getPosition().x) { // if next itinerary is on the same position on the axis of X as previous itinerary  
				//then I set sprit of horizontal path
				itinerary[i]->updateVisualPath(1);
			}
			else {
				// otherwise vertical path
				itinerary[i]->updateVisualPath(2);
			}
		}
		else { // if any itinerary but first & last
			// Then check on what axis previous itinerary & next itinerary are at to change the texture accordingly. 
			if (itinerary[i]->getPosition().x > itinerary[i - 1]->getPosition().x) { 
				if (itinerary[i + 1]->getPosition().y > itinerary[i]->getPosition().y) {
					itinerary[i]->updateVisualPath(4);
				}
				else if (itinerary[i + 1]->getPosition().y < itinerary[i]->getPosition().y) {
					itinerary[i]->updateVisualPath(3);
				}
			}
			else if (itinerary[i]->getPosition().x < itinerary[i - 1]->getPosition().x) {
				if (itinerary[i + 1]->getPosition().y > itinerary[i]->getPosition().y) {
					itinerary[i]->updateVisualPath(6);
				}
				else if (itinerary[i + 1]->getPosition().y < itinerary[i]->getPosition().y) {
					itinerary[i]->updateVisualPath(5);
				}
			}
			else if (itinerary[i]->getPosition().y > itinerary[i - 1]->getPosition().y) {
				if (itinerary[i + 1]->getPosition().x > itinerary[i]->getPosition().x) {
					itinerary[i]->updateVisualPath(5);
				}
				else if (itinerary[i + 1]->getPosition().x < itinerary[i]->getPosition().x) {
					itinerary[i]->updateVisualPath(3);
				}
			}
			else if (itinerary[i]->getPosition().y < itinerary[i - 1]->getPosition().y) {
				if (itinerary[i + 1]->getPosition().x > itinerary[i]->getPosition().x) {
					itinerary[i]->updateVisualPath(6);
				}
				else if (itinerary[i + 1]->getPosition().x < itinerary[i]->getPosition().x) {
					itinerary[i]->updateVisualPath(4);
				}
			}
			fillPath(i); 
		}
	}
}

void Game::fillPath(int _index) // Function to fill the gap between CURRENT & PREVIOUS path
// index to 
{
	float tempDistance;
	if (itinerary[_index]->getPosition().x == itinerary[_index - 1]->getPosition().x) { // if on the same axis of X 
		tempDistance = itinerary[_index]->getPosition().y - itinerary[_index - 1]->getPosition().y; 
		if (-32 <= tempDistance && tempDistance <= 32) { // check if distance is greater than 1 tile distance.
			std::cout << "no path are created" << std::endl;
		}
		else {
			float tiles = tempDistance / 32; // converting pixel to tiles
			if (tiles < 0) { // if direction is going negative ( opposite axis )
				for (int j = 1; j < -tiles; j++) { 

					path = new Path(itinerary[_index - 1]->getPosition().x, itinerary[_index - 1]->getPosition().y  - 32 * j, textureMap, 1);
					VisualEntityList.push_back(path);
				}
			}
			else {
				for (int j = 1; j < tiles; j++) {

					path = new Path(itinerary[_index - 1]->getPosition().x, itinerary[_index - 1]->getPosition().y + 32 * j, textureMap, 1);
					VisualEntityList.push_back(path);
				}
			}
		}
	}
	else if (itinerary[_index]->getPosition().y == itinerary[_index - 1]->getPosition().y) { // if on the same axis of Y
		tempDistance = itinerary[_index]->getPosition().x - itinerary[_index - 1]->getPosition().x;
		if (-32 <= tempDistance && tempDistance <= 32) { // check if distance is greater than 1 tile distance.
			std::cout << "no path are created " << std::endl;
		}
		else {
			float tiles = tempDistance / 32; // converting pixel to tiles
			if (tiles < 0) { // if direction is going negative ( opposite axis )
				for (int j = 1; j < -tiles; j++) {

					path = new Path(itinerary[_index]->getPosition().x + 32 * j, itinerary[_index - 1]->getPosition().y, textureMap, 2);
					VisualEntityList.push_back(path);
				}
			}
			else {
				for (int j = 1; j < tiles; j++) { 

					path = new Path(itinerary[_index]->getPosition().x - 32 * j, itinerary[_index - 1]->getPosition().y , textureMap, 2);
					VisualEntityList.push_back(path);
				}
			}
		}
	}
}

