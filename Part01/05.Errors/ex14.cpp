/* Read (day-of-the-week, value) pairs from standard input. For example:
 *   Tuesday 23 Friday 56 Tuesday -3 Thursday 99
 * Collect all the values for each day of the week in a vector<int>. Write out
 * the values of the seven day-of-the-week vectors. Print out the sum of the 
 * values in each vector. Ignore illegal days of the week, such as Funday, but
 * accept common synonyms such as Mon and monday. Write out the number of rejected
 * values.
 */
#include "../std_lib_facilities.h"

int sum(vector<int> values)
{
    int sum = 0;
    for (int v : values)
        sum += v;
    return sum;
}

int main()
{
    vector<int> mondays;
    vector<int> tuesdays;
    vector<int> wednesdays;
    vector<int> thursdays;
    vector<int> fridays;
    vector<int> saturdays;
    vector<int> sundays;
    int rejected_values = 0;

    string day_of_the_week = "";
    int value = 0;
    cout << "Write 'day-of-the-week, value' pairs, type 'noday 0' to stop. For example: \n";
    cout << "\tTuesday 23 Friday 56 Tuesday -3 Thursday 99 noday 0\n";
    while (true) {
        cin >> day_of_the_week >> value;
        if (day_of_the_week == "Monday" || day_of_the_week == "monday" 
            || day_of_the_week == "Mon" || day_of_the_week == "mon") mondays.push_back(value);
        else if (day_of_the_week == "Tuesday" || day_of_the_week == "tuesday"
            || day_of_the_week == "Tue" || day_of_the_week == "tue") tuesdays.push_back(value);
        else if (day_of_the_week == "Wednesday" || day_of_the_week == "wednesday"
            || day_of_the_week == "Wed" || day_of_the_week == "wed") wednesdays.push_back(value);
        else if (day_of_the_week == "Thursday" || day_of_the_week == "thursday"
            || day_of_the_week == "Thu" || day_of_the_week == "thu") thursdays.push_back(value);
        else if (day_of_the_week == "Friday" || day_of_the_week == "friday"
            || day_of_the_week == "Fri" || day_of_the_week == "fri") fridays.push_back(value);
        else if (day_of_the_week == "Saturday" || day_of_the_week == "saturday"
            || day_of_the_week == "Sat" || day_of_the_week == "sat") saturdays.push_back(value);
        else if (day_of_the_week == "Sunday" || day_of_the_week == "sunday"
            || day_of_the_week == "Sun" || day_of_the_week == "sun") sundays.push_back(value);
        else
            ++rejected_values;
        
        if (day_of_the_week == "noday" && value == 0) break;
    }

    cout << "Monday: " << sum(mondays) << endl;
    cout << "Tuesday: " << sum(tuesdays) << endl;
    cout << "Wednesday: " << sum(wednesdays) << endl;
    cout << "Thursday: " << sum(thursdays) << endl;
    cout << "Friday: " << sum(fridays) << endl;
    cout << "Saturday: " << sum(saturdays) << endl;
    cout << "Sunday: " << sum(sundays) << endl;
    cout << "Rejected values: " << rejected_values << endl;

    return 0;
}