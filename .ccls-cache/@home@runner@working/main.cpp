#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct box {
  int month1;
  int year1;
  int day1;
};

struct box2 {
  int day2;
  int month2;
  int year2;
  int pos;
};

const vector<box> tested_set = {{2, 2004, 29}, {4, 2005, 30}};
const vector<box2> tested_set2 = {
    {2, 5, 2004, 7},  {4, 6, 2006, 7},  {18, 9, 1996, 3}, {21, 12, 2013, 6},
    {19, 4, 2027, 1}, {29, 2, 1996, 4}, {29, 2, 2012, 3}, {28, 2, 2011, 1},
    {28, 2, 1919, 5}, {28, 2, 2029, 3}};

const vector<string> months = {"ЯНВАРЬ",   "ФЕВРАЛЬ", "МАРТ",   "АПРЕЛЬ",
                               "МАЙ",      "ИЮНЬ",    "ИЮЛЬ",   "АВГУСТ",
                               "СЕНТЯБРЬ", "ОКТЯБРЬ", "НОЯБРЬ", "ДЕКАБРЬ"};
const vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int shifts[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

int leap_year(int cur_year) {
  return (cur_year % 400 == 0 || (cur_year % 4 == 0 && cur_year % 100 != 0));
}

int amount_of_days(int cur_month, int cur_year) {
  return (cur_month != 2 ? days[cur_month - 1]
                         : (leap_year(cur_year) ? 29 : 28));
}

int day_position_in_week(int c_day, int month, int year) {
  int shift = shifts[month - 1];
  (leap_year(year) && month > 2) ? shift += 1 : shift;
  year = (year - 1) % 400;
  int century = year / 100;
  int index = ((4 * century) + (year % 100)) % 28;
  int weekday = (index + (index / 4)) + shift + (c_day - 1);
  return (weekday % 7) + 1;
}

void grid_output(int month, int year) {
  cout << months[month - 1] << " " << year << endl;
  cout << "  ПН ВТ СР ЧТ ПТ СБ ВС" << endl;
  cout << "  ";
  int days_n = amount_of_days(month, year);
  for (int count = 1, start = 1; count <= days_n; count++, start++) {
    while (day_position_in_week(1, month, year) > start) {
      cout << "   ";
      start++;
    }
    cout << ((count < 10) ? " " : "");
    cout << count << " ";
    if (day_position_in_week(count, month, year) % 7 == 0)
      cout << "\n  ";
  }
}

void obr() {
  int cur_month, cur_year;
  cout << "Введите номер месяца: ";
  cin >> cur_month;
  while (cur_month < 1 || cur_month > 12) {
    cout << "Неверно введён месяц. Введите номер месяца от 1 до 12, где 1 - "
            "январь, 12 - декабрь: ";
    cin >> cur_month;
  }
  cout << "Введите номер года от 1919 до 2029: ";
  cin >> cur_year;
  while (cur_year < 1919 || cur_year > 2029) {
    cout << "Неверно введён год. Введите число с 1919 до 2029: ";
    cin >> cur_year;
  }
  grid_output(cur_month, cur_year);
}

void test() {
  for (auto test_set : tested_set)
    assert(amount_of_days(test_set.month1, test_set.year1) == test_set.day1);
  cout << "Тесты пройдены" << endl;
}
void test2() {
  for (auto test_set : tested_set2)
    assert(day_position_in_week(test_set.day2, test_set.month2,
                                test_set.year2) == test_set.pos);
  cout << "Тесты 2 пройдены" << endl;
}

int main() {
  test();
  test2();
  obr();
  return 0;
}