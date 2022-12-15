#include <iostream>
#include <iomanip>
#include <sstream>
#include <string.h>
#include "Date.cpp"
using namespace std;

const Date EVENT_START(1, 1, 2023);
const Date EVENT_END(8, 1, 2023);
const int TOTAL_MALE_ROOMS = 40;
const int TOTAL_FEMALE_ROOMS = 30;

/**
 * @summary: making an accomodation system for a hostels
 * @date 06-11-2022
 * @author: Muhammad Faseeh Ud Din - 24100178
 *
 * @description: There are two Hostels, Male and Female
 * Male hostel has 40 rooms - Only double occupancy -- Total 80 beds
 *  Rate of Occupancy per day: 1000PKR
 * Female hostel has 30 rooms - Single and double occupancy -- Total 60 beds
 *  Rate of Occupancy per day - Single Occupancy: 2000PKR
 *  Rate of Occupancy per day - Double Occupancy: 1000PKR
 *
 * any room can be book for a maximum of 7 days
 * rent is on per day basis, and is charged in advance
 */

bool isInArray(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return true;
        }
    }
    return false;
}
int userIntPut(int acceptedTerms[], int acceptedTermsSize = 0)
{
    // error handled repeating input
    int input;
    while (!(cin >> input) || (acceptedTermsSize != 0 && !isInArray(acceptedTerms, acceptedTermsSize, input)))
    {
        cout << "Invalid input, please try again: ";
    }
    return input;
}
string userStrPut(int minLength, int maxLength = -1)
{
    // error handled repeating input
    string input;
    while (true)
    {
        // use getline and ignore properly
        //  cin.ignore();
        getline(cin, input);
        if (input.length() >= minLength && (maxLength == -1 || input.length() <= maxLength))
        {
            break;
        }
        cout << "Invalid input, please try again: ";
    }
    return input;
}

class Reservation
{
private:
    int hostelNumber;
    int roomNumber;
    char hostelType;
    bool waitList;
    int payment;
    int numberOfDays;
    Date checkInDate;

public:
    // only param
    Reservation(int hostelNumber, int roomNumber, char hostelType, bool waitList, int payment, int numberOfDays, int Day)
    {
        this->hostelNumber = hostelNumber;
        this->roomNumber = roomNumber;
        this->hostelType = hostelType;
        this->waitList = waitList;
        this->payment = payment;
        this->numberOfDays = numberOfDays;
        this->checkInDate = Date(Day, 1, 2023);
    }

    Reservation(int checkInDay, int numberOfDays, char hostelType)
    {
        this->checkInDate = Date(checkInDay, 1, 2023);
        this->numberOfDays = numberOfDays;
        this->hostelType = hostelType;
    }

    // deep reservation deletion
    ~Reservation()
    {
        cout << "Reservation deleted" << endl;
    }

    // all getters
    int getHostelNumber()
    {
        return hostelNumber;
    }
    int getRoomNumber()
    {
        return roomNumber;
    }
    char getHostelType()
    {
        return hostelType;
    }
    bool getWaitList()
    {
        return waitList;
    }
    int getPayment()
    {
        return payment;
    }
    int getNumberOfDays()
    {
        return numberOfDays;
    }
    string getCheckInDate()
    {
        string date;
        stringstream ss;
        ss << checkInDate;
        date = ss.str();
        return date;
    }

    // setters
    void setHostelNumber(int hostelNumber)
    {
        this->hostelNumber = hostelNumber;
    }
    void setRoomNumber(int roomNumber)
    {
        this->roomNumber = roomNumber;
    }
    void setHostelType(char hostelType)
    {
        this->hostelType = hostelType;
    }
};
class Delegate
{
    // limitations: no copy or assignment of delegates
private:
    const enum genders {
        male,
        female
    };
    string name;
    string CNIC;
    string phone;
    Reservation *reservation;
    string waitListQuery;

public:
    // only parameterized constructor
    Delegate(string name, string CNIC, string phone, Reservation *reservation)
    {
        this->name = name;
        this->CNIC = CNIC;
        this->phone = phone;
        this->reservation = reservation;
        waitListQuery = "";
    }
    Delegate(string name, string CNIC, string phone, string waitListQuery, Reservation *partialReservation)
    {
        this->name = name;
        this->CNIC = CNIC;
        this->phone = phone;
        this->waitListQuery = waitListQuery;
        this->reservation = partialReservation;
    }

