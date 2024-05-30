#include "XMLDataLoaderAdapterTest.hpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void XMLDataLoaderAdapterTest::TestLoadPolygon() {
    std::string xml = R"(
        <shapes>
            <polygon n="4" stroke="2" outline="black" fill="red">
                <point x="10" y="20"/>
                <point x="30" y="40"/>
                <point x="50" y="60"/>
                <point x="70" y="80"/>
            </polygon>
        </shapes>)";

    XMLDataLoaderAdapter& loader = XMLDataLoaderAdapter::getInstance();
    std::vector<std::unique_ptr<Shape>> shapes = loader.load(xml);

    Assert::AreEqual((size_t)1, shapes.size());
    Assert::IsTrue(dynamic_cast<Polygon*>(shapes[0].get()) != nullptr);

    Polygon* polygon = dynamic_cast<Polygon*>(shapes[0].get());
    Assert::AreEqual(4, polygon->getN());
    Assert::AreEqual(2, polygon->getStroke());
    Assert::AreEqual(std::string("black"), polygon->getOutline());
    Assert::AreEqual(std::string("red"), polygon->getFill());

    const std::vector<Point>& points = polygon->getPoints();
    Assert::AreEqual((size_t)4, points.size());
    Assert::AreEqual(10, points[0].x);
    Assert::AreEqual(20, points[0].y);
    Assert::AreEqual(30, points[1].x);
    Assert::AreEqual(40, points[1].y);
    Assert::AreEqual(50, points[2].x);
    Assert::AreEqual(60, points[2].y);
    Assert::AreEqual(70, points[3].x);
    Assert::AreEqual(80, points[3].y);
}

void XMLDataLoaderAdapterTest::TestLoadCircle() {
    std::string xml = R"(
        <shapes>
            <circle x="10" y="20" r="30" stroke="2" outline="black" fill="red"/>
        </shapes>)";

    XMLDataLoaderAdapter& loader = XMLDataLoaderAdapter::getInstance();
    std::vector<std::unique_ptr<Shape>> shapes = loader.load(xml);

    Assert::AreEqual((size_t)1, shapes.size());
    Assert::IsTrue(dynamic_cast<Circle*>(shapes[0].get()) != nullptr);

    Circle* circle = dynamic_cast<Circle*>(shapes[0].get());
    Assert::AreEqual(10, circle->getX());
    Assert::AreEqual(20, circle->getY());
    Assert::AreEqual(30, circle->getR());
    Assert::AreEqual(2, circle->getStroke());
    Assert::AreEqual(std::string("black"), circle->getOutline());
    Assert::AreEqual(std::string("red"), circle->getFill());
}


void XMLDataLoaderAdapterTest::TestLoadLine() {
    std::string xml = R"(
           <shapes>
               <line stroke="2" fill="black">
                   <point x="10" y="20"/>
                   <point x="30" y="40"/>
               </line>
           </shapes>)";

    XMLDataLoaderAdapter& loader = XMLDataLoaderAdapter::getInstance();
    std::vector<std::unique_ptr<Shape>> shapes = loader.load(xml);

    Assert::AreEqual((size_t)1, shapes.size());
    Assert::IsTrue(dynamic_cast<Line*>(shapes[0].get()) != nullptr);

    Line* line = dynamic_cast<Line*>(shapes[0].get());
    Assert::AreEqual(2, line->getStroke());
    Assert::AreEqual(std::string("black"), line->getFill());

    const std::vector<Point>& points = line->getPoints();
    Assert::AreEqual((size_t)2, points.size());
    Assert::AreEqual(10, points[0].x);
    Assert::AreEqual(20, points[0].y);
    Assert::AreEqual(30, points[1].x);
    Assert::AreEqual(40, points[1].y);
}

void XMLDataLoaderAdapterTest::TestLoadCurve() {
    std::string xml = R"(
           <shapes>
               <curve n="3" stroke="2" outline="black" fill="red">
                   <point x="10" y="20"/>
                   <point x="30" y="40"/>
                   <point x="50" y="60"/>
               </curve>
           </shapes>)";

    XMLDataLoaderAdapter& loader = XMLDataLoaderAdapter::getInstance();
    std::vector<std::unique_ptr<Shape>> shapes = loader.load(xml);

    Assert::AreEqual((size_t)1, shapes.size());
    Assert::IsTrue(dynamic_cast<Curve*>(shapes[0].get()) != nullptr);

    Curve* curve = dynamic_cast<Curve*>(shapes[0].get());
    Assert::AreEqual(3, curve->getN());
    Assert::AreEqual(2, curve->getStroke());
    Assert::AreEqual(std::string("black"), curve->getOutline());
    Assert::AreEqual(std::string("red"), curve->getFill());

    const std::vector<Point>& points = curve->getPoints();
    Assert::AreEqual((size_t)3, points.size());
    Assert::AreEqual(10, points[0].x);
    Assert::AreEqual(20, points[0].y);
    Assert::AreEqual(30, points[1].x);
    Assert::AreEqual(40, points[1].y);
    Assert::AreEqual(50, points[2].x);
    Assert::AreEqual(60, points[2].y);
}