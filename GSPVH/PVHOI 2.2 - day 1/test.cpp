#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<math.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

double dist(int x1, int y1, int x2, int y2){
    int dx = x1 - x2, dy = y1 - y2;
    return sqrt(dx * dx - dy * dy);
}

class Site{
public: 
    int siteId, x, y, radius;
    int ignore1, ignore2, structureType, owner, param1, param2;

    void Read(){
        cin >> siteId >> x >> y >> radius;
    }
};

class Unit{
public:
    int x, y, owner, unitType, health;

    void Read(){
        cin >> x >> y >> owner >> unitType >> health;
    }
};

void turn(int numSites){
    int gold;
    int touchedSite; // -1 if none
    cin >> gold >> touchedSite; cin.ignore();
    for (int i = 0; i < numSites; i++) {
        int siteId;
        int ignore1; // used in future leagues
        int ignore2; // used in future leagues
        int structureType; // -1 = No structure, 2 = Barracks
        int owner; // -1 = No structure, 0 = Friendly, 1 = Enemy
        int param1;
        int param2;
        cin >> siteId >> ignore1 >> ignore2 >> structureType >> owner >> param1 >> param2; cin.ignore();
    }
    int id = touchedSite;
    int numUnits;
    int enemy = 0,s2 = 0;
    cin >> numUnits; cin.ignore();
    for (int i = 0; i < numUnits; i++) {
        int x;
        int y;
        int owner;
        int unitType; // -1 = QUEEN, 0 = KNIGHT, 1 = ARCHER
        int health;
        cin >> x >> y >> owner >> unitType >> health; cin.ignore();
        enemy = unitType;
        s2 = owner;
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    // First line: A valid queen action
    // Second line: A set of training instructions
    
    //int n = rand() % 2;
    if(enemy != 0 && id != -1 && s2 != 1) cout << "BUILD "<< id << " BARRACKS-KNIGHT\n"  << "TRAIN " << id << endl;
    else if(id != -1) cout << "BUILD "<< id << " BARRACKS-ARCHER\n"  << "TRAIN " << id << endl;
    else cout << "BUILD "<< 3 << " BARRACKS-KNIGHT\n"  << "TRAIN " << 3 << endl;
}

int main()
{
    int numSites;
    cin >> numSites; cin.ignore();
    
    for (int i = 0; i < numSites; i++) {
        int siteId;
        int x;
        int y;
        int radius;
        cin >> siteId >> x >> y >> radius; cin.ignore();
    }

    // game loop
    int id = 0;
    while (1) {
        turn(numSites);
    }
}