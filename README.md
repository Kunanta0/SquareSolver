-----------------
SquareSolver README
-----------------
#Console application which solves quadratic equation

SquareSolver is a program, which can solves quadratic equation (ax^2+bx+c=0, where coefficients a, b, c are being entered by user). Program can process wrong user's input. This program starts from command line. It uses 2 options from it.
Option "***--solve***" has no arguments. It starts main part of program - solving quadratic equation. Coefficients a, b, c may be any double numbers. Program solve any equation and returns which case is being realized. There are 6 cases: 0 - *quadratic equation with no roots*; 1 - *quadratic equation with one root*; 2 - *quadratic equation with two roots*; 3 - *linear equation*; 4 - *infinity number of roots*; 5 - *zero roots*, because a = 0, b = 0 and c != 0. 
Option "***--test***" has a required argument. This option runs tests from the file, which user have to write at the argument. Tests have next syntaxis {"coefficient a" "coefficient b" "coefficient c" "case" "first root" "second root"}. Parameters are being splitting by the space. If there's no one of root, you must enter zero (0). Test file must has number of lines, which is the same as number of tests.

## Instalation

1. Clone repository: 
  enter in command line: git clone https://github.com/Kunanta0/SquareSolver.git
2. Open **c++** compilator:
  use **path** in command line to the folder with compilator

## Using

1. Open project in command line:
  enter in command line: "cd>folder with project"
2. Compile project in command line:
  enter "g++ main.cpp -o <.exe file to open, auto - a.exe>"
3. Run project:
  enter "<path to .exe file> --name_of_parametr (argument if required)"

## Project structure

-  'main.cpp': Source file
-  'input.h': File with input functions
-  'output.h': File with output functions
-  'maths.h': File with maths functions
-  'my_assert.h': File with my assert
-  'testik.h': File with functions that run tests
