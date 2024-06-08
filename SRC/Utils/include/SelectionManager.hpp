#pragma once

/**
 * @class SelectionManager - sigleton class that handles shape selection and deselection
 * @brief This file contains the declaration of the SelectionManager class
    * 
    * This class is a singleton class that handles shape selection and deselection
    * 
 */
class SelectionManager
{

public:
    /**
     * @brief Get the instance of the SelectionManager
     * @return SelectionManager* - instance of the SelectionManager
     */
    static SelectionManager* getInstance();


    /**
     * @brief Select a shape by index
     * @param[in] index Index of the shape to be selected
     * @return no return
     */
    void selectShape(int index);


    /**
     * @brief Deselect a shape by index
     * @param[in] index Index of the shape to be deselected
     * @return no return
     */
    void deselectShape(int index);

    /**
     * @brief Deselect all shapes
     * @return no return
     */
    void deselectAll();


    /**
     * @brief Get the selected shape index
     * @return int - selected shape index
     * @return -1 if no shape is selected
     */
    int getSelectedShapeIndex();

    /**
     * @brief Get the selected shape index
     * @return int - selected shape index
     * @return -1 if no shape is selected
     */
    bool isShapeSelected();

private:
    SelectionManager() : selectedShapeIndex(-1) {}
    static SelectionManager* instance;
    
    int selectedShapeIndex;
};