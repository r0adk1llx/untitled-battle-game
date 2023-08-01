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

bool enableDesbug = false;
bool setFirstTime = false;

// player stats

int playerHealth; // pretty self explanatory
int playerStrength; // adds (or subtracts) from attack damage
int playerLuck; // increases or decreases various stats and chances
int playerAccuracy; // adds to the attack hit chance roll
int playerCash; // shall not be referred to as cash in game. because its really not. credits maybe. currency possibly. cash, no.
int playerStasisCash; // allows less errors when calculating current credit amount

// vague check of stats

bool obsfucateStats = true;

string obPlayerHealth; // makes for some nice flavour text
string obPlayerStrength; // also reads real nice
string obPlayerLuck; // read above
string obPlayerAccuracy; // observe the opposite of below this line

// enemy stats

int enemyType;
string enemyName; // sets the output name and is for any necessary checks
string enemyArticle; // for phrasing text output in a cohesive way
string capitalArticle; // because setting a function to auto-capitalise is too hard (I don't know how.)
int enemyHealth; // self explanatory
int enemyStrength; // see above
int enemyAccuracy; // see two above
int enemyCashWorth; // both cash worth and min should equal to the max. ie. if max is 10 and min is 3 then worth is 7
int enemyCashMin; // check line before
bool enemyIntimidation; // allows enemies to have opening moves/first attacks
bool enemyTakesAdvantage; // usually true, but can be false. used mostly for Crit Fails

// random number catch

int playerAttRoll; // player attack
int playerActRoll; // player action (why these are in two different orders is honestly beyond me)
int playerBlockRoll;
int enemyActRoll; // enemy action
int enemyAttRoll; // enemy attack
int playerDodgeRoll;
int LuckRoll;
int playerCritFail;
int playerOuch;

int roomTypeNum;

int cashEarned;

// Random Text Cycle

int randTextNum;

string playerBigHit;

// floor data

bool isShopping = false;
bool isBattling = false;
bool battleLoop = false;

// track game stats

int turnsPassed; // for setting up turn based moves
int roomsPassed;
int enemiesDead;

// release variables

string releaseState = "alpha";
int majorVersion = 0;
int shareVersion = 0;
int revisionVersion = 0;
int minorVersion = 0;

