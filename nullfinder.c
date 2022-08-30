#include <stdio.h>

void print_grid(int grid[][7]) {
    for (int i = 0; i < 6; i++)
    {
        printf("|");
        for (int j = 0; j < 7; j++)
        {
            printf("%d|", grid[i][j]);
        }
        printf("\n");
    }
    printf("---------------\n");
}

int count_grid(int grid[][7], int s) {
    int counter = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (grid[i][j] == s)
            {
                counter += 1;
            }
        }
    }
    return counter;
}

int check_hor(int line[7], int column) {
    if (column > 2) 
    {
        return !(line[column] == line[column - 1] && 
                 line[column] == line[column - 2] && 
                 line[column] == line[column - 3]);
    }
    return 1;
}

int check_ver(int grid[][7], int line, int column) {
    if (line > 2) 
    {
        return !(grid[line][column] == grid[line - 1][column] && 
                 grid[line][column] == grid[line - 2][column] && 
                 grid[line][column] == grid[line - 3][column]);
    }
    return 1;
}

int check_diagonal1(int grid[][7], int line, int column) {
    if (line > 2 && column > 2) 
    {
        return !(grid[line][column] == grid[line - 1][column - 1] && 
                 grid[line][column] == grid[line - 2][column - 2] && 
                 grid[line][column] == grid[line - 3][column - 3]);
    }
    return 1;
}

int check_diagonal2(int grid[][7], int line, int column) {
    if (line > 2 && column < 4) 
    {
        return !(grid[line][column] == grid[line - 1][column + 1] && 
                 grid[line][column] == grid[line - 2][column + 2] && 
                 grid[line][column] == grid[line - 3][column + 3]);
    }
    return 1;
}

unsigned long solve_grid(int grid[][7], int line, int column) {
    unsigned long found = 0;

    if (column == 7) 
    {
        column = 0;
        line += 1;
    }
    if (line == 6)
    {
        return count_grid(grid, 1) == 21;
    }
    for (int i = 1; i < 3; i++) 
    {
        grid[line][column] = i;
        if (check_hor(grid[line], column) && 
            check_ver(grid, line, column) &&
            check_diagonal1(grid, line, column) &&
            check_diagonal2(grid, line, column))
        {
            found += solve_grid(grid, line, column + 1);
        }
    }
    grid[line][column] = 0;
    return found;
}

int main()
{
    int grid[6][7];

    printf("Null grids: %lu\n", solve_grid(grid, 0, 0));
    
    return 0;
}