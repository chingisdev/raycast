# raycast
### primitive 2D to 3D technology reproduce

# Launching:
#### 1. git clone https://github.com/chingisdev/raycast.git && cd raycast
#### 2. make
#### 3. ./cub3D map.cub

# Configuring:
#### explaining params:
R - resolution (must be 2 values)
NO / SO / WE / EA - directions (must contain absolute path to the xpm image file)
S - texture sprite (must contain absolute path to the xpm image file)
C, F - ceiling, floor (must contain RGB value separated by coma)

MAP contains from [0-2] symbols. 0 - For the floor / 1 - for the wall / 2 - for the sprite.
The map must be surrounded by walls, in other cases will be map-parsing error.

### Feel free to test it and have a nice experience :)
