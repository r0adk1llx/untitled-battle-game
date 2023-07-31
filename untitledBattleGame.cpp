#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <time.h>
using namespace std;

// start variables here

// submenu flags

bool isAbout;

// entry

string playerEntry;

// secret modes

bool secretsEnabled = false;



// debug

bool enableDebug = false;

// player stats

int playerHealth; // pretty self explanatory
int playerStrength; // adds (or subtracts) from attack damage
int playerLuck; // increases or decreases various stats and chances
int playerAccuracy; // adds to the attack hit chance roll
int playerCash;
int playerStasisCash;

int turnsPassed; // for setting up turn based moves
int roomsPassed;

// vague check of stats

bool obsfucateStats = true;

string obPlayerHealth;
string obPlayerStrength;
string obPlayerLuck;
string obPlayerAccuracy;

// enemy stats

int enemyType;
string enemyName;
int enemyHealth;
int enemyStrength;
int enemyAccuracy;

// random number catch

int playerAttRoll;
int playerActRoll;
int playerBlockRoll;
int EnemyActRoll;
int playerDodgeRoll;
int LuckRoll;

int roomTypeNum;

int cashEarned;

// floor data

bool isShopping = false;
bool isBattling = false;
bool battleLoop = false;

// release variables

string releaseState = "alpha";
int majorVersion = 0;
int shareVersion = 0;
int revisionVersion = 0;
int minorVersion = 0;

