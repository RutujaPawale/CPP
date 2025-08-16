#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Declare a map to store state names as keys and populations as values
    map<string, int> statePopulation;

    // Add some state-population data to the map
    statePopulation["Maharashtra"] = 39558223;
    statePopulation["Gujarat"] = 10935505;
    statePopulation["Delhi"] = 21381807;
    statePopulation["Orissa"] = 20217249;
    statePopulation["Kerala"] = 24021078;

    cout << "Find State Population\n";
    cout << "Type the name of a state to get its population, or type 'exit' to quit.\n";

    string state;
    while (true) {
        cout << "\nEnter state name: ";
        getline(cin, state);

        // Check if the user wants to exit
        if (state == "exit") {
            cout << "Exiting the program.\n";
            break;
        }

        // Search for the state in the map
        auto it = statePopulation.find(state);
        if (it != statePopulation.end()) {
            // If found, display the population
            cout << "The population of " << state << " is " << it->second << ".\n";
        }
        else {
            // If not found, display an error message
            cout << "State not found in the database. Please try again.\n";
        }
    }

    return 0;
}
