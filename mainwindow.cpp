/**
 * @file mainwindow.cpp
 * @authors Victor Valdez Landa, Harrison Doppelt
 *
 * @brief This file defines the implementation of the MainWindow class, which manages the game's user interface.
 *
 * It handles user interaction, sound effects, and updates the game state based on player input.
 *
 * @date 03/13/2025
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <algorithm>

using std::max;

MainWindow::MainWindow(Model* model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize audio players for buttons
    redButtonAudio = new QMediaPlayer(this);
    blueButtonAudio = new QMediaPlayer(this);
    redAudioOutput = new QAudioOutput(this);
    blueAudioOutput = new QAudioOutput(this);

    // Set audio output for each button sound effect
    blueButtonAudio->setAudioOutput(blueAudioOutput);
    redButtonAudio->setAudioOutput(redAudioOutput);

    // Set the volume of the audio (range is 0 to 100)
    redAudioOutput->setVolume(50);
    blueAudioOutput->setVolume(40);

    // Double playback rate to make button sounds quick and responsive
    redButtonAudio->setPlaybackRate(2.0);
    blueButtonAudio->setPlaybackRate(2.0);

    // Load button sounds from qrc file
    blueButtonAudio->setSource(QUrl("qrc:/sounds/blueButtonSound.wav"));
    redButtonAudio->setSource(QUrl("qrc:/sounds/redButtonSound.wav"));

    // Hide game buttons and UI elements until the game starts
    ui->redButton->setVisible(false);
    ui->blueButton->setVisible(false);
    ui->progressBar->setVisible(false);
    ui->gameOverLabel->setVisible(false);

    // Start button begins the game
    connect(ui->startButton,
            &QPushButton::clicked,
            model,
            &Model::startGame);


    // Shows game buttons when the Start button is clicked
    connect(ui->startButton,
            &QPushButton::clicked,
            this,
            &MainWindow::showGameButtons);

    // Hide start button and welcome label when the Start button is clicked
    connect(ui->startButton,
            &QPushButton::clicked,
            this,
            &MainWindow::hideGameButtons);

    // Enable or disable game buttons based on turn
    connect(model,
            &Model::playerTurnSignal,
            this,
            &MainWindow::updateGameButtonState);

    // Flashes the appropriate button during the computer's sequence
    connect(model,
            &Model::playMoveSignal,
            this,
            &MainWindow::flashButton);

    // Player input — clicking red button sends a signal to the model
    connect(ui->redButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onRedButtonClicked);

    // Player input — clicking blue button sends a signal to the model
    connect(ui->blueButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onBlueButtonClicked);

    /**
     * @brief SOURCE USED:
     * https://doc.qt.io/qt-6/signalsandslots.html.
     * Used this source to find a way to connect signals to slots from view to model without
     * having them knowing anything about each other preserving Model-View Architecture
     * plus finding a way to give parameters to each other.
     * Used the emitted buttonPressed to nofify the model.
     */
    connect(this,
            &MainWindow::buttonPressed,
            model,
            &Model::handlePlayerTurn);

    // Updates progress bar as the player progresses
    connect(model,
            &Model::progressUpdated,
            this,
            &MainWindow::setProgressBar);

    // Disables all UI elements after the game ends
    connect(model,
            &Model::gameOver,
            this,
            &MainWindow::onGameOver);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateGameButtonState(bool isTurn) {
    ui->redButton->setEnabled(isTurn);
    ui->blueButton->setEnabled(isTurn);
}

void MainWindow::flashButton(int buttonID, int speedFactor) {

    // Play the corresponding button sound
    if (buttonID == 0) {
        redButtonAudio->play();
    } else if (buttonID == 1) {
        blueButtonAudio->play();
    }

    // Temporarily change button color to simulate flashing
    QPushButton* button = (buttonID == 0) ? ui->redButton : ui->blueButton;
    button->setStyleSheet(buttonID == 0 ? "background-color: red;" : "background-color: blue;");

    // Set the flash duration to 60% of the speed factor, but ensure it is at least 100 milliseconds
    int flashTime = max(100, static_cast<int>(speedFactor * 0.6));

    // Reset button color
    QTimer::singleShot(flashTime, this, [button]() {
        button->setStyleSheet("");
    });
}

void MainWindow::showGameButtons() {
    ui->redButton->setVisible(true);
    ui->blueButton->setVisible(true);
    ui->progressBar->setVisible(true);
}

void MainWindow::hideGameButtons() {
    ui->startButton->setVisible(false);
    ui->gameStartLabel->setVisible(false);
}

void MainWindow::onRedButtonClicked() {
    emit buttonPressed(0);
}

void MainWindow::onBlueButtonClicked() {
    emit buttonPressed(1);
}

void MainWindow::setProgressBar(int progress) {
    ui->progressBar->setValue(progress);
}

void MainWindow::onGameOver() {
    ui->redButton->setVisible(false);
    ui->blueButton->setVisible(false);
    ui->progressBar->setVisible(false);

    // Display the game-over label
    ui->gameOverLabel->setVisible(true);
}
