def print_grid(grid):
    for line in grid:
        print("|" + "|".join([str(i).replace("1","x").replace("2","*") for i in line]) + "|")
    print("-" * (len(grid[0]) * 2 + 1))

def count_grid(grid, s):
    counter = 0
    for line in grid:
        counter += line.count(s)
    return counter

# x x x x pattern
def check_hor(line, column):
    if column > 2:
        return not (line[column] == line[column - 1] and 
                    line[column] == line[column - 2] and 
                    line[column] == line[column - 3])
    return True

# x pattern
# x
# x
# x
def check_ver(grid, line, column):
    if line > len(grid) - 4:
        return not (grid[line][column] == grid[line - 1][column] and 
                    grid[line][column] == grid[line - 2][column] and 
                    grid[line][column] == grid[line - 3][column])
    return True

# x    pattern
#  x
#   x
#    x
def check_diagonal1(grid, line, column):
    if line > 2 and column > 2:
        return not (grid[line][column] == grid[line - 1][column - 1] and 
                    grid[line][column] == grid[line - 2][column - 2] and 
                    grid[line][column] == grid[line - 3][column - 3])
    return True

#    x pattern
#   x
#  x
# x
def check_diagonal2(grid, line, column):
    if line > 2 and column < len(grid[line]) - 3:
        return not (grid[line][column] == grid[line - 1][column + 1] and 
                    grid[line][column] == grid[line - 2][column + 2] and 
                    grid[line][column] == grid[line - 3][column + 3])
    return True

def solve_grid(grid, line, column):
    found = 0
    
    if column == len(grid[line]):
        column = 0
        line += 1
    if line == 6:
        # print_grid(grid)
        return count_grid(grid, 1) == 21
    for player in [1, 2]:
        grid[line][column] = player
        if (check_hor(grid[line], column) and 
            check_ver(grid, line, column) and
            check_diagonal1(grid, line, column) and
            check_diagonal2(grid, line, column)):
            found += solve_grid(grid, line, column + 1)
    grid[line][column] = 0
    return found

grid = [[0 for _ in range(7)] for _ in range(6)]

try:
    print(solve_grid(grid, 0, 0))
except KeyboardInterrupt:
    print("Computation canceled by user")