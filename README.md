# Ping Pong Clone
A ping pong game clone. Created using the Simple DirectMedia Library (SDL).

![Preview of Ping Pong Clone](https://github.com/zenitopires/PingPong/blob/master/img/ping_pong.png)

## Workspace requirements
`git`, `make`, `gcc`

### Linux Instructions
In the the terminal type `git clone https://github.com/zenitopires/pingpong.git` to fetch the repository, `cd` into the game's directory and type `make` to build the game. Execute the game by typing `./pingpong`. 

## Dependencies
### Required
`SDL2`, `SDL_mixer`, `SDL_ttf`

### Installation on Fedora (should be similar to other Linux distros)
  (Tested recently on Fedora 31)
  
  Install the following SDL2 libraries

      $ sudo dnf install SDL2_image-devel
      $ sudo dnf install SDL2_ttf-devel
      $ sudo dnf install SDL2_mixer-devel
      $ sudo dnf install SDL2-devel
