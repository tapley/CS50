//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// height and width of paddle
#define PADDLE_HEIGHT 20
#define PADDLE_WIDTH 100

// height and width of bricks. height should match paddle. width should remain smaller than (WIDTH / 10).
#define BRICK_HEIGHT 20
#define BRICK_WIDTH 30

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);
    
int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;


    // keep playing until game over. 
    //SOURCES: modified from CS50 versions of cursor.c and bounce.c
    while (lives > 0 && bricks > 0)   
    {   
        //waits for click to start game and to start a round after losing a life
        waitForClick();
        
        // instantiate ball, centered in middle of window
        GOval ball = initBall(window);
            
        // direciton of ball initially
        double velocity_x = drand48() * 5;
        double velocity_y = 2;
        
        while (bricks > 0)
            {     
            // check for mouse event
            GEvent event = getNextEvent(MOUSE_EVENT);
            
            // if we heard one
            if (event != NULL)
            {
                // if the event was movement
                if (getEventType(event) == MOUSE_MOVED)
                {
                    // ensure paddle follows cursor
                    double x = getX(event) - PADDLE_WIDTH / 2;
                    setLocation(paddle, x, HEIGHT - (PADDLE_HEIGHT * 2));
                }
            }
            
            // move  ball
            move(ball, velocity_x, velocity_y);

            // bounce off left, right edges of window
            if (getX(ball) + RADIUS * 2 >= WIDTH)
            {
                velocity_x = -velocity_x;
            }
            else if (getX(ball) <= 0)
            {
                velocity_x = -velocity_x;
            };


            // bounce off top, bottom edges of window

            if (getY(ball) <= 0)
            {
                velocity_y = -velocity_y;
            }
            else if (getY(ball) + RADIUS * 2 >= HEIGHT)
            {
                removeGWindow(window, ball);
                lives = lives - 1;
                break;
            };        
                  
                          
            //bounces off paddle
            GObject object = detectCollision(window, ball);
            
            if (object == paddle)
            {
                velocity_y = -velocity_y;
            }
            else if (detectCollision(window, ball) != NULL && object != label)
            {
                removeGWindow(window, object);
                points = points + 1;
                bricks = bricks - 1;
                updateScoreboard(window, label, points);
                velocity_y = -velocity_y;
            }
            
            // linger before moving again
            pause(20); 
        }     
    }
    
    if (bricks == 0)
    { 
        GLabel win_banner = newGLabel("You win!!!");
        setLocation(win_banner, (WIDTH - getWidth(win_banner)) / 2, (HEIGHT - getHeight(win_banner)) * .75);
        add (window, win_banner);
    }  
    else
    {
        GLabel lose_banner = newGLabel("You lose!!!");
        setLocation(lose_banner, (WIDTH - getWidth(lose_banner)) / 2, (HEIGHT - getHeight(lose_banner)) * .75);
        add (window, lose_banner);
    }  
    
    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{ 
    // makes the spacing between bricks depend on constants. will automatically keep bricks centered
    double space = (WIDTH - (COLS * BRICK_WIDTH)) / (COLS + 1);

    // initializes bricks    
    for(int i = 0; i < ROWS; i ++)
    {
        for (int j = 0; j < COLS; j++)
        {
            GRect brick = newGRect(space + (BRICK_WIDTH + space) * j, (HEIGHT / 10) + (BRICK_HEIGHT + space) * i, BRICK_WIDTH, BRICK_HEIGHT);
            setFilled (brick, true);
            setColor (brick, "BLACK");
            add (window, brick);
        }
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{

    GOval ball = newGOval (WIDTH / 2 - RADIUS, HEIGHT / 2 - RADIUS, RADIUS * 2, RADIUS * 2);
    setFilled (ball, true);
    setColor (ball, "BLACK");
    add (window, ball);
    
    
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    GRect paddle = newGRect ((WIDTH - PADDLE_WIDTH) / 2, HEIGHT - (PADDLE_HEIGHT * 2), PADDLE_WIDTH, PADDLE_HEIGHT);
    setFilled (paddle, true);
    setColor (paddle, "BLACK");
    add (window, paddle);
    
    
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("0");
    setLocation(label, (WIDTH - getWidth(label)) / 2, (HEIGHT - getHeight(label)) / 2);
    add (window, label);
    
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}