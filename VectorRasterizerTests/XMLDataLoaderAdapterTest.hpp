#pragma once

#include "XMLDataLoaderAdapter.hpp"
#include "Shape.hpp"
#include "Point.hpp"
#include <vector>
#include <memory>
#include <string>

class XMLDataLoaderAdapterTest {
public:
    static void TestLoadPolygon();
    static void TestLoadCircle();
    static void TestLoadLine();
    static void TestLoadCurve();
};
