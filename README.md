# cub3D

cub3D is a simple 3D game engine project inspired by early raycasting games like Wolfenstein 3D. It is developed as part of the 42 school curriculum, focusing on understanding raycasting, graphics, and basic game mechanics in C.

## Features
- Raycasting engine for 3D rendering
- Textured walls and basic map parsing
- Player movement and rotation
- Simple collision detection
- Configurable map files
- Bonus: Additional features (see `src_bonus/`)

## Installation & Compilation

### Prerequisites
- GCC or Clang (C compiler)
- `make`
- X11 development libraries (for graphics)
- MinilibX (usually provided or included in 42 projects)

### Build
Clone the repository and compile the project:

```sh
make
```
For the bonus version:
```sh
make bonus
```

## Usage
Run the program with a map file:

```sh
./cub3D <map_file.cub>
```

Example:
```sh
./cub3D maps/valid.cub
```

## Map Format
Map files (`.cub`) define the world layout and textures. Example:

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0
111111
100001
1000N1
111111
```
- `NO`, `SO`, `WE`, `EA`: Texture paths for each wall direction
- `F`, `C`: Floor and ceiling colors (RGB)
- Map: 1 = wall, 0 = empty space, N/S/E/W = player start position and orientation

## Controls
- `W`, `A`, `S`, `D`: Move forward, left, backward, right
- Arrow keys: Rotate view
- `ESC`: Exit the game

## Dependencies
- Standard C library
- MinilibX (graphics library)
- X11 libraries (Linux/macOS)

## Project Structure
```
cub3D/
├── incl/         # Header files
├── libft/        # Custom C library (libft)
├── maps/         # Example map files
├── src/          # Main source code
├── src_bonus/    # Bonus features
├── textures/     # XPM texture files
├── Makefile      # Build script
```
