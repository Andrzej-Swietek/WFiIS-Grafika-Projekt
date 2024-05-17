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

using namespace tinyxml2;

class SVGDataLoaderAdapter : public DataLoader {
public:
    std::vector<std::unique_ptr<Shape>> load(const std::string& source) override;

    static SVGDataLoaderAdapter& getInstance();

private:
    SVGDataLoaderAdapter() = default;
    SVGDataLoaderAdapter(const SVGDataLoaderAdapter&) = delete;
    SVGDataLoaderAdapter& operator=(const SVGDataLoaderAdapter&) = delete;

    static SVGDataLoaderAdapter instance;
};