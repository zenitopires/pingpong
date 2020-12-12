# Ping Pong Clone
A ping pong game clone. Created using the Simple DirectMedia Library (SDL).

![Preview of Ping Pong Clone](https://github.com/zenitopires/PingPong/blob/master/img/ping_pong.png)

## Workspace requirements
`git`, `make`, `gcc`

gcc should be installed by default on Fedora (but if for some reason it isn't...)
- #### `git`, `make`, and `gcc` Fedora Installation
      $ sudo dnf install git
      $ sudo dnf install gcc
      $ sudo dnf install make

## Dependencies
### Required
`SDL2`, `SDL_mixer`, `SDL_ttf`, `SDL_image`

### SDL2
  7/1/2020 -- (Tested recently on Fedora 31)
  
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


## Usage

### Linux Instructions

    $ git clone https://github.com/zenitopires/pingpong.git
    $ cd PingPong
    $ make
    $ ./pingpong
