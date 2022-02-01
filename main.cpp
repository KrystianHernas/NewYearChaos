#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

std::vector<int> inputArray();
std::string minimumBribes(std::vector<int>& q);
void swap(int*, int*);

int main()
{
    int t;
    std::cout << "Input number of test cases: " << std::endl; std::cin >> t; std::vector<std::string> bribes;
    for (int i = 0; i < t; i++) {
        std::vector<int> inputVector = inputArray(); 
        bribes.push_back(minimumBribes(inputVector));
        inputVector.clear();
    }
    for (int i = 0; i < t; i++) {
        std::cout << bribes[i] << std::endl;
    }
    return 0;
}

std::vector<int> inputArray() {
    int n = 0, temp = 0; std::vector<int> q;
    std::cout << "Input queue size: " << std::endl; std::cin >> n;
    std::cout << "Input queue integers" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> temp; q.push_back(temp);
    }
    temp = q.size();
    try {
        if (temp < 1 || temp > 100000|| std::cin.fail()) {
            throw std::invalid_argument("Too large queue");
        }
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    return q;
};

std::string minimumBribes(std::vector<int>& q) {
    int i,j, numberOfBribes = 0;
    for (i = (q.size() - 1); i >= 0;i--) {
        if ((q[i] - (i + 1)) > 2) {
            return "Too chaotic"; break;
        }
        if (q[i] - 2 > 0) { 
            j = q[i] - 2; 
        }
        else j = 0;
        for (j ; j < i; j++) {
            if (q[j] > q[i]) {
                numberOfBribes++;
            }
        }
    }  
    return std::to_string(numberOfBribes);
}
// ALTERNATIVE FOR HACKERRANK NEEDS
//void minimumBribes(vector<int> q) {
//    int i, j, numberOfBribes = 0; bool sw = true;
//    for (i = (q.size() - 1); i >= 0; i--) {
//        if ((q[i] - (i + 1)) > 2) {
//            cout << "Too chaotic" << endl; sw = false; break;
//        }if (q[i] - 2 > 0) {
//            j = q[i] - 2;
//        }
//        else j = 0;
//        for (j; j < i; j++) {
//            if (q[j] > q[i]) {
//                numberOfBribes++;
//            }
//        }
//    }
//    if (sw) cout << std::to_string(numberOfBribes) << endl;
//}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}