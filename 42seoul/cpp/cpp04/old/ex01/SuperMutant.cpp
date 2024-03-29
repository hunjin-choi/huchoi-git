#include "SuperMutant.hpp"

SuperMutant::SuperMutant() :Enemy(170,"Super Mutant")
{
	std::cout<<"Gaaah. Me want smash heads!"<<std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout<<"Aaargh..."<<std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &src):Enemy(src.getHp(), src.getType())
{
	std::cout<<"Gaaah. Me want smash heads!"<<std::endl;
}

SuperMutant &SuperMutant::operator=(const SuperMutant &src)
{
	this->hp = src.getHp();
	this->type = src.getType();
	return *this;
}

void SuperMutant::takeDamage(int num)
{
	if (num < 0)
		return;
	int dmg = num > 3 ? num - 3 : 0;
	this->hp -= dmg;
	if (this->hp <= 0)
		this->hp = 0;
}
