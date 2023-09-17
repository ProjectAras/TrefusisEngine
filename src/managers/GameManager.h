//
// Created by elsa on 13.04.2020.
//

#ifndef TREFUSISENGINE_GAMEMANAGER_H
#define TREFUSISENGINE_GAMEMANAGER_H

#include <vector>
#include <string>
#include "../objects/Character.h"
#include "TimeManager.h"
#include "GraphicsManager.h"
#include "../objects/Player.h"
#include "../harlequin/DialogManager.hpp"
#include "../harlequin/ScriptManager.h"
/**
 * A singleton class, GameManager has only one active instance at any given time.
 */
class GameManager
{
private:
    std::vector<Character> characters;
    TimeManager timeManager;
    GraphicsManager graphicsManager;
    SDL_Event e;
    bool displayDialog = false;
    Dialog currentDialog{"", ""};
    static GameManager *game;
    ScriptManager harlequin;
    Player *player;
    /**
     * Move the player in given directions.
     * @param x movement in x direction.
     * @param y movement in y direction.
     */
    void movePlayer(float x, float y);
    /**
     * Track the objects.
     */
    void trackObjects();
    /**
     * Stub method to load the first scene for the first Milestone test.
     */
    void loadFirstScene();
    /**
     * Show the splash screen.
     */
    void showSplashScreen();
    /**
     * Handle the key presses by the user.
     */
    void handleKeys();
    /**
     * Check if player is still inside the map after move.
     * @param x Move in x direction.
     * @param y Move in y direction.
     * @return If the player is still inside bounds.
     */
    bool inline playerIsInsideMapAfterMove(float x, float y);
    /**
     * Check if the player's desired location is blocked.
     * @param dx Movement in x.
     * @param dy Movement in y.
     * @return If p.x + dx, p.y + dy is blocked.
     */
    bool inline playerIsBlockedAfterMove(float dx, float dy);
    /**
     * Handles the display and process of dialog.
     */
    void handleDialog();
    /**
     * Initialise a gamemanager instance.
     */
    GameManager();

public:
    bool quit;
    /**
     * Main loop of the game.
     */
    void Update();
    /**
     * Get the instance of the gamemaneger.
     * @return Only instance of the game manager.
     */
    static GameManager getInstance();
    /**
     * Close the game manager. Release used resources.
     */
    void close();
};

#endif // TREFUSISENGINE_GAMEMANAGER_H
