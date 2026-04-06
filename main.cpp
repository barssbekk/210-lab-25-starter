#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;
using namespace chrono;

long inputVector(const vector<string>& data);

int main() {
    string filename{"codes.txt"};

    ifstream fileInput{"codes.txt"};
    if (!fileInput) {
        cerr << "File not found\n";
        return 1;
    }

    vector<string> data{};
    string line{};
    while (getline(fileInput, line)) {
        data.push_back(line);
    }

    return 0;
}

// read
long inputVector(const vector<string>& data) {
    auto start{high_resolution_clock::now()};
    vector<string> vec{data.begin(), data.end()};
    auto end{high_resolution_clock::now()};
    return duration_cast<nanoseconds>(end - start).count();
}



/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/