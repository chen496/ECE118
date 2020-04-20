#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <cctype>
#include <fstream>
#include <sstream>
#include <math.h>


using namespace std;

struct date{
   int year, month, day;
};

struct person{
  string first_name, last_name;
  date date_of_birth;
  string state;
  int SSN;
  double balance;
};

void readdata(string filename, person database[]) {
  ifstream fin;
  fin.open(filename.c_str());
  if (fin.fail()) {
    cout << "cant open file \n";
  }
  string first_name, last_name;
  int year, month, day;
  string state;
  int SSN;
  double balance;
  int i = 0;
  string line;
  while (getline(fin, line)) {
    istringstream iss(line);
    iss >> first_name >> last_name >> year >> month >> day >> state >> SSN >> balance;
    date date_of_birth = {year, month, day};
    person t = {first_name, last_name, date_of_birth, state, SSN, balance};
    database[i] = t;
    i = i + 1;
  }
  fin.close();
}

void niceprint(person data) {
   cout << data.first_name << "," << data.last_name << " " << data.date_of_birth.year << " " << data.date_of_birth.month << " " << data.date_of_birth.day << " " << data.SSN << " " << data.balance << "\n";
}

bool equalChar(char &c1, char &c2) {
  if (c1 == c2) {
    return true;
  } else if (toupper(c1) == toupper(c2)) {
    return true;
  } else {
    return false;
  }
}

bool equalString(string &s1, string &s2) {
  return (s1.size() == s2.size() ) &&
			 std::equal(s1.begin(), s1.end(), s2.begin(), &equalChar);
}

bool search(string name, person database[]) {
  bool found = false;
  for (int i = 0; i < 1000; i++) {
    // case sensitive compare
    if (database[i].first_name == name || database[i].last_name == name) {
        niceprint(database[i]);
        found = true;
    }
  }
  return found;
}

bool search2(string name, person database[]) {
  bool found = false;
  for (int i = 0; i < 1000; i++) {
    // case sensitive compare
    if (equalString(database[i].first_name, name) || equalString(database[i].last_name, name)) {
        niceprint(database[i]);
        found = true;
    }
  }
  return found;
}


int main() {
  person db[1000];
  string filename = "data1.txt";
  readdata(filename, db);
  string name;
  cout << "Enter a name to search :";
  cin >> name;
  int sensitive;
  cout << "Sensitive search or not : (sensitive = 1, nonsensitive = 0) : ";
  cin >> sensitive;
  if (sensitive == 1) {
    search(name, db);
  } else {
    search2(name, db);
  }
}