    // deep delete delegate
    ~Delegate()
    {
        // to delete a delegate, we see if it has a reservation
        //  if it does, we delete the reservation
        //  if it doesn't, we do nothing
        if (reservation != NULL)
        {
            delete reservation;
        }
    }

    // getters
    // get reservation
    Reservation *getReservation()
    {
        return this->reservation;
    }
    // get name
    string getName()
    {
        return this->name;
    }
    // get CNIC
    string getCNIC()
    {
        return this->CNIC;
    }
    // get phone
    string getPhone()
    {
        return this->phone;
    }
    // get waitlistquery
    string getWaitListQuery()
    {
        return this->waitListQuery;
    }

    string getRoomDetail()
    {
        string roomDetail;
        stringstream ss;
        ss << reservation->getHostelType() << "-" << setfill('0') << setw(2) << reservation->getHostelNumber() << " R-" << setfill('0') << setw(3) << reservation->getRoomNumber();
        roomDetail = ss.str();
        return roomDetail;
    }
};

class Room
{
    // limitations: no copy or assignment of rooms
private:
    int roomNumber;
    int occupancy;
    Delegate **occupants;
    int minOccupancy;
    int occupancyLimit;
    int occupancyRate;
    int daysBooked;

public:
    // parameterized constructor
    Room(int roomNumber, int occupancyLimit, int minOccpancy, int occupancyRate)
    {
        this->roomNumber = roomNumber;
        this->occupancy = 0;
        this->occupancyLimit = occupancyLimit;
        this->minOccupancy = minOccpancy;
        this->occupancyRate = occupancyRate;
        this->daysBooked = 0;
        this->occupants = new Delegate *[this->occupancyLimit];
        for (int i = 0; i < occupancyLimit; i++)
            this->occupants[i] = nullptr;
    }

    void addOccupant(Delegate *newOccupant)
    {
        occupants[occupancy++] = newOccupant;
    }

    void removeOccupant(Delegate *rOccupant)
    {
        for (int i = 0; i < occupancy; i++)
        {
            if (rOccupant == occupants[i])
            {
                occupants[i] == NULL;
                occupancy--;
                return;
            }
        }
        __throw_logic_error("this delegate is not in this room");
    }

    // getters
    int getRoomNumber() { return this->roomNumber; }
    int getMinOccupancy() { return this->minOccupancy; }
    int getOccupancyLimit() { return this->occupancyLimit; }
    int getNumOccupants() { return this->occupancy; }
    bool allotable(int searchOcc) { return ((this->occupancyLimit - occupancy >= 1) && this->occupancyLimit == searchOcc); }
};

class Hostel
{
    // aggregates rooms
    // limitations: no copy or assignment of hostels
private:
protected:
    string name;
    int totalRooms;
    int totalFreeRooms;
    int totalOccupiedRooms;
    Room **freeRooms;
    Room **occupiedRooms;

public:
    // only param constructor
    Hostel(int totalRooms)
    {
        this->totalRooms = totalRooms;
        totalFreeRooms = totalRooms;
        totalOccupiedRooms = 0;
        freeRooms = new Room *[totalRooms];
        occupiedRooms = nullptr;
        for (int i = 0; i < totalRooms; i++)
            freeRooms[i] = nullptr;
    }

