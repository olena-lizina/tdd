#include "dollar.hpp"

Dollar::Dollar(int amount_)
    : amount(amount_)
{

}

void Dollar::times(int mult)
{
    amount *= mult;
}