#pragma once
#include "..\SGPE\Canvas.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include "TileManager.hpp"
#include "Tile.hpp"
#include "UniqueTile.hpp"
#include "LevelManagerPocketAnimalsSync.hpp"
#include "PopUp.hpp"
#include "Battle.hpp"
#include "Tracking.hpp"

#include "..\BattleSystem\InterLevelData.hpp"
#include "..\BattleSystem\BattlePlayer.hpp"

//TODO:	Player als laatste renderen.

class Grid : public Canvas {
private:
	std::vector<Tile*> tileVec;
	std::vector<UniqueTile*> unique;
	std::vector<Tile*> npcVec;
	sf::Vector2f playerPosition;
	unsigned int playerIndex;
	unsigned int playerTileIndex;
	unsigned int width;
	unsigned int tileSize;
	unsigned int moveTime;
	std::map<std::string, int> directionMap;
	std::shared_ptr<LevelManagerPocketAnimalsSync> levelSync;
	std::shared_ptr<PopUp> dialog;
	sf::View minimap;
	std::shared_ptr<NPCTracker> npcs;
	std::shared_ptr<PlayerProgress> pg;
	Battle battle;
	bool battleStarted = false;
	bool battleReturned = false;
	std::shared_ptr<InterLevelData> interLevelData;
	std::shared_ptr<BattlePlayer> battlePlayer;


public:
	Grid(TileManager & tileManager, unsigned int width, unsigned int tileSize, std::shared_ptr<LevelManagerPocketAnimalsSync> levelSync, std::shared_ptr<PopUp> dialog,
		std::shared_ptr<NPCTracker> npcs,
		std::shared_ptr<PlayerProgress> pg,
		std::shared_ptr<InterLevelData> interLevelData,
		std::shared_ptr<BattlePlayer> battlePlayer);
	Grid() {};
	void Render(std::shared_ptr<sf::RenderWindow> w);
	void AfterBattleSwitch();
	void update(float &dT);
	void draw(std::shared_ptr<sf::RenderWindow> w);
	void movePlayer(std::string direction);
	void moveNpc(unsigned int id, std::string direction, unsigned int time);
	int checkDirection(std::string direction);
	void setupMap(nlohmann::json::array_t &gridData);
	unsigned int move(unsigned int currentIndex, int ID, std::string direction);
	sf::Vector2f getPlayerPos();
	unsigned int getPlayerIndex();
	sf::Vector2f convertIndextoCoords(unsigned int index);
	void setPlayerIndex(unsigned int index);
	void setPlayerPosition(sf::Vector2f pos);
	void appendTile(Tile* toAdd) {
		tileVec.push_back(toAdd);
	}
	void updatePlayerIndex();
	~Grid();
};
