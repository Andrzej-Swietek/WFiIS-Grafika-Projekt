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
#include "Polygon.hpp"
#include "ShapeBuilder.hpp"


using namespace tinyxml2;

class XMLDataLoaderAdapter : public DataLoader {
public:
    std::vector<std::unique_ptr<Shape>> load(const std::string& source) override;

    static XMLDataLoaderAdapter& getInstance();

private:
    XMLDataLoaderAdapter() = default;
    XMLDataLoaderAdapter(const XMLDataLoaderAdapter&) = delete;
    XMLDataLoaderAdapter& operator=(const XMLDataLoaderAdapter&) = delete;

    static XMLDataLoaderAdapter instance;
};