    // member functions
    virtual void queryFreeRooms(int searchOcc)
    {
        cout << "\tRoom\t\tMax Occupancy" << endl;
        for (int fr = 0; fr < totalFreeRooms; fr++)
        {

            if (freeRooms[fr] != nullptr)
            {
                string color = (freeRooms[fr]->getNumOccupants() < freeRooms[fr]->getOccupancyLimit()) ? "\033[1;32m" : "\033[1;31m";
                if (searchOcc == 0)
                {
                    // ret all rooms

                    cout << "\t" << color
                         << name << " R-" << setfill('0') << setw(2) << freeRooms[fr]->getRoomNumber()
                         << "\033[0m"
                         << "\t" << (freeRooms[fr]->getOccupancyLimit() == 1 ? "Single" : "Double") << " Occpancy"
                         << "\t" << freeRooms[fr]->getNumOccupants() << "/" << freeRooms[fr]->getOccupancyLimit()
                         << endl;
                }
                else if (freeRooms[fr]->getOccupancyLimit() == searchOcc)
                {
                    // ret rooms with specific occ
                    cout << "\t" << color
                         << name << " R-" << setfill('0') << setw(2) << freeRooms[fr]->getRoomNumber()
                         << "\033[0m"
                         << "\t" << (freeRooms[fr]->getOccupancyLimit() == 1 ? "Single" : "Double") << " Occpancy"
                         << "\t" << freeRooms[fr]->getNumOccupants() << "/" << freeRooms[fr]->getOccupancyLimit()
                         << endl;
                }
            }
        }
    }
    int getNumberOfRooms() { return totalFreeRooms != 0 ? totalRooms : 0; }
    Room &operator()(int roomNumber)
    {
        return *freeRooms[roomNumber];
    }
};

// inheritance
class MaleHostel : public Hostel
{
    // limitations: no copy or assignment
public:
    // default constructor
    MaleHostel(string name) : Hostel(TOTAL_MALE_ROOMS)
    {
        this->name = name;
        // init rooms
        // R-1 -> R-40 - Double Occupancy Only - Rate: 1000
        // minOcc: 1, maxOcc: 2, rate: 1000
        for (int room = 0; room < TOTAL_MALE_ROOMS; room++)
        {
            freeRooms[room] = new Room(room + 1, 2, 1, 1000);
        }
    }

    // overriding pure virtual functions
    void queryFreeRooms(int searchOcc)
    {
        cout << "Free Rooms in " << name << ": " << endl;
        Hostel::queryFreeRooms(searchOcc);
    }
};

class FemaleHostel : public Hostel
{
    // limitations: no copy or assignment
public:
    // default constructor
    FemaleHostel(string name) : Hostel(TOTAL_FEMALE_ROOMS)
    {
        this->name = name;
        // init rooms
        // R-1->R-15: MinOcc: Double Occupancy, Rate: 1000
        for (int room = 0; room < TOTAL_FEMALE_ROOMS / 2; room++)
        {
            freeRooms[room] = new Room(room + 1, 2, 1, 1000);
        }
        // R-16->R-30: MinOcc: Single Occupancy, Rate: 2000

        for (int room = TOTAL_FEMALE_ROOMS - (TOTAL_FEMALE_ROOMS / 2); room < TOTAL_FEMALE_ROOMS; room++)
        {
            freeRooms[room] = new Room(room + 1, 1, 1, 2000);
        }
    }

    // overriding pure virtual functions
    void queryFreeRooms(int searchOcc)
    {
        cout << "Free Rooms in " << name << ": " << endl;
        Hostel::queryFreeRooms(searchOcc);
    }
};

struct LUMSHostels
{
    int totalHostels;
    int totalMaleHostels;
    int totalFemaleHostels;
    const enum HostelType {
        male,
        female
    };
    Hostel **hostels[2]; // a 2D array of hostels pointers

    // parameterized constructor
    LUMSHostels(int totalMaleHostels, int totalFemaleHostels)
    {
        this->totalMaleHostels = totalMaleHostels;
        this->totalFemaleHostels = totalFemaleHostels;
        this->totalHostels = totalMaleHostels + totalFemaleHostels;

        // init hostels pointer array using enum
        hostels[male] = new Hostel *[totalMaleHostels];
        hostels[female] = new Hostel *[totalFemaleHostels];

        // init hostels
        for (int mHos = 0; mHos < this->totalMaleHostels; mHos++)
        {
            hostels[male][mHos] = new MaleHostel("M-" + to_string(mHos + 1));
        }

        for (int fHos = 0; fHos < this->totalFemaleHostels; fHos++)
        {
            hostels[female][fHos] = new FemaleHostel("F-" + to_string(fHos + 1));
        }
    }

