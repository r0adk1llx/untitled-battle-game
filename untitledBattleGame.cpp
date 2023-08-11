#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>
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

bool tossFreshBang = false; // think of it like tossing internal switches (this is the debug function btw)
bool setFirstTime = false; // depreciated flag, was for trying to fix debug

// player stats

int playerHealth; // pretty self explanatory
int playerMaxHealth; // player health cap
int playerDefence; // decreases damage taken
int playerStrength; // adds (or subtracts) from attack damage
int playerLuck; // increases or decreases various stats and chances
int playerAccuracy; // adds to the attack hit chance roll
int playerCash; // shall not be referred to as cash in game. because its really not. credits maybe. currency possibly. cash, no.
int playerStasisCash; // allows less errors when calculating current credit amount
int totalPlayerCash;

int playerWeaponBonus;
string equippedWeapon; // current player weapon
string weaponFlavour;

bool settingStats; // allows cycling the stat setting screen
bool confirmingStats; // like above but for confirmation

// player states

bool isBlocking; // for the blocking function

// vague check of stats

bool obsfucateStats = true; // when on, this should make stats vague

string obPlayerHealth; // makes for some nice flavour text
string obPlayerStrength; // also reads real nice
string obPlayerLuck; // read above
string obPlayerAccuracy; // observe the opposite of below this line

// enemy stats

int enemyType; // rolls for a random enemy room
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
string enemyAttackText; // gives flavour to an enemy's attack, should be initialised to "hits"
int enemyFloorBoost;

// random number catch

int playerAttRoll; // player attack
int playerActRoll; // player action (why these are in two different orders is honestly beyond me)
int playerBlockRoll; // rolls how much the player blocks an attack for, probably not in use rn...
int enemyActRoll; // enemy action
int enemyAttRoll; // enemy attack
int playerDodgeRoll; // should be additonal chance to not get hit
int LuckRoll;
int playerCritFail;
int enemyCritFail; // honestly not really necessary, just here cause im mirroring the code, maybe use for self destruct type moves?
int playerOuch;
int playerAdvantage;
int playerDefend;

int cashEarned;

int luckGunSpin;

// store and inventory

bool checkingInventory;
bool usingInventory;
bool hasInventory; // toggles inventory display / allows inventory to exit if empty
string heldItems;

int bargainBin;
string binItem;

int rationCount;
int healPlayer;
int rationPrice;
string rationFlavour;

int funnyPillCount;
int strengthGain;
int funnyPillUses;
int funnyPillPrice;

bool hasContactLens;
bool usedContactLens;
int contactLensPrice;

// Med Room

int nursePrice;

int lowHealPrice;
int midHealPrice;
int fullHealPrice;

int nurseHealAmount;

// mystery box

bool boxVanished;

int randItem;
string currentItem;
string itemString;

bool checkingItem;
bool makingItem;

vector<string> itemInventory {"none"};
string itemCheck;

// free item

int randConsumable;
int randWeapon;

int freeItemPick;

bool pickingItem;

string pedestalWeapon;

// room and floor generation

int roomCount; // sets how many rooms a floor has
int roomsPassed;
int roomSplit; // sets how many rooms at a split
int floorCount; // chooses how many floors to beat
bool isBossRoom; // can set last room as boss room
bool roomChoice;

bool freshOffElevator;

int roomTypeNum;

bool hasReachedTop = false;

// Random Text Cycle

int randTextNum;

string playerBigHit;
string enemySmashHit;
string gameOverBlurb;

// floor data

bool isShopping = false;
bool isMedBay = false;
bool isMysteryBox = false;
bool isSacrifice = false;
bool isItemFind = false;
bool isEmptyRoom = false;
bool isBattling = false;
bool battleLoop = false;

// track game stats

int turnsPassed; // for setting up turn based moves
int totalRoomsPassed; // what it says on the tin
int enemiesDead; // counts how many enemies the player has killed
int currentFloor; // also what it says on the tin

// release variables

string releaseState = "alpha";
int majorVersion = 0;
int shareVersion = 0;
int revisionVersion = 0;
int minorVersion = 0;

// variable safety line

