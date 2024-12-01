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

	mobgen = 1; // One mob will spawn at beginning
	cooldown = 3; // In 3 seconds, mob will spawn 
	timer = 0; // Current time

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
	VE = new VisualElement(GameScreenX +8, GameScreenY -4  - 64, textureMap, 0);
	VisualEntityList.push_back(VE);

	//Hearts
	VE = new VisualElement(GameScreenX +32 +16, GameScreenY - 4 - 64, textureMap, 0);
	VisualEntityList.push_back(VE);

	//Hearts
	VE = new VisualElement(GameScreenX + 64 + 24, GameScreenY - 4 - 64, textureMap, 0);
	VisualEntityList.push_back(VE);

	//Coins
	VE = new VisualElement(GameScreenX + 64 + 24+ 128, GameScreenY - 4 - 64, textureMap,2);
	VisualEntityList.push_back(VE);

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

	//btn
	btn = new Button(GameScreenX, GameScreenY + GameScreen + 16, textureMap,CurrentApp,1 );
	VisualEntityList.push_back(btn);

	// towerpic
	bg = new Background(GameScreenX + 16, GameScreenY + GameScreen + 16 + 12, textureMap, 8 * 8, 2 * 8, 8, 32, 32);
	VisualEntityList.push_back(bg);

	//Cost Coins
	VE = new VisualElement(GameScreenX, GameScreenY + GameScreen + 16 + 12 + 64, textureMap, 3);
	VisualEntityList.push_back(VE);

	//Coins Value
	texts = new Text(GameScreenX + 40, GameScreenY + +GameScreen + 20  + 64, fontMenu, 32);
	texts->setText(std::to_string(3));
	VisualEntityList.push_back(texts);

	//btn
	btn = new Button(GameScreenX + 96, GameScreenY + GameScreen + 16, textureMap, CurrentApp, 2);
	VisualEntityList.push_back(btn);

	// towerpic
	bg = new Background(GameScreenX + 112, GameScreenY + GameScreen + 16 + 12, textureMap, 7 * 8, 3 * 8, 8, 32, 32);
	VisualEntityList.push_back(bg);

	//Cost Coins
	VE = new VisualElement(GameScreenX + 96, GameScreenY + GameScreen + 16 + 12 + 64, textureMap,3);
	VisualEntityList.push_back(VE);

	//Coins Value
	texts = new Text(GameScreenX + 96 + 40, GameScreenY + +GameScreen + 20 + 64, fontMenu, 32);
	texts->setText(std::to_string(5));
	VisualEntityList.push_back(texts);

	updateHearts();
	fillPurchaseSlots(GameScreenX, GameScreenY); // Temporary until i add the option to choose tile to craft on

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

void Game::buttonPress(int _case)
{
	if (indexslots < purchaseslots.size()) {
		switch (_case) {
		case 1:
			if (coins >= 3 && indexslots <= purchaseslots.size()) {
				tower = new Tower(purchaseslots[indexslots].x, purchaseslots[indexslots].y, textureMap, 0, &mobmanager, &VisualEntityList);
				VisualEntityList.push_back(tower);
				coins -= 3;
				updateCoinsValue();
				indexslots++;
			}
			break;
		case 2:
			if (coins >= 5 && indexslots <= purchaseslots.size()) {
				tower = new Tower(purchaseslots[indexslots].x, purchaseslots[indexslots].y, textureMap, 1, &mobmanager, &VisualEntityList);
				VisualEntityList.push_back(tower);
				coins -= 5;
				updateCoinsValue();
				indexslots++;
			}
			break;
		}
	}
	else {
		std::cout << "Too many towers, cannot purchase anymore." << std::endl;
	}
}

void Game::update(float dt)
{
	timer += dt; 
	cdfastgen += dt; 
	if (mobleftgen  > 0 && cdfastgen >0.05) {
		generateMob(); 
		cdfastgen = 0; 
	}else if (timer > cooldown) {
		generateMob(); 
		timer = 0; 
	}

	Scene::update(dt);


	for (int i = 0; i < VisualEntityList.size(); i++) {
		switch (VisualEntityList[i]->getflagDestroy()) {
		case 0:
			break;
		case 1: 
			VisualEntityList[i]->setflagDestroy(2); // to make sure that we are letting all of our entity have their turn to detach themselves off from the flagged entity
			break;
		case 2:
			delete (VisualEntityList[i]); // parenthese to be SURE SURE im deleting it right
			VisualEntityList.erase(VisualEntityList.begin() + i); // Freeing space off the vector
			i--; //because i freed space, the vector has moved the content to the current index and reduced its size. 
		}
	}

	for (int i = 0; i < mobmanager.size(); i++) {
		if (mobmanager[i]->getflagDestroy() > 0) {
			mobmanager.erase(mobmanager.begin() + i);
		}
	}
}

