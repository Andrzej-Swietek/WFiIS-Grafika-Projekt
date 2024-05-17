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
            
            if (type == "polygon") {
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
                shapes.push_back(ShapeBuilder::buildPolygon(n, stroke, outline, fill, points));
            } 
            // Podobne sekcje dla Circle, Ellipse, Line, Curve

            else if (type == "circle") {
                int x = elem->IntAttribute("x");
                int y = elem->IntAttribute("y");
                int r = elem->IntAttribute("r");
                int stroke = elem->IntAttribute("stroke");
                std::string outline = elem->Attribute("outline");
                std::string fill = elem->Attribute("fill");
                shapes.push_back(ShapeBuilder::buildCircle(x, y, r, stroke, outline, fill));
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
                shapes.push_back(ShapeBuilder::buildLine(x, y, stroke, fill, points));
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
                shapes.push_back(ShapeBuilder::buildCurve(n, stroke, outline, fill, points));
            }
        }
        
        return shapes;
    }