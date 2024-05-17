#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>

template <typename T>
class FileSaver {
public:
    virtual void save(const std::string& destination, const std::vector<T>& shapes) = 0;
    virtual ~FileSaver() = default;
};


