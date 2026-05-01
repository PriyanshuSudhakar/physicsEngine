#include "Libs/Reader.h"


std::string Reader::readFile(const std::string& filePath) {
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);

    if (!fileStream.is_open()) {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }

    std::stringstream sstr;
    sstr << fileStream.rdbuf(); // Read the file buffer into the string stream
    content = sstr.str();       // Convert stream to string
    fileStream.close();

    return content;
}