#include "Cells.h"

void Cells::setCellSize(float cellSize) {
    this->cellSize = cellSize;
}

void Cells::setCellSizeByLargestRadius(float maxRadius) {
    this->cellSize = 2 * maxRadius;
}

int Cells::getCellX(float x) {
    return (int)(floor(x / cellSize));
}

int Cells::getCellY(float y) {
    return (int)(floor(y / cellSize));
}

void Cells::buildSpatialHash(std::vector<Object*>& objects) {
    spatialHash.clear();
    for(auto& object:objects) {
        int cellX = getCellX(object->getCurrentCoordinates().x);
        int cellY = getCellY(object->getCurrentCoordinates().y);

        int hash = hasher.hashCell(cellX, cellY);
        spatialHash[hash].push_back(object);
    }
}