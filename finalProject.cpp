//https://github.com/fortnitedallas
#include <iostream>
#include <fstream>
using namespace std;

// Class: Date
class Date {
private:
    int day;
    int month;
    int year;
    int hour;
    int minute;

public:
    void setDay(int d) {
        if (d < 1 || d > 31) {
            cout << "Invalid day: must be between 1 and 31." << endl;
            return;
        }
        day = d;
    }

    int getDay() const {
        return day;
    }

    void setMonth(int m) {
        if (m < 1 || m > 12) {
            cout << "Invalid month: must be between 1 and 12." << endl;
            return;
        }
        month = m;
    }

    int getMonth() const {
        return month;
    }

    void setYear(int y) {
        year = y;
    }

    int getYear() const {
        return year;
    }

    void setHour(int h) {
        if (h < 0 || h > 23) {
            cout << "Invalid hour: must be between 0 and 23." << endl;
            return;
        }
        hour = h;
    }

    int getHour() const {
        return hour;
    }

    void setMinute(int m) {
        if (m < 0 || m > 59) {
            cout << "Invalid minute: must be between 0 and 59." << endl;
            return;
        }
        minute = m;
    }

    int getMinute() const {
        return minute;
    }

    friend ostream& operator<<(ostream& out, const Date& date) {
        out << date.day << "/" << date.month << "/" << date.year << " "
            << date.hour << ":" << date.minute;
        return out;
    }

    friend istream& operator>>(istream& in, Date& date) {
        in >> date.day >> date.month >> date.year >> date.hour >> date.minute;
        return in;
    }
};

// Class: Food
class Food {
private:
    string type; // Economic or Business
    string meal;

public:
    void setType(string& t) {
        type = t;
    }

    string getType() const {
        return type;
    }

    void setMeal(string& m) {
        meal = m;
    }

    string getMeal() const {
        return meal;
    }

    friend ostream& operator<<(ostream& out, const Food& food) {
        out << "Type: " << food.type << ", Meal: " << food.meal;
        return out;
    }

    friend istream& operator>>(istream& in, Food& food) {
        in >> food.type >> food.meal;
        return in;
    }
};

// Class: Airport
class Airport {
protected:
    string domesticFlights[10];
    string foreignFlights[10];
    int domesticCount;
    int foreignCount;

public:
    Airport() : domesticCount(0), foreignCount(0) {}

    virtual void addFlight(string type ,const string& flight) {
        if (type == "F") {
            if (foreignCount < 10) {
                foreignFlights[foreignCount] = flight;
            }
            foreignCount++;
        } else {
            if (domesticCount < 10) {
                domesticFlights[domesticCount] = flight;
            }
            domesticCount++;
        }
    }

    virtual void removeFlight(const string& flight) {
        for (int i = 0; i < domesticCount; ++i) {
            if (domesticFlights[i] == flight) {
                for (int j = i; j < domesticCount - 1; ++j) {
                    domesticFlights[j] = domesticFlights[j + 1];
                }
                domesticCount--;
                return;
            }
        }

        for (int i = 0; i < foreignCount; ++i) {
            if (foreignFlights[i] == flight) {
                for (int j = i; j < foreignCount - 1; ++j) {
                    foreignFlights[j] = foreignFlights[j + 1];
                }
                foreignCount--;
                return;
            }
        }
    }

    virtual void displayFlights() const = 0;
};

// Class: DomesticFlights (Derived from Airport)
class DomesticFlights : public Airport {
private:
    string originCity[10];
    string destinationCity[10];
    Date flightDate[10];
    string planeName[10];
    bool isCancelled[10];

public:
    void setOriginCity(string& city, int index) {
        originCity[index] = city;
    }

    string getOriginCity(int index) const {
        return originCity[index];
    }

    void setDestinationCity(string& city, int index) {
        destinationCity[index] = city;
    }

    string getDestinationCity(int index) const {
        return destinationCity[index];
    }

