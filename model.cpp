/**
 * @file model.cpp
 * @authors Victor Valdez Landa, Harrison Doppelt
 *
 * @brief This file defines the implementation of the Model class, which manages the game's core logic.
 *
 * It handles generating the sequence, tracking player input, and controlling the game state.
 *
 * @date 03/13/2025
 */

#include "model.h"

#include <cstdlib>
#include <ctime>
#include <QTimer>
#include <algorithm>

using std::max;
using std::srand;

Model::Model(QObject *parent) :
    QObject{parent},
    playerIndex(0),
    isGameOver(false)
{
    // Seed the random generator using the current time
    srand(static_cast<unsigned int>(std::time(nullptr)));
}

void Model::startGame() {
    gameLoop();
}

void Model::handlePlayerTurn(int buttonID) {

    // If the player's input matches the expected sequence value
    if (sequence[playerIndex] == buttonID) {
        playerIndex++;

        // Update the progress bar based on how much of the sequence has been completed
        emit progressUpdated(static_cast<int>((static_cast<double>(playerIndex) / sequence.size()) * 100));

        // If player has completed the sequence successfully
        if (playerIndex == static_cast<int>(sequence.size())) {

            // Reset index for the next round
            playerIndex = 0;

            // Immediately disable player input after last correct step
            emit playerTurnSignal(false);

            // Speed up the game by 10% for the next round (minimum delay capped at 300ms)
            speedFactor = max(300, static_cast<int>(speedFactor * 0.90));

            // Wait for 1 second before starting the next round
            QTimer::singleShot(1000, this, &Model::gameLoop);
        }
    }

    // If the player's input DOES NOT matche the expected sequence value
    else {
        isGameOver = true;
        emit gameOver();
    }
}

void Model::gameLoop() {

    // If the game is over, stop the loop
    if (isGameOver) {
        return;
    }

    // Disable player input during the computer's turn
    emit playerTurnSignal(false);

    // Add a new move to the sequence
    generateNextMove();

    // Reset the progress bar to 0%
    emit progressUpdated(0);

    // Computer plays the full sequence move-by-move
    playSequence();

    // After the sequence is finished, enable player input
    QTimer::singleShot(static_cast<int>(sequence.size()) * speedFactor + 100, this, [this]() {
        emit playerTurnSignal(true);    // Allow player input after the sequence ends
    });
}

void Model::generateNextMove() {

    // Generates 0 or 1 (red or blue)// Generates 0 or 1 (red or blue)
    int newMove = rand() % 2;

    // Add new move to sequence
    sequence.push_back(newMove);
}

void Model::playSequence() {

    for (size_t i = 0; i < sequence.size(); ++i) {

        // Timer that controls how fast individual moves are played
        QTimer::singleShot(i * speedFactor + 50, this, [this, i]() {
            emit playMoveSignal(sequence[i], speedFactor);
        });
    }
}
