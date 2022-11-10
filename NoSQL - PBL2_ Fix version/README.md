# Configuration:

1. Go to this file terminalUI/menuHanlder.h, edit the variable terminalWidth to adjust the length of your screen.
2. Edit your visual studio code terminal to display UTF-8 characters, or run the program from the .bat file instead

# How to execute:

1. FOR WINDOW: ``cd ./; if ($?) { g++ *.cpp ./terminalUI/*.cpp ./database/*.cpp -o main } ; if ($?) { .\main }``
2. FOR LINUX: ``cd ./; g++ *.cpp ./terminalUI/*.cpp ./database/*.cpp -o main && "./"main``
