#include <cstring>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

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
           << "Я пойду с тобой и мы попробуем остаться в живых." << endl;
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
    cout << "=================================================================="
            "==============";
    cout << endl << endl;
    cout << "Ну что ж, тогда - прощайте!\n"
         << "Надеюсь смерть вашего товарища не сильно вас огорчит." << endl;
  }
}
