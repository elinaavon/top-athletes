/* Title:               Top Athletes Program
   Name:                Elina Ivanova
   Course:              CSCI 240
   Instructor:          Professor Gunnett
   Due date:            12/1/2023
   Input:               Athletes' names, number of wins, and number of losses
   Output:              Average winning percentage of all athletes, each athlete's name, wins, losses, and winning percentage.
 */

// This program reads data from players.txt input file and calculates average winning percentage for all athletes and the winning percentage for each athlete.
// Then the results of the calculations are printed to standard output displaying a report showing the average percentage for all athletes, each athlete's name, wins, losses, and percentage (if it is above average percentage).

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int TOP_ATHLETES = 500;

// Declaring a structure to store athlete data
struct Athlete {
    string name;
    int wins;
    int losses;
    double percentage;
};


// Declaring functions 
int readScores(Athlete athletes[]);
double calculateWinningPercentage(int wins, int losses);
double calculateAverageWinningPercentage(const Athlete athletes[], int count);


int main()
{
    Athlete athletes[TOP_ATHLETES];

    int count = readScores(athletes);

    double averageWinningPercentage = calculateAverageWinningPercentage(athletes, count);

    // Outputing the average winning percentage
    cout << fixed << setprecision(2);
    cout << "Average Percentage: " << averageWinningPercentage << "%" << endl;
    cout << endl;


    // Outputing the chart header
    cout << left << setw(15) << "Athlete Name" << setw(7) << "Wins" << setw(7) << "Loss" << setw(15) << "Percentage" << endl;
    cout << "=======================================" << endl;

    // Outputing athlete data for those whose winnig percentage is above average
    for (int i = 0; i < count; i++) {
        if (athletes[i].percentage > averageWinningPercentage) {
            cout << left << setw(15) << athletes[i].name << right << setw(2) << athletes[i].wins << setw(8) << athletes[i].losses << right << setw(11) << athletes[i].percentage << "%" << endl;
        }
    }
    return 0;
}

// Defining a function that reads athlete's wins and losses from the input file
int readScores(Athlete athletes[]) {
    ifstream inFile("players.txt"); // Opening the input file

    int count = 0;

    while (count < TOP_ATHLETES && inFile >> athletes[count].name >> athletes[count].wins >> athletes[count].losses) {
        athletes[count].percentage = calculateWinningPercentage(athletes[count].wins, athletes[count].losses);
        count++;
    }

    inFile.close();

    return count;
}

// Defining a function that calculates a winning percentage for each athlete
double calculateWinningPercentage(int wins, int losses) {
    int totalGames = wins + losses;
    if (totalGames == 0) {
        return 0.0;
    }
    return static_cast<double>(wins) / totalGames * 100.0;
}

// Defining a function that calculates an average winning percentage for all athletes
double calculateAverageWinningPercentage(const Athlete athletes[], int count) {
    double totalPercentage = 0.0;
    for (int i = 0; i < count; i++) {
        totalPercentage += athletes[i].percentage;
    }
    if (count == 0) {
        return 0.0;
    }
    else {
        return totalPercentage / count;
    }
}


