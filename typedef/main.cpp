#include <climits>
#include <iostream>
#include <ostream>
#include "typedefs.h"

using namespace std;

int main() {
  int score;
  double distance;
  char playAgain;
  bool shieldsUp;
  short lives, aliensKilled;

  score = 0;
  distance = 4700.50;
  playAgain = 'y';
  shieldsUp = true;
  lives = 3;
  aliensKilled = 10;

  cout << endl;
  cout << "score:\t\t" << score << endl;
  cout << "distance:\t" << distance << endl;
  cout << "playAgain:\t" << playAgain << endl;
  cout << "shieldsUp:\t" << shieldsUp << endl;
  cout << "lives:\t\t" << lives << endl;

  double engineTemp = 7200.10;
  cout << "engineTemp:\t" << engineTemp << endl;

  int fuel;
  cout << endl << "How much fuel? ";
  cin >> fuel;
  cout << "fuel: " << fuel << endl;

  cout << endl << "IMPORTANT PART! DEFINITION OF THE UNSIGNED SHORT TYPE!" << endl;
  ushort bonus = 10;
  cout << "bonus: " << bonus << endl;
  ushort bonusOverMaxUshort = 100000; // NOLINT
  cout << "!!!cutted ushort bonusOverMaxUshort = 100000: " << bonusOverMaxUshort << "!!!" << endl;
  ushort bonusMaxUshort = 65535; // NOLINT
  cout << "not cutted ushort bonusMaxUshort = 65535: " << bonusMaxUshort << endl;
  return 0;
}
