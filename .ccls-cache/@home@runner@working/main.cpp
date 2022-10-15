#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const vector<string> months = {"Январь",   "Февраль", "Март",   "Апрель",
                               "Май",      "Июнь",    "Июль",   "Август",
                               "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
const vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leap_year(int cur_year) {
  return (cur_year % 400 == 0 || (cur_year % 4 == 0 && cur_year % 100 != 0));
}

int amount_of_days(int cur_month, int cur_year) {
  return (cur_month != 2 ? days[cur_month - 1]
                         : (leap_year(cur_year) ? 29 : 28));
}
struct box {
  int month1;
  int year1;
  int day1;
};

void obr() {
  int cur_month, cur_year;
  cout << "Введите номер месяца: ";
  cin >> cur_month;
  while (cur_month < 1 || cur_month > 12) {
    cout << "Неверно введён месяц. Введите номер месяца от 1 до 12, где \n 1 - "
            "январь \n 12 - декабрь"
         << endl;
    cin >> cur_month;
  }
  cout << "Введите номер года от 1919 до 2029: ";
  cin >> cur_year;
  while (cur_year < 1919 || cur_year > 2029) {
    cout << "Неверно введён год. Введите число с 1919 до 2029: ";
    cin >> cur_year;
  }
  amount_of_days(cur_month, cur_year);
}

const vector<box> tested_set = {{2, 2004, 29}, {4, 2005, 30}, {}};

void test() {
  for (auto test_set : tested_set)
    assert(amount_of_days(test_set.month1, test_set.year1) == test_set.day1);
  cout << "Тесты пройдены" << endl;
}

// int start_day()

int main() {
  test();
  obr(); // проблема: в фцнкции удаляются полученные значения cur_month и
         // cur_year
  cout << amount_of_days(3, 1900);
  return 0;
}