    // query free male rooms
    void queryFreeRooms(char query = 'B', int searchOcc = 2)
    {
        if (query == 'M' || query == 'B')
        {

            for (int mHos = 0; mHos < totalMaleHostels; mHos++)
            {
                hostels[male][mHos]->queryFreeRooms(searchOcc);
            }
        }
        if (query == 'F' || query == 'B')
        {
            for (int fHos = 0; fHos < totalFemaleHostels; fHos++)
            {
                hostels[female][fHos]->queryFreeRooms(searchOcc);
            }
        }
    }
    string firstFreeRoom(string reservationQuery)
    {
        if (reservationQuery[0] == 'M')
        {
            for (int mHos = 0; mHos < totalMaleHostels; mHos++)
                for (int room = 0; room < hostels[male][mHos]->getNumberOfRooms(); room++)
                    if (hostels[male][mHos]->operator()(room).allotable(2))
                    {
                        // follow format -> M-01 R-001
                        // declare ostringstream
                        stringstream oss;
                        string reservationResult;
                        oss << "M-" << setfill('0') << setw(2) << mHos + 1 << " R-" << setfill('0') << setw(3) << room + 1;
                        reservationResult = oss.str();
                        return reservationResult;
                    }

            return "NFR";
        }
        else if (reservationQuery[0] == 'F')
        {
            for (int fHos = 0; fHos < totalMaleHostels; fHos++)
                for (int room = 0; room < hostels[female][fHos]->getNumberOfRooms(); room++)
                    if (hostels[female][fHos]->operator()(room).allotable(reservationQuery[1] - '0'))
                    {
                        // follow format -> F-01 R-001
                        // declare ostringstream
                        stringstream oss;
                        string reservationResult;
                        oss << "F-" << setfill('0') << setw(2) << fHos + 1 << " R-" << setfill('0') << setw(3) << room + 1;
                        reservationResult = oss.str();
                        return reservationResult;
                    }
            return "NFR";
        }
    }
};

struct LUMUNDelegates
{
    int totalDelegates;
    Delegate **delegates;

    // default constructor
    LUMUNDelegates()
    {
        this->totalDelegates = 0;
        this->delegates = nullptr;
    }

    // member functions
    //  add a delegate
    void addDelegate(Delegate *delegate)
    {
        Delegate **temp = new Delegate *[totalDelegates + 1];
        for (int i = 0; i < totalDelegates; i++)
        {
            temp[i] = delegates[i];
        }
        temp[totalDelegates] = delegate;
        totalDelegates++;
        delegates = temp;
    }
    void removeDelegate(Delegate *delegate)
    {
        Delegate **temp = new Delegate *[totalDelegates - 1];
        int i = 0;
        for (; i < totalDelegates; i++)
        {
            if (delegates[i] == delegate)
            {
                break;
            }
            temp[i] = delegates[i];
        }
        for (; i < totalDelegates - 1; i++)
        {
            temp[i] = delegates[i + 1];
        }
        totalDelegates--;
        delegates = temp;
    }
};

struct Waitlist
{
    int waitListSize = 0;
    Delegate **waitList = nullptr;

    void addDelegate(Delegate *delegate)
    {
        Delegate **temp = new Delegate *[waitListSize + 1];
        for (int i = 0; i < waitListSize; i++)
        {
            temp[i] = waitList[i];
        }
        temp[waitListSize] = delegate;
        waitListSize++;
        waitList = temp;
    }

    Delegate *removeTopDelegate()
    {
        Delegate *delegate = waitList[0];
        Delegate **temp = new Delegate *[waitListSize - 1];
        for (int i = 0; i < waitListSize - 1; i++)
        {
            temp[i] = waitList[i + 1];
        }
        waitListSize--;
        waitList = temp;
        return delegate;
    }

