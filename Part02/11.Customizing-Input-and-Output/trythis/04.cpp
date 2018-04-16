/*
  Make a simple table including the last name, first name, telephone number, and
  email address for yourself and at least five of your friends. Experiment with
  different field widths until you are sastified that the table is well presented.
*/
#include "../std_lib_facilities.h"

int main()
{

  cout << "Last name\tFirst Name\tTelephone number\tEmail Address\n";
  cout << "Felix" << setw(10) << "\tDerick" << setw(20) << "\t202-555-0112" << setw(30) << "\temail@example.com\n";
  cout << "Wayne" << setw(10) << "\tJill" << setw(20) << "\t202-555-0191" << setw(25) << "\texample@mail.com\n";
  cout << "Brennan" << setw(10) << "\tJanis" << setw(20) << "\t202-555-0199" << setw(20) << "\tumane@zome.com\n";
  cout << "Alannis" << setw(10) << "\tMerry" << setw(20) << "\t202-555-0140" << setw(30) << "\tleptoac@coldmail.com\n";
  cout << "Grahame" << setw(10) << "\tHailie" << setw(20) << "\t202-555-0177" << setw(30) << "\tuser28527@bmail.com\n";
  cout << "Claire" << setw(10) << "\tCole" << setw(20) << "\t202-555-0142" << setw(30) << "\tuser37826@bmail.com\n";
  
  return 0;
}
