# Folder Organizer (C++)

This project is a system tool that automatically sorts files within folders into separate folders based on their extensions.

## Features

* Extension Detection : Automatically identifies file types (Images, Documents, Videos etc.)
* Smart Categorization : Creates dedicated folders and moves files into their respective locations.
* Collision Safety : Prevents overwriting files with the same name during the moving process.
* Clean Architecture : Modular desing with seperate logic and extension definitions

## Project Structure

* Dateiordnen.cpp/.h : Core logic and file handling implementation.
* extensions.h : Header file containing predefined mappings for file extensions
* .gitignore : Configure to keep the repository clean from build artifacts.

## Usage

The project designed as a library.You can integrate it into your main application as follows : 

```cpp
#include "DateiOrdnen.h"
#include <string>

int main() {
    // Define the path to be organized
    std::string path = "/home/user/Downloads"; 
    
    // Call the static organize method
    FileManager::organize(path);
    
    return 0;
}
```

# Requirements

* A C++ compiler (GCC , Clang or MSVC)
* Standart Template Library (STL)