    void removeFromWaitList(Delegate *delegate)
    {
        if (waitListSize == 0)
        {
            return;
        }
        Delegate **temp = new Delegate *[waitListSize - 1];
        int i = 0;
        for (; i < waitListSize; i++)
        {
            if (waitList[i] == delegate)
            {
                break;
            }
            temp[i] = waitList[i];
        }
        for (; i < waitListSize - 1; i++)
        {
            temp[i] = waitList[i + 1];
        }
        waitListSize--;
        waitList = temp;
    }
};

struct LUMUNManagment

{
    int totalHostels;
    int totalMaleHostels;
    int totalFemaleHostels;

    LUMSHostels *hostels;
    LUMUNDelegates *delegates;
    Waitlist *waitList;

    bool roomAllotted = false;
    bool waitListed = false;
    int currentDelegateIndex = -1;

    // parameterized constructor
    LUMUNManagment(int totalMaleHostels, int totalFemaleHostels)
    {
        this->totalMaleHostels = totalMaleHostels;
        this->totalFemaleHostels = totalFemaleHostels;
        this->totalHostels = totalMaleHostels + totalFemaleHostels;

        // init hostels
        hostels = new LUMSHostels(totalMaleHostels, totalFemaleHostels);

        // init delegates
        delegates = new LUMUNDelegates();

        // init waitlist
        waitList = new Waitlist();
    }

    void addDelegate(string name, string cnic, string phone, Reservation *reservation)
    {
        // make delegate
        Delegate *delegate = new Delegate(name, cnic, phone, reservation);
        // add delegate to delegates
        delegates->addDelegate(delegate);
        // add delegate to hostel
        hostels->hostels[delegate->getReservation()->getHostelType() == 'M' ? 0 : 1][delegate->getReservation()->getHostelNumber() - 1]->operator()(delegate->getReservation()->getRoomNumber() - 1).addOccupant(delegate);
    }
    void addDelegate(Delegate *delegate)
    {
        // add delegate to delegates
        delegates->addDelegate(delegate);
        // add delegate to hostel
        hostels->hostels[delegate->getReservation()->getHostelType() == 'M' ? 0 : 1][delegate->getReservation()->getHostelNumber() - 1]->operator()(delegate->getReservation()->getRoomNumber() - 1).addOccupant(delegate);
        // increment totalDelegates
    }

    void addToWaitList(Delegate *delegate)
    {
        waitList->addDelegate(delegate);
    }

    void reserveRoom(string reservationQuery)
    {
        if (roomAllotted || waitListed)
        {
            cout << "You have already been allotted a room, or are on the waitlist" << endl;
            cout << "Please checkout or cancel your appointment to continue" << endl;
            return;
        }
        string reservationResult = hostels->firstFreeRoom(reservationQuery);
        if (reservationResult == "NFR")
        {
            cout << "No Free Rooms Are Available Right Now, We can reserve a room for you when one becomes available" << endl;
            cout << "We will add you to the waiting list!" << endl;
            waitListed = true;
        }
        else
        {
            cout << "Your room has been reserved!" << endl;
            cout << "Your room is: " << reservationResult << endl;
            roomAllotted = true;
        }
        cout << "Please Enter your detials to complete the reservation" << endl;
        cout << "Enter your name: ";
        cin.ignore();
        string name = userStrPut(1, 90);
        cout << "Enter your CNIC (13 Digits): ";
        // pakistani cnic is 13 digits long
        string cnic = userStrPut(13);
        cout << "Enter your Phone Number (11 Digits): ";
        string phone = userStrPut(11);
        int days[8] = {1, 2, 3, 4, 5, 6, 7, 8};
        int checkInDay;
        int reservationDays;
        while (true)
        {
            cout << "What day will you check in? (Days from 1st of January 2023): ";
            checkInDay = userIntPut(days, 8);
            cout << "Reservation for how many days? (1-8): ";
            reservationDays = userIntPut(days, 8);

            if (checkInDay + reservationDays > 8)
            {
                cout << "You cannot reserve a room for more than event days" << endl;
                cout << "Please try again" << endl;
            }
            else
            {
                break;
            }
        }

        //////////////I WAS HERE!!!!
        //
        if (reservationResult == "NFR")
        {
            // add to waiting list

            addToWaitList(new Delegate(name, cnic, phone, reservationQuery, new Reservation(checkInDay, reservationDays, reservationResult[0])));
            waitListed = true;
            currentDelegateIndex = waitList->waitListSize - 1;
        }
        else
        {

            // make a reservation object
            // reservationResult is a string in the format "M-01 R-001"
            int reservationHostelNumber = stoi(reservationResult.substr(2, 2));
            int reservationRoomNumber = stoi(reservationResult.substr(7, 3));
            char reservationHostelType = reservationResult[0];

            // make a new delegate object and add it to the delegates array and add the delegate to the room
            addDelegate(name, cnic, phone, new Reservation(reservationHostelNumber, reservationRoomNumber, reservationHostelType, false, (reservationQuery[1] - '0') == 1 ? 2000 * reservationDays : 1000 * reservationDays, reservationDays, checkInDay));
            roomAllotted = true;
            currentDelegateIndex = delegates->totalDelegates - 1;
            // add the room to the delegate
            // add the delegate to the waiting list if the room is not available
        }
    }

