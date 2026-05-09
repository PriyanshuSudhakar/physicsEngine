#pragma once

#include <cmath>
#include <unordered_map>
#include "../core/Object.h"
#include "CreateHash.h"

class Cells {
    private:
        float cellSize;
        std::unordered_map<int, std::vector<Object*>> spatialHash;
    public:
        Cells();
        void setCellSize(float cellSize);
        void setCellSizeByLargestRadius(float maxRadius);
        int getCellX(float x);
        int getCellY(float y);
        void buildSpatialHash(std::vector<Object*>& objects);
};