void Game::EntityEventHandler(int _case)
{
	switch (_case) {
	case 0:
		HP--;
		updateHearts(); 
		break;
	case 1:
		coins++; 
		updateCoinsValue(); 
		break; 
	}
}

void Game::generateMob()
{
	float posx = CurrentApp->getWindow().getSize().x / 2; // Middle of window on axis X
	float posy = CurrentApp->getWindow().getSize().y / 2; // Middle of window on axis Y

	float GameScreen = 16 * 32; // entire Map is a square of 16 tiles with tiles of 32 pixels. 
	float GameScreenX = posx - (GameScreen / 2);
	float GameScreenY = posy - (GameScreen / 2);

	srand(time(NULL));
	std::cout << (rand() % 2) << std::endl;
	if ((rand() % 2) == 0) {
		e = new Mob(0, 0, textureMap, 6 * 8, 2 * 8, 8, 32, 32, 12, 25, &itinerary, CurrentApp);
	}
	else {
		e = new Mob(0, 0, textureMap, 6 * 8, 3 * 8, 8, 32, 32, 7, 40, &itinerary, CurrentApp);
	}
	VisualEntityList.push_back(e);
	mobmanager.push_back(e);
	mobleftgen--; 
	if (mobleftgen == 0) {
		mobgen += 1; 
		cooldown += 0.25; 
		mobleftgen = mobgen; 
	}

}

void Game::updateCoinsValue()
{
	for (int i = 0; i < VisualEntityList.size(); i++) {
		if (Text* texttmpt = dynamic_cast<Text*> (VisualEntityList[i])) {
			texttmpt->setText(std::to_string(coins));
			return; // I dont need to continue the loop as I only wanted the first text of the EntityList.
			// I know its not the best approach, i'd change it if I need more text to update in the game
		}
	}
}

void Game::updateHearts()
{
	if (HP == 0) {
		SceneManager::GetInstance()->ChangeScene("GameOver");
		return;
	}
	int heartfillcount=0; 
	for (int i = 0; i < VisualEntityList.size(); i++) {
		if (VisualElement* VEtmpt = dynamic_cast<VisualElement*> (VisualEntityList[i])) {
			if (VEtmpt->getVisualElementChoice() < 2) { // get visual entity that were set as hearts.
				switch (heartfillcount) {
				case 0:
					if (HP >= 1) {//heart Is full 
						VEtmpt->VisualElementTemplate(0);
					}
					else { // If not full
						VEtmpt->VisualElementTemplate(1);
					}
					heartfillcount++;
					break;
				case 1:
					if (HP >= 2) {//heart Is full 
						VEtmpt->VisualElementTemplate(0);
					}
					else { // If not full
						VEtmpt->VisualElementTemplate(1);
					}
					heartfillcount++;
					break;
				case 2:
					if (HP >= 3) { //heart Is full 
						VEtmpt->VisualElementTemplate(0);
					}
					else { // If not full
						VEtmpt->VisualElementTemplate(1);
					}
					heartfillcount++;
					break;
				}
			}
		}
	}
}

void Game::fillPurchaseSlots(float _GameScreenX, float _GameScreenY)
{
	indexslots = 0; 
	purchaseslots.push_back(sf::Vector2f(_GameScreenX + 32 * 5, _GameScreenY + 32 * 4));
	purchaseslots.push_back(sf::Vector2f(_GameScreenX + 32 * 7, _GameScreenY + 32 * 4));
	purchaseslots.push_back(sf::Vector2f(_GameScreenX + 32 * 4, _GameScreenY + 32 * 6));
	purchaseslots.push_back(sf::Vector2f(_GameScreenX + 32 * 7, _GameScreenY + 32 * 6));
	purchaseslots.push_back(sf::Vector2f(_GameScreenX + 32 * 10, _GameScreenY + 32 * 2));
	purchaseslots.push_back(sf::Vector2f(_GameScreenX + 32 * 8, _GameScreenY + 32 * 8));
	purchaseslots.push_back(sf::Vector2f(_GameScreenX + 32 * 10, _GameScreenY + 32 *4));
	purchaseslots.push_back(sf::Vector2f(_GameScreenX + 32 * 9, _GameScreenY + 32 * 3));
	purchaseslots.push_back(sf::Vector2f(_GameScreenX + 32 * 2, _GameScreenY + 32 * 11));
	purchaseslots.push_back(sf::Vector2f(_GameScreenX + 32 * 4, _GameScreenY + 32 * 11));
}

