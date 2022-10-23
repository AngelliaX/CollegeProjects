
# How to use the program

1. There's multiple folders so you need to change the command to execute the program:
    1. Run in Visual Studio Code (VSC) with Coderunner:
        - edit the cpp command to "cd $dir && g++ *.cpp ./menuHandler/*.cpp ./objects/*.cpp -o $fileNameWithoutExt && $dir$fileNameWithoutExt"
    2. Run in any kind of terminal (VSC included)
        - move to the parent's folder which contains main.cpp
        - run this command in the terminal: g++ *.cpp ./menuHandler/*.cpp ./objects/*.cpp -o main && "./"main
    
2. Edit the terminalWidth in terminalUI.h to change the line's width ("====")

# Fun fact:

1. The program was made in 7 hours and 49 minutes, within 2 days

```
  _______             _______ _           _____             _   
 |__   __|           |__   __| |         / ____|           | |  
    | |_   _ _ __   __ _| |  | |__   ___| |  __  ___   __ _| |_ 
    | | | | | '_ \ / _` | |  | '_ \ / _ \ | |_ |/ _ \ / _` | __|
    | | |_| | | | | (_| | |  | | | |  __/ |__| | (_) | (_| | |_ 
    |_|\__,_|_| |_|\__, |_|  |_| |_|\___|\_____|\___/ \__,_|\__|
                    __/ |                                       
                   |___/                                            
```
