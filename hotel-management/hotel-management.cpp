#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class User {
private:
    string fullName;
    string passportSeries;
    string login;
    string password;
    int age;

public:
    User(string _name, string _passportSeries, string _login, string _password, int _age)
        : fullName(_name), passportSeries(_passportSeries), login(_login), password(_password), age(_age) { }

    string getFullName() const { return fullName; }
    string getPassportSeries() const { return passportSeries; }
    string getLogin() const { return login; }
    string getPassword() const { return password; }
    int getaAge() const { return age; }

    bool operator == (const User& other) const {
        return fullName == other.fullName &&
            passportSeries == other.passportSeries &&
            login == other.login &&
            password == other.password &&
            age == other.age;
    }
};

class Room
{
private:
    int roomId;
    int amountOfParts;
    int priceOfRoom;
    int rentedDays;
    vector<User> users;

public:
    Room(int _roomId, int _amountOfParts, int _priceOfRoom, int _rentedDays)
        : roomId(_roomId), amountOfParts(_amountOfParts), priceOfRoom(_priceOfRoom), rentedDays(_rentedDays) { }

    /*int getRoomId() const { return roomId; }
    int getAmountOfParts() const { return amountOfParts; }
    int getPriceOfRoom() const { return priceOfRoom; }
    int getRentedDays() const { return rentedDays; }*/

    /*bool operator == (const Room& other) const {
        return roomId == other.roomId &&
            amountOfParts == other.amountOfParts &&
            priceOfRoom == other.priceOfRoom &&
            rentedDays == other.rentedDays;
    }*/


    void addUser(const User& user) {
        users.push_back(user);
    }

    void deleteUser(const User& user) {
        auto it = find(users.begin(), users.end(), user);

        if (it != users.end()) {
            users.erase(it);
            cout << "\nUser deleted successfully.\n\n" << endl;
        }
        else {
            cout << "\nUser not found!\n\n" << endl;
        }
    }

    bool findUser(const string& fullName) {
        for (const auto& user : users) {
            if (user.getFullName() == fullName) {
                cout << "\n\nFull Name: " << user.getFullName() <<
                    ", Passport Series: " << user.getPassportSeries() <<
                    ", Login: " << user.getLogin() <<
                    ", Password: " << user.getPassword() <<
                    ", Age: " << user.getaAge() << endl;
                return true;
            }
        }

        return false;
    }

    vector<User> getAllUsers() const {
        return users;
    }

    void saveUserToFile(const string& fileName) const {
        ofstream outFile(fileName);
        if (outFile.is_open()) {
            for (const auto& user : users) {
                outFile << user.getFullName() << ","
                    << user.getPassportSeries() << ","
                    << user.getLogin() << ","
                    << user.getPassword() << ","
                    << user.getaAge() << endl;
            }

            outFile.close();
            cout << "\nUser Data saved to file successfully!\n\n" << endl;
        }
        else {
            cout << "\nUnable to open file to save user data!\n\n" << endl;
        }
    }
};


int main()
{
    cout << "Welcome to the Grand Horizon Hotel! We're delighted to have you with us!\n\n";
    
    Room room(3, 4, 15, 7);

    int choice;
    do {
        cout << "1. Add User" << endl;
        cout << "2. Delete User" << endl;
        cout << "3. Find User" << endl;
        cout << "4. View All Users" << endl;
        cout << "5. Save User Data" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter one of the options: ";
        cin >> choice;

        switch (choice) {
            case 1: 
            {
                string fullName, passportSeries, login, password;
                int age;

                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, fullName);

                cout << "Enter passport series: ";
                cin.ignore();
                getline(cin, passportSeries);

                cout << "Enter Login: ";
                cin.ignore();
                getline(cin, login);

                cout << "Enter Password: ";
                cin.ignore();
                getline(cin, password);

                cout << "Enter Age: ";
                cin >> age;

                User newUser(fullName, passportSeries, login, password, age);
                room.addUser(newUser);
                break;
            }
            case 2:
            {
                string fullName, passportSeries, login, password;
                int age;

                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, fullName);

                cout << "Enter passport series: ";
                cin.ignore();
                getline(cin, passportSeries);

                cout << "Enter Login: ";
                cin.ignore();
                getline(cin, login);

                cout << "Enter Password: ";
                cin.ignore();
                getline(cin, password);

                cout << "Enter Age: ";
                cin >> age;

                User deleteUser(fullName, passportSeries, login, password, age);
                room.deleteUser(deleteUser);
                break;
            }
            case 3:
            {
                string fullName;
                
                cout << "Enter Full Name: ";
                cin.ignore();
                getline(cin, fullName);

                if (!room.findUser(fullName));
                {
                    cout << "\nUser not found\n\n" << endl;
                }

                break;
            }
            case 4: {
                cout << "\nAll Users:\n" << endl;
                vector<User> allUsers = room.getAllUsers();

                for (const auto& user : allUsers) {
                    cout << "Name: " << user.getFullName() <<
                        ", Passpport Series: " << user.getPassportSeries() <<
                        ", Login: " << user.getLogin() <<
                        ", Password: " << user.getPassword() <<
                        ", Age: " << user.getaAge() << endl << endl;
                }

                break;
            }
            case 5:
            {
                room.saveUserToFile("hotel_users.txt");
                break;
            }
            case 6:
            {
                cout << "\nExiting...." << endl;
                break;
            }
            default:
                cout << "\nInvalid choice! Please enter a valid option.\n" << endl;
                break;
        }

    } while (choice != 6);


    return 0;
}