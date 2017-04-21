#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

bool addedInt[100];

int getRandomNumber(int lower, int higher) {
    return (rand() % (higher - lower + 1) + lower);
}

vector<int> getInput(int inputSize) {
    int inputArray[inputSize];
    //int* inputArray = new int[inputSize];
    for (int i = 0; i < inputSize; i++) {
        inputArray[i] = getRandomNumber(-500, 500);
    }
    vector<int> inputVector(inputArray, inputArray + sizeof(inputArray)/sizeof(int));
    return inputVector;
}

vector<int> getTestCase(int testNum) {
    switch (testNum) {
        case 1: {// Even, random
            cout << "Test Case 1" << endl;
            int inputArray[] = {1, 6, 4, 9, 0, 12, 56, 3};
            cout << "Array values: ";
            for (int k = 0; k < sizeof(inputArray)/sizeof(int); k++) {
                cout << inputArray[k] << " ";
            }
            cout << endl;
            vector<int> inputVector(inputArray, inputArray + sizeof(inputArray)/sizeof(int));
            return inputVector;
        }
			break;
        case 2: { // Odd, random
            cout << "Test Case 2" << endl;
            int inputArray2[] = {5, 8, 2, 3, 0, 11, 4, 29, 7};
            cout << "Array values: ";
            for (int k = 0; k < sizeof(inputArray2)/sizeof(int); k++) {
                cout << inputArray2[k] << " ";
            }
            cout << endl;
            vector<int> inputVector2(inputArray2, inputArray2 + sizeof(inputArray2)/sizeof(int));
            return inputVector2;
        }
			break;
        case 3: {// Sorted
            cout << "Test Case 3" << endl;
            int inputArray3[] = {23, 30, 47, 55, 69, 70, 81, 99};
            cout << "Array values: ";
            for (int k = 0; k < sizeof(inputArray3)/sizeof(int); k++) {
                cout << inputArray3[k] << " ";
            }
            cout << endl;
            vector<int> inputVector3(inputArray3, inputArray3 + sizeof(inputArray3)/sizeof(int));
            return inputVector3;
        }
			break;
		case 4: {// Reverse order
		    cout << "Test Case 4" << endl;
            int inputArray4[] = {123, 93, 87, 75, 60, 33, 12, 2, 1};
            cout << "Array values: ";
            for (int k = 0; k < sizeof(inputArray4)/sizeof(int); k++) {
                cout << inputArray4[k] << " ";
            }
            cout << endl;
            vector<int> inputVector4(inputArray4, inputArray4 + sizeof(inputArray4)/sizeof(int));
            return inputVector4;
        }
			break;
		case 5: {// Contains negative values
		    cout << "Test Case 5" << endl;
            int inputArray5[] = {-1, 6, 4, 0, 8, -3, 2, 5};
            cout << "Array values: ";
            for (int k = 0; k < sizeof(inputArray5)/sizeof(int); k++) {
                cout << inputArray5[k] << " ";
            }
            cout << endl;
            vector<int> inputVector5(inputArray5, inputArray5 + sizeof(inputArray5)/sizeof(int));
            return inputVector5;
        }
			break;
		case 6: {// Contains duplicates
		    cout << "Test Case 6" << endl;
            int inputArray6[] = {50, 4, 2, 3, 1, 9, 10, 2, 3};
            cout << "Array values: ";
            for (int k = 0; k < sizeof(inputArray6)/sizeof(int); k++) {
                cout << inputArray6[k] << " ";
            }
            cout << endl;
            vector<int> inputVector6(inputArray6, inputArray6 + sizeof(inputArray6)/sizeof(int));
            return inputVector6;
        }
			break;
		default:
			int inputArray7[] = {0};
			cout << "----- Invalid size input! -----" << endl;
			vector<int> inputVector7(inputArray7, inputArray7 + sizeof(inputArray7)/sizeof(int));
            return inputVector7;
			break;
    }
}
