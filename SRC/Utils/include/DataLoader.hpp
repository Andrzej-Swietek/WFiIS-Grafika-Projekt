#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>

#include <tinyxml2.h> // Biblioteka do parsowania XML (trzeba ją dodać do projektu)

#include "Shape.hpp"
#include "Point.hpp"


using namespace tinyxml2;

class DataLoader {
public:
    virtual std::vector<std::unique_ptr<Shape>> load(const std::string& source) = 0;
    virtual ~DataLoader() = default;
};