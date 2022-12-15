#include <iostream>
using namespace std;

struct Person
{
    string name = "", cnic = "", contact = "";
};

class Booking
{
public:
    string booking_date;
    string Booking_start;
    string booking_end;
    int num_days;
    string booking_hostel;
    int room_num;
    string type_occup;
    Person info;

    Booking()
    {
        booking_date = "01/01/2023";
        Booking_start = "01/01/2023";
        booking_end = "08/01/2023";
        num_days = 8;
        booking_hostel = "";
        room_num = 0;
        type_occup = "";
        info.cnic = "";
        info.name = "";
        info.contact = "";
    }
};

class Accomodation
{
public:
    string location;
    string type;
    int total_rooms;
    int num_delegates;
    int occupied_rooms;
    Booking recent_booking;
    Accomodation() {}
};

class MaleHostel : public Accomodation
{
public:
    int available_rooms[40]; // 1-> occupied, 0-> available
    int male_occupied_rooms = 0;
    int male_room_slots = 0; // tracks the current cap of a double occupancy room
    Booking male_double_booking[40][2];

    Booking male_waiting_list[5];
    int male_waiting_list_size = 0;

    MaleHostel()
    {
        location = "male";
        type = "double";
        total_rooms = 40;
        num_delegates = 0;
        for (int i = 0; i < 40; i++)
        {
            available_rooms[i] = 0;
        }
    }

};

class FemaleHostel : public Accomodation
{
public:
    int female_room_slots = 0;

    int available_single_rooms[15]; // 1-> occupied, 0-> available
    int available_double_rooms[15]; // 2-> occupied, 1-> 1 delegate,  0 -> empty
    int single_occupied_rooms = 0;
    int double_occupied_rooms = 0;

    // Booking *female_booking;
    Booking *female_single_booking;

    Booking female_double_booking[15][2];

    Booking female_waiting_list[5];
    int female_waiting_list_size = 0;

    FemaleHostel()
    {
        location = "female";
        type = "single";
        total_rooms = 30;
        num_delegates = 0;
        occupied_rooms = 0;
        female_single_booking = NULL;
        for (int i = 0; i < 15; i++)
        {
            available_single_rooms[i] = 0;
            available_double_rooms[i] = 0;
        }
    }

    void increaseFemaleSingleBookingSize()
    {

        available_single_rooms[single_occupied_rooms] = 1;
        single_occupied_rooms += 1;
        num_delegates += 1;

        if (single_occupied_rooms == 1)
        {
            female_single_booking = new Booking[single_occupied_rooms];
            return;
        }

        Booking *new_booking = new Booking[single_occupied_rooms];
        for (int i = 0; i < single_occupied_rooms - 1; i++)
        {
            new_booking[i] = female_single_booking[i];
        }

        // Deleting the old booking array
        delete[] female_single_booking;

        // Copying the new array into male_booking
        female_single_booking = new_booking;
    }
};

class Delegates : public MaleHostel, public FemaleHostel
{
public:
    void query();
    void reserve();
    void checkOut();
    void cancel();
};

void Delegates ::query()
{
    cout << "On which factor you want to search by?" << endl;
    cout << "1. Hostels (male/female)" << endl;
    cout << "2. Accomodation type (single, double)" << endl;
    int opt;
    cin >> opt;
    if (opt == 1)
    {
        cout << "List of available rooms in Male hostels\n";
        for (int i = 0; i < 40; i++)
        {
            if (available_rooms[i] == 0)
            {
                cout << "Room No." << i + 1 << endl;
            }
        }
        cout << endl;

        cout << "\nList of available rooms in Female hostels\n";
        for (int i = 0; i < 15; i++)
        {
            if (available_double_rooms[i] == 0)
            {
                cout << "Room No." << i + 1 << endl;
            }
        }
        for (int i = 0; i < 15; i++)
        {
            if (available_single_rooms[i] == 0)
            {
                cout << "Room No." << i + 16 << endl;
            }
        }
        cout << endl;
    }
    else if (opt == 2)
    {
        cout << "List of available rooms in double Occupancy in Male Hostel\n";
        for (int i = 0; i < 40; i++)
        {
            if (available_rooms[i] == 0)
            {
                cout << "Room No." << i + 1 << endl;
            }
        }
        cout << endl;

        cout << "List of available rooms in Double Occupancy in Female Hostel\n";
        for (int i = 0; i < 15; i++)
        {
            if (available_single_rooms[i] == 0)
            {
                cout << "Room No." << i + 1 << endl;
            }
        }

        cout << "List of available rooms in Single Occupancy in Female Hostel\n";
        for (int i = 0; i < 15; i++)
        {
            if (available_double_rooms[i] == 0)
            {
                cout << "Room No." << i + 16 << endl;
            }
        }
        cout << endl;
    }
}

