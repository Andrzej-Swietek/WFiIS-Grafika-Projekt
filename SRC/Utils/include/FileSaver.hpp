#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>



/**
 * @class FileSaver
 * @brief Template class for saving vectors of objects to a specified destination.
 *
 * @tparam T Type of objects to be saved.
 */
template <typename T>
class FileSaver {
public:
    /**
     * @brief Save vector of objects to a specified destination.
     *
     * @param destination Destination path where the data should be saved.
     * @param shapes Vector of objects to save.
     */
    virtual void save(const std::string& destination, const std::vector<T>& shapes) = 0;



    /**
     * @brief Virtual destructor for FileSaver.
     *
     * Ensures correct cleanup when derived classes are destroyed through base class pointers.
     */
    virtual ~FileSaver() = default;
};


