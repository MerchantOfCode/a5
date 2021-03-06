#ifndef FLOOR_H
#define FLOOR_H
#include "cell.h"
#include "Gold.h"
#include <vector>
#include <istream>

class Controller;
class Player;

class Floor {
	
	Player *player;					// pointer to the Player abstract class
	Controller *controller;			// Pointer so the Floor can interact with the Controller
	int level;						// tracks the level of the this floor
	std::fstream *file;
	bool alive;						// Always keeps track of the player's life to determine if dead 
	std::vector<Pos> chambers[5];	// The 5 chambers with the Cell positions

	// Private methods
	void generatePotion();
	void generateStairs();
	void generateGold();
	void generateEnemy();
	void generateDragon(int, int, Gold *);
	void clearFloor();							// clears the floor for a new level
	void makeChambers();						// After a floor has been initialized, this will create the chambers.
	void addToChamber(int, int, int);			// Adds a cell at grid[row][col] to a chamber
	void addNeighbours(int, int, int);			// Adds the neighbours of grid[row][col] to the chamber
	void updateEnemies();						//Updates the positions of all enemies on the floor
	void generatePlayer(std::string, int, int);
	
public:
	Floor(int);
	~Floor();

	Cell ***grid;					// 2d-array containing each individual cell* on the floor
	std::string actionQueue;		// stores the Action messages
	static bool dlc;				// Static variable to determine if there is dlc or not
	static bool predetermined;		// Static variable to determine if the map we read in is a save-file
	void initialize(std::string, Controller *, std::fstream *);
	void playerMove(std::string);
	void playerAttack(std::string);
	void playerUse(std::string);
	bool getPlayerHostile();					// Checks if the player has aggravated the Merchants in the current run
	void setAlive(bool);							
	bool getAlive();
	void moveLevel();
	void repositionPlayer();
	void giveGold(int x);							// gives the player x amount of gold
	void print();								// prints out the floor layout
	int chamberPos(Pos);						// Given a position, returns which chamber its in
	int getLevel();								// Returns the level that this floor is on
};

#endif


