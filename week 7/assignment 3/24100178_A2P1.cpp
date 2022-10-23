#include <iostream>
using namespace std;

// forward declaration of all classes
class PokeType;
class Pokemon;
class Trainer;

// implement a pokemon turn based RPG game
// implement a PokeType class
class PokeType
{
private:
    char type;
    int base_speed;
    int base_attack;
    int base_hp;

public:
    PokeType(char type)
    {
        if (type == 'f')
        {
            base_speed = 10;
            base_attack = 15;
            base_hp = 65;
        }
        else if (type == 'w')
        {
            base_speed = 5;
            base_attack = 20;
            base_hp = 100;
        }
        else if (type == 'g')
        {
            base_speed = 2;
            base_attack = 25;
            base_hp = 50;
        }
        else
        {
            string errorMessage = "Invalid Pokemon type";
            __throw_invalid_argument(errorMessage.c_str());
        }
    }
    friend class Pokemon;
};

// implement a Pokemon class
class Pokemon
{
private:
    string name;
    PokeType *type;
    Trainer *trainer;
    int level;
    int current_hp;
    int current_speed;
    int current_attack;
    int xp;

public:
    // default constructor
    Pokemon()
    {
        name = "NoName";
        type = NULL;
        trainer = NULL;
        level = 1;
        current_hp = 0;
        current_speed = 0;
        current_attack = 0;
        xp = 0;
    }
    Pokemon(string name, char type, int level)
    {
        this->name = name;
        this->type = new PokeType(type);
        if (level > 0)
        {
            this->level = level;
        }
        else
        {
            string errorMessage = "Invalid Pokemon level";
            __throw_invalid_argument(errorMessage.c_str());
        }
        // trainer = NULL;
        this->current_hp = this->level == 1 ? this->type->base_hp : (this->type->base_hp) * (1 + ((this->level - 1) * 0.10));
        this->current_attack = this->level == 1 ? this->type->base_attack : (this->type->base_attack) * (1 + ((this->level - 1) * 0.05));
        this->current_speed = this->type->base_speed;
        this->xp = 0;
    }
    // copy constructor
    Pokemon(const Pokemon &p)
    {
        this->name = p.name;
        this->type = p.type;
        this->trainer = p.trainer;
        this->level = p.level;
        this->current_hp = p.current_hp;
        this->current_speed = p.current_speed;
        this->current_attack = p.current_attack;
        this->xp = p.xp;
        cout << "Pokemon " << this->name << " is copied" << endl;
    }
    void operator++(int postfix)
    {
        this->level++;
        this->current_hp = this->type->base_hp * (1 + ((this->level - 1) * 0.10));
        this->current_attack = this->type->base_attack * (1 + ((this->level - 1) * 0.05));
    }
    string getName()
    {
        return this->name;
    }
    int getLevel()
    {
        return this->level;
    }
    void DisplayPokemon()
    {
        cout << "Name: " << this->name << endl;
        cout << "Level: " << this->level << endl;
        cout << "Type: " << this->type->type << endl;
        cout << "HP: " << this->current_hp << endl;
        cout << "Attack: " << this->current_attack << endl;
        cout << "Speed: " << this->current_speed << endl;
        cout << "XP: " << this->xp << endl;
    }
};

// implment a Trainer class
class Trainer
{
private:
    string name;
    int num_pokemon;
    Pokemon *pokemon_owned;
    int current_party_size;
    Pokemon *current_party[6];

public:
    // parameterized constructor
    Trainer(string name)
    {
        num_pokemon = 0;
        this->name = name;
        pokemon_owned = NULL;
        for (int i = 0; i < 6; i++)
        {
            current_party[i] = NULL;
        }
    }
    void AddPokemon(Pokemon &pokemon)
    {
        // check if pokemon_owned is NULL
        if (num_pokemon == 0)
        {
            num_pokemon += 1;
            pokemon_owned = new Pokemon[num_pokemon];
            pokemon_owned[0] = pokemon;
        }
        else
        {
            num_pokemon += 1;
            Pokemon *temp = new Pokemon[num_pokemon];
            for (int i = 0; i < num_pokemon - 1; i++)
            {
                temp[i] = pokemon_owned[i];
            }
            temp[num_pokemon - 1] = pokemon;
            delete[] pokemon_owned;
            pokemon_owned = temp;
        }
    }
    void DisplayPokemon()
    {
        cout << this->name << "'s Pokemon:" << endl;
        for (int i = 0; i < num_pokemon; i++)
        {
            cout << pokemon_owned[i].getName() << " --- " << pokemon_owned[i].getLevel() << endl;
        }
        cout << endl
             << endl;
    }
    friend ostream &operator<<(ostream &out, const Trainer &trainer)
    {
        out << trainer.name << "'s Pokemon:" << endl;
        for (int i = 0; i < trainer.num_pokemon; i++)
        {
            out << trainer.pokemon_owned[i].getName() << " --- " << trainer.pokemon_owned[i].getLevel() << endl;
        }
        out << endl
            << endl;
        return out;
    }
    void operator+(Pokemon &pokemon)
    {
        AddPokemon(pokemon);
    }
    string getName()
    {
        return this->name;
    }
};

