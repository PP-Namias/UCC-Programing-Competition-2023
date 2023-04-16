#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int numSections;
    cout << "Enter number of sections: ";
    cin >> numSections;

    int sectionSizes[numSections];
    int* sectionScores[numSections];

    for (int i = 0; i < numSections; i++)
    {
        int numStudents;
        cout << "Enter number of students in section " << i+1 << ": ";
        cin >> numStudents;
        sectionSizes[i] = numStudents;

        sectionScores[i] = new int[numStudents];

        for (int j = 0; j < numStudents; j++)
        {
            cout << "Enter exam score of student number " << j+1 << " in section " << i+1 << ": ";
            cin >> sectionScores[i][j];
        }
    }

    // Compute averages
    double sectionAverages[numSections];
    double totalAverage = 0.0;
    int numStudentsTotal = 0;

    for (int i = 0; i < numSections; i++)
    {
        double sum = 0.0;
        for (int j = 0; j < sectionSizes[i]; j++)
        {
            sum += sectionScores[i][j];
        }
        sectionAverages[i] = sum / sectionSizes[i];
        totalAverage += sum;
        numStudentsTotal += sectionSizes[i];
    }

    totalAverage /= numStudentsTotal;

    // Compute highest and lowest scores
    int highestScore = -1;
    int lowestScore = 101;

    for (int i = 0; i < numSections; i++)
    {
        for (int j = 0; j < sectionSizes[i]; j++)
        {
            highestScore = max(highestScore, sectionScores[i][j]);
            lowestScore = min(lowestScore, sectionScores[i][j]);
        }
    }

    // Compute mode
    int allScores[numStudentsTotal];
    int index = 0;
    for (int i = 0; i < numSections; i++)
    {
        for (int j = 0; j < sectionSizes[i]; j++)
        {
            allScores[index++] = sectionScores[i][j];
        }
    }

    int modes[101] = {0};
    int maxCount = 1;
    int count = 1;
    int currentMode = allScores[0];

    for (int i = 1; i < numStudentsTotal; i++)
    {
        if (allScores[i] == allScores[i-1])
        {
            count++;
        }
        else
        {
            if (count > maxCount)
            {
                for (int j = 0; j < 101; j++)
                {
                    modes[j] = 0;
                }
                modes[currentMode] = 1;
                maxCount = count;
            }
            else if (count == maxCount)
            {
                modes[currentMode] = 1;
            }
            currentMode = allScores[i];
            count = 1;
        }
    }

    if (count > maxCount)
    {
        for (int j = 0; j < 101; j++)
        {
            modes[j] = 0;
        }
        modes[currentMode] = 1;
        maxCount = count;
    }
    else if (count == maxCount)
    {
        modes[currentMode] = 1;
    }

    // Compute median
    int allScoresSorted[numStudentsTotal];
    index = 0;
        
    for (int i = 0; i < numSections; i++)
    {
        for (int j = 0; j < sectionSizes[i]; j++)
        {
            allScoresSorted[index++] = sectionScores[i][j];
        }
    }

    for (int i = 0; i < numStudentsTotal-1; i++)
    {
        for (int j = i+1; j < numStudentsTotal; j++)
        {
            if (allScoresSorted[i] > allScoresSorted[j])
            {
                int temp = allScoresSorted[i];
                allScoresSorted[i] = allScoresSorted[j];
                allScoresSorted[j] = temp;
            }
        }
    }

    double median = 0.0;
    if (numStudentsTotal % 2 == 0)
    {
        median = (allScoresSorted[numStudentsTotal/2-1] + allScoresSorted[numStudentsTotal/2]) / 2.0;
    }
    else
    {
        median = allScoresSorted[numStudentsTotal/2];
    }

    // Output results
    for (int i = 0; i < numSections; i++)
    {
        cout << "Average score in section " << i+1 << ": " << fixed << setprecision(2) << sectionAverages[i] << endl;
    }

    cout << "Average score in all section: " << fixed << setprecision(2) << totalAverage << endl;

    cout << "Highest score in section 1: " << highestScore << endl;
    for (int i = 1; i < numSections; i++)
    {
        int currentMax = -1;
        for (int j = 0; j < sectionSizes[i]; j++)
        {
            currentMax = max(currentMax, sectionScores[i][j]);
        }
        cout << "Highest score in section " << i+1 << ": " << currentMax << endl;
    }
    cout << "Highest score in all section: " << highestScore << endl;

    cout << "Lowest score in section 1: " << lowestScore << endl;
    for (int i = 1; i < numSections; i++)
    {
        int currentMin = 101;
        for (int j = 0; j < sectionSizes[i]; j++)
        {
            currentMin = min(currentMin, sectionScores[i][j]);
        }
        cout << "Lowest score in section " << i+1 << ": " << currentMin << endl;
    }
    cout << "Lowest score in all section: " << lowestScore << endl;

    cout << "Mode: ";
    for (int i = 0; i < 101; i++)
    {
        if (modes[i] == 1)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "Median: " << fixed << setprecision(2) << median << endl;

    // Deallocate memory
    for (int i = 0; i < numSections; i++)
    {
        delete[] sectionScores[i];
    }

    return 0;
}