#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Train {
public:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    int seatsAvailable;
    Train(int trainNumber, string trainName, string source, string destination, int seatsAvailable) {
        this->trainNumber = trainNumber;
        this->trainName = trainName;
        this->source = source;
        this->destination = destination;
        this->seatsAvailable = seatsAvailable;
    }
};
class Ticket {
public:
    int ticketId;
    string passengerName;
    int trainNumber;
    Ticket(int ticketId, string passengerName, int trainNumber) {
        this->ticketId = ticketId;
        this->passengerName = passengerName;
        this->trainNumber = trainNumber;
    }
};

vector<Train> trains;
vector<Ticket> tickets;
int ticketCounter = 1;
void addTrain(int trainNumber, string trainName, string source, string destination, int seatsAvailable) {
    Train newTrain(trainNumber, trainName, source, destination, seatsAvailable);
    trains.push_back(newTrain);
    cout << "Train added successfully!" << endl;
}
void bookTicket(string passengerName, int trainNumber) {
    for (auto& train : trains) {
        if (train.trainNumber == trainNumber) {
            if (train.seatsAvailable > 0) {
                Ticket newTicket(ticketCounter++, passengerName, trainNumber);
                tickets.push_back(newTicket);
                train.seatsAvailable--;
                cout << "Ticket booked successfully! Ticket ID: " << newTicket.ticketId << endl;
                return;
            } else {
                cout << "No seats available on this train." << endl;
                return;
            }
        }
    }
    cout << "Train not found." << endl;
}
void viewBookedTickets() {
    if (tickets.empty()) {
        cout << "No tickets booked." << endl;
        return;
    }
    for (const auto& ticket : tickets) {
        cout << "Ticket ID: " << ticket.ticketId << ", Passenger Name: " << ticket.passengerName << ", Train Number: " << ticket.trainNumber << endl;
    }
}
int main() {
    int choice;
    while (true) {
        cout << "\n1. Add Train\n2. Book Ticket\n3. View Booked Tickets\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int trainNumber, seatsAvailable;
                string trainName, source, destination;
                cout << "Enter Train Number: ";
                cin >> trainNumber;
                cout << "Enter Train Name: ";
               cin.ignore();
                getline(cin, trainName);
                cout << "Enter Source: ";
                getline(cin, source);
                cout << "Enter Destination: ";
                getline(cin, destination);
                cout << "Enter Seats Available: ";
                cin >> seatsAvailable;
                addTrain(trainNumber, trainName, source, destination, seatsAvailable);
                break;
            }
            case 2: {
                string passengerName;
                int trainNumber;
                cout << "Enter Passenger Name: ";
                cin.ignore();
                getline(cin, passengerName);
                cout << "Enter Train Number: ";
                cin >> trainNumber;
                bookTicket(passengerName, trainNumber);
                break;
            }
            case 3:
                viewBookedTickets();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
