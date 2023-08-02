#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <time.h>
using namespace std;

// start variables here

// menu flags

bool startMenu;

// submenu flags

bool isAbout;

// settings

bool allowFlash = false; // toggles colour flash for certain occurances, off by default

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
int totalPlayerCash;

bool settingStats;
bool confirmingStats;

// player states

bool isBlocking;

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
string enemyAttackText;

// random number catch

int playerAttRoll; // player attack
int playerActRoll; // player action (why these are in two different orders is honestly beyond me)
int playerBlockRoll;
int enemyActRoll; // enemy action
int enemyAttRoll; // enemy attack
int playerDodgeRoll;
int LuckRoll;
int playerCritFail;
int enemyCritFail; // honestly not really necessary, just here cause im mirroring the code, maybe use for self destruct type moves?
int playerOuch;
int playerAdvantage;
int playerDefend;

int cashEarned;

// inventory

bool checkingInventory;
string heldItems;


// room and floor generation

int roomCount; // sets how many rooms a floor has
int roomsPassed;
int roomSplit; // sets how many rooms at a split
int floorCount; // chooses how many floors to beat
bool isBossRoom; // can set last room as boss room
bool roomChoice;

bool freshOffElevator;

int roomTypeNum;

// Random Text Cycle

int randTextNum;

string playerBigHit;
string enemySmashHit;
string gameOverBlurb;

// floor data

bool isShopping = false;
bool isBattling = false;
bool battleLoop = false;

// track game stats

int turnsPassed; // for setting up turn based moves
int totalRoomsPassed;
int enemiesDead;
int currentFloor;

// release variables

string releaseState = "alpha";
int majorVersion = 0;
int shareVersion = 0;
int revisionVersion = 0;
int minorVersion = 0;

