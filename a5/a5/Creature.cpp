#include "Creature.h"
#include <cstdlib>
#include <math.h>
#include <string>
using namespace std;

//Calls the cell constructor 
Creature::Creature(int x, int y, char sym, Floor *flr) : Cell(x, y, sym, true), floor(flr) { }


Creature::~Creature() {

}

void Creature::loseHp(double damage) {
	hp -= damage;
	if (hp <= 0) {
		hp = 0;
		death();
	}
}

double Creature::getHp() {
	return hp;
}

string Creature::getName() {
	return name;
}

double Creature::getDefense() {
	return def;
}
