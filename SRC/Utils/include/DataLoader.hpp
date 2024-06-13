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


/**
 * @class DataLoader
 * @brief Abstract base class for loading shapes from a data source.
 */
class DataLoader {
public:
    /**
     * @brief Load shapes from a specified data source.
     *
     * @param source Source string specifying the data location.
     * @return Vector of unique pointers to loaded Shape objects.
     */
    virtual std::vector<std::unique_ptr<Shape>> load(const std::string& source) = 0;
    

    /**
     * @brief Virtual destructor for DataLoader.
     *
     * Ensures correct cleanup when derived classes are destroyed through base class pointers.
     */
    virtual ~DataLoader() = default;
};