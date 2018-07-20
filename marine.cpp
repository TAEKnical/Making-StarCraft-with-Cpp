#include <iostream>

using namespace std;

class Marine{

	static int total_marine_num;
	const static int i = 0;

	int hp; // marine`s hp
	int coord_x, coord_y; // the position
	const int default_damage; // marine`s power
	bool is_dead; //the states

public:
	Marine(); //default constructor
	Marine(int x, int y); // make marine on coordinate (x,y)
	Marine(int x, int y, int default_damage);

	int attack() const; // returning damage
	Marine& be_attacked(int damage_earn); // harm damage
	void move(int x, int y); // move to the new position
	static void show_total_marine();
	~Marine(){total_marine_num--;}

	void show_states();
};

int Marine::total_marine_num = 0;

/*Marine::Marine()
{
	hp=50;
	coord_x = coord_y =0;
	damage = 5;
	is_dead = false;
	name = NULL;
}*/
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false)
{
	total_marine_num++;
}
/*Marine::Marine(int x, int y)
{
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
	name = NULL;
}*/

Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), hp(50), default_damage(default_damage), is_dead(false)
{
	total_marine_num++;
}
Marine::Marine(int x, int y) : hp(50), coord_x(x), coord_y(y), default_damage(5), is_dead(false)
{
	total_marine_num++;
}

void Marine::move(int x, int y)
{
	coord_x=x;
	coord_y=y;
}

int Marine::attack() const
{
	return default_damage;
}

Marine& Marine::be_attacked(int damage_earn)
{
	hp-=damage_earn;
	if(hp<=0)
		is_dead=true;
	return *this;
}

void Marine::show_states()
{
	cout<<"***Marine***"<<endl;
	cout<<"Location : ("<<coord_x<<","<<coord_y<<")"<<endl;
	cout<<"HP : "<<hp<<endl;
	cout<<"total_marine_number :"<<total_marine_num<<endl;
}

void create_marine()
{
	Marine marine3(10, 10, 4);
	Marine::show_total_marine();
}

void Marine::show_total_marine()
{
	cout << "the number of marines : "<< total_marine_num << endl;
}
int main()
{
	Marine marine1 (5,1);
	Marine::show_total_marine();

	Marine marine2 (3,7);
	Marine::show_total_marine();

	create_marine();
	Marine::show_total_marine();

	cout<<endl<<"marine1 attacked twice marine2!"<<endl;
	marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

	marine1.show_states();
	marine2.show_states();

	/*Marine* marine[100];

	marine[0] = new Marine (99,128,"Marine0");
	marine[1] = new Marine (90,125,"Marine1");

	marine[0]->show_states();
	marine[1]->show_states();

	cout<<endl<<endl<<"marine1 attacked marine0!"<<endl;

	marine[0]->be_attacked(marine[1]->attack());
	
	marine[0]->show_states();
	marine[1]->show_states();

	delete marine[0];
	delete marine[1];*/
}