    void setFlightDate(Date& date, int index) {
        flightDate[index] = date;
    }

    Date getFlightDate(int index) const {
        return flightDate[index];
    }

    void setPlaneName(string& name, int index) {
        planeName[index] = name;
    }

    string getPlaneName(int index) const {
        return planeName[index];
    }

    void setIsCancelled(bool cancelled, int index) {
        isCancelled[index] = cancelled;
    }

    bool getIsCancelled(int index) const {
        return isCancelled[index];
    }

    void displayFlights() const override {
        for (int i = 0; i < domesticCount; i++) {
            cout << domesticFlights[i] << " | "
                 << flightDate[i] << " | "
                 << originCity[i] << " to " << destinationCity[i] << " | "
                 << planeName[i] << endl;
        }
    }

    int getCount() const {
        return domesticCount;
    }
};

// Class: DomesticCities
class DomesticCities {
private:
    string cities[10];
    int cityCount;

public:
    DomesticCities() : cityCount(0) {}

    void addCity(string& city) {
        if (cityCount < 10) {
            cities[cityCount++] = city;
        } else {
            cout << "Maximum number of cities reached!" << endl;
        }
    }

    string getCities() {
        string cityList = "";
        for (int i = 0; i < cityCount; ++i) {
            cityList += cities[i];
            if (i != cityCount - 1) {
                cityList += ", ";
            }
        }
        return cityList;
    }

    void displayCities() const {
        for (int i = 0; i < cityCount; ++i) {
            cout << cities[i] << endl;
        }
    }
};

// Class: ForeignFlights (Derived from Airport)
class ForeignFlights : public Airport {
private:
    string CITY[10];
    string destinationCity[10];
    Date flightDate[10];
    string Name[10];
    bool isCancelled[10];

public:
    void setOriginCitY(string city, int NUM) 
    {
        if (NUM == -1)
            NUM = 0;
        CITY[NUM] = city;
    }

    string getOriginCitY(int index) const {
        return CITY[index];
    }

    void setDestinationCity(string& city, int index) {
        destinationCity[index] = city;
    }

    string getDestinationCity(int index) const {
        return destinationCity[index];
    }

    void setFlightDate(Date& date, int index) {
        flightDate[index] = date;
    }

    Date getFlightDate(int index) const {
        return flightDate[index];
    }

    void setPlaneNamE(string name, int num) {
        if (num == -1)
            num = 0;
        Name[num] = name;
    }

    string getPlaneName(int index) const {
        return Name[index];
    }

    void setIsCancelled(bool cancelled, int index) {
        isCancelled[index] = cancelled;
    }

    bool getIsCancelled(int index) const {
        return isCancelled[index];
    }

    void displayFlights() const override {
        for (int i = 0; i < foreignCount; i++) {
            cout << foreignFlights[i] << " | "
                 << flightDate[i] << " | "
                 << CITY[i] << " to " << destinationCity[i] << " | "
                 << Name[i] << endl;
        }
    }

    int getCount()  {
        return foreignCount;
    }
};

// Class: ForeignCities
class ForeignCities {
private:
    string cities[10];
    int cityCount;

public:
    ForeignCities() : cityCount(0) {}

    void addCity(string& city) {
        if (cityCount < 10) {
            cities[cityCount++] = city;
        } else {
            cout << "Maximum number of cities reached!" << endl;
        }
    }

    string getCities() {
        string cityList = "";
        for (int i = 0; i < cityCount; ++i) {
            cityList += cities[i];
            if (i != cityCount - 1) {
                cityList += ", ";
            }
        }
        return cityList;
    }

    void displayCities() const {
        for (int i = 0; i < cityCount; ++i) {
            cout << cities[i] << endl;
        }
    }
};

// Class: Customer
class Customer {
private:
    string name;
    double balance;
    string purchasedFlights[10];
    string flightTypes[10]; // Domestic or Foreign
    int flightCount;

public:
    Customer() : balance(0.0), flightCount(0) {}

