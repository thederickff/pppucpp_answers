/**
* Write a program that prompts the user to enter some number of pennie, nickels
* dimes, quarters, half-dollars, and one dollar. Query the user separately for
* for the numbers  of each coin. If only one of a coin is reported, make the output
* grammatically correct. Also, report the sum in dollars and cents.
*/
#include "../std_lib_facilities.h"

int main()
{
  double pennie, nickel, dime, quarter, half_dollar, dollar;
  double total;

  // Get data
  cout << "Enter with some pennies: " << endl;
  cin >> pennie;
  cout << "Enter with some nickels: " << endl;
  cin >> nickel;
  cout << "Enter with some dimes: " << endl;
  cin >> dime;
  cout << "Enter with some quarters: " << endl;
  cin >> quarter;
  cout << "Enter with some half dollars: " << endl;
  cin >> half_dollar;
  cout << "Enter with some dollars: " << endl;
  cin >> dollar;

  // If only one of a coin is reported, make the output grammatically correct.
  if (pennie < 2)
    cout << "You have " << pennie << " pennie." << endl;
  else
    cout << "You have " << pennie << " pennies." << endl;

  if (nickel < 2)
    cout << "You have " << nickel << " nickel." << endl;
  else
    cout << "You have " << nickel << " nickels." << endl;

  if (dime < 2)
    cout << "You have " << dime << " dime." << endl;
  else
    cout << "You have " << dime << " dimes." << endl;

  if (quarter < 2)
    cout << "You have " << quarter << " quarter." << endl;
  else
    cout << "You have " << quarter << " quarters." << endl;

  if (half_dollar < 2)
    cout << "You have " << half_dollar << " half dollar." << endl;
  else
    cout << "You have " << half_dollar << " half dollars." << endl;

  if (dollar < 2)
    cout << "You have " << dollar << " dollar." << endl;
  else
    cout << "You have " << dollar << " dollars." << endl;


  // Report the sum in dollars and cents.
  total += pennie *  0.01;
  total += nickel * 0.05;
  total += dime * 0.10;
  total += quarter * 0.25;
  total += half_dollar * 0.50;
  total += dollar * 1;

  cout << "The value of all of your coins is $" << total << endl;
  return 0;
}
