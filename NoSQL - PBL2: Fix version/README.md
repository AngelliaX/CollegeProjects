This project is built to run on VSC in Ubuntu

Some set-up requirement for the program to run:
1. Do as this youtube clip to install VSCode & its extensions, C++
    - This project is built to run on VSC in Ubuntu
2. Change the execute command in Code runner by:
    - Going to Extension -> Code runner -> Setting -> first setting.json
    - change the command to: "cd $dir && g++ *.cpp ./database/*.cpp ./terminalUI/*.cpp -l sqlite3 -o $fileNameWithoutExt && $dir$fileNameWithoutExt" 

3. Install c++ library:
    - nlohmann json
