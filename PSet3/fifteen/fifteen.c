/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements the Game of Fifteen (generalized to d x d).
 *
 * Usage: ./fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [MIN,MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

// board's dimension
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void save(void);

int main(int argc, string argv[])
{
    // greet player
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < MIN || d > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            MIN, MIN, MAX, MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // saves the current state of the board (for testing)
        save();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(void)
{    
    //makes all rows except final
    for(int row = 0; row < (d-1); row++)        
    {
        //makes cols in rows
        for(int col = 0; col < d; col++)
        {
            board[row][col] = (d*d-1) - ((row * d) + col);
        };
    };
    //makes final row
    if ((d%2) == 0)
    {    
        for (int row = (d - 1), col = 0 ; col < (d - 3); col++)
        {
            board[row][col] = (d*d-1) - ((row * d) + col);
        }
        board[d-1][d-3] = 1; 
        board[d-1][d-2] = 2;
        board[d-1][d-1] = '_';
    }
    else
    {
        for (int row = (d - 1), col = 0 ; col < (d - 1); col++)
        {
            board[row][col] = (d*d-1) - ((row * d) + col);
        }
        board[d-1][d-1] = '_';
    }; 
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    
    //prints rows
    for(int row = 0; row < d; row++)        
    {
        //prints cols in rows
        for(int col = 0; col < d; col++)
        {
            if (board[row][col] == '_')
                printf("  _");
            else
                printf(" %2d", board[row][col]);
        };
        printf("\n");
    }; 

}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    //declares variables to check
    int space_row;
    int space_col;
    int tile_row;
    int tile_col;

    //linears search for location of '_'
    for(int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
            if (board[row][col] == '_')
                {
                //saves location of space
                space_row = row;
                space_col = col;                
                break;
                }
        }
    };
    
    //linear search for location of tile
    for(int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
            if (board[row][col] == tile)
                {
                //saves location of space
                tile_row = row;
                tile_col = col;                
                break;
                };
        }
    };
    
    //checks if horizontal-adjacent move is legal. if not, returns false
    if (tile_row == space_row)
    {
        if (tile_col - space_col == 1 || tile_col - space_col == -1)
        {
            //if legal, swaps values and returns true
            board[space_row][space_col] = tile;
            board[tile_row][tile_col] = '_';
            return true;
        }
        else
            return false;
    }
    //checks if vertical-adjacent move is legal. if not, returns false
    else if (tile_col == space_col)
    {
        if (tile_row - space_row == 1 || tile_row - space_row == -1)
        {
            //if legal, swaps values and returns true
            board[space_row][space_col] = tile;
            board[tile_row][tile_col] = '_';
            return true;
        }
        else
            return false;
    }
    //returns false in case non-adjacent tile is entered
    else    
        return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int check_won = 0;
    
    //checks top left piece
    if (board[0][0] != 1)
    {
        check_won = 1;
    };
    
    //checks bottom right piece
    if (board[d-1][d-1] != '_')
    {
        check_won = 1;
    };
   
    //checks all rows except the last
    for (int row = 0; row < (d-1); row++)
    {
        for (int col = 1; col < d; col++)
        {
            if (board[row][col] - board[row][col-1] != 1)
            {
                check_won = 1;
            }
        };
    };

    //checks last row
    for (int row = (d-1), col = 1; col < (d-1); col++)
    {
        if (board[row][col] - board[row][col-1] != 1)
        {
            check_won = 1;
        }
    };    
        
    //checks that rows are in right order (previous 2 for-loops mean only (col = 0) needs to be checked)
    for (int col = 0, row = 1; row < d; row++)
    {
        if (board[row][col] - board[row-1][col] != d)
        {
            check_won = 1;
        }
    };   
    
    //checks if any of the losing conditions have changed check_won to 1. if not, you won!
    if (check_won == 1)
        return false;
    else
        return true;  
}

/**
 * Saves the current state of the board to disk (for testing).
 */
void save(void)
{
    // log
    const string log = "log.txt";

    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }

    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }

    // log board
    fprintf(p, "{");
    for (int i = 0; i < d; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < d; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < d - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < d - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");

    // close log
    fclose(p);
}
