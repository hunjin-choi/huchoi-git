#include "Human.hpp"

std::string Human::identify() const
{
   return brain.identify();
}

const Brain &Human::getBrain() const
{
    const Brain &ret = brain;
    return (ret);
}