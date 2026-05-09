#pragma once

class CreateHash
{
private:
    int largePrime1;
    int largePrime2;

public:
    CreateHash();
    CreateHash(int largePrime1, int largePrime2);
    int hashCell(int cellX, int cellY);
};