#include <cstring>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

struct dices {
  int arr[3];
};

struct dices dices() {
  struct dices dcs;
  dcs.arr[0] = random()%(6 - 1 + 1) + 1;
  dcs.arr[1] = random()%(6 - 1 + 1) + 1;
  dcs.arr[2] = random()%(6 - 1 + 1) + 1;
  return dcs;
}

int main(int, char **) {
  system("clear");
  cout << "Приветствую, путники! Вы действительно хотите войти в это "
          "подземелье?\t"
       << "y/n" << endl;
  char wantEntire;
  int noCnt = 0;
  bool endAdventure = false;
  while (noCnt < 3) {
    if ('y' == wantEntire) {
      cout << "Не буду вас отговаривать.\n"
           << "Я видел как ваш товарищ спустился туда в поисках подземного "
              "источника воды.\n"
           << "Я пойду с вами и мы попробуем остаться в живых." << endl;
      break;
    } else if ('n' == wantEntire) {
      noCnt++;
      if (noCnt >= 3) {
        endAdventure = true;
        break;
      }
      int lastCnt = 3 - noCnt;
      ostringstream question;
      if (lastCnt <= 1) {
        question << "Спрашиваю последний раз:";
      } else {
        question << "Я спрошу ещё только " << lastCnt << " раз:";
      }
      cout << question.str() << endl;
      cout << "А вы разве не ищете своего товарища?\nЯ видел как он спустился "
              "туда в поисках подземного источника воды."
           << endl;
    }
    cin >> wantEntire;
    if (wantEntire != 'y' && wantEntire != 'n') {
      cout << "Я понимаю только y/n";
      continue;
    }
  }
  if (endAdventure) {
    cout << "========================================"
         << "========================================";
    cout << endl << endl;
    cout << "Ну что ж, тогда - прощайте!\n"
         << "Надеюсь смерть вашего товарища не сильно вас огорчит." << endl;
  }
  struct dices d = dices();
  for (int i = 0; i < 3; i++) {
      cout << d.arr[i] << endl;
  }
}
