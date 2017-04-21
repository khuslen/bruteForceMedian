#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>
#include <ctime>

#include "testFunctions.h"

using namespace std;

ofstream myfile;

const int NUM_TESTS = 10; // per input size
const int INPUT_SIZE = 50000; // 1 to 50000

int basicOpsAverage = 0;
int result;

int BruteForceMedian(vector<int> inputVector, int option);
void performTestCases();
void getAverageCaseBasicOps();
void getAverageCaseExecTime();

int main()
{
    int option;

    cout << "Select an option" << endl;
    cout << "1. Perform test cases." << endl;
    cout << "2. Generate average-case number of basic operations results." << endl;
    cout << "3. Generate average-case execution results." << endl;
    cout << "Enter option: ";
    cin >> option;

    switch (option) {
    case 1:
        performTestCases();
        break;
    case 2:
        getAverageCaseBasicOps();
        break;
    case 3:
        getAverageCaseExecTime();
        break;
    default:
        cout << "Invalid option!" << endl;
        break;
    }
    return 0;
}

int BruteForceMedian(vector<int> inputVector, int option) {
    int n = inputVector.size(); // number of elements in the input vector
    int k = ceil(n/2.0);

    if (option == 1) {
        cout << "n: " << n << endl;
        cout << "k: " << k << endl;
    }

    int numsmaller, numequal;
    int basicOps = 0;

    for (int i = 0; i < n; i++) {
        numsmaller = 0; // number of elements smaller than inputArray[i]
        numequal = 0; // number of elements equal to inputArray[i]
        for (int j = 0; j < n; j++) {
            basicOps++;
            if (inputVector[j] < inputVector[i]) {
                numsmaller++;
            } else if (inputVector[j] == inputVector[i]) {
                numequal++;
            }
        }
        if (numsmaller < k && k <= (numsmaller + numequal)) {
            if (option == 1) cout << "Median: " << inputVector[i] << endl;
            basicOpsAverage += basicOps;
            return inputVector[i];
        }
    }
    return -1;
}

void performTestCases() {
    cout << "Performing Functional Testing" << endl;
    for (int i = 1; i <= 6; i++) {
        vector <int> inputVector = getTestCase(i);
        result = BruteForceMedian(inputVector, 1);
    }
}

void getAverageCaseBasicOps() {
    cout << "Generating Average-Case Number of Basic Operations Performed Data" << endl;
    cout << "Beginning 10 test cases for input sizes from 1 to " << INPUT_SIZE << "..." << endl;

    myfile.open ("resultsBasicOps.csv");
    myfile << "Input size, Average number of basic operations" << endl;

    for (int i = 1; i <= INPUT_SIZE; i += 500) {
        for (int j = 0; j < NUM_TESTS; j++) {
            vector <int> inputVector = getInput(i);
            result = BruteForceMedian(inputVector, 2);
        }
        basicOpsAverage = basicOpsAverage / NUM_TESTS;
        myfile << i << "," << basicOpsAverage << endl;
        basicOpsAverage = 0;
    }
    myfile.close();
    cout << "Result saved to resultsBasicOps.csv file" << endl;
}

void getAverageCaseExecTime() {
    cout << "Generating Average-Case Execution Time Data" << endl;
    double execTime;
    double execTimeAverage = 0;

    myfile.open ("resultsExecTime.csv");
    myfile << "Input size, Average number of basic operations" << endl;
    cout << "Beginning 10 test cases for input sizes from 1 " << INPUT_SIZE << "..." << endl;
    for (int i = 1; i <= INPUT_SIZE; i += 500) {
        for (int j = 0; j < NUM_TESTS; j++) {
            cout << "Input size: " << i << " Test number: " << j;
            vector <int> inputVector = getInput(i);
            const clock_t begin_time = clock();
            result = BruteForceMedian(inputVector, 3);
            const clock_t end_time = clock();
            execTime = (float(end_time) - float(begin_time))/1000000.0F;
            cout << " execTime: " << execTime << endl;
            execTimeAverage += execTime;
        }
        cout << " execTimeTotal: " << execTimeAverage << endl;
        execTimeAverage = execTimeAverage / NUM_TESTS;
        myfile << i << "," << execTimeAverage << endl;
        execTimeAverage = 0;
    }
    myfile.close();
    cout << "Result saved to resultsExecTime.csv file" << endl;

}
