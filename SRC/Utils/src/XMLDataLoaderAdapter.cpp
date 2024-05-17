#include "XMLDataLoaderAdapter.hpp"

XMLDataLoaderAdapter XMLDataLoaderAdapter::instance;

XMLDataLoaderAdapter& XMLDataLoaderAdapter::getInstance() {
    return instance;
}


std::vector<std::unique_ptr<Shape>> XMLDataLoaderAdapter::load(const std::string& source)
 {
        std::vector<std::unique_ptr<Shape>> shapes;
        XMLDocument doc;
        doc.Parse(source.c_str());
        
        XMLElement* root = doc.RootElement();
        if (!root) return shapes;
        
        for (XMLElement* elem = root->FirstChildElement(); elem != nullptr; elem = elem->NextSiblingElement()) {
            std::string type = elem->Name();
            ShapeBuilder shapeBuilder;

            if (type == "polygon") {
                int n = elem->IntAttribute("n", 0);
                int stroke = elem->IntAttribute("stroke", 1);
                std::string outline = elem->Attribute("outline");
                std::string fill = elem->Attribute("fill");
                std::vector<Point> points;
                for (XMLElement* pointElem = elem->FirstChildElement("point"); pointElem != nullptr; pointElem = pointElem->NextSiblingElement("point")) {
                    int x = pointElem->IntAttribute("x");
                    int y = pointElem->IntAttribute("y");
                    points.push_back({ x, y });
                }

                shapeBuilder.builder()
                    ->setN(n)
                    ->setStroke(stroke)
                    ->setOutline(outline)
                    ->setFill(fill)
                    ->setPoints(points);
                Polygon p = shapeBuilder.buildPolygon();
                shapes.push_back(std::make_unique<Polygon>(p));
            } 
            // Podobne sekcje dla Circle, Ellipse, Line, Curve

            else if (type == "circle") {
                int x = elem->IntAttribute("x");
                int y = elem->IntAttribute("y");
                int r = elem->IntAttribute("r");
                int stroke = elem->IntAttribute("stroke");
                std::string outline = elem->Attribute("outline");
                std::string fill = elem->Attribute("fill");

                shapeBuilder.builder()
                    ->setX(x)
                    ->setY(y)
                    ->setR(r)
                    ->setStroke(stroke)
                    ->setOutline(outline)
                    ->setFill(fill);
                Circle c = shapeBuilder.buildCircle();
                shapes.push_back(std::make_unique<Circle>(c));
            } 
            //else if (type == "ellipse") {
            //    int r = elem->IntAttribute("r");
            //    int stroke = elem->IntAttribute("stroke");
            //    std::string outline = elem->Attribute("outline");
            //    std::string fill = elem->Attribute("fill");
            //    std::vector<Point> points;
            //    for (XMLElement* pointElem = elem->FirstChildElement("point"); pointElem != nullptr; pointElem = pointElem->NextSiblingElement("point")) {
            //        int x = pointElem->IntAttribute("x");
            //        int y = pointElem->IntAttribute("y");
            //        points.push_back({ x, y });
            //    }
            //    shapes.push_back(ShapeBuilder::buildEllipse(r, stroke, outline, fill, points));
            //}
            else if (type == "line") {
                int x = elem->IntAttribute("x");
                int y = elem->IntAttribute("y");
                int stroke = elem->IntAttribute("stroke");
                std::string fill = elem->Attribute("fill");
                std::vector<Point> points;
                for (XMLElement* pointElem = elem->FirstChildElement("point"); pointElem != nullptr; pointElem = pointElem->NextSiblingElement("point")) {
                    int px = pointElem->IntAttribute("x");
                    int py = pointElem->IntAttribute("y");
                    points.push_back({ px, py });
                }

                shapeBuilder.builder();

                Line l = shapeBuilder.buildLine();

                shapes.push_back(std::make_unique<Line>(l));
            } else if (type == "curve") {
                int n = elem->IntAttribute("n");
                int stroke = elem->IntAttribute("stroke");
                std::string outline = elem->Attribute("outline");
                std::string fill = elem->Attribute("fill");
                std::vector<Point> points;
                for (XMLElement* pointElem = elem->FirstChildElement("point"); pointElem != nullptr; pointElem = pointElem->NextSiblingElement("point")) {
                    int x = pointElem->IntAttribute("x");
                    int y = pointElem->IntAttribute("y");
                    points.push_back({ x, y });
                }

                shapeBuilder.builder();

                Curve c = shapeBuilder.buildCurve();

                shapes.push_back(std::make_unique<Curve>(c));
            }
        }
        
        return shapes;
    }