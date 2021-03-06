#ifndef CELL_H
#define CELL_H

class Pos {
public:
	Pos(int x, int y);
	~Pos();
	int row;
	int col;
};

class Cell
{
protected:
	int posX;
	int posY;
	char symbol;
	bool moves;
	int chamber;
	

public:
	Cell(int, int, char);
	Cell(int, int, char, bool);
	virtual ~Cell();
	bool inChamber;			// Whether the Cell has already been added to a chamber or not
	char getSymbol();		// Returns the symbol associated to this cell
	virtual int getType(); //Used for determining type of gold/potion collected
	virtual void movement();
	virtual Pos getLocation();		// Gets the cell location
	virtual int getChamber();
	virtual void setChamber(int);
};

#endif