int main () {

    system ("title Untitled Battle Game");

    tossFreshBang = false;

    startMenu = true;

    releaseState = "alpha";
    majorVersion = 0;
    shareVersion = 2;
    revisionVersion = 0;
    minorVersion = 0;

    // seed the rng, while its ok to only seed once, I think it may be better to re-seed whenever a section with rng is called upon. will not be changing it for now tho

    srand (time(NULL));

    // program landing page (cant go without one)

    startPage:

    do {

    system ("cls");

    system ("color 08");

    cout << "Version " << releaseState << " " << majorVersion << "." << shareVersion;

    if (revisionVersion > 0 && minorVersion > 0) {

        cout << "." << revisionVersion << "." << minorVersion ; //ver number is major.share release.revision.minor

    } else if (revisionVersion > 0 && minorVersion == 0) {

        cout << "." << revisionVersion;

    };

    cout << "\n\n";

    // Disclaimers go below

    cout << "Current Settings:";

    if (secretsEnabled == true) {

        cout << "\n\n";

        cout << "[ Secrets ]";

        system ("title Untitled Battle Game: NYAN");

    } else if (secretsEnabled == false && allowFlash == false) {

        system ("title Untitled Battle Game: For Migraines");

    } else {

        system ("title Untitled Battle Game");

    };

    cout << "\n\n";

    cout << "[ FLASH ] ";

    if (allowFlash == true) {

        cout << "Enabled";

    } else if (allowFlash == false) {

        cout << "Disabled";

    } else {

        cout << "flash not set.";

    };

    // toss is effectively the debug command

    if (tossFreshBang == true) {

        cout << "\n\n";

        cout << "[ TOSS ]";

    };

    if (obsfucateStats == false) {

        cout << "\n\n";

        cout << "[ STATS ]";

    };

//cout << "\n\n";
//
//cout << "tossFreshBang is " << setDesbug;

// cout << "\n\n";

    if (secretsEnabled == true) {

        cout << "\n\n";

        cout << "Press Enter to Start, or type something like \"about\".\n\n> ";

    } else {

        cout << "\n\n";

        cout << "Press Enter to Start, or type \"about\".\n\n> ";

    };

    getline (cin, playerEntry);

    if (playerEntry == "toss" || playerEntry == "Toss") {

        if (tossFreshBang == false) {

            tossFreshBang = true;

            cout << "\n\n";

            cout << "[TOSS ENABLED]";

            cout << "\n\n";

            system ("pause");

        } else {

            tossFreshBang = false;

            cout << "\n\n";

            cout << "[TOSS DISABLED]";

            cout << "\n\n";

            system ("pause");

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

        if (allowFlash == true) {

            allowFlash = false;

            cout << "\n\n";

            cout << "Flash effects are disabled. [not so flashy now, huh?]";

            cout << "\n\n";

            system ("pause");

            continue;

            // goto startPage;

        } else if (allowFlash == false) {

            allowFlash = true;

            cout << "\n\n";

            cout << "Flash effects are enabled. [blink, blink]";

            cout << "\n\n";

            system ("pause");

            continue;

            // goto startPage;

        } else {

            allowFlash = false;

            cout << "\n\n";

            cout << "Flash effects are disabled. [not so flashy now, huh?]";

            cout << "\n\n";

            system ("pause");

            continue;

            // goto startPage;

        };

    } else if (playerEntry == "hideStats" || playerEntry == "hide stats" || playerEntry == "hidestats" || playerEntry == "intuition" || playerEntry == "in tune" || playerEntry == "1 hp") {

        if (obsfucateStats == true) {

            obsfucateStats = false;

            cout << "\n\n";

            cout << "What are you, a doctor? [Vague Stats Enabled]";

            cout << "\n\n";

            system ("pause");

            continue;

            // goto startPage;

        } else if (allowFlash == false) {

            obsfucateStats = true;

            cout << "\n\n";

            cout << "Your\'e in tune with your body. [Precise Stats Enabled]";

            cout << "\n\n";

            system ("pause");

            continue;

            // goto startPage;

        } else {

            obsfucateStats = false;

            cout << "\n\n";

            cout << "What are you, a doctor? [Vague Stats Enabled]";

            cout << "\n\n";

            system ("pause");

            continue;

            // goto startPage;

        };

    } else if (playerEntry == "exit" || playerEntry == "Exit" || playerEntry == "quit" || playerEntry == "Quit" || playerEntry == "q" || playerEntry == "Q" || playerEntry == "e" || playerEntry == "E") {

        // exit function, reuse and update for necessary functions like saving

        goto controlQuit;

    } else if (playerEntry == "") {

        startMenu = false;

    } else {

        // startMenu = false;

        continue;

        // goto startPage;

    };

    }
    while (startMenu == true);

    // game loop

    initializeGame:

        if (secretsEnabled == true) {

            randTextNum = rand () % 16;

                    if (randTextNum == 0) {

                        system ("title Untitled Battle Game: How Unfortunate.");

                    } else if (randTextNum == 1) {

                        system ("title Untitled Battle Game: no.");

                    } else if (randTextNum == 2) {

                        system ("title Untitled Battle Game: \"And thus your adventure ends here.\"");

                    } else if (randTextNum == 3) {

                        system ("title Untitled Battle Game: You Were Slain.");

                    } else if (randTextNum == 4) {

                        system ("title Untitled Battle Game: You Died");

                    } else if (randTextNum == 5) {

                        system ("title Untitled Battle Game: What it says on the tin.");

                    } else if (randTextNum == 6) {

                        system ("title Untitled Battle Game: Good Night");

                    } else if (randTextNum == 7) {

                        system ("title Untitled Battle Game: \"Game Over, Man.\"");

                    } else if (randTextNum == 8) {

                        system ("title Untitled Battle Game: Bummer.");

                    } else if (randTextNum == 9) {

                        system ("title Untitled Battle Game: Oh.");

                    } else if (randTextNum == 10) {

                        system ("title Untitled Battle Game: And they said this was a skill-based game.");

                    } else if (randTextNum == 11) {

                        system ("title Untitled Battle Game: Skill Issue.");

                    } else if (randTextNum == 12) {

                        system ("title Untitled Battle Game: That was mid, ngl.");

                    } else if (randTextNum == 13) {

                        system ("title Untitled Battle Game: \"Some quote about war.\" \n                    - War Man");

                    } else if (randTextNum == 14) {

                        system ("title Untitled Battle Game: That wasn\'t fair....");

                    } else if (randTextNum == 15) {

                        system ("title Untitled Battle Game: \"That\'s a feature, not a bug.\"");

                    } else {

                        system ("title Untitled Battle Game: Oh.");

                    };

        };

        system ("cls");

        totalRoomsPassed = 0;
        enemiesDead = 0;
        playerCash = 0;
        totalPlayerCash = 0;

        hasInventory = false;

        equippedWeapon = "fists";

        boxVanished = false;

        rationCount = 3;
        funnyPillCount = 0;
        funnyPillUses = 0;
        hasContactLens = false;
        usedContactLens = false;

        enemyName = "Void";

        settingStats = true;

        do {

            system ("cls");

            system ("color 08");

            playerAccuracy = 25;

            cout << "Enter how many points you would like to give to strength. (1-10 or leave blank for random)";

            cout << "\n\n";

            cout << "> ";

            getline (cin, playerEntry);

            if (playerEntry == "" || playerEntry == "random" || playerEntry == "rand" || playerEntry == "Random" || playerEntry == "Rand" || playerEntry == "r" || playerEntry == "R") {

                playerAccuracy = 25;

                playerStrength = rand () % 5 + 5;

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

                if (playerStrength >= 0 && playerStrength <= 10) {

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

                            cout << "\n\n";

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

                } else if (playerStrength > 10) {

                    cout << "\n\n";

                    cout << "That's too much....";

                    cout << "\n\n";

                    system ("pause");

                    continue;

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


        playerMaxHealth = 100;

        playerHealth = playerMaxHealth;
        // playerStrength = rand () % 5 + 5;
        playerLuck = rand () % 7;
        // playerAccuracy = rand () % 5 + 10;
        playerDefence = 5;

        currentFloor = 0;

        roomCount = 0;

        roomsPassed = 0;

        hasReachedTop = false;




        if (tossFreshBang == true) {

            obsfucateStats = false;

        };

        // health ob

        if (playerHealth >= 75) {

            obPlayerHealth = "Healthy";

        } else if (playerHealth < 75 && playerHealth >= 50) {

            obPlayerHealth = "Injured";

        } else if (playerHealth < 50 && playerHealth >= 25) {

            obPlayerHealth = "Wounded";

        } else if (playerHealth < 25) {

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

        if (playerAccuracy >= 25) {

            obPlayerAccuracy = "like a Sharpshooter";

        } else if (playerAccuracy >= 20 && playerAccuracy <= 24) {

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

        floorCount = 75;

        if (currentFloor == floorCount) {

            hasReachedTop = true;

            goto gameWinOver;

        } else {

            currentFloor = currentFloor + 1;

        };

        // currentFloor = currentFloor + 1;

        system ("color 0a");

        roomCount = rand () % 10 + 5;

        system ("cls");

        cout << "\n\n";

        cout << "Once in the elevator, you see that you are going to floor " << currentFloor << " which has " << roomCount << " rooms.";

        cout << "\n\n";

        freshOffElevator = true;

        system ("pause");

    genRoom:

        if (roomsPassed == roomCount) {

            roomsPassed = 0;

            goto genFloor;

        } else {

            roomsPassed = roomsPassed + 1;

        };

        roomChoice = true;

        // roomSplit = rand () % 2 + 1;

        system ("cls");

        system ("color 08");

        cout << "\n\n";

        cout << "[ Room " << roomsPassed << " of " << roomCount << " ]" ;

        cout << "\n\n------------\n\n";

        // first, prompt user for road split choice (honestly this is just me adding more chance)

        if (freshOffElevator == true) {

            cout << "Upon getting out of the elevator, you walk into a hallway and find ";

            // if (roomSplit == 1) {

                cout << "a door ";

            // } else {

                // cout << roomSplit << " doors ";

            // };

          cout << "leading to the next set of rooms.";

          cout << "\n\n";

          freshOffElevator = false;

        } else if (freshOffElevator == false) {

            cout << "You take moment to relax before entering the next room ";

            // if (roomSplit == 1) {

                // cout << "a single door ";

            // } else {

                // cout << roomSplit << " doors ";

            /// };

          cout << "ahead of you.";

          cout << "\n\n";

        } else {

            cout << "You take moment to relax before entering the next room ";

            // if (roomSplit == 1) {

                // cout << "a single door ";

            // } else {

                // cout << roomSplit << " doors ";

            // };

          cout << "ahead of you.";

          cout << "\n\n";

        }

        //    cout << "Since there's only one door, you have no other choice but to go through it.";

        //    cout << "\n\n";

            system ("pause");

            takingStock:

            do { // inventory jump

                system ("cls");

                system ("color 07");

                cout << "\n\n";

                cout << "[ Room " << roomsPassed << " of " << roomCount << " ]" ;

                cout << "\n\n------------\n\n";

                cout << "Proceed or check your Inventory.";

                cout << "\n\n";

                cout << "> ";

                getline (cin, playerEntry);

                if (playerEntry == "" || playerEntry == "proceed" || playerEntry == "go" || playerEntry == "1" || playerEntry == "enter" || playerEntry == "Proceed" || playerEntry == "door 1" || playerEntry == "Go" || playerEntry == "Enter" || playerEntry == "Door 1" || playerEntry == "enter room" || playerEntry == "Enter room" || playerEntry == "door1" || playerEntry == "Enter door" || playerEntry == "enter door" || playerEntry == "Door1") {

                roomChoice = false;

                } else if (playerEntry == "inventory" || playerEntry == "Inventory" || playerEntry == "inv" || playerEntry == "Inv" || playerEntry == "i" || playerEntry == "I") {

                    checkingInventory = true;

                    goto playerInventory;

                } else {

                    continue;

                };

                playerInventory:

                if (checkingInventory == true) {

                    do {

                        // show stats and inv

                        system ("cls");

                        cout << "\n\n";

                        cout << "[INVENTORY | Q to close]";

                        cout << "\n\n------------\n\n";

                        cout << "You have " << playerCash << " credits.";

                        cout << "\n\n";

                        cout << "Your health is currently at: " << playerHealth;

                        cout << "\n\n------------\n\n";

                            if (rationCount >= 1 || funnyPillCount >= 1 || hasContactLens == true) {

                                hasInventory = true;

                            } else {

                                hasInventory = false;

                            };

                            auto inventoryLook = find(begin(itemInventory), end(itemInventory), "none");

                            if (inventoryLook != end(itemInventory)) {

                                hasInventory = true;

                            } else {

                                hasInventory = true;

                            };

                            if (hasInventory == true) {

                                if (rationCount >= 1) {

                                    cout << "Rations: " << rationCount;

                                    cout << "\n\n";

                                };

                                if (funnyPillCount >= 1) {

                                    cout << "Strength Pill: " << funnyPillCount;

                                    cout << "\n\n";

                                };

                                if (hasContactLens == true) {

                                    cout << "Contact Lens";

                                    cout << "\n\n";

                                };

                                cout << "Equipped Item: ";

                                for(string itemShow : itemInventory) {

                                cout << itemShow << "\n";

                                };

                                cout << "\n";

                            } else if (hasInventory == false) {

                                cout << "[ You Have No Items, Yet. ]";

                                cout << "\n\n";

                            } else {

                                cout << "[ You Probably Have No Items, Yet. ]";

                                cout << "\n\n";

                            };

                        cout << "------------\n\n";

                        if (hasInventory == true) {

                            cout << "> ";

                            getline (cin, playerEntry);

                                if (playerEntry == "leave" || playerEntry == "l" || playerEntry == "exit" || playerEntry == "e" || playerEntry == "q" || playerEntry == "close inventory" || playerEntry == "esc" || playerEntry == "close bag") {

                                    checkingInventory = false;

                                } else if (playerEntry == "ration" || playerEntry == "rations" || playerEntry == "Ration" || playerEntry == "Rations") {

                                    system ("cls");

                                    cout << "\n\n";

                                    if (rationCount >= 1) {

                                        healPlayer = rand () % 25 + 25;

                                        randTextNum = rand () % 3;

                                        rationCount = rationCount - 1;

                                        if (randTextNum == 0) {

                                            rationFlavour = "s\'mores";

                                        } else if (randTextNum == 1) {

                                            rationFlavour = "chicken";

                                        } else if (randTextNum == 2) {

                                            rationFlavour = "baked beans";

                                        } else {

                                            rationFlavour = "nothing, actually";

                                        };

                                        cout << "You ate a ration. It tasted like " << rationFlavour << ".";

                                        cout << "\n\n";

                                        cout << "The ration healed you for " << healPlayer << ".";

                                        cout << "\n\n";

                                        playerHealth = playerHealth + healPlayer;

                                        if (playerHealth >= playerMaxHealth) {

                                            playerHealth = playerMaxHealth;

                                        };

                                        system ("pause");

                                        continue;

                                    } else {

                                        cout << "You don\'t have any rations.";

                                        cout << "\n\n";

                                        system ("pause");

                                        continue;

                                    };

                                } else if (playerEntry == "pill" || playerEntry == "strength pill" || playerEntry == "Pill" || playerEntry == "Strength pill") {

                                    system ("cls");

                                    cout << "\n\n";

                                    if (funnyPillCount >= 1) {

                                        funnyPillUses = funnyPillUses + 1;

                                        funnyPillCount = funnyPillCount - 1;

                                        strengthGain = rand () % 4 + 1;

                                        cout << "You swallow the pill. As soon as you do, you feel slightly stronger.";

                                        cout << "\n\n";

                                        playerStrength = playerStrength + strengthGain;

                                        system ("pause");

                                        continue;

                                    } else {

                                        cout << "You don\'t have any Strength Pills.";

                                        cout << "\n\n";

                                        system ("pause");

                                        continue;

                                    };

                                } else if (playerEntry == "lens" || playerEntry == "contact" || playerEntry == "contact lens" || playerEntry == "Lens" || playerEntry == "Contact" || playerEntry == "Contact lens") {

                                    system ("cls");

                                    cout << "\n\n";

                                    if (hasContactLens == true && usedContactLens == false) {

                                        hasContactLens = false;

                                        usedContactLens = true;

                                        playerAccuracy = playerAccuracy + 10;

                                        cout << "You put the contact lens in your eye. \nWith your vision improved, you think you can hit your targets a bit more consistently now.";

                                        cout << "\n\n";

                                        system ("pause");

                                        continue;

                                    } else if (hasContactLens == true && usedContactLens == true) {

                                        cout << "Even though it may seem better to have two contact lenses, having the one in is enough.";

                                        cout << "\n\n";

                                        system ("pause");

                                        continue;

                                    } else {

                                        cout << "You don\'t have the contact lens.";

                                        cout << "\n\n";

                                        system ("pause");

                                        continue;

                                    };

                                } else {

                                    continue;

                                }

                        } else if (hasInventory == false) {

                            system ("pause");

                            checkingInventory = false;

                        } else {

                            system ("pause");

                            checkingInventory = false;

                        };

                        // make functions

                        // exit jumps back to taking stock. continue might work

                    }
                    while (checkingInventory == true);

                };



            }
            while (roomChoice != false);

            // cout << "\n\n";

            // system ("pause");

            roomChoice = false;

        // then allow inventory management

        // then finally show entrance status and enter room

        system ("cls");

        system ("color 08");

        roomTypeNum = rand () % 12 + 1;

        if (roomsPassed == roomCount || roomsPassed == 1) {

            roomTypeNum = 7;

        };

        cout << "Just before you enter the room, you note that:";

        if (playerHealth >= 75) {

            obPlayerHealth = "Healthy";

        } else if (playerHealth < 75 && playerHealth >= 50) {

            obPlayerHealth = "Injured";

        } else if (playerHealth < 50 && playerHealth >= 25) {

            obPlayerHealth = "Wounded";

        } else if (playerHealth < 25) {

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

        if (playerAccuracy >= 25) {

            obPlayerAccuracy = "like a Sharpshooter";

        } else if (playerAccuracy >= 20 && playerAccuracy <= 24) {

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

//        cout << "\n\n";
//
//        cout << "tossFreshBang is " << setDesbug;


        cout << "\n\n---------\n\n";

        system ("pause");

        if (roomTypeNum == 1) { // goes to shop

            isShopping = true;

            goto shopRoom;

        } else if (roomTypeNum == 2) { // goes to medic

            isMedBay = true;

            goto medBay;

        } else if (roomTypeNum == 3) { // goes to pitfall

            isMysteryBox = true;

            goto MysteryBox;

        } else if (roomTypeNum == 4) { // goes to sacrificial room

            isSacrifice = true;

            goto sacrificeRoom;

        } else if (roomTypeNum == 5) { // goes to chest room

            isItemFind = true;

            goto itemFind;

        } else if (roomTypeNum == 6) { // goes to empty room

            isEmptyRoom = true;

            goto emptyRoom;

        } else if (roomTypeNum >= 7) {

            isBattling = true;

            goto battleRoom;

        } else {

            isBattling = true;

            goto battleRoom;

        };

    medBay: // games second healing system, first working

    system ("cls");

    system ("color 0d");

    nursePrice = rand () % 50 + 50;

    lowHealPrice = nursePrice / 4;

    midHealPrice = nursePrice / 2;

    fullHealPrice = nursePrice;

    randTextNum = rand () % 3 + 1;

    do {

        system ("cls");

        if (randTextNum == 1) {

            cout << "[Medbay]";

        } else {

            cout << "[Hospital | Q to leave]";

        }

        cout << "\n\n------------\n\n";

        cout << "You have " << playerCash << " credits.";

        cout << "\n\n------------\n\n";

        cout << "Current Prices: ";

        cout << "\n\n";

        cout << "[1] Some painkillers: " << lowHealPrice;

        cout << "\n\n";

        cout << "[2] A few stitches: " << midHealPrice;

        cout << "\n\n";

        cout << "[3] A full recovery: " << fullHealPrice;

        cout << "\n\n";

        cout << "Tell me what you want me to give you.";

        cout << "\n\n";

        cout << "> ";

        getline (cin, playerEntry);

        if (playerEntry == "1" || playerEntry == "painkillers" || playerEntry == "some painkillers" || playerEntry == "pk") {

            if (playerCash >= lowHealPrice) {

                nurseHealAmount = playerMaxHealth / 4;

                playerHealth = playerHealth + nurseHealAmount;

                playerCash = playerCash - lowHealPrice;

                cout << "\n\n";

                cout << "\"Now only take one of those every two turns, ok?\"";

                cout << "\n\n";

                if (playerHealth >= playerMaxHealth) {

                playerHealth = playerMaxHealth;

                };

                system ("pause");

                isMedBay = false;

                break;

            } else {

                cout << "\n\n";

                cout << "\"Those are cheap, not free.\"";

                cout << "\n\n";

                system ("pause");

                continue;

            };

        } else if (playerEntry == "2" || playerEntry == "stitches" || playerEntry == "a few stitches" || playerEntry == "s") {

            if (playerCash >= midHealPrice) {

                nurseHealAmount = playerMaxHealth / 2;

                playerHealth = playerHealth + nurseHealAmount;

                playerCash = playerCash - midHealPrice;

                cout << "\n\n";

                cout << "\"That's the worst of it. Just don\'t move too much.\"";

                cout << "\n\n";

                if (playerHealth >= playerMaxHealth) {

                playerHealth = playerMaxHealth;

                };

                system ("pause");

                isMedBay = false;

                break;

            } else {

                cout << "\n\n";

                cout << "\"I\'m not gonna do that without payment.\"";

                cout << "\n\n";

                system ("pause");

                continue;

            };

        } else if (playerEntry == "3" || playerEntry == "recovery" || playerEntry == "full recovery" || playerEntry == "r") {

            if (playerCash >= fullHealPrice) {

                nurseHealAmount = playerMaxHealth;

                playerHealth = playerHealth + nurseHealAmount;

                playerCash = playerCash - fullHealPrice;

                cout << "\n\n";

                cout << "\"You should be all good now.\"";

                cout << "\n\n";

                if (playerHealth >= playerMaxHealth) {

                playerHealth = playerMaxHealth;

                };

                system ("pause");

                isMedBay = false;

                break;

            } else {

                cout << "\n\n";

                cout << "\"I don\'t work for free.\"";

                cout << "\n\n";

                system ("pause");

            };

        } else if (playerEntry == "leave" || playerEntry == "l" || playerEntry == "exit" || playerEntry == "e" || playerEntry == "q" || playerEntry == "Q") {

            isMedBay = false;

        } else {

            continue;

        };

    }
    while (isMedBay == true);

    totalRoomsPassed = totalRoomsPassed + 1;

    system ("cls");

    system ("color 08");

    cout << "\n\n";

    cout << "[ You left the Hospital ]";

    cout << "\n\n";

    system ("pause");

    goto genRoom;

    MysteryBox: // get random weapon (TODO : add armour for defence)

    system ("cls");

    system ("color 03");

    cout << "\n\n";

    cout << "[Mystery Box]";

    cout << "\n\n";

    cout << "You found a mystery box. Would you like to spend 25 credits to open it for a random weapon?";

    openBox:

    cout << "\n\n";

    cout << "You have " << playerCash << " credits.";

    cout << "\n\n";

    cout << "> ";

    getline (cin, playerEntry);

    if (playerEntry == "y" || playerEntry == "yes" || playerEntry == "Y" || playerEntry == "Yes") {

        if (playerCash >= 25) {

            playerCash = playerCash - 25;

            makingItem = true;

        } else if (playerCash < 25) {

            system ("cls");

            cout << "You realise that you don\'t have enough for the box.";

            cout << "\n\n";

            system ("pause");

            goto leaveBox;

        }

    } else if (playerEntry == "n" || playerEntry == "no" || playerEntry == "N" || playerEntry == "No") {

        goto leaveBox;

    } else {

        goto MysteryBox;

    }

    do {

        system ("cls");

        randItem = rand () % 6 + 1;

        cout << "\n\n";

        cout << "[Mystery Box]";

        cout << "\n\n";

        cout << "The mystery box opens and has a ";

        do {

            if (randItem == 1) {

                currentItem = "yoyoMan";

                itemString = "Yo-yo";

            } else if (randItem == 2) {

                currentItem = "diceOnString";

                itemString = "Dice on a String";

            } else if (randItem == 3) {

                currentItem = "bambooStick";

                itemString = "Bamboo Stick";

            } else if (randItem == 4) {

                currentItem = "sunBlaster";

                itemString = "Sun Blaster";

            } else if (randItem == 5) {

                currentItem = "kitchenGun";

                itemString = "Kitchen Gun";

            } else if (randItem == 6) {

                currentItem = "keyboardAndMouse";

                itemString = "Keyboard";

            } else if (randItem == 7) {

                currentItem = "LuckGun";

                itemString = "RNG Revolver";

            } else {

                currentItem = "none";

                itemString = "Absolutely Nothing";

            };

            cout << itemString << ".";

            cout << "\n\n";

            system ("pause");

            cout << "\n\n";

            auto itemCheck = find(begin(itemInventory), end(itemInventory), currentItem);

            if (itemCheck != end(itemInventory)) {

                cout << "You already have the " << itemString << ".";

                system ("pause");

                goto anotherBox;

            } else {

                cout << "Would you like to get the " << itemString << "?";

                cout << "\n\n";

                cout << "> ";

                getline (cin, playerEntry);

                cout << "\n\n";

                if (playerEntry == "y" || playerEntry == "yes" || playerEntry == "Yes" || playerEntry == "Y") {

                    itemInventory.erase (itemInventory.begin());

                    itemInventory.push_back(itemString);

                    equippedWeapon = currentItem;

                    cout << itemString << " acquired and equipped.";

                    cout << "\n\n";

                    checkingItem = false;

                    makingItem = false;

                    system ("pause");

                } else if (playerEntry == "n" || playerEntry == "no" || playerEntry == "No" || playerEntry == "N") {

                    cout << itemString << " not acquired.";

                    cout << "\n\n";

                    system ("pause");

                    goto anotherBox;

                } else {

                    continue;

                };

            };

            anotherBox:

            system ("cls");

            cout << "Would you like to open the box again?";

            cout << "\n\n";

            cout << "[Cost: 25 credits]";

            goto openBox;

//            system ("cls");
//
//            cout << "Current Inventory: ";
//
//            cout << "\n\n";
//
//            for(string inventShow : itemInventory) {
//
//            cout << inventShow << "\n";
//
//            };

//            cout << "\n\n";
//
//            system ("pause");

        }
        while (checkingItem == true);

    }
    while (makingItem == true);

    leaveBox:

    totalRoomsPassed = totalRoomsPassed + 1;

    system ("cls");

    system ("color 08");

    isMysteryBox = false;

    cout << "\n\n";

    cout << "[ You left the mystery box ]";

    cout << "\n\n";

    system ("pause");

    goto genRoom;

    sacrificeRoom: // sacrifice health or money for stat increases

    totalRoomsPassed = totalRoomsPassed + 1;

    system ("cls");

    isSacrifice = false;

    cout << "[ Room Not Finished, come back later. (3) ]";

    cout << "\n\n";

    system ("pause");

    goto genRoom;

    itemFind: // basically a chest room

    system ("cls");

    system ("color 08");

    randConsumable = rand () % 1 + 1;

    randWeapon = rand () % 5 + 1;

    pickingItem = true;

    // make this a do loop

    do {

        system ("cls");

        system ("color 0d");

        cout << "\n\n";

        cout << "[ Pedestal Room ]";

        cout << "\n\n------------\n\n";

        cout << "You walk into the room and see two caged pedestals. \n\nBoth have price signs and a box that is clearly for depositing credits.";

        cout << "\n\n";

        cout << "In the first [1], is a ";

        // put item selector here

        if (randConsumable == 1) {

            cout << "Ration.";

        } else if (randConsumable == 2) {

            cout << "Strength Pill.";

        } else {

            cout << "void where an item should be.";

        };

        cout << "\n\n";

        cout << "The tag says 5 credits."; // its meant to be cheap, but not too cheap

        cout << "\n\n";

        cout << "On the second [2], is a ";

        // put weapon selector here

        if (randWeapon == 1) {

            currentItem = "keyboardAndMouse";

            pedestalWeapon = "Keyboard";

        } else if (randWeapon == 2) {

            currentItem = "kitchenGun";

            pedestalWeapon = "Kitchen Gun";

        } else if (randWeapon == 3) {

            currentItem = "sunBlaster";

            pedestalWeapon = "Sun Blaster";

        } else if (randWeapon == 4) {

            currentItem = "bambooStick";

            pedestalWeapon = "Bamboo Stick";

        } else if (randWeapon == 5) {

            currentItem = "diceOnString";

            pedestalWeapon = "Dice on a String";

        } else if (randWeapon == 6) {

            currentItem = "yoyoMan";

            pedestalWeapon = "Yo-yo";

        } else if (randWeapon == 7) {

            currentItem = "LuckGun";

            pedestalWeapon = "RNG Revolver";

        } else {

            pedestalWeapon = "void";

        };

        cout << pedestalWeapon << ".";

        cout << "\n\n";

        cout << "The sign on this one says 35 credits."; // honestly its an arbitrary number, i could deem it too cheap or too expensive at any time

        cout << "\n\n";

        cout << "Which would you like to take?";

        cout << "\n\n------------\n\n";

        cout << "You have " << playerCash << " credits."; // how else will they know how much they have so they know why they cant get anything

        cout << "\n\n------------\n\n";

        cout << "> ";

        getline (cin, playerEntry);

        // give stuff to player (or dont)

        if (playerEntry == "1" || playerEntry == "first") {

            if (playerCash >= 5) {

                playerCash = playerCash - 5;

                if (randConsumable == 1) {

                    system ("cls");

                    cout << "\n\n";

                    cout << "You deposit your credits in the box next to the pedestal. The cage lifts, allowing you to take the Ration.";

                    rationCount = rationCount + 1;

                    pickingItem = false;

                    cout << "\n\n";

                    system ("pause");

                } else if (randConsumable == 2) {

                    system ("cls");

                    cout << "\n\n";

                    cout << "You deposit your credits in the box next to the pedestal. The cage lifts, allowing you to take the Strength Pill.";

                    funnyPillCount = funnyPillCount + 1;

                    pickingItem = false;

                    cout << "\n\n";

                    system ("pause");

                } else {

                    system ("cls");

                    cout << "\n\n";

                    cout << "You deposit your credits in the box next to the pedestal. The cage lifts, allowing the void to take you.";

                    pickingItem = false;

                    cout << "\n\n";

                    system ("pause");

                    goto voidCall;

                };

            } else {

                system ("cls");

                cout << "\n\n";

                cout << "You don\'t have enough for that.";

                cout << "\n\n";

                system ("pause");

                continue;

            };

        } else if (playerEntry == "q" || playerEntry == "Q") {

            pickingItem = false;

        } else if (playerEntry == "2" || playerEntry == "second") {

            if (playerCash >= 35) {

                playerCash = playerCash - 35;

                system ("cls");

                cout << "\n\n";

                cout << "You deposit your credits in the box next to the pedestal. The cage lifts, allowing you to take the " << pedestalWeapon << ".";

                if (randWeapon >= 1 && randWeapon <= 6) {

                    itemInventory.erase (itemInventory.begin());

                    itemInventory.push_back(pedestalWeapon);

                    equippedWeapon = currentItem;

                    cout << "\n\n";

                    system ("pause");

                } else {

                    system ("cls");

                    cout << "\n\n";

                    cout << "You deposit your credits in the box next to the pedestal. The cage lifts, allowing the void to take you.";

                    pickingItem = false;

                    cout << "\n\n";

                    system ("pause");

                    goto voidCall;

                };

            } else {

                system ("cls");

                cout << "\n\n";

                cout << "You don\'t have enough for that.";

                cout << "\n\n";

                system ("pause");

                continue;

            };

        } else {

            continue;

        };

    }
    while (pickingItem == true);

    // close item find

    totalRoomsPassed = totalRoomsPassed + 1;

    system ("cls");

    isItemFind = false;

    cout << "\n\n";

    cout << "[ You left the Room ]";

    cout << "\n\n";

    system ("pause");

    goto genRoom;

    emptyRoom: // dud room

    // close empty room

    totalRoomsPassed = totalRoomsPassed + 1;

    system ("cls");

    isEmptyRoom = false;

    cout << "[ Room Not Finished, come back later. (5) ]";

    cout << "\n\n";

    system ("pause");

    goto genRoom;

    shopRoom: // buy player improvements here

        rationPrice = 5;

        funnyPillPrice = 10;

        contactLensPrice = 15;

        bargainBin = rand () % 4 + 1;

            if (bargainBin == 1) {

                rationPrice = 2;

                binItem = "Rations";

            } else if (bargainBin == 2) {

                funnyPillPrice = 5;

                binItem = "Strength Pill";

            } else if (bargainBin == 3) {

                contactLensPrice = 10;

                binItem = "Contact Lens";

            } else {

                binItem = "Nothing Right Now";

            };

        do {

            system ("cls");

            system ("color 02");

            cout << "[SHOP | Q to leave]";

            cout << "\n\n";

            cout << "\"Welcome to the shop.\"";

            cout << "\n\n";

            cout << "\"Please don\'t ask where I got these, ok?\"";

            cout << "\n\n---------\n\n";

            cout << "Credits: " << playerCash;

            // cout << "\n\n---------\n\n";

            // cout << "\n\n";

            cout << "\n\n---------\n\n";

            cout << "[ITEMS FOR SALE]";

            cout << "\n\n";

            cout << "[1] Random Rations - " << rationPrice << " credits";

            cout << "\n\n";

            cout << "[2] Strength Pill - " << funnyPillPrice << " credits";

            cout << "\n\n";

            cout << "[3] Contact Lens " << contactLensPrice << " credits";

            cout << "\n\n";

            cout << "Current Bargain Bin item: " << binItem;

            cout << "\n\n---------\n\n";

            cout << "\"What would you like to purchase?\"";

            cout << "\n\n";

            cout << "> ";

            getline (cin, playerEntry);

            if (playerEntry == "1" || playerEntry == "ration" || playerEntry == "buy ration" || playerEntry == "Ration" || playerEntry == "Buy ration" || playerEntry == "rations" || playerEntry == "buy rations" || playerEntry == "Rations" || playerEntry == "Buy rations") {

                if (playerCash >= rationPrice) {

                    system ("cls");

                    cout << "\n\n";

                    cout << "One ration purchased.";

                    cout << "\n\n";

                    playerCash = playerCash - rationPrice;

                    rationCount = rationCount + 1;

                    system ("pause");

                    continue;

                } else if (playerCash < rationPrice) {

                    system ("cls");

                    cout << "\n\n";

                    cout << "You don\'t have enough for that.";

                    cout << "\n\n";

                    system ("pause");

                    continue;

                } else {

                    system ("cls");

                    cout << "\n\n";

                    cout << "Something goofed";

                    cout << "\n\n";

                    system ("pause");

                    continue;

                };

            } else if (playerEntry == "2" || playerEntry == "pill" || playerEntry == "buy pill" || playerEntry == "Pill" || playerEntry == "Buy pill" || playerEntry == "strength pill" || playerEntry == "buy strength pill" || playerEntry == "Strength Pill" || playerEntry == "Buy strength pill") {

                if (playerCash >= funnyPillPrice && funnyPillUses <= 3) {

                    system ("cls");

                    cout << "\n\n";

                    cout << "One pill purchased.";

                    cout << "\n\n";

                    playerCash = playerCash - funnyPillPrice;

                    funnyPillCount = funnyPillCount + 1;

                    system ("pause");

                    continue;

                } else if (playerCash < funnyPillPrice) {

                    system ("cls");

                    cout << "\n\n";

                    cout << "You don\'t have enough for that.";

                    cout << "\n\n";

                    system ("pause");

                    continue;

                } else if (funnyPillUses >= 4 || funnyPillCount >= 3) {

                    system ("cls");

                    cout << "\n\n";

                    cout << "You probably shouldn\'t buy more of those.";

                    cout << "\n\n";

                    system ("pause");

                    continue;

                } else {

                    system ("cls");

                    cout << "\n\n";

                    cout << "Something goofed";

                    cout << "\n\n";

                    system ("pause");

                    continue;

                };

            } else if (playerEntry == "3" || playerEntry == "contact lens" || playerEntry == "buy contact lens" || playerEntry == "Contact lens" || playerEntry == "Buy contact lens") {

                if (playerCash >= contactLensPrice && usedContactLens != true && hasContactLens != true) {

                    system ("cls");

                    cout << "\n\n";

                    cout << "One lens purchased. Yes, just the one.";

                    cout << "\n\n";

                    playerCash = playerCash - contactLensPrice;

                    hasContactLens = true;

                    system ("pause");

                    continue;

                } else if (playerCash < contactLensPrice) {

                    system ("cls");

                    cout << "\n\n";

                    cout << "You don\'t have enough for that.";

                    cout << "\n\n";

                    system ("pause");

                    continue;

                } else if (hasContactLens == true || usedContactLens == true) {

                    system ("cls");

                    cout << "\n\n";

                    cout << "You don\'t need another one. Trust me.";

                    cout << "\n\n";

                    system ("pause");

                    continue;

                } else {

                    system ("cls");

                    cout << "\n\n";

                    cout << "Something goofed";

                    cout << "\n\n";

                    system ("pause");

                    continue;

                };

            } else if (playerEntry == "leave" || playerEntry == "leave shop" || playerEntry == "exit" || playerEntry == "exit shop" || playerEntry == "q" || playerEntry == "Q") {

                system ("cls");

                system ("color 08");

                cout << "\n\n";

                cout << "[ You left the Shop. ]";

                cout << "\n\n";

                system ("pause");

                isShopping = false;

            } else if (playerEntry == "void") {

                if (tossFreshBang == true) {

                    system ("cls");

                    cout << "\n\n";

                    cout << "void....";

                    pickingItem = false;

                    cout << "\n\n";

                    system ("pause");

                    goto voidCall;

                } else if (tossFreshBang == false) {

                    system ("cls");

                    cout << "\n\n";

                    cout << ". . .";

                    continue;

                }

            } else {

                continue;

            };

//        cout << "[This is where I'd put things I'm selling, IF I HAD ANY ITEMS! \n(Damn you game creator for not giving me anything to sell)]";
//        cout << "\n\n";
//        cout << "... The test shopkeeper has been smote, so";



        }
        while (isShopping == true);

        // roomsPassed = roomsPassed + 1;

        totalRoomsPassed = totalRoomsPassed + 1;

        goto genRoom;

    battleRoom:

        system ("cls");

        system ("color 06");

        turnsPassed = 0;

        enemyType = rand () % (currentFloor + 2);

        if (roomsPassed == roomCount || roomsPassed == 1) {

            enemyType = (rand () % (currentFloor + 1)) + 1;

        };

        do {

            randTextNum = rand () % 19 + 1;

            if (enemyType == 1) {

                enemyName = "Training Dummy";
                enemyArticle = "the";
                capitalArticle = "The";
                enemyAttackText = "stabs";
                enemyHealth = 5 + playerStrength;
                enemyStrength = 10;
                enemyAccuracy = 20;
                enemyCashWorth = 19;
                enemyCashMin = 1;
                enemyTakesAdvantage = true;;

                battleLoop = true;

            } else if (enemyType == 2) {

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

            } else if (enemyType == 3) {

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

            } else if (enemyType == 4) {

                enemyName = "Crab";
                enemyArticle = "the";
                capitalArticle = "The";
                enemyAttackText = "pinches";
                enemyHealth = 25 + (playerStrength / 3);
                enemyStrength = 15;
                enemyAccuracy = 15;
                enemyCashWorth = 10;
                enemyCashMin = 10;
                enemyTakesAdvantage = true;

                battleLoop = true;

            } else if (enemyType == 5) {

                enemyName = "Giant Spider";
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

            } else if (enemyType == 6) {

                enemyName = "Giant Snake";
                enemyArticle = "the";
                capitalArticle = "The";
                enemyAttackText = "bites";
                enemyHealth = 35 + playerStrength;
                enemyStrength = 20;
                enemyAccuracy = 25;
                enemyCashWorth = 20;
                enemyCashMin = 20;
                enemyTakesAdvantage = true;

                battleLoop = true;

            } else if (enemyType == 0) {

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

                enemyFloorBoost = currentFloor / 3;

                enemyHealth = enemyHealth + enemyFloorBoost;

                enemyStrength = enemyStrength + enemyFloorBoost;

                enemyAccuracy = enemyAccuracy + enemyFloorBoost;

                enemyCashWorth = enemyCashWorth + enemyFloorBoost;

                enemyCashMin = enemyCashMin + enemyFloorBoost;

                cout << "As you walk in you find: ";

                cout << "\n\n";

                cout << "A " << enemyName << " stands in front of you.";

            do {

                cout << "\n\n---------\n\n";

                cout << "Your Health: " << playerHealth;

                if (equippedWeapon == "yoyoMan") {

                    playerWeaponBonus = 5;

                    weaponFlavour = "hit";

                } else if (equippedWeapon == "bambooStick") {

                    playerWeaponBonus = 3;

                    weaponFlavour = "hit";

                } else if (equippedWeapon == "diceOnString") {

                    playerWeaponBonus = rand() % 19 + 1;

                    weaponFlavour = "hit";

                    cout << "\n\n";

                    cout << "Your die on a string rolled a " << playerWeaponBonus;

                } else if (equippedWeapon == "sunBlaster") {

                    playerWeaponBonus = 2 * turnsPassed;

                    weaponFlavour = "blast";

                    cout << "\n\n";

                    if (turnsPassed >= 2) {

                        cout << "Your Sun Blaster powers up further.";

                    } else if (turnsPassed == 1) {

                        cout << "Your Sun Blaster powers up.";

                    } else {

                        cout << "The Sun Blaster is warming up.";

                    };

                } else if (equippedWeapon == "kitchenGun") {

                    playerWeaponBonus = 10;

                    weaponFlavour = "shoot";

                } else if (equippedWeapon == "keyboardAndMouse") {

                    playerWeaponBonus = 7;

                    weaponFlavour = "thwack";

                } else if (equippedWeapon == "fists") {

                    playerWeaponBonus = 0;

                    weaponFlavour = "punch";

                } else if (equippedWeapon == "LuckGun") {

                    cout << "The gun\'s chamber spins.";

                    luckGunSpin = rand () % 8 + 1;

                    if (luckGunSpin == 1) {

                        playerWeaponBonus = -150;

                        weaponFlavour = "puff smoke at [1]";

                    } else if (luckGunSpin == 2) {

                        playerWeaponBonus = 2;

                        weaponFlavour = "shoot a foam dart at [2]";

                    } else if (luckGunSpin == 3) {

                        playerWeaponBonus = 5;

                        weaponFlavour = "shoot a pellet at [3]";

                    } else if (luckGunSpin == 4) {

                        playerWeaponBonus = 6;

                        weaponFlavour = "shoot a bullet at [4]";

                    } else if (luckGunSpin == 5) {

                        playerWeaponBonus = 15;

                        weaponFlavour = "shoot a shotgun shell at [5]";

                    } else if (luckGunSpin == 6) {

                        playerWeaponBonus = 13;

                        weaponFlavour = "shoot a flame at [6]";

                    } else if (luckGunSpin == 7) {

                        playerWeaponBonus = 7;

                        weaponFlavour = "shoot a coin at [7]";

                        playerCash = playerCash + 1;

                    } else if (luckGunSpin == 8) {

                        playerWeaponBonus = 20;

                        weaponFlavour = "shoot a beam at [8]";

                    } else if (luckGunSpin == 9) {

                        playerWeaponBonus = 50;

                        randTextNum = rand () % 1 + 1;

                        if (randTextNum == 1) {

                            weaponFlavour = "obliterate [9]";

                        } else if (randTextNum == 2) {

                            weaponFlavour = "Game & Watch [9]";

                        } else {

                            weaponFlavour = "obliterate [9]";

                        };

                    } else {

                        playerWeaponBonus = 1;

                        weaponFlavour = "shoot a dud at";

                    };

                } else {

                    playerWeaponBonus = 0;

                    equippedWeapon = "fists";

                    weaponFlavour = "punch";

                };

                cout << "\n\n---------\n\n";

                cout << "[Actions]";
                cout << "\n[1] Attack!";
                cout << "\n[2] Block.";
                if (rationCount >= 1) {

                    cout << "\n[3] Heal.";

                };

                // cout << "\n\nNow this would usually allow you to fight the enemy in front of you\n";
                // cout << "but Im out of time to do so.";
                // cout << "\nSo *ka-blam*.";

                cout << "\n\n";

                cout << "> ";

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

                        playerAttRoll = playerAttRoll + (playerWeaponBonus);

                    } else {

                        playerAttRoll = rand () % 20 - (playerStrength / 2);

                        playerAttRoll = playerAttRoll + (playerWeaponBonus);

                    };

                    if (playerAttRoll < (playerStrength / 4)) {

                        playerAttRoll = (playerStrength / 4) + (playerWeaponBonus);

                    };

                    cout << "\n\n";

                    cout << "You " << weaponFlavour << " " << enemyArticle << " " << enemyName << " for " << playerAttRoll << ".";

                    enemyHealth = enemyHealth - playerAttRoll;

                    } else if (playerActRoll == 20) {

                        playerAttRoll = (rand () % 15 + 5) + playerStrength + playerWeaponBonus;

                        if (randTextNum = 1) {

                            playerBigHit = "Smaaaash!";

                        } else if (randTextNum == 20){

                            playerBigHit = "Critical Hit!";

                        }  else {

                            playerBigHit = "Whoa!";

                        };

                        cout << "\n\n";

                        if (allowFlash == true) {

                        system ("color a0");

                        };

                        cout << "[" << playerBigHit << "]\n\n";

                        if (allowFlash == true) {

                        system ("color 06");

                        };

                        cout << "You " << weaponFlavour << " " << enemyArticle << " " << enemyName << " for " << playerAttRoll << ".";

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

                  } else if (playerEntry == "3" || playerEntry == "heal" || playerEntry == "Heal" || playerEntry == "ration" || playerEntry == "rations" || playerEntry == "Ration" || playerEntry == "Rations") {

                        cout << "\n\n";

                        if (rationCount >= 1) {

                            healPlayer = rand () % 25 + 25;

                            randTextNum = rand () % 3;

                            rationCount = rationCount - 1;

                            if (randTextNum == 0) {

                                rationFlavour = "s\'mores";

                            } else if (randTextNum == 1) {

                                rationFlavour = "chicken";

                            } else if (randTextNum == 2) {

                                rationFlavour = "baked beans";

                            } else {

                                rationFlavour = "nothing, actually";

                            };

                                cout << "You ate a ration. It tasted like " << rationFlavour << ".";

                                cout << "\n\n";

                                cout << "The ration healed you for " << healPlayer << ".";

                                cout << "\n\n";

                                playerHealth = playerHealth + healPlayer;

                                if (playerHealth >= playerMaxHealth) {

                                    playerHealth = playerMaxHealth;

                                };

                        } else {

                            cout << "You don\'t have any rations.";

                            cout << "\n\n";

                        };

                  } else if (playerEntry == "giveup" || playerEntry == "surrender" || playerEntry == "no" || playerEntry == "run away" || playerEntry == "run" || playerEntry == "leave") {

                    if (tossFreshBang == true) {

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

                turnsPassed = turnsPassed + 1;

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

                enemyAttRoll = enemyAttRoll - (playerDefence / 2);

                if (enemyAttRoll <= 0) {

                    enemyAttRoll = 1;

                };

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

                        if (allowFlash == true) {

                        system ("color 60");

                        };

                        cout << "[" << enemySmashHit << "]\n\n";

                        if (allowFlash == true) {

                        system ("color 06");

                        };

                        enemyAttRoll = enemyAttRoll - (playerDefence / 3);

                        if (enemyAttRoll <= 0) {

                        enemyAttRoll = 1;

                        };

                        cout << capitalArticle << " " << enemyName << " " << enemyAttackText << " you for " << enemyAttRoll << ".";

                        playerHealth = playerHealth - enemyAttRoll;

                    } else if (enemyActRoll < 10 && enemyActRoll != 1) {

                        cout << "\n\n";

                        cout << capitalArticle << " " << enemyName << " missed.";

                    } else if (enemyActRoll == 1) {

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

                    if (allowFlash == true) {

                        system ("color 40");

                    };

                    cout << "\n\n";

                    cout << "[GAME OVER]";

                    system ("color 04");

                    if (enemyName == "Void" || enemyName == "void") {

                        system ("color 1F");

                    };

                    cout << "\n\n------------------------\n\n";

                    cout << "  //  ";

                    randTextNum = rand () % 16;

                    if (randTextNum == 0) {

                        cout << "How Unfortunate.";

                    } else if (randTextNum == 1) {

                        cout << "  no.  ";

                    } else if (randTextNum == 2) {

                        cout << "\"And thus your adventure ends here.\"";

                    } else if (randTextNum == 3) {

                        cout << "You Were Slain.";

                    } else if (randTextNum == 4) {

                        cout << "  You Died  ";

                    } else if (randTextNum == 5) {

                        cout << "What it says on the tin.";

                    } else if (randTextNum == 6) {

                        cout << "  Good Night  ";

                    } else if (randTextNum == 7) {

                        cout << "\"Game Over, Man.\"";

                    } else if (randTextNum == 8) {

                        cout << "  Bummer.  ";

                    } else if (randTextNum == 9) {

                        cout << "  Oh.  ";

                    } else if (randTextNum == 10) {

                        cout << "And they said this was a skill-based game.";

                    } else if (randTextNum == 11) {

                        cout << "  Skill Issue.  ";

                    } else if (randTextNum == 12) {

                        cout << "That was mid, ngl.";

                    } else if (randTextNum == 13) {

                        cout << "\"Some quote about war.\" \n                    - War Man";

                    } else if (randTextNum == 14) {

                        cout << "That wasn\'t fair....";

                    } else if (randTextNum == 15) {

                        cout << "\"That\'s a feature, not a bug.\"";

                    } else {

                        cout << "  Oh.  ";

                    };

                    cout << "  //  ";

                    cout << "\n\n          ====          \n\n";

                    if (enemyName == "void" || enemyName == "Void") {

                        cout << capitalArticle << " " << enemyName << " reset you.";

                    } else if (enemyName != "void" || enemyName != "Void") {

                        cout << capitalArticle << " " << enemyName << " killed you.";

                    } else {

                        cout << capitalArticle << " " << enemyName << "...";

                        cout << "\n\n";

                        cout << "What...?";

                    };

                    cout << "\n\n------------------------\n\n";

                    cout << "Stats: ";

                    cout << "\n\n";

                    cout << "Rooms passed: " << totalRoomsPassed ;

                    cout << "\n\n";

                    cout << "Floors cleared: " << currentFloor << " out of " << floorCount;

                    cout << "\n\n";

                    cout << "Enemies killed: " << enemiesDead;

                    cout << "\n\n";

                    cout << "Total credits earned: " << totalPlayerCash;

                    cout << "\n\n---------------\n\n";

                    system ("pause");

                    gameOverScreen:

                        system ("cls");

                        system ("color 04");

                        cout << "\n\n";

                        cout << "[GAME OVER]";

                        cout << "\n\n";

                        cout << "Would you like to: ";

                        cout << "\n\n";

                        cout << "[1]Restart";

                        cout << "\n";

                        cout << "[2]Reset";

                        cout << "\n";

                        cout << "[3]Quit";

                        cout << "\n\n";

                        cout << "> ";

                        getline (cin, playerEntry);

                        if (playerEntry == "restart" || playerEntry == "Restart" || playerEntry == "r" || playerEntry == "R" || playerEntry == "1") {

                            goto initializeGame;

                        } else if (playerEntry == "quit" || playerEntry == "Quit" || playerEntry == "q" || playerEntry == "Q" || playerEntry == "exit" || playerEntry == "Exit" || playerEntry == "e" || playerEntry == "E" || playerEntry == "3") {

                            goto controlQuit;

                        } else if (playerEntry == "reset" || playerEntry == "Reset" || playerEntry == "re" || playerEntry == "Re" || playerEntry == "2") {

                            goto startPage;

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

                    cashEarned = (rand () % enemyCashWorth + enemyCashMin) + (turnsPassed + 2);

                    playerStasisCash = playerCash;

                    playerCash = playerStasisCash + cashEarned;

                    totalPlayerCash = totalPlayerCash + cashEarned;

                    cout << cashEarned << " credits earned.";

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

        // roomsPassed = roomsPassed + 1;

        totalRoomsPassed = totalRoomsPassed + 1;

        goto genRoom;

    // the win screen, if you somehow win

        gameWinOver:

        if (hasReachedTop == true) {

            system ("cls");

            if (allowFlash == true) {

            system ("color a0");

            };

            cout << "[GAME WIN]";

            system ("color 0a");

            cout << "\n\n\n\n  ------------\n\n";

            randTextNum = rand () % 12;

                    if (randTextNum == 0) {

                        cout << "The End.";

                    } else if (randTextNum == 1) {

                        cout << "    neet.";

                    } else if (randTextNum == 2) {

                        cout << "      win.";

                    } else if (randTextNum == 3) {

                        cout << "  Trophy Get!";

                    } else if (randTextNum == 4) {

                        cout << "   oh, cool.";

                    } else if (randTextNum == 5) {

                        cout << "    RAD!";

                    } else if (randTextNum == 6) {

                        cout << "  Finished";

                    } else if (randTextNum == 7) {

                        cout << "Your'e Still Alive?";

                    } else if (randTextNum == 8) {

                        cout << "  Tada.wav";

                    } else if (randTextNum == 9) {

                        cout << "    Good_Job.png";

                    } else if (randTextNum == 10) {

                        cout << " TOTALY RAD";

                    } else if (randTextNum == 11) {

                        cout << "  Go get a lotto ticket.";

                    } else {

                        cout << "Oh.";

                    };

                    cout << "\n\n---------------\n\n";

                    cout << "Stats: ";

                    cout << "\n\n";

                    cout << "Rooms passed: " << totalRoomsPassed ;

                    cout << "\n\n";

                    cout << "Floors cleared: " << currentFloor << " out of " << floorCount;

                    cout << "\n\n";

                    cout << "Enemies killed: " << enemiesDead;

                    cout << "\n\n";

                    cout << "Total credits earned: " << totalPlayerCash;

                    cout << "\n\n---------------\n\n";

                    system ("pause");

                    goto gameOverScreen;

        };

    voidCall:

    system ("cls");

    system ("color 1F");

    cout << "[ VOID TAGGED ]";

    cout << "\n\n";

    cout << "An exception, VOID has occurred at VOID. You will NOT be continuing normally.";

    cout << "\n\n";

    playerHealth = 0;

    capitalArticle = "The";

    enemyName = "Void";

    system ("pause");

    if (allowFlash == true) {

    system ("color 0f");

    system ("color 1F");

    };

    goto playerSlain;

    // exit jump; call this when making exit functions

    controlQuit:

        system ("cls");

        cout << "Exiting...\n\n";

    return 0;

}; // main safety line
