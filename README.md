# ColorConverter

## Description

**Version 2.0**

A project that converts inputed RGB values into approximations of what those with various types of color blindness would see

**Updates**
- Added Achromatopsia as selectable color blindness type.
- Merged the three seperate Protanopia, Deutranopia, and Tritanopia functions into one function, to ease adding other types of color vision in the future.
- Reorganized code for easier readability and expandability.

## Developer

Caleb Sweeney

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
Please enter P for Protanopia, D for Deutranopia, T for Tritanopia, or A for Achromatopsia (Enter any other letter to exit the program):
R
Please enter three numbers, for R, G, and B. (from 0-255, inclusive):
200 050 000
Protanopia R G B: 135 133 12
Please enter R for Protanopia, G for Deutranopia, and B for Tritanopia (Enter any other letter to exit the program):
f
You have exited the program :(
 
```
