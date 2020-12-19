# Ping Pong Clone
A ping pong game clone. Created using the Simple DirectMedia Library (SDL).

![Preview of Ping Pong Clone](https://github.com/zenitopires/PingPong/blob/master/img/ping_pong.png)

## Workspace requirements
`git`, `make`, `gcc`, `cmake`

gcc should be installed by default on Fedora (but if for some reason it isn't...)
- #### `git`, `make`, `cmake`, and `gcc` Fedora Installation
      $ sudo dnf install git
      $ sudo dnf install gcc
      $ sudo dnf install make
      $ sudo dnf install cmake

- #### Arch Linux
      $ sudo pacman -S git
      $ sudo pacman -S gcc
      $ sudo pacman -S make
      $ sudo pacman -S cmake
 



## Dependencies
### Required
`SDL2`, `SDL_mixer`, `SDL_ttf`, `SDL_image`

### SDL2

- #### SDL2 installation on Fedora

      $ sudo dnf install SDL2_image-devel
      $ sudo dnf install SDL2_ttf-devel
      $ sudo dnf install SDL2_mixer-devel
      $ sudo dnf install SDL2-devel

- #### SDL2 installation on Arch Linux
      $ sudo pacman -S sdl2
      $ sudo pacman -S sdl2_image
      $ sudo pacman -S sdl2_ttf
      $ sudo pacman -S sdl2_mixer
      
- #### Windows
  For windows download the appropriate development libraries for your MinGW compiler.
  
      $ https://www.libsdl.org/download-2.0.php
      $ https://www.libsdl.org/projects/SDL_image/
      $ https://www.libsdl.org/projects/SDL_ttf/
      $ https://www.libsdl.org/projects/SDL_ttf/

## Usage

### Linux Instructions

    $ git clone https://github.com/zenitopires/pingpong.git
    $ cd PingPong
    $ mkdir build
    $ cmake -S . -B build
    $ cd build
    $ make
    $ ./PingPong
    
### Windows Instructions
    $ git clone https://github.com/zenitopires/pingpong.git
    $ cd PingPong
    $ mkdir build
    $ cmake -S . -B build
    $ cd build
    $ mingw32-make.exe
    $ .\PingPong
