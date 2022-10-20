# Memento Mori | Style Guide

This is the c++ styling standards that you should try and use during the project to ensure a consistent coding standard across the board, you may not always be able to follow these standards but try to follow them as much as possible.

## Naming Conventions
- Files should always be named in Pascal Case formatting, this means that the first letter of each word is capitalised and there are no spaces between words.(obv - Copilot generated this)

- Classes should follow in the same suit as files, they should be named in Pascal Case formatting.

- Functions should be named in camel case formatting, along with variables.

- Enums should be named in Pascal Case formatting.


## Folder Structure
- Files are split into different modules that are compiled by the CMakeList file, these modules are split into the following categories:
    - Driver - This will run simulations and tests, it will also be the main entry point for the program.
    - Manipulation - This will contain all the functions that will be used to manipulate the simulation.
    - Creation - This will contain all the classes that can add items to the simulation.

- Each module folder contains 2 sub folders, public and private
    - Public - This will contain all the header files that are used by different modules.
    - Private - This will contain all the source files that are used by the module.

## Header File Formatting
- Classes should be formatted in the following way:
```cpp
/*                                      <-- Comment block to show author
 *  FileName.h                          <-- File name
 *  Created on: mm/dd/yyyy.             <-- Date of creation
 *  Author: Name Surname (uXXXXXXXX)    <-- Author name and student number
 */

#pragma once                <-- Compile Guard

#include "./OtherHeader.h"       <-- Include statements | Always use relative paths

↓ Comment block to explain class
/**                         
 * @brief This is a class that does something
 */
class ClassName
{                           
public:                     <-- Labels hugging the wall
    ClassName();
    ~ClassName();
    void FunctionName();
                            <--- Open line between labels 
private:
    int m_VariableName;
};

Ordering should be:
- Public
- Protected
- Private
```

## Source File Formatting
- Source files should be formatted in the following way:
```cpp
/*                                      <-- Comment block to show author
 *  FileName.cpp                        <-- File name
 *  Created on: mm/dd/yyyy.             <-- Date of creation
 *  Author: Name Surname (uXXXXXXXX)    <-- Author name and student number
 */

#include "../public/ClassHeader.h"      <-- Include statements | Always use relative paths

↓ Comment block to explain function
/**
 * @brief This is a function that does something
 * @param ParameterName - This is a parameter that does something
 * @return This is a return value that does something
 */
void FunctionName(int ParameterName){
    //...
}

Ordering within documentation should be:
- brief
- Parameters
- Return   

```