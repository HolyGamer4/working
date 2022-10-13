#include <iostream>
#include <vector>
using namespace std;

const vector <string> months = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", \
                             "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
const vector <int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leap_year(int cur_year) {
    return (cur_year % 400 == 0 || (cur_year % 4 == 0 && cur_year % 100 != 0));
}

int amount_of_days(int cur_month, int cur_year) {
    return (cur_month != 2 ? days[cur_month - 1] : (leap_year(cur_year) ? 29 : 28));
}

// int start_day()

int main()
{
    cout << amount_of_days(3, 1900);
    return 0;
}