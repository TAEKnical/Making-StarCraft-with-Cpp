#include <iostream>

using namespace std;

class Marine{
	int hp; // marine`s hp
	int coord_x, coord_y; // the position
	int damage; // marine`s power
	bool is_dead; //the states
	char *name;// marine`s name

public:
	Marine(); //default constructor
	Marine(int x, int y); // make marine on coordinate (x,y)
	Marine(int x, int y, const char *marine_name);

	int attack(); // returning damage
	void be_attacked(int damage_earn); // harm damage
	void move(int x, int y); // move to the new position

	void show_states();

	~Marine();
};

Marine::Marine()
{
	hp=50;
	coord_x = coord_y =0;
	damage = 5;
	is_dead = false;
	name = NULL;
}

Marine::Marine(int x, int y)
{
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
	name = NULL;
}

Marine::Marine(int x,int y,const char*marine_name)
{
	name = new char [strlen(marine_name)+1];
	strcpy(name, marine_name);

	coord_x=x;
	coord_y=y;
	hp=50;
	damage=5;
	is_dead=false;
}

void Marine::move(int x, int y)
{
	coord_x=x;
	coord_y=y;
}

int Marine::attack()
{
	return damage;
}

void Marine::be_attacked(int damage_earn)
{
	hp-=damage_earn;
	if(hp<=0)
		is_dead=true;
}

void Marine::show_states()
{
	cout<<"***Marine:"<<name<<"***"<<endl;
	cout<<"Location : ("<<coord_x<<","<<coord_y<<")"<<endl;
	cout<<"HP : "<<hp<<endl;
}

Marine::~Marine()
{
	cout<<name<<"의 소멸자 호출!"<<endl;
	if(name!=NULL){
		delete []name;
	}
}

int main()
{
	/*Marine marine1 (5,1);
	Marine marine2 (3,7);

	marine1.show_states();
	marine2.show_states();

	cout<<endl<<"marine1 attacked marine2!"<<endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_states();
	marine2.show_states();*/

	Marine* marine[100];

	marine[0] = new Marine (99,128,"Marine0");
	marine[1] = new Marine (90,125,"Marine1");

	marine[0]->show_states();
	marine[1]->show_states();

	cout<<endl<<endl<<"marine1 attacked marine0!"<<endl;

	marine[0]->be_attacked(marine[1]->attack());
	
	marine[0]->show_states();
	marine[1]->show_states();

	delete marine[0];
	delete marine[1];
}