    void setName(string& n) {
        name = n;
    }

    string getName() const {
        return name;
    }

    void setBalance(double b) {
        balance = b;
    }

    double getBalance() const {
        return balance;
    }

    void addPurchasedFlight(string& flight, string& flightType) {
        if (flightCount < 10) {
            purchasedFlights[flightCount] = flight;
            flightTypes[flightCount++] = flightType;
        }
    }

    string* getPurchasedFlights() {
        return purchasedFlights;
    }

    string* getFlightTypes() {
        return flightTypes;
    }

    void refundTicket(string& flight) {
        for (int i = 0; i < flightCount; ++i) {
            if (purchasedFlights[i] == flight) {
                for (int j = i; j < flightCount - 1; ++j) {
                    purchasedFlights[j] = purchasedFlights[j + 1];
                    flightTypes[j] = flightTypes[j + 1];
                }
                flightCount--;
                break;
            }
        }
    }

    void displayPurchasedFlights() const {
        for (int i = 0; i < flightCount; ++i) {
            cout << "Flight: " << purchasedFlights[i] << " (" << flightTypes[i] << ")" << endl;
        }
    }
};

// Class: Admin
class Admin {
private:
    string adminName;
    string adminPassword;

public:
    void setAdminName(const string& name) {
        adminName = name;
    }

    string getAdminName() const {
        return adminName;
    }

    void setAdminPassword(const string& password) {
        adminPassword = password;
    }
    
    string getAdminPassword() const {
        return adminPassword;
    }

    void manageFlights(DomesticFlights& domesticFlight, ForeignFlights& foreignFlight) {
        int choice;
        do {
            cout << "\nAdmin Menu:\n";
            cout << "1. Add Domestic Flight\n";
            cout << "2. Remove Domestic Flight\n";
            cout << "3. Display Domestic Flights\n";
            cout << "4. Add Foreign Flight\n";
            cout << "5. Remove Foreign Flight\n";
            cout << "6. Display Foreign Flights\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    string flight, origin, destination, plane;
                    int day, month, year, hour, minute;
                    Date flightDate;
                    bool cancelled;
                    cout << "Enter flight number to add: ";
                    cin >> flight;
                    cout << "Enter origin city: ";
                    cin >> origin;
                    cout << "Enter destination city: ";
                    cin >> destination;
                    cout << "Enter flight date (day month year): ";
                    cin >> day >> month >> year;
                    cout << "Enter flight time (hour minute): ";
                    cin >> hour >> minute;
                    cout << "Enter plane name: ";
                    cin >> plane;
                    cout << "Is the flight cancelled? (1 for yes, 0 for no): ";
                    cin >> cancelled;
                    flightDate.setDay(day);
                    flightDate.setMonth(month);
                    flightDate.setYear(year);
                    flightDate.setHour(hour);
                    flightDate.setMinute(minute);
                    domesticFlight.addFlight("D",flight);
                    domesticFlight.setOriginCity(origin, domesticFlight.getCount() - 1);
                    domesticFlight.setDestinationCity(destination, domesticFlight.getCount() - 1);
                    domesticFlight.setFlightDate(flightDate, domesticFlight.getCount() - 1);
                    domesticFlight.setPlaneName(plane, domesticFlight.getCount() - 1);
                    domesticFlight.setIsCancelled(cancelled, domesticFlight.getCount() - 1);
                    cout << "Domestic flight added successfully!\n";
                    break;
                }
                case 2: {
                    string flight;
                    cout << "Enter flight number to remove: ";
                    cin >> flight;
                    domesticFlight.removeFlight(flight);
                    cout << "Domestic flight removed successfully!\n";
                    break;
                }
                case 3: {
                    cout << "Domestic Flights:\n";
                    cout << "Flight Number |   Time   |   Route   | Plane Name\n";
                    cout << "-------------------------------------------------\n";
                    domesticFlight.displayFlights();
                    break;
                }
                case 4: {
                    string flight, origin, destination, plane;
                    int day, month, year, hour, minute;
                    Date flightDate;
                    bool cancelled;
                    cout << "Enter flight number to add: ";
                    cin >> flight;
                    cout << "Enter origin city: ";
                    cin >> origin;
                    cout << "Enter destination city: ";
                    cin >> destination;
                    cout << "Enter flight date (day month year): ";
                    cin >> day >> month >> year;
                    cout << "Enter flight time (hour minute): ";
                    cin >> hour >> minute;
                    cout << "Enter plane name: ";
                    cin >> plane;
                    cout << "Is the flight cancelled? (1 for yes, 0 for no): ";
                    cin >> cancelled;
                    flightDate.setDay(day);
                    flightDate.setMonth(month);
                    flightDate.setYear(year);
                    flightDate.setHour(hour);
                    flightDate.setMinute(minute);
                    foreignFlight.addFlight("F",flight);
                    foreignFlight.setOriginCitY(origin, foreignFlight.getCount() - 1);
                    foreignFlight.setDestinationCity(destination, foreignFlight.getCount() - 1);
                    foreignFlight.setFlightDate(flightDate, foreignFlight.getCount() - 1);
                    foreignFlight.setPlaneNamE(plane, foreignFlight.getCount() - 1);
                    foreignFlight.setIsCancelled(cancelled, foreignFlight.getCount() - 1);
                    cout << "Foreign flight added successfully!\n";
                    break;
                }
                case 5: {
                    string flight;
                    cout << "Enter flight number to remove: ";
                    cin >> flight;
                    foreignFlight.removeFlight(flight);
                    cout << "Foreign flight removed successfully!\n";
                    break;
                }
                case 6: {
                    cout << "Foreign Flights:\n";
                    cout << "Flight Number |   Time   |   Route   | Plane Name\n";
                    cout << "-------------------------------------------------\n";
                    foreignFlight.displayFlights();
                    break;
                }
                case 0: {
                    cout << "Exiting admin menu.\n";
                    break;
                }
                default: {
                    cout << "Invalid choice. Please try again.\n";
                }
            }
        } while (choice != 0);
    }
};

