#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class IceCreamPreferences {
private:
    unordered_set<string> vanilla;
    unordered_set<string> butterscotch;
    vector<string> universal;

public:
    void addVanillaStudent(const string &name) {
        vanilla.insert(name);
    }

    void addButterscotchStudent(const string &name) {
        butterscotch.insert(name);
    }

    void addUniversalStudent(const string &name) {
        universal.push_back(name);
    }

    void displaySet(const unordered_set<string> &s) {
        for (const string &name : s) {
            cout << name << " ";
        }
        cout << endl;
    }

    void displayVector(const vector<string> &v) {
        for (const string &name : v) {
            cout << name << " ";
        }
        cout << endl;
    }

    void computeAndDisplayResults() {
        unordered_set<string> both;
        unordered_set<string> either;
        vector<string> neither;

        for (const string &name : vanilla) {
            if (butterscotch.find(name) != butterscotch.end()) {
                both.insert(name);
            }
        }

        either = vanilla;
        for (const string &name : butterscotch) {
            either.insert(name);
        }

        for (const string &name : universal) {
            if (vanilla.find(name) == vanilla.end() && butterscotch.find(name) == butterscotch.end()) {
                neither.push_back(name);
            }
        }

        cout << "Students who like both Vanilla and Butterscotch: ";
        displaySet(both);

        cout << "Students who like either Vanilla or Butterscotch or both: ";
        displaySet(either);

        cout << "Number of students who like neither Vanilla nor Butterscotch: " << neither.size() << endl;
        cout << "Students who like neither: ";
        displayVector(neither);
    }
};

int main() {
    IceCreamPreferences preferences;
    int n;

    cout << "Enter number of students in the class: ";
    cin >> n;
    cout << "Enter names of all students: \n";
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        preferences.addUniversalStudent(name);
    }


    int v;
    cout << "Enter number of students who like Vanilla: ";
    cin >> v;
    cout << "Enter names of students who like Vanilla: \n";
    for (int i = 0; i < v; i++) {
        string name;
        cin >> name;
        preferences.addVanillaStudent(name);
    }

 
    int b;
    cout << "Enter number of students who like Butterscotch: ";
    cin >> b;
    cout << "Enter names of students who like Butterscotch: \n";
    for (int i = 0; i < b; i++) {
        string name;
        cin >> name;
        preferences.addButterscotchStudent(name);
    }


    preferences.computeAndDisplayResults();

    return 0;
}
