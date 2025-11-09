#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Member {
private:
    string name, game, gender, membershipType, contact, guardian, address, timeSlot, date;
    int age;
    double fee;
    static int count;        // total members count
    static double totalIncome; // total income of the day

public:
    Member() {
        name = game = gender = membershipType = contact = guardian = address = timeSlot = date = "";
        age = 0;
        fee = 0.0;
    }
    void inputData() {
        cout << "\n===== ENTER MEMBER DETAILS =====\n";
        cin.ignore();
        cout << "Enter Member Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Gender (Male/Female/Other): ";
        getline(cin, gender);
        cout << "Enter Game / Attraction: ";
        getline(cin, game);
        cout << "Enter Membership Type: ";
        getline(cin, membershipType);
        cout << "Enter Fee (₹): ";
        cin >> fee;
        cin.ignore();
        cout << "Enter Contact No.: ";
        getline(cin, contact);
        cout << "Enter Guardian / Parent Name: ";
        getline(cin, guardian);
        cout << "Enter Date of Visit (DD-MM-YYYY): ";
        getline(cin, date);
        cout << "Enter Time Slot (e.g. 11:00 AM - 2:00 PM): ";
        getline(cin, timeSlot);
        cout << "Enter Address: ";
        getline(cin, address);

        count++;             // count increment
        totalIncome += fee;  // income add
    }
    void displayData() const {
        cout << "\n=============================================\n";
        cout << "        🏰  FUN KINGDOM - VISIT SLIP 🏰       \n";
        cout << "=============================================\n";
        cout << left << setw(20) << "Member Name:" << name << endl;
        cout << left << setw(20) << "Age:" << age << " years" << endl;
        cout << left << setw(20) << "Gender:" << gender << endl;
        cout << left << setw(20) << "Game:" << game << endl;
        cout << left << setw(20) << "Membership:" << membershipType << endl;
        cout << left << setw(20) << "Fee (₹):" << fixed << setprecision(2) << fee << endl;
        cout << left << setw(20) << "Contact No.:" << contact << endl;
        cout << left << setw(20) << "Guardian:" << guardian << endl;
        cout << left << setw(20) << "Date of Visit:" << date << endl;
        cout << left << setw(20) << "Time Slot:" << timeSlot << endl;
        cout << left << setw(20) << "Address:" << address << endl;
        cout << "---------------------------------------------\n";
        cout << "Rules:\n";
        cout << "1) Please wear seat belt on rides.\n";
        cout << "2) Kids must be accompanied by guardians.\n";
        cout << "3) Management reserves all rights.\n";
        cout << "---------------------------------------------\n";
        cout << "Issued By: Fun Kingdom Reception\n";
        cout << "Signature: ______________________\n";
        cout << "=============================================\n";
        cout << "🎉  THANK YOU FOR VISITING FUN KINGDOM! 🎉\n";
        cout << "=============================================\n";
    }
    void saveToFile() const {
        ofstream fout("fun_kingdom_records.txt", ios::app);
        fout << "---------------------------------------------\n";
        fout << "Name: " << name << endl;
        fout << "Age: " << age << endl;
        fout << "Gender: " << gender << endl;
        fout << "Game: " << game << endl;
        fout << "Membership: " << membershipType << endl;
        fout << "Fee: " << fee << endl;
        fout << "Contact: " << contact << endl;
        fout << "Guardian: " << guardian << endl;
        fout << "Date: " << date << endl;
        fout << "Time Slot: " << timeSlot << endl;
        fout << "Address: " << address << endl;
        fout << "---------------------------------------------\n";
        fout.close();
    }
    static int getCount() {
        return count;
    }

    static double getTotalIncome() {
        return totalIncome;
    }
    ~Member() {}
};
int Member::count = 0;
double Member::totalIncome = 0.0;

int main() {
    vector<Member> members;
    int choice;

    do {
        cout << "\n=============================================\n";
        cout << "       🎡 FUN KINGDOM MEMBER SYSTEM 🎡        \n";
        cout << "=============================================\n";
        cout << "1. Add New Member\n";
        cout << "2. Display All Members\n";
        cout << "3. Show Total Members\n";
        cout << "4. Show Total Income of the Day\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Member m;
            m.inputData();
            m.displayData();
            m.saveToFile();
            members.push_back(m);
            break;
        }
        case 2: {
            if (members.empty()) {
                cout << "\nNo members added yet.\n";
            } else {
                for (size_t i = 0; i < members.size(); ++i) {
                    cout << "\n--- Member " << i + 1 << " ---";
                    members[i].displayData();
                }
            }
            break;
        }
        case 3:
            cout << "\nTotal Members Registered: " << Member::getCount() << endl;
            break;
        case 4:
            cout << fixed << setprecision(2);
            cout << "\n💰 Total Income of the Day: ₹" << Member::getTotalIncome() << endl;
            break;
        case 5:
            cout << "\nThank you for using Fun Kingdom System! 😊\n";
            break;
        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