int main () {

    system ("color 08");

    enableDesbug = false;

    startMenu = true;

    releaseState = "alpha";
    majorVersion = 0;
    shareVersion = 1;
    revisionVersion = 0;
    minorVersion = 2;

    // seed the rng

    srand (time(NULL));

    // program landing page (cant go without one)

    startPage:

    do {

    system ("cls");

    cout << "Version " << releaseState << " " << majorVersion << "." << shareVersion << "." << revisionVersion << "." << minorVersion ; //ver number is major.share release.revision.minor

    cout << "\n\n";

    cout << "Warning: There is some minor flashing that can be enabled in this game. [Currently set to on for testing reasons]";

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

            continue;

            // goto startPage;

        } else if (enableDesbug = true) {

            cout << "\n\n";

            cout << "[DEBUG DISABLED]";

            enableDesbug = false;

            cout << "\n\n";

            system ("pause");

            continue;

            // goto startPage;

        } else {

            setFirstTime = false;

        };

    } else if (playerEntry == "about" || playerEntry == "About") {

        // about menu

        isAbout = true;

        do {

            system ("cls");

            cout << "[TODO: Write About Page]\n\n";

            system ("pause");

            isAbout = false;

            continue;

            // goto startPage;

        }
        while (isAbout == true);

    } else if (playerEntry == "secretnyan") {

        if (secretsEnabled == false) {

            secretsEnabled = true;
            cout << "\n\nSecrets are now enabled!\n\n";


        } else {

            secretsEnabled = false;
            cout << "\n\nSecrets? What secrets? [Disabled Secrets]\n\n";

        };

        system ("pause");

        continue;

        // goto startPage;


    } else if (playerEntry == "toggleFlashing" || playerEntry == "toggleFlash" || playerEntry == "toggleflash" || playerEntry == "toggleflashing" || playerEntry == "Flash" || playerEntry == "flash" || playerEntry == "Flashing" || playerEntry == "flashing" || playerEntry == "clap on" || playerEntry == "clap off" || playerEntry == "clapon" || playerEntry == "clapoff") {

        if (allowFlash = true) {

            allowFlash = false;

            cout << "\n\n";

            cout << "Flash effects are disabled. [not so flashy now, huh?]";

            cout << "\n\n";

            system ("pause");

            continue;

            // goto startPage;

        } else if (allowFlash = false) {

            allowFlash = true;

            cout << "\n\n";

            cout << "Flash effects are enabled. [blink, blink]";

            cout << "\n\n";

            system ("pause");

            continue;

            // goto startPage;

        } else {

            allowFlash = true;

            cout << "\n\n";

            cout << "Flash effects are enabled. [blink, blink]";

            cout << "\n\n";

            system ("pause");

            continue;

            // goto startPage;

        };

    } else if (playerEntry == "exit" || playerEntry == "Exit" || playerEntry == "quit" || playerEntry == "Quit" || playerEntry == "q" || playerEntry == "Q" || playerEntry == "e" || playerEntry == "E") {

        // exit function, reuse and update for necessary functions like saving

        goto controlQuit;

    } else {

        startMenu = false;

        // continue;

        // goto startPage;

    };

    }
    while (startMenu == true);

    // game loop

    initializeGame:

        system ("cls");

        totalRoomsPassed = 0;
        enemiesDead = 0;
        totalPlayerCash = 0;

        enemyName = "Void";

        settingStats = true;

        do {

            system ("cls");

            system ("color 08");

            playerAccuracy = 30;

            cout << "Enter how many points you would like to give to strength. (1-30 or random)";

            cout << "\n\n";

            cout << "> ";

            getline (cin, playerEntry);

            if (playerEntry == "random" || playerEntry == "rand" || playerEntry == "Random" || playerEntry == "Rand" || playerEntry == "r" || playerEntry == "R") {

                playerAccuracy = 30;

                playerStrength = rand () % 15 + 5;

                playerAccuracy = playerAccuracy - playerStrength;

                cout << "\n\n";

                cout << "Strength randomised to: " << playerStrength;

                cout << "\n\n";

                cout << "Accuracy randomised to: " << playerAccuracy;

                cout << "\n\n";

                system ("pause");

                settingStats = false;

                // playerAccuracy = rand () % 5 + 10;

            } else if (playerEntry != "") {

                try {

                playerStrength = stoi (playerEntry);

                }
                catch (...) {

                    cout << "\n\n";

                    cout << "Not a valid entry.";

                    cout << "\n\n";

                    system ("pause");

                    continue;

                }

                if (playerStrength >= 0 && playerStrength <= 30) {

                    playerAccuracy = playerAccuracy - playerStrength;

                    confirmingStats = true;

                    do {

                        system ("cls");

                        cout << "\n\n";

                        cout << "This will set your Accuracy as " << playerAccuracy << "." ;

                        cout << "\n\n";

                        cout << "Is that ok?";

                        cout << "\n\n";

                        cout << "> ";

                        getline (cin, playerEntry);

                        if (playerEntry == "yes" || playerEntry == "y" || playerEntry == "Yes" || playerEntry == "Y") {

                            system ("cls");

                            cout << "Set.";

                            cout << "\n\n";

                            system ("pause");

                            confirmingStats = false;

                            settingStats = false;

                        } else if (playerEntry == "no" || playerEntry == "n" || playerEntry == "No" || playerEntry == "N") {

                            cout << "\n\n";

                            cout << "Ok.";

                            cout << "\n\n";

                            system ("pause");

                            confirmingStats = false;

                        } else {

                            continue;

                        };

                }
                while (confirmingStats == true);

                } else {

                    cout << "\n\n";

                    cout << "Not a valid number.";

                    cout << "\n\n";

                    system ("pause");

                    continue;

                };

            } else {

                continue;

            };

        }
        while (settingStats == true);


        playerHealth = 100;
        // playerStrength = rand () % 5 + 5;
        playerLuck = rand () % 7;
        // playerAccuracy = rand () % 5 + 10;




        if (enableDesbug = true) {

            obsfucateStats = false;

        };





        // health ob

        if (playerHealth >= 75) {

            obPlayerHealth = "Healthy";

        } else if (playerHealth >= 50 && playerHealth <= 74) {

            obPlayerHealth = "Injured";

        } else if (playerHealth >= 25 && playerHealth <= 49) {

            obPlayerHealth = "Wounded";

        } else if (playerHealth <= 25) {

            obPlayerHealth = "Mortally Wounded";

        } else {

            obPlayerHealth = "[Health System Broken, Come Back Later]";

        };

        // strength ob

        if (playerStrength >= 30) {

            obPlayerStrength = "Really Strong";

        } else if (playerStrength >= 20 && playerStrength <= 29) {

            obPlayerStrength = "Pretty Strong";

        } else if (playerStrength >= 10 && playerStrength <= 19) {

            obPlayerStrength = "Kinda Strong";

        } else if (playerStrength <= 10 && playerStrength >= 4) {

            obPlayerStrength = "Relatively Strong";

        } else if (playerStrength <= 3) {

            obPlayerStrength = "like a paper could crush you";

        } else {

            obPlayerStrength = "[Health System Broken, Come Back Later]";

        };

        // accuracy ob

        if (playerAccuracy >= 30) {

            obPlayerAccuracy = "Like a Sharpshooter";

        } else if (playerAccuracy >= 20 && playerAccuracy <= 29) {

            obPlayerAccuracy = "Really Accurate";

        } else if (playerAccuracy >=10 && playerAccuracy <= 19) {

            obPlayerAccuracy = "Pretty Accurate";

        } else if (playerAccuracy <= 10 && playerAccuracy >= 4) {

            obPlayerAccuracy = "sure you could hit something if you tried";

        } else if (playerAccuracy <= 3) {

            obPlayerAccuracy = "like you may as well close your eyes";

        } else {

            obPlayerAccuracy = "[Health System Broken, Come Back Later]";

        };

    genFloor:

        roomCount = rand () % 9 + 1;

        cout << "Once in the elevator, you see that you are going to floor " << currentFloor << " which has " << roomCount << " rooms.";

        cout << "\n\n";

        freshOffElevator = true;

    genRoom:

        roomChoice = true;

        roomSplit = rand () % 2 + 1;

        system ("cls");

        system ("color 08");

        // first, prompt user for road split choice (honestly this is just me adding more chance)

        if (freshOffElevator == true) {

            cout << "Upon getting out of the elevator, you walk into a hallway and see ";

            if (roomSplit == 1) {

                cout << "a single door ";

            } else {

                cout << roomSplit << " doors ";

            };

          cout << "in front of you.";

          cout << "\n\n";

          freshOffElevator = false;

        } else if (freshOffElevator == false) {

            cout << "Upon leaving that room, you spot ";

            if (roomSplit == 1) {

                cout << "a single door ";

            } else {

                cout << roomSplit << " doors ";

            };

          cout << "ahead of you.";

          cout << "\n\n";

        } else {

            cout << "Upon leaving that room, you spot ";

            if (roomSplit == 1) {

                cout << "a single door ";

            } else {

                cout << roomSplit << " doors ";

            };

          cout << "ahead of you.";

          cout << "\n\n";

        }

        if (roomSplit == 1) {

            cout << "Since there's only one door, you have no other choice but to go through it.";

            cout << "\n\n";

            system ("pause");

            do {

                system ("cls");

                system ("color 07");

                cout << "Proceed or check your Inventory.";

                cout << "\n\n";

                cout << "> ";

                getline (cin, playerEntry);

                if (playerEntry == "proceed" || playerEntry == "go" || playerEntry == "1" || playerEntry == "enter" || playerEntry == "Proceed" || playerEntry == "door 1" || playerEntry == "Go" || playerEntry == "Enter" || playerEntry == "Door 1" || playerEntry == "enter room" || playerEntry == "Enter room" || playerEntry == "door1" || playerEntry == "Enter door" || playerEntry == "enter door" || playerEntry == "Door1") {

                roomChoice = false;

                } else if (playerEntry == "inventory" || playerEntry == "Inventory" || playerEntry == "inv" || playerEntry == "Inv" || playerEntry == "i" || playerEntry == "I") {

                    do {

                        system ("cls");

                        cout << "[INVENTORY]";

                        cout << "\n\n------------\n\n";

                        cout << "This is where you would put stuff, if items were implemented";

                        cout << "\n\n\n\n\n\n------------\n\n";

                        cout << "You would be able to enter an item here but due to the inventory not being implemented,";

                        cout << "\n\n";

                        system ("pause");

                        checkingInventory = false;
                    }
                    while (checkingInventory == true);

                } else {

                    continue;

                };

            }
            while (roomChoice != false);

            // cout << "\n\n";

            // system ("pause");

            roomChoice = false;

        } else if (roomSplit > 1) {

            system ("pause");

            do {

                system ("cls");

                system ("color 07");

                cout << "Choose a door to go through or check your Inventory.";

                cout << "\n\n";

                cout << "> ";

                getline (cin, playerEntry);

                if (playerEntry == "3" || playerEntry == "2" || playerEntry == "1" || playerEntry == "door 3" || playerEntry == "door 2" || playerEntry == "door 1" || playerEntry == "Door 3" || playerEntry == "Door 2" || playerEntry == "Door 1" || playerEntry == "door3" || playerEntry == "door2" || playerEntry == "door1" || playerEntry == "Door3" || playerEntry == "Door2" || playerEntry == "Door1") {

                roomChoice = false;

                } else if (playerEntry == "inventory" || playerEntry == "Inventory" || playerEntry == "inv" || playerEntry == "Inv" || playerEntry == "i" || playerEntry == "I") {

                    do {

                        system ("cls");

                        cout << "[INVENTORY]";

                        cout << "\n\n------------\n\n";

                        cout << "This is where you would put stuff, if items were implemented";

                        cout << "\n\n\n\n\n\n------------\n\n";

                        cout << "You would be able to enter an item here but due to the inventory not being implemented,";

                        cout << "\n\n";

                        system ("pause");

                        checkingInventory = false;
                    }
                    while (checkingInventory == true);

                } else {

                    continue;

                };

            }
            while (roomChoice != false);

        };

        // then allow inventory management

        // then finally show entrance status and enter room

        system ("cls");

        system ("color 08");

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

        system ("color 02");

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

        roomsPassed = roomsPassed + 1;

        totalRoomsPassed = totalRoomsPassed + 1;

        goto genRoom;

    battleRoom:

        system ("cls");

        system ("color 06");

        do {

            randTextNum = rand () % 19 + 1;

            enemyType = rand () % 6 + 1;

            if (enemyType == 1) {

                enemyName = "Spider";
                enemyArticle = "the";
                capitalArticle = "The";
                enemyAttackText = "bites";
                enemyHealth = 40 + (playerStrength / 3);
                enemyStrength = 20;
                enemyAccuracy = 20;
                enemyCashWorth = 10;
                enemyCashMin = 15;
                enemyTakesAdvantage = true;

                battleLoop = true;

            } else if (enemyType == 2) {

                enemyName = "Crab";
                enemyArticle = "the";
                capitalArticle = "The";
                enemyAttackText = "pinches";
                enemyHealth = 25 + (playerStrength / 3);
                enemyStrength = 15;
                enemyAccuracy = 15;
                enemyCashWorth = 9;
                enemyCashMin = 1;
                enemyTakesAdvantage = true;

                battleLoop = true;

            } else if (enemyType == 3) {

                enemyName = "Shadow";
                enemyArticle = "the";
                capitalArticle = "The";
                enemyAttackText = "hits";
                enemyHealth = 15 + (playerStrength / 3);
                enemyStrength = 5;
                enemyAccuracy = 25;
                enemyCashWorth = 10;
                enemyCashMin = 5;
                enemyTakesAdvantage = true;

                battleLoop = true;

            } else if (enemyType == 4) {

                enemyName = "Possessed Armour";
                enemyArticle = "the";
                capitalArticle = "The";
                enemyAttackText = "swings its sword at";
                enemyHealth = 30 + (playerStrength / 2);
                enemyStrength = 30;
                enemyAccuracy = 3;
                enemyCashWorth = 5;
                enemyCashMin = 15;
                enemyTakesAdvantage = true;

                battleLoop = true;

            } else if (enemyType == 5) {

                enemyName = "Test Dummy";
                enemyArticle = "the";
                capitalArticle = "The";
                enemyAttackText = "stabs";
                enemyHealth = 5 + playerStrength;
                enemyStrength = 10;
                enemyAccuracy = 20;
                enemyCashWorth = 19;
                enemyCashMin = 1;
                enemyTakesAdvantage = true;

                battleLoop = true;

            } else if (enemyType == 7) {

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

                battleLoop = false;

                system ("pause");

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

                battleLoop = false;

                system ("pause");

            };

            if (battleLoop == true) {

                cout << "As you walk in you find ";

                cout << "\n\n";

                cout << "A " << enemyName << " stands in front of you.";

            do {

                cout << "\n\n---------\n\n";

                cout << "Your Health: " << playerHealth;

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

                if (playerActRoll >= 20) {

                    playerActRoll = 20;

                };

                if (playerActRoll < 10) { // re-rolls once to improve hit chance

                    if (playerAccuracy > 10) {

                        playerActRoll = rand () % 20 + (playerAccuracy / 2);

                    } else {

                        playerActRoll = rand () % 20 - (playerAccuracy / 2);

                    };

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

                        system ("color a0");

                        cout << "[" << playerBigHit << "]\n\n";

                        system ("color 06");

                        cout << "You hit " << enemyArticle << " " << enemyName << " for " << playerAttRoll << ".";

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

                            system ("color 60");

                            cout << "In your attempt to hit " << enemyArticle << " " << enemyName << ", you tripped and took " << playerOuch << " damage.";

                            system ("color 06");

                            playerHealth = playerHealth - playerOuch;

                        } else {

                            cout << "You missed.";

                        };

                    } else {

                        cout << "You missed.";

                    };

                    if (enemyHealth <= 0) {

                        enemyHealth = 0;

                        cout << "\n\n";

                        system ("pause");

                        goto enemyKilled;

                    };

                    cout << "\n\n";

                    cout << "The " << enemyName << " has " << enemyHealth << " HP left.";

                    cout << "\n\n";

                  } else if (playerEntry == "2" || playerEntry == "Block" || playerEntry == "block" || playerEntry == "b" || playerEntry == "B") {

                    playerBlockRoll = rand () % 21 + playerLuck;

                    playerDefend = playerBlockRoll / 2;

                    cout << "\n\n";

                    cout << "You Blocked.";

                    cout << "\n\n";

                    isBlocking = true;

                  } else if (playerEntry == "giveup" || playerEntry == "surrender" || playerEntry == "no" || playerEntry == "run away") {

                    if (enableDesbug == true) {

                        cout << "\n\n";

                        cout << "Upon giving up, you are smote by the unknown forces of the tower.";

                        cout << "\n\n";

                        system ("color 0c");

                        playerHealth = 0;

                        system ("pause");

                        capitalArticle = "Your";

                        enemyName = "cowardice";

                        goto playerSlain;

                    } else {

                        cout << "\n\n";

                        randTextNum = rand () % 2;

                        if (randTextNum == 0) {

                            cout << "\n\n";

                            cout << "You hear someone whisper in your head, \"Cowardice will not be tolerated.\" You decide to continue fighting.";

                            cout << "\n\n";

                        } else {

                            cout << "\n\n";

                            cout << "Please don\'t do that....";

                            cout << "\n\n";

                        };

                    };

                        cout << "\n\n";

                  } else {

                    system ("cls");

                    cout << "The " << enemyName << " is standing there, menacingly.";

                    continue;

                  };

                  // system ("pause");

                // enemy attack goes below here

                /*

                // int enemyHealth; // self explanatory
                // int enemyStrength; // see above
                // int enemyAccuracy; // see two above
                // int enemyCashWorth; // both cash worth and min should equal to the max. ie. if max is 10 and min is 3 then worth is 7
                // int enemyCashMin; // check line before
                // bool enemyIntimidation; // allows enemies to have opening moves/first attacks
                // bool enemyTakesAdvantage; // usually true, but can be false. used mostly for Crit Fails

                int playerAttRoll; // player attack
                int playerActRoll; // player action (why these are in two different orders is honestly beyond me)
                int playerBlockRoll;
                int enemyActRoll; // enemy action
                int enemyAttRoll; // enemy attack
                int playerDodgeRoll;
                int LuckRoll;
                int playerCritFail;
                int playerOuch;

                */

                if (enemyAccuracy > 10) {

                    enemyActRoll = rand () % 20 + (enemyAccuracy / 2);

                  } else {

                    enemyActRoll = rand () % 20 - (enemyAccuracy / 2);

                  };

                if (enemyActRoll >= 20) {

                    enemyActRoll = 20;

                };

                if (enemyActRoll < 10) { // re-rolls once to improve hit chance

                    if (enemyAccuracy > 10) {

                        enemyActRoll = rand () % 20 + (enemyAccuracy / 2);

                    } else {

                        enemyActRoll = rand () % 20 - (enemyAccuracy / 2);

                    };

                };

                  if (enemyActRoll >= 10 && enemyActRoll != 20) {

                    if (enemyStrength > 10) {

                        enemyAttRoll = rand () % 20 + (enemyStrength / 2);

                    } else {

                        enemyAttRoll = rand () % 20 - (enemyStrength / 2);

                    };

                    if (enemyAttRoll < (enemyStrength / 4)) {

                        enemyAttRoll = enemyStrength / 4;

                    };

                cout << "\n\n";

                cout << capitalArticle << " " << enemyName << " " << enemyAttackText << " you for " << enemyAttRoll << ".";

                playerHealth = playerHealth - enemyAttRoll;

                } else if (enemyActRoll == 20) {

                        enemyAttRoll = (rand () % 15 + 5) + enemyStrength;

                        if (isBlocking == true) {

                          enemyAttRoll = enemyAttRoll - (enemyAttRoll / 3);

                          isBlocking = false;

                        };

                        if (randTextNum = 1) {

                            enemySmashHit = "Ouch.";

                        } else if (randTextNum == 20){

                            enemySmashHit = "Critical Hit!";

                        }  else {

                            enemySmashHit = "That\'ll bruise.";

                        };

                        cout << "\n\n";

                        system ("color 60");

                        cout << "[" << enemySmashHit << "]\n\n";

                        system ("color 06");

                        cout << capitalArticle << " " << enemyName << " hit you for " << enemyAttRoll << ".";

                        playerHealth = playerHealth - enemyAttRoll;

                    } else if (playerActRoll < 10 && playerActRoll != 1) {

                        cout << "\n\n";

                        cout << capitalArticle << " " << enemyName << " missed.";

                    } else if (playerActRoll == 1) {

                        enemyCritFail = rand () % 100;

                        // if it lands on 4, 18, 47, 58, or 83 then it will trigger crit fail

                        // if (playerCritFail = 47 || playerCritFail = 83 || playerCritFail = 18 || playerCritFail = 4 || playerCritFail = 58) (for historical reasons)

                        if (enemyCritFail == 4 || enemyCritFail == 18 || enemyCritFail == 47 || enemyCritFail == 58 || enemyCritFail == 83) {

                            playerAdvantage = rand () % 10 + 15;

                            cout << "\n\n";

                            system ("color a0");

                            cout << "As " << capitalArticle << " " << enemyName << " misses its attack, you hit it for " << playerAdvantage << " damage.";

                            system ("color 06");

                            enemyHealth = enemyHealth - playerAdvantage;

                        } else {

                            cout << "\n\n";

                            cout << capitalArticle << " "  << enemyName << " missed.";

                        };

                    } else {

                        cout << "\n\n";

                        cout << capitalArticle << " "  << enemyName << " missed.";

                    };

                    cout << "\n\n";

                    if (playerHealth <= 0) {

                        playerHealth = 0;

                        system ("color 0c");

                    };

                    system ("pause");

            playerSlain:

                if (playerHealth <= 0) {

                    system ("cls");

                    // if (allowFlash == true) {

                        system ("color 40");

                    // };

                    cout << "[GAME OVER]";

                    system ("color 04");

                    cout << "\n\n\n\n  ------------\n\n";

                    randTextNum = rand () % 7;

                    if (randTextNum == 0) {

                        cout << "How Unfortunate.";

                    } else if (randTextNum == 1) {

                        cout << "     no.";

                    } else if (randTextNum == 2) {

                        cout << "\"And thus your adventure ends here.\"";

                    } else if (randTextNum == 3) {

                        cout << "You Were Slain.";

                    } else if (randTextNum == 4) {

                        cout << "   You Died";

                    } else if (randTextNum == 5) {

                        cout << "What it says on the tin.";

                    } else if (randTextNum == 6) {

                        cout << "Good Night";


                    } else {

                        cout << "Oh.";

                    };

                    cout << "\n\n  ------------\n\n\n\n";

                    cout << capitalArticle << " " << enemyName << " killed you.";

                    cout << "\n\n\n\n\n\n";

                    cout << "You passed " << totalRoomsPassed << " rooms, killed " << enemiesDead << " enemies , and earned " << totalPlayerCash << " total credits." ;

                    cout << "\n\n";

                    system ("pause");

                    gameOverScreen:

                        system ("cls");

                        system ("color 04");

                        cout << "[GAME OVER]";

                        cout << "\n\n";

                        cout << "Would you like to: ";

                        cout << "\n\n";

                        cout << "Restart";

                        cout << "\n";

                        cout << "Quit";

                        cout << "\n\n";

                        cout << "> ";

                        getline (cin, playerEntry);

                        if (playerEntry == "restart" || playerEntry == "Restart" || playerEntry == "r" || playerEntry == "R") {

                            goto initializeGame;

                        } else if (playerEntry == "quit" || playerEntry == "Quit" || playerEntry == "q" || playerEntry == "Q" || playerEntry == "exit" || playerEntry == "Exit" || playerEntry == "e" || playerEntry == "E") {

                            goto controlQuit;

                        } else {

                            goto gameOverScreen;

                        };

                };


                // };

            // cout << "\n\n";

                // enemyHealth = 0;

                enemyKilled:

                if (enemyHealth <= 0) {

                        enemyHealth = 0;
                };

                if (enemyHealth <= 0) {

                    system ("cls");

                    cout << "\n\n";

                    cout << enemyName << " Defeated.";

                    enemiesDead = enemiesDead + 1;

                    cout << "\n\n";

                    cashEarned = rand () % enemyCashWorth + enemyCashMin;

                    playerStasisCash = playerCash;

                    playerCash = playerStasisCash + cashEarned;

                    totalPlayerCash = totalPlayerCash + cashEarned;

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

        roomsPassed = roomsPassed + 1;

        totalRoomsPassed = totalRoomsPassed + 1;

        goto genRoom;


    // exit jump; call this when making exit functions

    controlQuit:

        system ("cls");

        cout << "Exiting...\n\n";

    return 0;

}; //safety line
