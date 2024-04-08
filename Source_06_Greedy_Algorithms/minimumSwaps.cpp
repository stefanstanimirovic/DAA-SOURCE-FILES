#include <string>
using namespace std;

int minSwaps(string s) {
    int openBrackets = 0; 
    int swaps = 0;        

    for (char& c : s) {
        if (c == '[') {
            openBrackets++;
        }
        else if (openBrackets > 0) {
            openBrackets--;
        }
    }

    swaps = (openBrackets + 1) / 2;

    return swaps;
}