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


/**
 * @class SVGDataLoaderAdapter
 * @brief Adapter class to load shapes from an SVG data source.
 *
 * This class adapts DataLoader interface to load shapes specifically from SVG format.
 */
class SVGDataLoaderAdapter : public DataLoader {
public:
    /**
     * @brief Load shapes from an SVG source.
     *
     * @param source String containing the SVG data source.
     * @return std::vector<std::unique_ptr<Shape>> Vector of unique pointers to loaded Shape objects.
     */
    std::vector<std::unique_ptr<Shape>> load(const std::string& source) override;


    /**
     * @brief Get the singleton instance of SVGDataLoaderAdapter.
     *
     * @return SVGDataLoaderAdapter& Reference to the singleton instance of SVGDataLoaderAdapter.
     */
    static SVGDataLoaderAdapter& getInstance();

private:
    SVGDataLoaderAdapter() = default;
    SVGDataLoaderAdapter(const SVGDataLoaderAdapter&) = delete;
    SVGDataLoaderAdapter& operator=(const SVGDataLoaderAdapter&) = delete;

    static SVGDataLoaderAdapter instance;
};