    void checkOut()
    {
        if (!roomAllotted && !waitListed)
        {
            cout << "You have not been allotted a room, or are on the waitlist" << endl;
            cout << "Please reserve a room to continue" << endl;
            return;
        }
        {
            cout << "You have not been allotted a room yet" << endl;
        }
        if (!waitListed)
        {
            cout << "You have not been waitlisted" << endl;
        }

        // print the delegate's details
        // print the delegate's room details
        // print the delegate's hostel details
        // print the delegate's reservation details
        // print the delegate's waitlist details
        // print the delegate's payment details

        Delegate *currentDelegate;
        if (waitListed)
        {
            currentDelegate = waitList->waitList[currentDelegateIndex];
        }
        else
        {
            currentDelegate = delegates->delegates[currentDelegateIndex];
        }
        cout << "Payment Details" << endl;
        cout << "Name: " << currentDelegate->getName() << endl;
        cout << "CNIC: " << currentDelegate->getCNIC() << endl;
        cout << "Phone: " << currentDelegate->getPhone() << endl;

        cout << "Reservation Details" << endl;
        if (waitListed)
        {
            cout << "You are on the waitlist" << endl;
            cout << "You will be notified when a room becomes available" << endl;

            cout << endl
                 << endl;

            cout << "Waitlist Details" << endl;
            cout << "Waitlist Number: " << currentDelegateIndex + 1 << endl;
            cout << "Waitlist Size: " << waitList->waitListSize << endl;

            cout << "Payment Details" << endl;
            cout << "Total Amount: " << currentDelegate->getReservation()->getPayment() << endl;

            waitListed = false;
            currentDelegateIndex = -1;
        }
        else if (roomAllotted)
        {
            cout << "Hostel Type: " << currentDelegate->getReservation()->getHostelType() << endl;
            cout << "Hostel Number: " << currentDelegate->getReservation()->getHostelNumber() << endl;
            cout << "Room Number: " << currentDelegate->getReservation()->getRoomNumber() << endl;

            cout << "Payment Details" << endl;
            cout << "Total Amount: " << currentDelegate->getReservation()->getPayment() << endl;

            roomAllotted = false;
            currentDelegateIndex = -1;
        }
    }

