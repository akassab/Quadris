
# Quadris

Quadris is a Tetris-like game that myself and 2 other students worked on for our final project. 

## What I learned
Model View Controller MVC pattern in C++
Observer pattern
interpreter
factory pattern

## Installation
Requires Xming for GUI : http://www.geo.mtu.edu/geoschem/docs/putty_install.html
For windows users, make sure your ssh client has X11 forwarding enabled.
For putty:
![](x11Enabled.gif)
Also make sure Xming is in your taskbar.
![](x11Enabled1.gif)
```bash
git clone https://github.com/akassab/QuadrisProject.git
cd QuadrisProjectProject/quadris
make
./quadris
```
## Usage
Input(command line only): 
"right", 
"left", 
"down",
"clockwise", 
"counterclockwise"

For faster input"
"5right,
"5left", 
"5down", 
"5clockwise, 
"5counterclockwise"

Always end your turn with "drop" 

![](example.gif)

Perfect example script:
```Shell
drop
5right drop
3right drop
clockwise drop
4right clockwise drop
clockwise 2right drop
6right drop
6right 3clockwise drop
clockwise 10right drop
5right drop
right drop
3right clockwise drop
4right drop
7right 3clockwise drop
clockwise drop
clockwise 9right drop
```

