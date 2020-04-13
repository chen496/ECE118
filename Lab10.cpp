#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

double Round2(double val) {
  return floor(val * 100 + 0.5) / 100;
}

int main() {
  string file = "items.txt";
  ifstream fin(file.c_str());
  ofstream fout("receipt.txt");
  string line;
  string name;
  double quantity, ppu;
  double discount;
  char taxornot;
  double price_discount;
  double total_price;
  double tax;
  if (!fin) {
    cout << "warning: cant open file " << file << "\n";
  }
  if (!fout) {
    cout << "error opening receipt.txt\n";
  }
  string customer;
  cout << "customer needed" << "\n";
  cin >> customer;
  string cfile, ofile;
  cfile = customer + "_items.txt";
  ofile = customer + "_receipts.txt";
  cout << "InputFile = " << cfile << endl;
  cout << "OutputFile = " << ofile << endl;
  while(getline(fin, line)) {
    istringstream iss(line);
    iss >> name >> quantity >> ppu >> discount >> taxornot; 
    cout << "product name : " << name << endl;
    fout << name << " " <<  quantity << " " << ppu << " " << discount << " " << taxornot << " ";
    total_price = ppu * quantity;
    price_discount = total_price * (1.0 - discount / 100.0);
    if (taxornot == 'Y') {
      tax = price_discount * 0.07;
    } else {
      tax = 0.0;
    }
    fout << Round2(total_price) << " " << Round2(price_discount) << " " << Round2(tax) << " " << Round2(price_discount - tax) << endl;
  }
}
