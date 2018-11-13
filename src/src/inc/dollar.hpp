#ifndef DOLLAR_HPP
#define DOLLAR_HPP

class Dollar
{
public:
    Dollar(int amount);
    void times(int mult);

public:
    int amount = { 0 };
};

#endif // DOLLAR_HPP