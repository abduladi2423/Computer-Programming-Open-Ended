#include <iostream>
using namespace std;
const int size1 = 5;
const int size2 = 7;
const int size3 = size1 + size2;

int array1[size1];
int array2[size2];
int array3[size3];

void merge() {
    for (int i = 0; i < size1; i++) {
        array3[i] = array1[i];
    }

    for (int i = 0; i < size2; i++) {
        array3[size1 + i] = array2[i];
    }

    for (int i = 0; i < size3; i++) {
        for (int j = 0; j < size3 - 1 - i; j++) {
            if (array3[j] > array3[j + 1]) {
                int swap = array3[j];
                array3[j] = array3[j + 1];
                array3[j + 1] = swap;
            }
        }
    }
}

void findCommonElements() {
    cout << "Common Elements: ";

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (array1[i] == array2[j]) {
                cout << array1[i] << "\t";
                array2[j] = INT_MIN;
                break;
            }
        }
    }

    cout << endl;
}

bool isPalindrome(char str[], int length) {
    int start = 0;
    int end = length - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int main() {
    using namespace std;  // Use the namespace only where needed

    cout << "Array 1 :" << endl;
    for (int i = 0; i < size1; i++) {
        cin >> array1[i];
    }

    cout << "Array 2 :" << endl;
    for (int i = 0; i < size2; i++) {
        cin >> array2[i];
    }

    merge();

    cout << "The Arrays In Ascending order are as follows :" << endl;
    for (int i = 0; i < size3; i++) {
        cout << array3[i] << "\t";
    }

    cout << "\n\nThe Common Elements in the arrays are :\n";
    findCommonElements();

    char inputString[100];
    cout << "\n\nEnter a sentence:\n";
    cin.ignore();  // Ignore newline character left in the buffer
    cin.getline(inputString, 100);

    int length = strlen(inputString);
    if (isPalindrome(inputString, length)) {
        cout << "The input sentence is a palindrome.\n";
    }
    else {
        cout << "The input sentence is not a palindrome.\n";
    }

    return 0;
}
