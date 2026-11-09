
#include <iostream>
using namespace std;

// Function to enter marks
void readMarks(int marks[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter marks of student " << i + 1 << ": ";
        cin >> marks[i];
    }
}

// Function to display results
void displayResults(int marks[], int n)
{
    int total = 0;
    int highest = marks[0];
    int lowest = marks[0];
    int passed = 0;
    int failed = 0;

    for (int i = 0; i < n; i++)
    {
        total = total + marks[i];

        if (marks[i] > highest)
            highest = marks[i];

        if (marks[i] < lowest)
            lowest = marks[i];

        if (marks[i] >= 45)
            passed++;
        else
            failed++;
    }

    double average = (double)total / n;

    cout << "\n===== STUDENT MARKS REPORT =====\n";
    cout << "Total Marks: " << total << endl;
    cout << "Average Marks: " << average << endl;
    cout << "Highest Marks: " << highest << endl;
    cout << "Lowest Marks: " << lowest << endl;
    cout << "Passed Students: " << passed << endl;
    cout << "Failed Students: " << failed << endl;
}

int main()
{
    int n;
    char choice;

    do
    {
        cout << "\nEnter number of students (1-100): ";
        cin >> n;

        while (n < 1 || n > 100)
        {
            cout << "Invalid count! Enter again: ";
            cin >> n;
        }

        int marks[100];

        readMarks(marks, n);
        displayResults(marks, n);

        cout << "\nDo you want to continue? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "\nThank you!\n";

    return 0;
}
