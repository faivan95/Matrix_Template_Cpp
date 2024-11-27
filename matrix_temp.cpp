#pragma once

#include "matrix_temp.h"

bool checkForString(const std::string& str) { 
    try { 
        std::stoi(str); 
        return false; 
    } 
    catch (std::exception) { 
        return true; 
    }
}