void AddPokemonHelper(Trainer *trainer)
{
    string name;
    char type;
    int level;
    cout << "Enter the name of the Pokemon: ";
    cin >> name;
    cout << "Enter the type of the Pokemon: ";
    cin >> type;
    cout << "Enter the level of the Pokemon: ";
    cin >> level;
    Pokemon pokemon(name, type, level);
    trainer->AddPokemon(pokemon);
}

Trainer **trainerMenu(Trainer **trainers, int &num_trainers)
{
    if (num_trainers == 0)
    {
        cout << "here" << endl;
        cout << "Trainer Menu" << endl;
        cout << "No Trainers Exist, would you like to create one? (y/n) (case sensitive)" << endl;
        char choice;
        cin >> choice;
        if (choice == 'y')
        {
            cout << "Enter Trainer Name: " << endl;
            string name;
            cin >> name;

            trainers = new Trainer *[++num_trainers];
            trainers[0] = new Trainer(name);
            cout << "Trainer " << name << " created" << endl;
            return trainers;
        }
    }
    else if (num_trainers == 1)
    {
        cout << trainers[0]->getName() << "'s menu:" << endl;

        int exitVal = 3;
        int choice = 0;
        while (choice != exitVal)
        {
            cout << "1. Add Pokemon?" << endl;
            cout << "2. Display Pokemon?" << endl;
            cout << "3. Return to Main Menu?" << endl;
            cout << "Choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                AddPokemonHelper(trainers[0]);
                break;
            }
            case 2:
            {
                trainers[0]->DisplayPokemon();
                break;
            }
            case 3:
            {
                cout << "Returning to Main Menu" << endl;
                return trainers;
                break;
            }
            default:
            {
                cout << "Invalid Choice" << endl;
                break;
            }
            }
        }
    }
    else if (num_trainers > 1)
    {
        cout << "Trainer Menu" << endl;
        int exitVal = num_trainers + 2;
        for (int i = 0; i < num_trainers; i++)
        {
            cout << i + 1 << ". " << trainers[i]->getName() << endl;
        }
        cout << exitVal - 1 << ". Add New Trainer" << endl;
        cout << exitVal << ". Return to Main Menu" << endl;
        // select a trainer
        int choice = 0;
        while (choice != exitVal)
        {
            cout << "Choice: ";
            cin >> choice;
            if (choice == exitVal)
            {
                cout << "Returning to Main Menu" << endl;
                return trainers;
            }
            else if (choice == exitVal - 1)
            {
                cout << "Enter Trainer Name: " << endl;
                string name;
                cin >> name;

                Trainer **temp = new Trainer *[++num_trainers];
                for (int i = 0; i < num_trainers - 1; i++)
                {
                    temp[i] = trainers[i];
                }
                temp[num_trainers - 1] = new Trainer(name);

                delete[] trainers;
                trainers = temp;
                
                cout << "Trainer " << name << " created" << endl;
                return trainers;
            }
            else if (choice >= 1 && choice <= num_trainers)
            {
                Trainer *currentTrainer = trainers[choice - 1];
                cout << currentTrainer->getName() << "'s menu:" << endl;
                int exitVal = 3;
                int choice = 0;
                while (choice != exitVal)
                {
                    cout << "1. Add Pokemon?" << endl;
                    cout << "2. Display Pokemon?" << endl;
                    cout << "3. Return to Main Menu?" << endl;
                    cout << "Choice: ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                    {
                        AddPokemonHelper(currentTrainer);
                        break;
                    }
                    case 2:
                    {
                        currentTrainer->DisplayPokemon();
                        break;
                    }
                    case 3:
                    {
                        cout << "Returning to Main Menu" << endl;
                        return trainers;
                        break;
                    }
                    default:
                    {
                        cout << "Invalid Choice" << endl;
                        break;
                    }
                    }
                }
            }
            else
            {
                cout << "Invalid Choice" << endl;
            }
        }
    }
    return trainers;
}

void game()
{
    Trainer **trainers = new Trainer *[3];
    Trainer ash("Ash");
    Trainer misty("Misty");
    Trainer brock("Brock");
    trainers[0] = &ash;
    trainers[1] = &misty;
    trainers[2] = &brock;

    int num_trainers = 3;

    const int exitVal = 2;
    int choice = 0;
    while (choice != exitVal)
    {
        cout << "1. Trainer Menu?" << endl;
        cout << "2. Exit" << endl;

        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            trainers = trainerMenu(trainers, num_trainers);
        }
        else if (choice == exitVal)
        {
            cout << "Exiting..." << endl;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
}

int main()
{

    game();

    return 0;
}