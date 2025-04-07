#include <iostream>
#include <queue>
#include <string>

using namespace std;


struct Patient {
    string name;
    int emergencyLevel;

    Patient(string n, int e) : name(n), emergencyLevel(e) {}
};


struct ComparePriority {
    bool operator()(const Patient& a, const Patient& b) {
        return a.emergencyLevel < b.emergencyLevel;
    }
};

void displayQueue(priority_queue<Patient, vector<Patient>, ComparePriority> pq) {
    cout << "\nCurrent Treatment Order:\n";
    int order = 1;
    while (!pq.empty()) {
        Patient p = pq.top();
        pq.pop();
        cout << order++ << ". " << p.name << " (Emergency Level: " << p.emergencyLevel << ")\n";
    }
    cout << endl;
}

int main() {
    priority_queue<Patient, vector<Patient>, ComparePriority> patientQueue;
    int choice;

    do {
        cout << "\n--- Patient Treatment System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name;
            int emergency;

            cout << "Enter patient name: ";
            getline(cin, name);
            cout << "Enter emergency level (1 - Low, 5 - Critical): ";
            cin >> emergency;

            patientQueue.push(Patient(name, emergency));

            displayQueue(patientQueue);
        }
        else if (choice != 2) {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 2);

    cout << "Exiting the system. Stay safe!\n";
    return 0;
}
