#include "SVGDataLoaderAdapter.hpp"

SVGDataLoaderAdapter SVGDataLoaderAdapter::instance;

SVGDataLoaderAdapter& SVGDataLoaderAdapter::getInstance() {
    return instance;
}


std::vector<std::unique_ptr<Shape>> SVGDataLoaderAdapter::load(const std::string& source)
{
    // .. TODO: parsing SVG
    std::vector<std::unique_ptr<Shape>> result;
    return result;
}