    void giveRoomToWaitListDelegate()
    {
        if (waitList->waitListSize <= 0)
        {
            cout << "No one is on the waitlist" << endl;
            return;
        }

        string reservationResult = hostels->firstFreeRoom(waitList->waitList[0]->getWaitListQuery());
        if (reservationResult == "NFR")
        {
            cout << "ROOM FOR WAITLIST DELEGATE IS NOT AVAILABLE\n";
            cout << "No Free Rooms Are Available Right Now, We can reserve a room for you when one becomes available" << endl;
            cout << "We will add you to the waiting list!" << endl;
        }
        else
        {
            cout << "WAITLIST DELEGATE: " << waitList->waitList[0]->getName() << " has been given a room\n";
            cout << "Room is: " << reservationResult << endl;
            cout << "Please inform on this phone number: " << waitList->waitList[0]->getPhone() << endl;

            // allot room
            //  make a reservation object
            // reservationResult is a string in the format "M-01 R-001"
            int reservationHostelNumber = stoi(reservationResult.substr(2, 2));
            int reservationRoomNumber = stoi(reservationResult.substr(7, 3));
            waitList->waitList[0]->getReservation()->setHostelNumber(reservationHostelNumber);
            waitList->waitList[0]->getReservation()->setRoomNumber(reservationRoomNumber);
            waitList->waitList[0]->getReservation()->setHostelType(reservationResult[0]);
            // make a new delegate object and add it to the delegates array and add the delegate to the room
            addDelegate(waitList->removeTopDelegate());
            roomAllotted = true;
            currentDelegateIndex = delegates->totalDelegates - 1;
            // add the room to the delegate
            // add the delegate to the waiting list if the room is not available
        }
    }

    void deleteDelegate(Delegate *delegate)
    {
        // remove from room if allotted
        if (delegate->getReservation() != NULL)
        {
            hostels->hostels[delegate->getReservation()->getHostelType() == 'M' ? 0 : 1][delegate->getReservation()->getHostelNumber() - 1]->operator()(delegate->getReservation()->getRoomNumber() - 1).removeOccupant(delegate);
            // remove from waitlist if waitlisted
        }
        if (delegate->getWaitListQuery() != "")
        {
            waitList->removeFromWaitList(delegate);
        }
        // remove from delegates array
        delegates->removeDelegate(delegate);
    }

    void cancelReservation()
    {
        // we will delete the delegate, delete the reservation, and remove the delegate from the hostel room ya bitch
        cout << "We're sorry to see you go\n";
        Delegate *delegateToCancel = nullptr;

        if (waitListed)
        {
            delegateToCancel = delegates->delegates[currentDelegateIndex];
            cout << "Removing " << delegateToCancel->getName() << " from waitlist\n";
        }
        else if (roomAllotted)
        {
            delegateToCancel = delegates->delegates[currentDelegateIndex];
            cout << "Removing " << delegateToCancel->getName() << " from " << delegateToCancel->getRoomDetail() << "\n";
        }
        else
        {
            int indexOfDelegateToCancel = -1;
            cout << "What is your name: ";
            cin.ignore();
            string delegateName = userStrPut(0, 90);
            for (int i = 0; i < delegates->totalDelegates; i++)
            {
                if (delegates->delegates[i]->getName() == delegateName)
                {
                    delegateToCancel = delegates->delegates[i];
                    cout << "Removing " << delegateToCancel->getName() << " from " << delegateToCancel->getRoomDetail() << "\n";
                    break;
                }
            }

            if (delegateToCancel == nullptr)
            {
                // checking waitlist
                for (int i = 0; i < waitList->waitListSize; i++)
                {
                    if (waitList->waitList[i]->getName() == delegateName)
                    {
                        delegateToCancel = waitList->waitList[i];
                        cout << "Removing " << delegateToCancel->getName() << " from waitlist\n";
                        break;
                    }
                }
                // if on waitlist just remove and delete ezpz
                if (delegateToCancel != nullptr)
                {
                    waitList->removeFromWaitList(delegateToCancel);
                    delegates->removeDelegate(delegateToCancel);
                    return;
                }
            }
            // if still not found
            if (delegateToCancel == nullptr)
            {
                cout << "You are not in the system, please try again\n";
                return;
            }
        }

        deleteDelegate(delegateToCancel);
        giveRoomToWaitListDelegate();
        waitListed = false;
        roomAllotted = false;
        currentDelegateIndex = -1;
    }
};

