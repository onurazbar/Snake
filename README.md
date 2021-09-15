# Snake

This is 2D snake game. Game software is developed via C++ using SFML. For more information about SFML please check the [link](https://www.sfml-dev.org/).


## Project Scheme

All source(.cpp) files are placed inside the source folder **src** and all header(.hpp) files are placed inside the folder **include**. Images that are used to create textures are placed inside the folder **image**. Fonts that are used for diplaying message box text are placed inside the folder **fonts**. There is also **GameView** folder that contains some game scenes but I do not prefer to add to the repo. So it is ignored inside gitignore. Besides there are also **Makefile** and **README** files.


## Build Instructions

If SFML is not available in your system, you need to install it before building the project. There is a **Makefile** to compile the source codes, link object files with SFML files and create the executable game file. To build the project go to root directory **Snake** and simply type below command:

**make**

During first build, all the source files will be compiled and the executable game file will be created. However in later builds, only the modified and dependent source files will be compiled again.

When building the project, object folder **obj** will be created and corresponding object files will be created under this folder. Then binary folder **bin** will be created and executable game file will be created under this folder after objects and SFML files are linked.

If you want to make a clean build by removing output folders and files, type below command:

**make clean**

This will remove **bin** and **obj** folders and all their contents. Then type **make** commmand again.

![View_2](https://user-images.githubusercontent.com/34675907/133378518-7eb3a1a0-667c-4571-bca9-60444c988162.png)


## Game Instructions

When you build the project, executable game file **snake** will be created under **bin** folder. To run the game go to **bin** folder and run the executable file like below;

**./snake**

Aim of the game is to grow the snake as much as possible by eating fruits. Every time a fruit is eaten, game score is incremented one and it is shown above next to the title. If you hit the fire on the edges or the tail of the snake game will be over. When game is over a message box is displayed with game score and game window will be closed after 5 seconds.


## Game Views

Here are some gameplay videos.

![View_3](https://github.com/onurazbar/Snake/blob/main/GameView/GamePlay_1.gif)

![View_4](https://github.com/onurazbar/Snake/blob/main/GameView/GamePlay_2.gif)

![View_5](https://github.com/onurazbar/Snake/blob/main/GameView/GamePlay_3.gif)

