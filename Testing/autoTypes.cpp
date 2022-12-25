#include <iostream>
using namespace std;

// i have two questions regarding the Auto type
//  one is that can functions just return autos, and this can become like javascript?

// lets check
struct actor
{
    int id;
    string name;
    string email;

    actor(int id, string name, string email) : id(id), name(name), email(email){};
};

struct User : actor
{
    // nothing safe
    User(int id, string name, string email) : actor(id, name, email){};
};

struct Admin : actor
{
    int safeNumber;
    Admin(int id, string name, string email, int safeNumber) : actor(id, name, email), safeNumber(safeNumber){};
};

// auto getActor(int safety = 0)
// {
//     if(safety == 0)
//     {
//         return User();
//     }
//     else
//     {
//         return Admin();
//     }
// }
// this is not allowed, but meh.

actor* getActorData(int safety = 0)
{
    if (safety == 0)
    {
        return new User(1, "user", "admin@gmail.com");
    }
    else
    {
        return new Admin(100, "admin", "admin@admin.com",3);
    }
}

int main()
{
    cout << getActorData() << endl;
    return 0;
}