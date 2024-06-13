#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>

#include <tinyxml2.h> // Biblioteka do parsowania XML (trzeba ją dodać do projektu)

#include "DataLoader.hpp"
#include "Shape.hpp"
#include "Point.hpp"
#include "PolygonShape.hpp"
#include "ShapeBuilder.hpp"


using namespace tinyxml2;


/**
 * @class XMLDataLoaderAdapter
 * @brief Adapter class to load shapes from an XML data source.
 *
 * This class adapts DataLoader interface to load shapes specifically from XML format.
 */
class XMLDataLoaderAdapter : public DataLoader {
public:
    /**
     * @brief Load shapes from an XML source.
     *
     * @param source String containing the XML data source.
     * @return std::vector<std::unique_ptr<Shape>> Vector of unique pointers to loaded Shape objects.
     */
    std::vector<std::unique_ptr<Shape>> load(const std::string& source) override;
    
    
    /**
     * @brief Get the singleton instance of XMLDataLoaderAdapter.
     *
     * @return XMLDataLoaderAdapter& Reference to the singleton instance of XMLDataLoaderAdapter.
     */
    static XMLDataLoaderAdapter& getInstance();

private:
    XMLDataLoaderAdapter() = default;
    XMLDataLoaderAdapter(const XMLDataLoaderAdapter&) = delete;
    XMLDataLoaderAdapter& operator=(const XMLDataLoaderAdapter&) = delete;

    static XMLDataLoaderAdapter instance;
};