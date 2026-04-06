#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
using namespace chrono;

const int NUM_RUNS{100};

long inputVector(const vector<string>& data);
long inputList(const vector<string>& data);
long inputSet(const vector<string>& data);

long sortVector(vector<string> data);
long sortList(list<string> data);
// no need std::sort for set, set alr sorted

long insertVector(vector<string> data);
long insertSet(set<string> data);

long deleteVector(vector<string> data);

int main() {
    string filename{"codes.txt"};

    ifstream fileInput{"codes.txt"};
    if (!fileInput) { // check if file opens
        cerr << "File not found\n";
        return 1;
    }

    vector<string> data{};
    string line{};
    while (getline(fileInput, line)) {
        data.push_back(line);
    }

    cout << "Loaded lines: " << data.size() << '\n';
    long vecRead {inputVector(data)};
    long listRead {inputList(data)};
    long setRead {inputSet(data)};

    cout << "READ TEST\n";
    cout << "Vector:\t" << vecRead  << " ms\n";
    cout << "List:\t"   << listRead << " ms\n";
    cout << "Set:\t"    << setRead  << " ms\n";

    return 0;
}

// READ
long inputVector(const vector<string>& data) {
    auto start{high_resolution_clock::now()};

    for (int i{0}; i < NUM_RUNS; ++i)
        vector<string> vec{data.begin(), data.end()};

    auto end{high_resolution_clock::now()};
    return duration_cast<milliseconds>(end - start).count();
}

long inputList(const vector<string>& data) {
    auto start{high_resolution_clock::now()};

    for (int i{0}; i < NUM_RUNS; ++i)
        list<string> myList{data.begin(), data.end()};

    auto end{high_resolution_clock::now()};
    return duration_cast<milliseconds>(end - start).count();
}

long inputSet(const vector<string>& data) {
    auto start{high_resolution_clock::now()};

    for (int i{0}; i < NUM_RUNS; ++i)
        set<string> st{data.begin(), data.end()};

    auto end{high_resolution_clock::now()};
    return duration_cast<milliseconds>(end - start).count();
}

// SORT
// sort vec
long sortVector(vector<string> data) {
    auto start{high_resolution_clock::now()};

    for (int i{0}; i < NUM_RUNS; ++i) {
        vector<string> temp{data};
        sort(temp.begin(), temp.end());
    }

    auto end{high_resolution_clock::now()};
    return duration_cast<milliseconds>(end - start).count();
}

// sort list
long sortList(list<string> data) {
    auto start{high_resolution_clock::now()};

    for (int i{0}; i < NUM_RUNS; ++i) {
        list<string> temp{data};
        temp.sort();
    }

    auto end{high_resolution_clock::now()};
    return duration_cast<milliseconds>(end - start).count();
}

// INSERT
// insert vec
long insertVector(vector<string> data) {
    auto start{high_resolution_clock::now()};

    for (int i{0}; i < NUM_RUNS; ++i) {
        vector<string> temp{data};
        temp.insert(temp.begin() + temp.size() / 2, "TESTCODE");
    }

    auto end{high_resolution_clock::now()};
    return duration_cast<milliseconds>(end - start).count();
}

// TODO: add insert list
long insertList(list<string> data) {
    auto start{high_resolution_clock::now()};

    for (int i{0}; i < NUM_RUNS; ++i) {
        list<string> temp{data};

        auto it = temp.begin(); // iterator
        int mid = temp.size() / 2;

        for (int j{0}; j < mid; ++j) { // half
            ++it;
        }

        temp.insert(it, "TESTCODE");
    }

    auto end{high_resolution_clock::now()};
    return duration_cast<milliseconds>(end - start).count();
}

// insert set
long insertSet(set<string> data) {
    auto start{high_resolution_clock::now()};

    for (int i{0}; i < NUM_RUNS; ++i) {
        set<string> temp{data};
        temp.insert("TESTCODE");
    }

    auto end{high_resolution_clock::now()};
    return duration_cast<milliseconds>(end - start).count();
}

// delete
// delete vec
long deleteVector(vector<string> data) {
    auto start{high_resolution_clock::now()};

    for (int i{0}; i < NUM_RUNS; ++i) {
        vector<string> temp{data};
        temp.erase(temp.begin() + temp.size()/2);
    }

    auto end{high_resolution_clock::now()};
    return duration_cast<milliseconds>(end - start).count();
}

// TODO: delete list

// delete set
long deleteSet(set<string> data) {
    auto start{high_resolution_clock::now()};

    for (int i{0}; i < NUM_RUNS; ++i) {
        set<string> temp{data};
        temp.insert("TESTCODE");
        temp.erase("TESTCODE");
    }
    auto end{high_resolution_clock::now()};
    return duration_cast<milliseconds>(end - start).count();
}



/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/