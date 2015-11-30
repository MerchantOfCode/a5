#ifndef ENEMY_H
#define ENEMY_H
#include "Creature.h"
#include "Floor.h"


class Floor;

class Enemy : public Creature
{
protected:
	bool hostile;
	int maxHp;
public:
	Enemy(int, int, char, Floor *);
	~Enemy();
};

#endif

