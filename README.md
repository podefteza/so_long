# 🕹️ so_long: A 2D Game in C with MinilibX
<p align="center">
  <img src="https://github.com/podefteza/so_long/blob/main/42_porto_map.gif" alt="so_long" >
</p>

## Introduction  
**so_long** is a 2D game developed in C using the **MinilibX** graphical library. This project is part of the 42 curriculum and focuses on fundamental programming concepts such as memory management, recursive algorithms, and event-driven programming. The objective is to guide the player through a maze-like map, collect items, and reach the exit while avoiding obstacles. The project emphasizes clean code, adhering to the **Norminette** coding standard, and implementing an efficient **flood-fill algorithm** for path validation.

## Game Objective  
The player starts at a designated position on the map and must:  
- Collect all the collectibles (`C`).  
- Reach the exit (`E`) after collecting all items.  
- Avoid obstacles like walls (`1`) and potential enemies (`X` for bonus features).

## Features  
- **Custom Map Validation:** Ensures the map meets required constraints: rectangular shape, surrounded by walls, exactly one player (`P`), at least one collectible (`C`), and one exit (`E`).  
- **Path Validation with Flood Fill:** Uses a depth-first search (DFS) algorithm to verify that all collectibles and the exit are reachable.  
- **Keyboard Interaction:** Move the player using the arrow keys (`W`, `A`, `S`, `D`) or the keyboard arrows. Exit the game with the `ESC` key or the close button.  
- **Sprite-based Graphics:** Custom sprites for the player, collectibles, walls, and exit.  
- **Move Counter Display:** Displays the number of moves in the terminal.

## Project Structure  
- **`so_long.c`**: Main file that initializes the game and sets up event hooks using MinilibX.  
- **`default_variables.c`**: Initializes all game variables to default values.  
- **`file_checker.c`**: Validates the input map file for structure, characters, and boundaries.  
- **`flood_fill.c`**: Implements the flood-fill algorithm to check path validity.  
- **`game_setup.c`**: Loads the sprites and prepares the game window.  
- **`move_player.c`**: Handles player movement and sprite updates.  
- **`cleanup_and_exit.c`**: Frees allocated memory and closes the game properly.

## How It Works  
1. **Initialization**: The game reads a `.ber` map file, validates it, and loads the sprites and window.  
2. **Flood Fill Algorithm**: Ensures all collectibles and the exit are reachable.  
3. **Player Interaction**: Player moves using keyboard input. Movement updates the player’s position, collects items, and checks for win conditions.  
4. **Game End**: The game ends if the player collects all items and reaches the exit or manually quits.

## Controls  
- `W` / `↑` : Move Up  
- `A` / `←` : Move Left  
- `S` / `↓` : Move Down  
- `D` / `→` : Move Right  
- `ESC`: Quit the Game

## Compilation and Execution  
```bash
git clone https://github.com/podefteza/so_long
git clone https://github.com/42Paris/minilibx-linux
make
./so_long map_name.ber
```

## Map File Format  
The map file must follow these rules:  
- Use only the characters:  
  - `1` : Wall  
  - `0` : Empty space  
  - `P` : Player's starting position (must appear exactly once)  
  - `C` : Collectible (must have at least one)  
  - `E` : Exit (must appear exactly once)  
  - `X` : Enemy (optional, for bonus features)  
- The map must be **surrounded by walls** (`1`) on all sides.
- It must be **rectangular**, meaning all rows must have the same length.

## Example Map and Flood Fill Algorithm

The **Flood Fill algorithm** is a depth-first search (DFS) technique used to determine reachable areas in a grid, similar to how paint fills an enclosed space. It starts from a specific position (the player's initial position `P` in this case) and recursively explores adjacent cells in a predefined order.

### Process Overview:
1. **Starting Point**: The algorithm begins at `P`.
2. **Exploration Order**: It checks adjacent cells in the following order:
   - **Right** (x + 1, y)
   - **Down** (x, y + 1)
   - **Left** (x - 1, y)
   - **Up** (x, y - 1)
3. **Marking Cells**: Accessible cells (`0`, `C`, or `E`) are marked as `*` or `#` to indicate they’ve been visited.
4. **Backtracking**: If a path is blocked by walls (`1`), it backtracks to the previous cell to explore other directions.
5. **Completion**: The algorithm stops when all reachable cells are explored, ensuring all collectibles `C` and the exit `E` can be reached.

This approach guarantees that every path is explored until either all goals are met or no further moves are possible.


<p align="center">
  <img src="https://github.com/podefteza/so_long/blob/main/Exemple%20Map.png" alt="Exemple Map" height="189">
  <img src="https://github.com/podefteza/so_long/blob/main/Flood%20Fill%20Order.png" alt="Flood Fill Order" height="189">
</p>
<p align="center">
  <img src="https://github.com/podefteza/so_long/blob/main/Loaded%20Map.png" alt="Loaded Map" height="189">
  <img src="https://github.com/podefteza/so_long/blob/main/Visualization.gif" alt="Flood Fill Visualization" height="189">
</p>

## Credits:
The sprites of the characters used in the game were made by [Pixel Figures](https://www.tumblr.com/pixelfigures/68724021934/the-office-pixel-art).