int main () {

    enableDesbug = false;

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

    if (enableDesbug = true) {

        cout << "\n\n";

        cout << "[DEBUG]";

    };

    if (secretsEnabled == true) {

        cout << "\n\n";

        cout << "Press Enter to Start, or type something like \"about\".\n> ";

    } else {

        cout << "\n\n";

        cout << "Press Enter to Start, or type \"about\".\n> ";

    };
    getline (cin, playerEntry);

    if (playerEntry == "debug" || playerEntry == "Debug") {

        // bool enableDesbug;

        setFirstTime = true;

        if (setFirstTime = true) {

            cout << "[DEBUG ENABLED]";

            enableDesbug = true;

            cout << "\n\n";

            system ("pause");

            goto startPage;

        } else if (enableDesbug = true) {

            cout << "\n\n";

            cout << "[DEBUG DISABLED]";

            enableDesbug = false;

            cout << "\n\n";

            system ("pause");

            goto startPage;

        } else {

            setFirstTime = false;

        };

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



        if (enableDesbug = true) {

            obsfucateStats = false;

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

        cout << "Just before you enter the room, you note that:";

        cout << "\n\n---------\n\n";

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

            cout << "You have " << playerCash << " credits.";

        };

        cout << "\n\n---------\n\n";

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

            randTextNum = rand () % 19 + 1;

            enemyType = rand () % 10;

            if (enemyType >= 5) {

                enemyName = "Test Dummy";
                enemyArticle = "the";
                capitalArticle = "The";
                enemyHealth = 25 + (playerStrength / 3);
                enemyStrength = 5;
                enemyAccuracy = 10;
                enemyCashWorth = 9;
                enemyCashMin = 1;

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

                // cout << "\n\nNow this would usually allow you to fight the enemy in front of you\n";
                // cout << "but Im out of time to do so.";
                // cout << "\nSo *ka-blam*.";

                cout << "\n\n";

                getline (cin, playerEntry);

                if (playerEntry == "1" || playerEntry == "Attack" || playerEntry == "attack" || playerEntry == "a" || playerEntry == "A") {

                  // player attack

                  if (playerAccuracy > 10) {

                    playerActRoll = rand () % 20 + (playerAccuracy / 2);

                  } else {

                    playerActRoll = rand () % 20 - (playerAccuracy / 2);

                  };

                  if (playerActRoll >= 10 && playerActRoll != 20) {

                    if (playerStrength > 10) {

                        playerAttRoll = rand () % 20 + (playerStrength / 2);

                    } else {

                        playerAttRoll = rand () % 20 - (playerStrength / 2);

                    };

                    if (playerAttRoll < (playerStrength / 4)) {

                        playerAttRoll = playerStrength / 4;

                    };

                    cout << "\n\n";

                    cout << "You hit " << enemyArticle << " " << enemyName << " for " << playerAttRoll << ".";

                    enemyHealth = enemyHealth - playerAttRoll;

                    } else if (playerActRoll == 20) {

                        playerAttRoll = (rand () % 15 + 5) + playerStrength;

                        if (randTextNum = 1) {

                            playerBigHit = "Smaaaash!";

                        } else if (randTextNum == 20){

                            playerBigHit = "Critical Hit!";

                        }  else {

                            playerBigHit = "Whoa!";

                        };

                        cout << "\n\n";

                        cout << "[" << playerBigHit << "]\n\n" << "You hit " << enemyArticle << " " << enemyName << " for " << playerAttRoll << ".";

                        enemyHealth = enemyHealth - playerAttRoll;

                    } else if (playerActRoll < 10 && playerActRoll != 1) {

                        cout << "\n\n";

                        cout << "You missed.";

                    } else if (playerActRoll == 1) {

                        playerCritFail = rand () % 100;

                        // if it lands on 4, 18, 47, 58, or 83 then it will trigger crit fail

                        // if (playerCritFail = 47 || playerCritFail = 83 || playerCritFail = 18 || playerCritFail = 4 || playerCritFail = 58) (for historical reasons)

                        if (playerCritFail == 4 || playerCritFail == 18 || playerCritFail == 47 || playerCritFail == 58 || playerCritFail == 83) {

                            playerOuch = rand () % 10 + 15;

                            cout << "In your attempt to hit " << enemyArticle << " " << enemyName << ", you tripped and took " << playerOuch << " damage.";

                            playerHealth = playerHealth - playerOuch;

                        } else {

                            cout << "You missed.";

                        };

                    } else {

                        cout << "You missed.";

                    };

                    if (enemyHealth <= 0) {

                        enemyHealth = 0;

                    };

                    cout << "\n\n";

                    cout << "The " << enemyName << " has " << enemyHealth << " HP left.";

                    cout << "\n\n";

                  };

                  system ("pause");

                  // enemy attack goes below here

                // };

            // cout << "\n\n";

                // enemyHealth = 0;

                if (enemyHealth <= 0) {

                    system ("cls");

                    cout << "\n\n";

                    cout << enemyName << " Defeated.";

                    cout << "\n\n";

                    cashEarned = rand () % enemyCashWorth + enemyCashMin;

                    playerStasisCash = playerCash;

                    playerCash = playerStasisCash + cashEarned;

                    cout << cashEarned << " currency earned.";

                    cout << "\n\n";

                    system ("pause");

                    battleLoop = false;

                } else if (enemyHealth > 0){

                    system ("cls");

                    cout << "The " << enemyName << " is standing there, menacingly.";

                } else {

                    system ("cls");

                    cout << "[ERROR]";

                    cout << "\n\n";

                    cout << "Something Goofed.";

                    system ("pause");

                    break;
                    // cout << "\n\n";

                };

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
