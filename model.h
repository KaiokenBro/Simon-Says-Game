#ifndef MODEL_H
#define MODEL_H

/**
 * @file model.h
 * @authors Victor Valdez Landa, Harrison Doppelt
 *
 * @brief This file defines the Model class, which handles the core game logic for the Simon game.
 *
 * It manages the sequence of moves, player input, and game state transitions.
 *
 * @date 03/13/2025
 */

#include <QObject>
#include <vector>

using std::vector;

/**
 * @class Model
 * @brief The Model class handles the game's logic and state.
 *
 * It generates and stores the sequence of moves, checks player input,
 * and updates the game state accordingly.
 */
class Model : public QObject {
    Q_OBJECT

public:

    /**
     * @brief Constructs a new Model object.
     *
     * Initializes game state,
     * and seeds the random number generator to ensure a different sequence each game.
     *
     * @param parent A pointer to the parent QObject (default is nullptr).
     */
    explicit Model(QObject* parent = nullptr);

private:

    /**
     * @brief Index tracking the player's position in the sequence.
     */
    int playerIndex;

    /**
     * @brief Flag indicating whether the game is over.
     */
    bool isGameOver;

    /**
     * @brief Stores the sequence of moves.
     *
     * Each move is represented by an integer (0 = red, 1 = blue).
     */
    vector<int> sequence;

    /**
     * @brief Controls the game loop.
     *
     * Generates a new sequence move, plays the sequence, and manages turn transitions.
     */
    void gameLoop();

    /**
     * @brief Generates the next move in the sequence.
     *
     * Appends a new random move (red or blue) to the sequence.
     */
    void generateNextMove();

    /**
     * @brief Plays the stored sequence of moves.
     *
     * Emits a signal for each step to flash the buttons.
     */
    void playSequence();

    /**
     * @brief Initial time delay (in milliseconds) between sequence steps.
     */
    int speedFactor = 1000;

public slots:

    /**
     * @brief Starts a new game.
     *
     * Resets the state and starts the game loop.
     */
    void startGame();

    /**
     * @brief Handles player input during their turn.
     *
     * Compares the player's input with the stored sequence and updates the game state.
     *
     * @param buttonID The ID of the button the player pressed (0 for red, 1 for blue).
     */
    void handlePlayerTurn(int buttonID);

signals:

    /**
     * @brief Emitted when it's the player's turn.
     *
     * @param isTurn True if it's the player's turn, false otherwise.
     */
    void playerTurnSignal(bool isTurn);

    /**
     * @brief Emits the next move in the sequence.
     *
     * @param buttonID The ID of the button to flash (0 for red, 1 for blue).
     * @param speedFactor The time interval between each move in milliseconds.
     */
    void playMoveSignal(int buttonID, int speedFactor);

    /**
     * @brief Emits the progress update during the player's turn.
     *
     * @param progress The current progress percentage (0–100).
     */
    void progressUpdated(int progress);

    /**
     * @brief Signals that the game is over.
     *
     * Used to display "You Lose" message.
     */
    void gameOver();
};

#endif // MODEL_H
