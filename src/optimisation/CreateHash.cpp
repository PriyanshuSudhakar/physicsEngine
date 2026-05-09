#include "CreateHash.h"

CreateHash::CreateHash(int largePrime1, int largePrime2)
{
    this->largePrime1 = largePrime1;
    this->largePrime2 = largePrime2;
}

CreateHash::CreateHash()
{
    this->largePrime1 = 73856093;
    this->largePrime2 = 19349663;
}

int CreateHash::hashCell(int cellX, int cellY)
{
    return (cellX * 73856093) ^ (cellY * 19349663);
}