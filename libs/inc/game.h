#ifndef GAME_H
#define GAME_H

#include <glad.h>
#include <glfw3.h>

/*
    Enum for basic state control
    Should not be used for tracking progress
*/
enum gameState {
    GAME_MENU,      //Game is at the Menu
    GAME_RUN,       //Game is running
    GAME_PAUSE,     //Game is paused
    GAME_END,       //Placeholder end state, to be replaced with more in depth control logic for player death at a later date
};

class Game
{
    public:
        gameState state;
        bool Keys[1024];

        //Constructor and Destructor
        Game();
        ~Game();
        //Initalize the basic game state
        void Init();
        //Game Loop Stuff
        void ProcessInput(float dt);
        void Upadate(float dt);
        void Render();
};

#endif