int main () {

    enableDebug = false;

    releaseState = "alpha";
    majorVersion = 0;
    shareVersion = 0;
    revisionVersion = 1;
    minorVersion = 0;

    // seed the rng

    srand (time(NULL));

    // program landing page (cant go without one)

    startPage:

    system ("cls");

    cout << "Version " << releaseState << " " << majorVersion << "." << shareVersion << "." << revisionVersion << "." << minorVersion ; //ver number is major.share release.revision.minor

    if (secretsEnabled == true) {

        cout << "\n\n";

        cout << "Press Enter to Start, or type something like \"about\".\n> ";

    } else {

        cout << "\n\n";

        cout << "Press Enter to Start, or type \"about\".\n> ";

    };
    getline (cin, playerEntry);

    if (playerEntry == "debug" || playerEntry == "Debug") {

        if (enableDebug = true) {

            cout << "\n\n";

            cout << "[DEBUG DISABLED]";

            enableDebug = false;

            cout << "\n\n";

            system ("pause");

            goto startPage;

        }

        if (enableDebug = false) {

            cout << "[DEBUG ENABLED]";

            enableDebug = true;

            cout << "\n\n";

            system ("pause");

            goto startPage;

        }

    };

    if (playerEntry == "about" || playerEntry == "About") {

        // about menu

        isAbout = true;

        do {

            system ("cls");

            cout << "[TODO: Write About Page]\n\n";

            system ("pause");

            isAbout = false;
            goto startPage;

        }
        while (isAbout == true);

    };

    if (playerEntry == "secretnyan") {

        if (secretsEnabled == false) {

            secretsEnabled = true;
            cout << "\n\nSecrets are now enabled!\n\n";


        } else {

            secretsEnabled = false;
            cout << "\n\nSecrets? What secrets? [Disabled Secrets]\n\n";

        };

        system ("pause");
        goto startPage;


    };

    if (playerEntry == "exit" || playerEntry == "Exit" || playerEntry == "quit" || playerEntry == "Quit" || playerEntry == "q" || playerEntry == "Q" || playerEntry == "e" || playerEntry == "E") {

        // exit function, reuse and update for necessary functions like saving

        goto controlQuit;

    };

    // game loop

    initializeGame:

        system ("cls");

        playerHealth = 100;
        playerStrength = rand () % 5 + 5;
        playerLuck = rand () % 7;
        playerAccuracy = rand () % 5 + 10;

        if (enableDebug = true) {

            // obsfucateStats = false;

        };

        // health ob

        if (playerHealth >= 75) {

            obPlayerHealth = "Healthy";

        } else if (playerHealth >= 50 != playerHealth >= 75) {

            obPlayerHealth = "Injured";

        } else if (playerHealth >=25 != playerHealth >= 50) {

            obPlayerHealth = "Wounded";

        } else if (playerHealth <= 25) {

            obPlayerHealth = "Mortally Wounded";

        } else {

            obPlayerHealth = "[Health System Broken, Come Back Later]";

        };

        // strength ob

        if (playerStrength >= 30) {

            obPlayerStrength = "Really Strong";

        } else if (playerStrength >= 20 != playerStrength >=30) {

            obPlayerStrength = "Pretty Strong";

        } else if (playerStrength >=10 != playerStrength >=20) {

            obPlayerStrength = "Kinda Strong";

        } else if (playerStrength <= 10 != playerStrength > 10) {

            obPlayerStrength = "Relatively Strong";

        } else if (playerStrength <= 3) {

            obPlayerStrength = "like a paper could crush you";

        } else {

            obPlayerStrength = "[Health System Broken, Come Back Later]";

        };

        // accuracy ob

        if (playerAccuracy >= 30) {

            obPlayerAccuracy = "Like a Sharpshooter";

        } else if (playerAccuracy >= 20 != playerAccuracy >=30) {

            obPlayerAccuracy = "Really Accurate";

        } else if (playerAccuracy >=10 != playerAccuracy >=20) {

            obPlayerAccuracy = "Pretty Accurate";

        } else if (playerAccuracy <= 10 != playerAccuracy > 10) {

            obPlayerAccuracy = "sure you could hit something if you tried";

        } else if (playerAccuracy <= 3) {

            obPlayerAccuracy = "like you may as well close your eyes";

        } else {

            obPlayerAccuracy = "[Health System Broken, Come Back Later]";

        };

    genRoom:

        system ("cls");

        roomTypeNum = rand () % 10;

        cout << "Just before you enter the room, you note that:\n\n";

        if (obsfucateStats == true) {

            cout << "Health-wise you feel " << obPlayerHealth << ".";

            if (playerHealth <= 50) {

                cout << "\n\n";
                cout << "You should probably find a way to heal those wounds.";

            };

            cout << "\n\n";

            cout << "Strength wise you feel " << obPlayerStrength << ".";

            cout << "\n\n";

            cout << "Accuracy wise you feel " << obPlayerAccuracy << ".";

        };

        if (obsfucateStats == false) {

            cout << "Health: " << playerHealth ;
            cout << "\n\n";
            cout << "Strength: " << playerStrength ;
            cout << "\n\n";
            cout << "Accuracy: " << playerAccuracy ;

        };

        if (playerCash >= 1) {

            cout << "\n\n";

            cout << "You are holding " << playerCash << "$.";

        };

        cout << "\n\n";

        system ("pause");

        if (roomTypeNum >= 5) {

            isShopping = true;

            goto shopRoom;

        } else {

            isBattling = true;

            goto battleRoom;

        };

    shopRoom:

        system ("cls");

        do {

        cout << "[SHOP]";
        cout << "\n\n";

        cout << "\"Welcome to the shop.\"";
        cout << "\n\n";
        cout << "[ITEMS FOR SALE]";
        cout << "\n\n";
        cout << "[This is where I'd put things I'm selling, IF I HAD ANY ITEMS! \n(Damn you game creator for not giving me anything to sell)]";
        cout << "\n\n";
        cout << "... The test shopkeeper has been smote, so";

        cout << "\n\n";
        system ("pause");

        isShopping = false;

        }
        while (isShopping == true);

        goto genRoom;

    battleRoom:

        system ("cls");

        do {

            enemyType = rand () % 10;

            if (enemyType >= 5) {

                enemyName = "Test Dummy";
                enemyHealth = 25;
                enemyStrength = 5;
                enemyAccuracy = 10;

                battleLoop = true;

            } else {

                cout << "You wander into the room expecting a fight but find it empty. ";

                if (playerHealth >= 50) {

                    cout << "\n\n";

                    cout << "Oh, well.";

                    cout << "\n\n";

                };

                if (playerHealth <= 49) {

                    cout << "\n\n";

                    cout << "*sigh*";

                    cout << "\n\n";

                };

                system ("pause");

            };

            if (battleLoop == true) {

                cout << "As you walk in you find ";

                cout << "\n\n";

                cout << "A " << enemyName << " stands in front of you.";

            do {



                cout << "\n\n---------\n\n";

                cout << "[Actions]";
                cout << "\n[1] Attack!";
                cout << "\n[2] Block.";

                cout << "\n\nNow this would usually allow you to fight the enemy in front of you\n";
                cout << "but Im out of time to do so.";
                cout << "\nSo *ka-blam*.";

                cout << "\n\n";

                enemyHealth = 0;

                if (enemyHealth == 0) {

                    cout << enemyName << " Defeated.";

                    cout << "\n\n";

                    cashEarned = rand () % 9 + 1;

                    playerStasisCash = playerCash;

                    playerCash = playerStasisCash + cashEarned;

                    cout << cashEarned << "$ earned.";

                    cout << "\n\n";

                    system ("pause");

                    battleLoop = false;

                }

            }
            while (battleLoop == true);

            };

            // cout << "\n\n";

            // system ("pause");

            isBattling = false;

        }
        while (isBattling == true);

        goto genRoom;


    // exit jump; call this when making exit functions

    controlQuit:

        system ("cls");

        cout << "Exiting...\n\n";

    return 0;

}; //safety line
