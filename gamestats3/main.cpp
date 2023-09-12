#include "typedefs.h"
#include <climits>
#include <iostream>
#include <iterator>

using namespace std;

int main(int, char **) {
  const int ALIEN_POINTS = 150;
  int aliensKilled = 10;
  int score = aliensKilled * ALIEN_POINTS;
  cout << endl
       << "score = aliensKilled * ALIEN_POINTS: "
       << score
       << endl
       << endl;

  enum diffuculty { NOVICE, EASY, NORMAL, HARD, UNBEATABLE };
  diffuculty myDifficulty = EASY;
  enum shipCost { FIGHTER_COST = 25, BOMBER_COST, CRUISER_COST = 50 };
  cout << "FIGHTER_COST: " << FIGHTER_COST << endl;
  cout << "BOMBER_COST: " << BOMBER_COST << endl;
  cout << "CRUISER_COST: " << CRUISER_COST << endl << endl;
  shipCost myShipCost = BOMBER_COST;
  cout << "To upgrade my ship to a Cruiser will cost "
       << (CRUISER_COST - myShipCost) << " Resource Points." << endl;

  return 0;
}
