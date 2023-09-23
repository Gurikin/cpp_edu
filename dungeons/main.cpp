#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <decimal/decimal>
#include <iostream>
#include <limits>
#include <ostream>
#include <sstream>
#include <string>
#include <thread>

using namespace std;
using namespace decimal;

void printText(string text, int timeToSleep = 15) {
  for (string::iterator it = text.begin(); it != text.end(); ++it) {
    cout << *it << flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(timeToSleep));
  }
  cout << endl;
}

struct Dices {
  int arr[3];
};

struct Dices dices() {
  srand((unsigned)time(0));
  struct Dices dcs;
  dcs.arr[0] = 1 + rand() % 6;
  dcs.arr[1] = 1 + rand() % 6;
  dcs.arr[2] = 1 + rand() % 6;
  return dcs;
}

int takePersonsBeforeDown() {
  system("clear");
  printText("Уже довольно темно. Подскажи, сколько вас всего?");
  int persons = 0;
  while (persons <= 0) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> persons;
    if (cin.fail()) {
      printText(
          "Чегоооо?!\nКхмхмх. Скажи ещё раз, пожалуйста. Я не расслышал.");
    }
  }
  return persons;
}

void waitEnter() {
  printText("<Нажми [Пробел], затем [Enter]...>", 20);
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  while (getchar() != ' ') {
    printText("Не можем продолжить без пробела.");
  }
  system("clear");
}

void goDown() {
  printText("Спускаемся?");
  waitEnter();
}

void endGame() {
  printText("Игра окончена!");
  waitEnter();
}

int calcPersonGroups(int persons) {
  return (persons / 3) < 1 ? 1 : persons / 3;
}

float calcPersonModificator(int persons, int dice) {
  float personModificator = 1.0f;
  int personGroups = calcPersonGroups(persons);
  bool greaterThan3 = personGroups > 1;
  if (greaterThan3) {
    personModificator *= 1.5;
  }
  bool luckGreaterThanGroups = (persons / 3) < dice;
  if (!luckGreaterThanGroups) {
    personModificator /= 1.15;
  }
  return personModificator * (static_cast<float>(dice) / personGroups) *
         (static_cast<float>(personGroups) / 6 * dice);
}

string darknessText(int darkness) {
  switch (darkness) {
  case 1:
  case 2:
    return "Тма хоть глаз выколи. ААЙ!!! Кто здесь?! Дайте огня - "
           " не вижу ничего!";
  case 3:
  case 4:
    return "Местами брезжет свет. Это не может не радовать как и небольшой "
           "глоток воздуха.";
  case 5:
  default:
    return "Светло как днем. Странно, если учесть, что мы под землей.";
  };
}

int diceToIntRange(int dice) {
  switch (dice) {
  case 1:
  case 2:
    return 3;
  case 3:
  case 4:
    return 2;
  case 5:
  default:
    return 1;
  };
}

int calcPassedPersons(int persons, int personsModificatorDice, int enemies,
                      int darkness) {
  float personModificator =
      calcPersonModificator(persons, personsModificatorDice);
  int personGroups = calcPersonGroups(persons);
  float personsToEnemy =
      personModificator * persons / (enemies * 3 * diceToIntRange(darkness));
  long personsDied = 0;
  if (personsToEnemy < 3) {
    personsDied = static_cast<int>(lround((3 - personsToEnemy) / 3 * persons));
  }
  return (persons - personsDied);
}

int dungeonAction(int persons, int personsModificatorDice, int enemies,
                  int darkness) {
  system("clear");
  ostringstream text;
  text << "Итак: нас " << persons << " человек." << endl;
  text << darknessText(darkness) << endl;
  text << "В этой пещере слышны шорохи нескольких существ. Похоже их всего "
       << diceToIntRange(enemies);
  printText(text.str());
  waitEnter();
  text.str("");
  text.clear();
  text << "Они идут! Доставайте оружие!";
  printText(text.str(), 50);
  waitEnter();
  text.str("");
  text.clear();
  text << "Получай!!! Я ранен!!! В строй!!! Встать в строй группами!!!";
  printText(text.str(), 5);
  waitEnter();
  int passedPersons = calcPassedPersons(persons, personsModificatorDice,
                                        diceToIntRange(enemies), darkness);
  text.str("");
  text.clear();
  if (passedPersons > 0) {
    text << "Всё закончилось. Нас осталось " << passedPersons;
    printText(text.str());
    return passedPersons;
  } else {
    text << "Ну вот. Все путники мертвы. Мои питомцы сыты. Пойду наверх ждать "
            "других простачков.";
    printText(text.str());
    endGame();
    return 0;
  }
}

int main(int, char **) {
  system("clear");
  printText("Приветствую, путники! Вы действительно хотите войти в это "
            "подземелье?\t[y/n]");
  char wantEntire;
  int noCnt = 0;
  bool endAdventure = false;
  while (noCnt < 3) {
    if ('y' == wantEntire) {
      system("clear");
      printText("Не буду вас отговаривать.\n"
                "Я видел как ваш товарищ спустился туда в поисках подземного "
                "источника воды.\n"
                "Я пойду с вами и мы попробуем остаться в живых.");
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
        question << "Я спрошу ещё только " << lastCnt << " раза:";
      }
      system("clear");
      printText(question.str());
      printText("А вы разве не ищете своего товарища?\n"
                "Я видел как он спустился туда в поисках подземного источника "
                "воды.[y/n]");
    }
    cin >> wantEntire;
    if (wantEntire != 'y' && wantEntire != 'n') {
      printText("Я понимаю только [y/n]");
      continue;
    }
  }
  if (endAdventure) {
    system("clear");
    printText("Ну что ж, тогда - прощайте!\n"
              "Надеюсь смерть вашего товарища не сильно вас огорчит.");
    endGame();
    return 0;
  }
  goDown();
  int personsNum = takePersonsBeforeDown();
  printText("Ну пойдем.");

  int dungeonActionResult = personsNum;
  while (dungeonActionResult != 0) {
    waitEnter();
    printText("Кидаем кубики...", 30);
    struct Dices d = dices();
    for (int i = 0; i < 3; i++) {
      printText(to_string(d.arr[i]), 200);
    }
    d = dices();
    dungeonActionResult =
        dungeonAction(dungeonActionResult, d.arr[0], d.arr[1], d.arr[2]);
    if (dungeonActionResult != 0) {
      goDown();
    }
  }
  return 0;
}
