#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// This function read a file and create a table with the integer view
// Parameters :
//     a : number of rows (int)
//     b : number of cols (int)
// return :
//     A table with all the sudoku table in the file
int** create_table(int rows, int cols) {
    int** arr = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*) malloc(cols * sizeof(int));
    }
    FILE* file = fopen("/home/leelou/Documents/Programmation/sudoku_c/text.txt", "r");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return arr;
    }
    char* ligne = (char*) malloc(100 * sizeof(char));
    if (ligne == NULL) {
        printf("Impossible d'allouer la mémoire.\n");
        return arr;
    }
    int i = 0;
    while (fgets(ligne, 100, file) != NULL && i < rows) {
        char* tok = strtok(ligne, "\n");
        int j = 0;
        int v = 0;
        int c = 0;
        while (tok != NULL && j < cols) {
            while(tok[v]){
              c = tok[v] - 48;
              arr[i][j] = c;
              v++;
              j++;
            }
            i++;
            tok = strtok(NULL, "\n");
        }
    }
    fclose(file);
    free(ligne);
    return arr;
}

// This function dree the memory allocation of our sudoku table
// Parameters :
//     arr : sudoku table (int**)
//     rows : number of rows (int)
void free_table(int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

// This function print the sudoku table
// Parameters :
//     arr : sudoku table (int**)
//     rows : number of rows (int)
//     cols : numbe of cols (int)
void display_table(int** arr, int rows, int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%i ", arr[i][j]);
        }
        printf("\n");
    }
}

// This function allow us to find the next empty case
// Parameters :
//     arr : sudoku table (int**)
//     rows : number of rows (int)
//     col : number of col (int)
// return :
//     If the sudoku is solve or not
bool find_empty_cell(int **arr, int* row, int* col) {
    // Trouver la prochaine case vide dans la grille.
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (arr[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// This function read a file and create a table with the integer view
// Parameters :
//     a : number of rows (int)
//     b : number of cols (int)
// return :
//     A table with all the sudoku table in the file
bool is_valid(int **arr, int row, int col, int num) {
    // Verification of the number in one specific case

    // Verification of the row
    for (int i = 0; i < 9; i++) {
        if (arr[row][i] == num) {
            return false;
        }
    }

    // Verification of the col
    for (int i = 0; i < 9; i++) {
        if (arr[i][col] == num) {
            return false;
        }
    }

    // Verification in 3x3
    int region_row = (row / 3) * 3;
    int region_col = (col / 3) * 3;
    for (int i = region_row; i < region_row + 3; i++) {
        for (int j = region_col; j < region_col + 3; j++) {
            if (arr[i][j] == num) {
                return false;
            }
        }
    }

    // If all the verification didn't fail, the number is valid
    return true;
}

// This function is the sudoku solver
// Parameters :
//     arr : sudoku table (int **)
// return :
//     A table with all the sudoku table in the file
bool solve_sudoku(int **arr) {
    int row, col;
    if (!find_empty_cell(arr, &row, &col)) {
        // If the grid is full, the solution is find
        return true;
    }

    // Try every number possible in this case
    for (int num = 1; num <= 9; num++) {
        if (is_valid(arr, row, col, num)) {
            arr[row][col] = num;

            // Recursive
            if (solve_sudoku(arr)) {
                return true;
            }

            // If none number is found, reinitialisation of the case
            arr[row][col] = 0;
        }
    }

    // If all the number didn't work, the solution of the grid can't be found
    return false;
}


int main(){
    // Initialisation of the cols and rows
    int rows = 9;
    int cols = 9;

    // Creation of the table
    int** grid = create_table(rows, cols);

    // Display table
    printf("Sudoku non résolu: \n");
    display_table(grid, rows, cols);

    // Solve sudoku
    solve_sudoku(grid);

    printf("Sudoku résolu: \n");
    // Display table
    display_table(grid, rows, cols);

    // Free table
    free_table(grid, rows);

    return 0;
}