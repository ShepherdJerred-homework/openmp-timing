#include <iostream>
#include <omp.h>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ratio;
using std::chrono::time_point;
using std::chrono::duration;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

struct Input {
    int x;
    int sizeOfVector;
    vector<double> a;
    vector<double> b;
};

Input getInput() {
    int x;
    int sizeOfVector;
    vector<double> a;
    vector<double> b;

    cin >> sizeOfVector;

    a.reserve(static_cast<unsigned long>(sizeOfVector));
    b.reserve(static_cast<unsigned long>(sizeOfVector));

    int n;
    for (int i = 0; i < sizeOfVector; i++) {
        cin >> n;
        a.push_back(n);
    }

    for (int i = 0; i < sizeOfVector; i++) {
        cin >> n;
        b.push_back(n);
    }

    cin >> x;

    Input input = {
            x,
            sizeOfVector,
            a,
            b
    };

    return input;
}

vector<double> calc(Input input) {
    vector<double> results;
    results.resize(static_cast<unsigned long>(input.sizeOfVector));

#pragma omp parallel for
    for (int i = 0; i < input.sizeOfVector; i++) {
        results[i] = (input.a[i] * input.x) + input.b[i];
    }

    return results;
}

void printResults(vector<double> results) {
    for (double &result : results) {
        cout << result << " ";
    }
    cout << endl;
}

int main() {
//    omp_set_num_threads(64);
    
    Input input = getInput();

    time_point startTime = high_resolution_clock::now();
    vector<double> results = calc(input);
    time_point endTime = high_resolution_clock::now();

    duration time_taken = duration_cast<nanoseconds>(endTime - startTime);

//    printResults(results);
    cerr << "Time taken: " << time_taken.count() << "ns" << endl;
}
