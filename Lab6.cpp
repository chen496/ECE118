// hint 
#include "library.h"

int length_of_month(int year, int month)
{ if (month == 1)
    return 31;
  if (month == 2 && year%400 == 0)
    return 29;
  if (month == 2 && year%100 != 0 && year%4 == 0)
    return 29;
  if (month == 2)
    return 28;
  if (month == 3)
    return 31;
  if (month == 4)
    return 30;
  if (month == 5)
    return 31;
  if (month == 6)
    return 30;
  if (month == 7)
    return 31;
  if (month == 8)
    return 31;
  if (month == 9)
    return 30;
  if (month == 10)
    return 31;
  if (month == 11)
    return 30;
  if (month == 12)
    return 31; }

int day_of_the_year(int year, int month, int day)
{ if (month == 1)
    return day;
  return day_of_the_year(year, month - 1, length_of_month(year, month - 1) + day); 
} 
