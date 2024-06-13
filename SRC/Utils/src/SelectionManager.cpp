#include "SelectionManager.hpp"


SelectionManager* SelectionManager::instance = nullptr;

SelectionManager* SelectionManager::getInstance() {
    if (instance == nullptr) {
        instance = new SelectionManager();
    }
    return instance;
}


void SelectionManager::selectShape(int index) {
    if (index >= 0) {
        selectedShapeIndex = index;
    } else {
        selectedShapeIndex = -1;
    }
}



void SelectionManager::deselectShape(int index) {
    if (selectedShapeIndex == index) {
        selectedShapeIndex = -1;
    }
}

void SelectionManager::deselectAll() {
    selectedShapeIndex = -1;
}


int SelectionManager::getSelectedShapeIndex() {
    return selectedShapeIndex;
}

bool SelectionManager::isShapeSelected() {
    return getSelectedShapeIndex() != -1;
}