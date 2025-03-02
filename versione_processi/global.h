#ifndef GLOBAL_H
#define GLOBAL_H

#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <bits/time.h>
#include <string.h>

#define ENEMIES 25
#define MAX_X 80
#define MAX_Y 20

// Macro gestione pipe
#define READ 0
#define WRITE 1

// Macro per la direzione degli spari diagonali
#define DIR_UP 1
#define DIR_DOWN -1

// Macro per l'identificazione degli oggetti
#define PLAYER '+'
#define ENEMY '<'
#define ROCKET '*'
#define ENEMY_ROCKET 'o'
#define ROCKET_UP 'u'
#define ROCKET_DOWN 'd'

// Macro proiettili giocatore
#define MAX_ROCKET 20

// Macro movimento nemici
#define HORIZONTAL 1
#define VERTICAL 0

// Macro per i ritardi
#define ENEMY_DELAY 300000
#define ROCKET_DELAY 30000

// Macro condizioni di vittoria
#define WIN 1
#define DEFEAT 0

/* Oggetto da rappresentare. Nave giocatore, nave nemica, oggetti di gioco quali siluri, proiettili, etc. */
typedef struct {
    char identifier;    // Carattere dell'oggetto. Es: "-" come proiettile.
    int x;              // Posizione dell'oggetto nell'asse x
    int y;              // Posizione dell'oggetto nell'asse y
    int lives;          // Numero di vite disponibii dell'oggetto
    pid_t pid;          // Pid del processo di riferimento dell'oggetto
    int serial;         // Numero univoco della nave
} Object;

// Funzioni libreria player.c
void playerShip(int mainPipe);
void playerShotInit(int mainPipe, int x, int y, int serial);
void shot(int mainPipe, int x, int y, int direction, int serial);

// Funzioni libreria enemies.c
void fleetEnlister(int mainPipe);
void enemyShip(int mainPipe, Object enemy);
void enemyShot(int mainPipe, int x, int y, int serial);

// Funzioni libreria gameplay.c
void gameArea(int mainPipe);

// Funzioni di utilità globale (global.c)
void printSprite(int posX, int posY, int dimRow, int dimCol, char sprite[dimRow][dimCol]);
void deleteSprite(Object item);
void rocketAnimation(int x, int y);
void printLives(int lives);
int timeTravelEnemyRocket(int microSeconds);
int checkCollision(Object a, Object b);
int isRocket(Object item);
Object resetItem();

// Funzioni avvio e fine gioco (start-over.c)
void startGame();
void gameOver(int winCondition, int score);
void countdownPrint(int x, int y, int count);

#endif /* GLOBAL_H */