void DelegateMenu(LUMUNManagment &lumunManagment)
{
    int choice;
    while (true)
    {
        cout << "1. Query" << endl;
        cout << "2. Reserve" << endl;
        cout << "3. Check out" << endl;
        cout << "4. Cancel Reservation" << endl;
        cout << "5. Back to menu" << endl;
        cout << "Enter your choice: ";
        int choices[] = {1, 2, 3, 4, 5};
        choice = userIntPut(choices, 5);

        switch (choice)
        {
        case 1:
            // Query Rooms
            {
                if (lumunManagment.roomAllotted || lumunManagment.waitListed)
                {
                    cout << "You have already been allotted a room, or are on the waitlist" << endl;
                    cout << "Please checkout or cancel your appointment to continue" << endl;
                    break;
                }
                cout << "Search By: \n";
                cout << "1. Hostel(Male/Female)\n";
                cout << "2. Room Type(Single/Double)\n";
                int searchBy[2] = {1, 2};
                int queryType = userIntPut(searchBy, 2);

                // <!-- Hostel Query --!>
                if (queryType == 1)
                {
                    cout << "Search By Hostel: \n";
                    cout << "1. Male\n";
                    cout << "2. Female\n";
                    int seachByHostel[] = {1, 2};
                    int searchType = userIntPut(seachByHostel, 2);

                    if (searchType == 1)
                        lumunManagment.hostels->queryFreeRooms('M', 0);
                    else if (searchType == 2)
                        lumunManagment.hostels->queryFreeRooms('F', 0);
                }
                else if (queryType == 2)
                {
                    cout << "Search By Room Type: \n";
                    cout << "1. Single Occupancy\n";
                    cout << "2. Double Occupancy\n";
                    int seachByRoomType[] = {1, 2};
                    int searchType = userIntPut(seachByRoomType, 2);

                    if (searchType == 1)
                    {
                        lumunManagment.hostels->queryFreeRooms('B', 1);
                    }
                    else if (searchType == 2)
                    {
                        lumunManagment.hostels->queryFreeRooms('B', 2);
                    }
                }
            }
            break;
        case 2:
            // Reserve Room
            {
                string reservationQuery;
                cout << "Reserve Room: \n";
                cout << "1. Male\n";
                cout << "2. Female\n";
                int reserveByHostel[] = {1, 2};
                int searchType = userIntPut(reserveByHostel, 2);
                if (searchType == 1)
                {
                    // double only
                    reservationQuery = "M2";
                    lumunManagment.reserveRoom(reservationQuery);
                }
                else if (searchType == 2)
                {
                    // single or double
                    cout << "1. Single Occupancy\n";
                    cout << "2. Double Occupancy\n";
                    int reserveByRoomType[] = {1, 2};
                    int searchType = userIntPut(reserveByRoomType, 2);

                    if (searchType == 1)
                    {
                        reservationQuery = "F1";
                        lumunManagment.reserveRoom(reservationQuery);
                    }
                    else if (searchType == 2)
                    {
                        reservationQuery = "F2";
                        lumunManagment.reserveRoom(reservationQuery);
                    }
                }
            }
            break;
        case 3:
            // Check out
            lumunManagment.checkOut();
            break;
        case 4:
            // Cancel Reservation
            lumunManagment.cancelReservation();
            break;
        case 5:
            // Back to menu
            return;
        default:
            cout << "\033[1;31m"
                 << "Invalid choice"
                 << "\033[0m" << endl;
            break;
        }
    }
}

int LumsHostelManagementSystem()
{

    // for the time being we have only two hostels - and the system is designed around that
    LUMUNManagment lumunManagment(1, 1);

    // main menu
    int choice;
    while (true)
    {
        cout << "1. Room Reservation (Delegates Operations)" << endl;
        cout << "2. Administrative Operations" << endl;
        cout << "3. Quit" << endl;
        cout << "Choice: ";
        int choices[] = {1, 2, 3};
        choice = userIntPut(choices, 3);

        switch (choice)
        {
        case 1:
            // delegates operations
            DelegateMenu(lumunManagment);
            break;
        case 2:
            // admin operations
            // print "admin operations are yet to be implemented" in red color
            cout << "\033[1;31m"
                 << "Admin operations are yet to be implemented"
                 << "\033[0m" << endl;

            break;
        case 3:
            // quit
            return 0;
        default:
            // print "Invalid choice" in red
            cout << "\033[1;31m"
                 << "Invalid choice"
                 << "\033[0m" << endl;
            break;
        }
    }
}

int main() { return LumsHostelManagementSystem(); }