void Delegates ::reserve()
{
    cout << "What do you want to reserve?" << endl;
    cout << "1. Room in a Male Hostel" << endl;
    cout << "2. Room in a Female Hostel" << endl;
    int opt;
    cin >> opt;
    if (opt == 1)
    {
        if (male_waiting_list_size > 4 && male_occupied_rooms > 40)
        {
            cout << "All rooms are reserved and waiting List is also full. Your request cannot be entertained\n";
        }
        else if (male_waiting_list_size < 4 && male_occupied_rooms >= 40)
        {
            cout << "Enter booking details" << endl;
            cout << "Enter date of booking(dd/mm/yy): ";
            cin >> male_waiting_list[male_waiting_list_size].booking_date;

            cout << "Enter date of start of occupancy(dd/mm/yy): ";
            cin >> male_waiting_list[male_waiting_list_size].Booking_start;

            cout << "Enter date of end of occupancy(dd/mm/yy): ";
            cin >> male_waiting_list[male_waiting_list_size].booking_end;

            cout << "Enter number of days booked: ";
            cin >> male_waiting_list[male_waiting_list_size].num_days;

            male_waiting_list[male_waiting_list_size].room_num = male_waiting_list_size + 1;
            male_waiting_list[male_waiting_list_size].booking_hostel = "male";
            male_waiting_list[male_waiting_list_size].type_occup = "double";

            cout << endl
                 << "Peronal information of customer" << endl;

            cout << "Name: ";
            cin >> male_waiting_list[male_waiting_list_size].info.name;

            cout << "CNIC: ";
            cin >> male_waiting_list[male_waiting_list_size].info.cnic;

            cout << "Phone: ";
            cin >> male_waiting_list[male_waiting_list_size].info.contact;

            cout << "All Rooms are reserved so your request will be placed in the waiting list\n";
            male_waiting_list_size++;

            return;
        }
        else
        {
            cout << "Enter booking details" << endl;
            cout << "Enter date of booking(dd/mm/yy): ";
            cin >> male_double_booking[male_occupied_rooms][male_room_slots].booking_date;

            cout << "Enter date of start of occupancy(dd/mm/yy): ";
            cin >> male_double_booking[male_occupied_rooms][male_room_slots].Booking_start;

            cout << "Enter date of end of occupancy(dd/mm/yy): ";
            cin >> male_double_booking[male_occupied_rooms][male_room_slots].booking_end;

            cout << "Enter number of days booked: ";
            cin >> male_double_booking[male_occupied_rooms][male_room_slots].num_days;

            male_double_booking[male_occupied_rooms][male_room_slots].room_num = male_occupied_rooms + 1;
            male_double_booking[male_occupied_rooms][male_room_slots].booking_hostel = "male";
            male_double_booking[male_occupied_rooms][male_room_slots].type_occup = "double";

            cout << endl
                 << "Peronal information of customer" << endl;

            cout << "Name: ";
            cin >> male_double_booking[male_occupied_rooms][male_room_slots].info.name;

            cout << "CNIC: ";
            cin >> male_double_booking[male_occupied_rooms][male_room_slots].info.cnic;

            cout << "Phone: ";
            cin >> male_double_booking[male_occupied_rooms][male_room_slots].info.contact;

            MaleHostel::recent_booking = male_double_booking[male_occupied_rooms][male_room_slots];
            male_room_slots += 1;
            MaleHostel::num_delegates += 1;

            if (male_room_slots == 2)
            {
                available_rooms[male_occupied_rooms] = 1;
                // cout<<"\nCheck: available_double_rooms "<<male_occupied_rooms << " is "<<available_double_rooms[male_occupied_rooms]<<endl;
                male_occupied_rooms += 1;
                male_room_slots = 0;
            }
        }
    }
    else if (opt == 2)
    {
        if (double_occupied_rooms < 15)
        {
            cout << "Enter booking details" << endl;
            cout << "Enter date of booking(dd/mm/yy): ";
            cin >> female_double_booking[double_occupied_rooms][female_room_slots].booking_date;

            cout << "Enter date of start of occupancy(dd/mm/yy): ";
            cin >> female_double_booking[double_occupied_rooms][female_room_slots].Booking_start;

            cout << "Enter date of end of occupancy(dd/mm/yy): ";
            cin >> female_double_booking[double_occupied_rooms][female_room_slots].booking_end;

            cout << "Enter number of days booked: ";
            cin >> female_double_booking[double_occupied_rooms][female_room_slots].num_days;

            female_double_booking[double_occupied_rooms][female_room_slots].room_num = double_occupied_rooms + 1;
            female_double_booking[double_occupied_rooms][female_room_slots].booking_hostel = "female";
            female_double_booking[double_occupied_rooms][female_room_slots].type_occup = "double";

            cout << endl
                 << "Peronal information of customer" << endl;

            cout << "Name: ";
            cin >> female_double_booking[double_occupied_rooms][female_room_slots].info.name;

            cout << "CNIC: ";
            cin >> female_double_booking[double_occupied_rooms][female_room_slots].info.cnic;

            cout << "Phone: ";
            cin >> female_double_booking[double_occupied_rooms][female_room_slots].info.contact;

            MaleHostel::recent_booking = female_double_booking[double_occupied_rooms][female_room_slots];
            female_room_slots += 1;
            FemaleHostel::num_delegates += 1;

            if (female_room_slots == 2)
            {
                available_double_rooms[double_occupied_rooms] = 1;
                // cout<<"\nCheck: available_double_rooms "<<double_occupied_rooms << " is "<<available_double_rooms[double_occupied_rooms]<<endl;
                double_occupied_rooms += 1;
                female_room_slots = 0;
            }
        }
        else if (single_occupied_rooms < 15)
        {
            increaseFemaleSingleBookingSize();

            cout << "Enter booking details" << endl;
            cout << "Enter date of booking(dd/mm/yy): ";
            cin >> female_single_booking[single_occupied_rooms - 1].booking_date;

            cout << "Enter date of start of occupancy(dd/mm/yy): ";
            cin >> female_single_booking[single_occupied_rooms - 1].Booking_start;

            cout << "Enter date of end of occupancy(dd/mm/yy): ";
            cin >> female_single_booking[single_occupied_rooms - 1].booking_end;

            cout << "Enter number of days booked: ";
            cin >> female_single_booking[single_occupied_rooms - 1].num_days;

            female_single_booking[single_occupied_rooms - 1].room_num = 15 + single_occupied_rooms;
            female_single_booking[single_occupied_rooms - 1].booking_hostel = "female";
            female_single_booking[single_occupied_rooms - 1].type_occup = "single";

            cout << endl
                 << "Peronal information of customer" << endl;

            cout << "Name: ";
            cin >> female_single_booking[single_occupied_rooms - 1].info.name;

            cout << "CNIC: ";
            cin >> female_single_booking[single_occupied_rooms - 1].info.cnic;

            cout << "Phone: ";
            cin >> female_single_booking[single_occupied_rooms - 1].info.contact;
            MaleHostel::recent_booking = female_single_booking[single_occupied_rooms - 1];
        }
        else if (female_waiting_list_size < 4)
        {
            cout << "Enter booking details" << endl;
            cout << "Enter date of booking(dd/mm/yy): ";
            cin >> female_waiting_list[female_waiting_list_size].booking_date;

            cout << "Enter date of start of occupancy(dd/mm/yy): ";
            cin >> female_waiting_list[female_waiting_list_size].Booking_start;

            cout << "Enter date of end of occupancy(dd/mm/yy): ";
            cin >> female_waiting_list[female_waiting_list_size].booking_end;

            cout << "Enter number of days booked: ";
            cin >> female_waiting_list[female_waiting_list_size].num_days;

            female_waiting_list[female_waiting_list_size].room_num = female_waiting_list_size + 1;
            female_waiting_list[female_waiting_list_size].booking_hostel = "female";
            female_waiting_list[female_waiting_list_size].type_occup = "double";

            cout << endl
                 << "Peronal information of customer" << endl;

            cout << "Name: ";
            cin >> female_waiting_list[female_waiting_list_size].info.name;

            cout << "CNIC: ";
            cin >> female_waiting_list[female_waiting_list_size].info.cnic;

            cout << "Phone: ";
            cin >> female_waiting_list[female_waiting_list_size].info.contact;

            cout << "All Rooms are reserved so your request will be placed in the waiting list\n";
            female_waiting_list_size++;

            return;
        }
        else
        {
            cout << "All rooms are reserved and waiting List is also full. Your request cannot be entertained\n";
        }
    }
}
void Delegates ::checkOut()
{
    cout << "\n====================================== " << endl;
    cout << "                CHECKOUT              " << endl;
    cout << "====================================== " << endl;

    cout << " Booking Details \n";
    cout << "Booking Date: " << MaleHostel::recent_booking.booking_date << endl;
    cout << "Start Date of booking: " << MaleHostel::recent_booking.Booking_start << endl;
    cout << "End Date of booking: " << MaleHostel::recent_booking.booking_end << endl;
    cout << "Number of Days: " << MaleHostel::recent_booking.num_days << endl;
    cout << "Hostel Type: " << MaleHostel::recent_booking.booking_hostel << endl;
    cout << "Room Number: " << MaleHostel::recent_booking.room_num << endl;
    cout << "Occupancy Type: " << MaleHostel::recent_booking.type_occup << endl;
    cout << "Name: " << MaleHostel::recent_booking.info.name << endl;
    cout << "CNIC: " << MaleHostel::recent_booking.info.cnic << endl;
    cout << "Contact: " << MaleHostel::recent_booking.info.contact << endl;

    cout << "You total bill is: ";
    if (MaleHostel::recent_booking.booking_hostel == "male")
    {
        int bill = 1000 * MaleHostel::recent_booking.num_days;
        cout << bill << " PKR\n";
        cout << "ThankYou!\n";
    }

    else if (MaleHostel::recent_booking.booking_hostel == "female" && MaleHostel::recent_booking.type_occup == "double")
    {
        int bill = 1000 * MaleHostel::recent_booking.num_days;
        cout << bill << " PKR\n";
        cout << "ThankYou!\n";
    }
    else
    {
        int bill = 1000 * MaleHostel::recent_booking.num_days;
        cout << bill << " PKR\n";
        cout << "ThankYou!\n";
    }
}
void Delegates ::cancel()
{
    string name, type;
    cout << "Enter Name\n";
    cin >> name;

    cout << "Enter Hostel Type(male/female)" << endl;
    cin >> type;

    if (type == "male")
    {

        if (male_waiting_list_size >= 0)
        {
            Booking data = male_waiting_list[male_waiting_list_size];
            male_waiting_list_size--;

            for (int i = 0; i < male_occupied_rooms; i++)
            {
                for (int k = 0; k < 2; k++)
                {
                    if (male_double_booking[i][k].info.name == name)
                    {
                        data = male_double_booking[i][k];
                        available_rooms[i] = 0;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < male_occupied_rooms; i++)
            {
                for (int k = 0; k < 2; k++)
                {
                    if (male_double_booking[i][k].info.name == name)
                    {
                        available_rooms[i] = 0;
                    }
                }
            }
        }
    }
    else
    {

        int found_index=0 ;
        int found_slot=0 ;
        // first search in the double occupancy rooms
        for (int i = 0; i < double_occupied_rooms; i++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (female_double_booking[i][k].info.name == name)
                {
                    found_index=i ;
                    found_slot=k ;
                }
            }
        }

        if (female_waiting_list_size > 0)
        {
            Booking data = female_waiting_list[female_waiting_list_size];
            female_waiting_list_size--;
            female_double_booking[found_index][found_slot] = data ;
            return ;
        }
        else {
            available_double_rooms[found_index] = 0 ;
            return ;
        }

        // Search in Single occupancy rooms
        for (int i = 0; i < single_occupied_rooms; i++)
        {
            if (female_single_booking[i].info.name == name)
            {
                found_index=i ;
            }
        }

        if (female_waiting_list_size > 0)
        {
            Booking data = female_waiting_list[female_waiting_list_size];
            female_waiting_list_size--;
            female_single_booking[found_index] = data ;
            return ;
        }
        else {
            available_single_rooms[found_index] = 0 ;
            return ;
        }
        
    }
}

int main()
{
    Delegates delegate;

    while (true)
    {
        cout << "1. Delegates Operations" << endl;
        cout << "2. Administrative Operations" << endl;
        cout << "3. Quit" << endl;
        int n;
        cin >> n;
        if (n == 1)
        {
            while (true)
            {
                cout << "1. Query " << endl;
                cout << "2. Reserve " << endl;
                cout << "3. Check out" << endl;
                cout << "4. Cancel reservation" << endl;
                cout << "5. Back to menu" << endl;
                int s;
                cin >> s;

                if (s == 1)
                    delegate.query();
                else if (s == 2)
                    delegate.reserve();
                else if (s == 3)
                    delegate.checkOut();
                else if (s == 4)
                    delegate.cancel();
                else if (s == 5)
                    break;
                else
                    cout << "Wrong Option. Please select a correct option\n ";
            }
        }
        else if (n == 2)
        {
            while (true)
            {
                cout << "1. Check Occupancies Status " << endl;
                cout << "2. Check Reserved Occupancies " << endl;
                cout << "3. Check Wailisted bookings" << endl;
                cout << "4. Check Income" << endl;
                cout << "5. Back to menu" << endl;
                int s;
                cin >> s;
                // if(s == 1)
                //     // emptyOccupancies();
                // else if(s == 2)
                //     // reservedOccupancies();
                // else if(s == 3)
                //     // waitingListInfo();
                // else if(s == 4)
                //     // generateIncome();
                // else
                //     break;
            }
        }
        else if (n == 3)
        {
            exit(1);
        }
    }
}