// Class: Tax
class Tax {
public:
    static double applyPurchaseTax(double price) {
        return price * 1.01;
    }

    static double applyCancellationTax(double price) {
        return price * 1.10;
    }
};

int main() {
    DomesticFlights domesticFlight;
    ForeignFlights foreignFlight;
    string flight1;

    cout << "Enter flight number: ";
    cin >> flight1;

    string origin, destination, plane, flightType;
    int day, month, year, hour, minute;
    bool cancelled;

    cout << "Enter origin city: ";
    cin >> origin;
    cout << "Enter destination city: ";
    cin >> destination;

    cout << "Enter flight date (day month year): ";
    cin >> day >> month >> year;

    cout << "Enter flight time (hour minute): ";
    cin >> hour >> minute;

    cout << "Enter plane name: ";
    cin >> plane;

    cout << "Enter flight type (Domestic = D or Foreign = F): ";
    cin >> flightType;

    cout << "Is the flight cancelled? (1 for yes, 0 for no): ";
    cin >> cancelled;

    Date flightDate;
    flightDate.setDay(day);
    flightDate.setMonth(month);
    flightDate.setYear(year);
    flightDate.setHour(hour);
    flightDate.setMinute(minute);

    if (flightType == "D") {
        domesticFlight.addFlight("D",flight1);
        domesticFlight.setOriginCity(origin, domesticFlight.getCount() - 1);
        domesticFlight.setDestinationCity(destination, domesticFlight.getCount() - 1);
        domesticFlight.setFlightDate(flightDate, domesticFlight.getCount() - 1);
        domesticFlight.setPlaneName(plane, domesticFlight.getCount() - 1);
        domesticFlight.setIsCancelled(cancelled, domesticFlight.getCount() - 1);
    } else if (flightType == "F") {
        foreignFlight.addFlight("F",flight1);
        foreignFlight.setOriginCitY(origin, foreignFlight.getCount() - 1);
        foreignFlight.setDestinationCity(destination, foreignFlight.getCount() - 1);
        foreignFlight.setFlightDate(flightDate, foreignFlight.getCount() - 1);
        foreignFlight.setPlaneNamE(plane, foreignFlight.getCount() - 1);
        foreignFlight.setIsCancelled(cancelled, foreignFlight.getCount() - 1);
    } else {
        cout << "Invalid flight type entered. Exiting..." << endl;
        return 1;
    }

    cout << "\nDomestic Flights:\n";
    domesticFlight.displayFlights();

    cout << "\nForeign Flights:\n";
    foreignFlight.displayFlights();

    Customer customer;
    string customerName;
    double customerBalance;

    cout << "Enter customer name: ";
    cin >> customerName;
    cout << "Enter customer balance: ";
    cin >> customerBalance;

    customer.setName(customerName);
    customer.setBalance(customerBalance);
    customer.addPurchasedFlight(flight1, flightType);

    cout << "Customer " << customer.getName() << " has purchased flight: " << flight1 << " (" << flightType << ")" << endl;
    cout << "Current Balance: $" << customer.getBalance() << endl;

    Food food;
    string foodType, meal;

    cout << "Enter food type (Economic or Business): ";
    cin >> foodType;
    cout << "Enter meal: ";
    cin >> meal;

    food.setType(foodType);
    food.setMeal(meal);

    cout << "Food Information:\n" << food << endl;

    double ticketPrice;
    cout << "Enter ticket price: ";
    cin >> ticketPrice;

    double purchasePrice = Tax::applyPurchaseTax(ticketPrice);
    cout << "Ticket price after 1% purchase tax: $" << purchasePrice << endl;

    double finalPrice = purchasePrice;
    if (cancelled) {
        finalPrice = Tax::applyCancellationTax(purchasePrice);
        cout << "Ticket price after 10% cancellation tax: $" << finalPrice << endl;
    }

    ofstream outFile("flight_info.txt");
    if (outFile.is_open()) {
        outFile << "Flight Information:\n";
        outFile << "Flight Number: " << flight1 << "\n";
        outFile << "Origin City: " << origin << "\n";
        outFile << "Destination City: " << destination << "\n";
        outFile << "Flight Date: " << flightDate << "\n";
        outFile << "Plane Name: " << plane << "\n";
        outFile << "Cancelled: " << (cancelled ? "Yes" : "No") << "\n";

        outFile << "\nCustomer Information:\n";
        outFile << "Customer Name: " << customer.getName() << "\n";
        outFile << "Customer Balance: $" << customer.getBalance() << "\n";
        outFile << "Purchased Flight: " << flight1 << " (" << flightType << ")\n";

        outFile << "\nFood Information:\n";
        outFile << food << "\n";

        outFile << "\nTicket Information:\n";
        outFile << "Ticket Price: $" << ticketPrice << "\n";
        outFile << "Purchase Price after Tax: $" << purchasePrice << "\n";
        outFile << "Final Price after Cancellation Tax (if applicable): $" << finalPrice << "\n";

        outFile.close();
        cout << "Information saved to flight_info.txt" << endl;
    } else {
        cout << "Unable to open file to save information" << endl;
    }

    Admin admin; 
    string adminName, adminPassword;

    cout << "Enter admin name: ";
    cin >> adminName;
    cout << "Enter admin password: ";
    cin >> adminPassword;

    admin.setAdminName(adminName);
    admin.setAdminPassword(adminPassword);
    
    cout << "Admin authenticated successfully." << endl;
    admin.manageFlights(domesticFlight, foreignFlight);

    return 0;
}