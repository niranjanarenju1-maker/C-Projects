
#include <iostream>
using namespace std;

// Function to read student marks
void readMarks(int marks[], int n)
{
    cout << "\nEnter the marks of " << n << " students:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];

        while (marks[i] < 0 || marks[i] > 100)
        {
            cout << "Invalid marks! Enter marks between 0 and 100: ";
            cin >> marks[i];
        }
    }
}

// Function to calculate total marks
int calculateTotal(int marks[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total += marks[i];
    }

    return total;
}

// Function to find highest mark
int findHighest(int marks[], int n)
{
    int highest = marks[0];

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > highest)
        {
            highest = marks[i];
        }
    }

    return highest;
}

// Function to find lowest mark
int findLowest(int marks[], int n)
{
    int lowest = marks[0];

    for (int i = 1; i < n; i++)
    {
        if (marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }

    return lowest;
}

// Function to count passed students
int countPassed(int marks[], int n)
{
    int passed = 0;

    for (int i = 0; i < n; i++)
    {
        if (marks[i] >= 40)
        {
            passed++;
        }
    }

    return passed;
}

// Function to count failed students
int countFailed(int marks[], int n)
{
    int failed = 0;

    for (int i = 0; i < n; i++)
    {
        if (marks[i] < 40)
        {
            failed++;
        }
    }

    return failed;
}

// Function to display the analysis
void displayResults(int marks[], int n)
{
    int total = calculateTotal(marks, n);
    double average = (double)total / n;

    cout << "\n========== STUDENT MARKS REPORT ==========\n";

    cout << "\nStudent Marks:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": "
             << marks[i] << endl;
    }

    cout << "\nTotal Marks: " << total;
    cout << "\nAverage Marks: " << average;
    cout << "\nHighest Mark: " << findHighest(marks, n);
    cout << "\nLowest Mark: " << findLowest(marks, n);
    cout << "\nPassed Students: " << countPassed(marks, n);
    cout << "\nFailed Students: " << countFailed(marks, n);

    cout << "\n==========================================\n";
}

// Main function
int main()
{
    int n;
    char choice;

    do
    {
        cout << "\n===== STUDENT MARKS ANALYZER =====\n";

        cout << "Enter the number of students (1-100): ";
        cin >> n;

        while (n < 1 || n > 100)
        {
            cout << "Invalid count! Enter a number between 1 and 100: ";
            cin >> n;
        }

        int marks[100];

        readMarks(marks, n);

        displayResults(marks, n);

        cout << "\nDo you want to analyze again? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "\nThank you for using Student Marks Analyzer!\n";

    return 0;
}
