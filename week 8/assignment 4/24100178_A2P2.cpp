const int DEBUG = 1;

#include <iostream>
using namespace std;

const int MATCH_WIN_XP = 15;
const int MATCH_LOSE_XP = 4;
const int MATCH_DRAW_XP = 5;
const int BATTLE_WIN_XP = 5;
const int BATTLE_LOSE_XP = -2;
const int BATTLE_DRAW_XP = 2;

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
        if (type == 'f' || type == 'F')
        {
            this->type = 'f';
            base_speed = 10;
            base_attack = 15;
            base_hp = 65;
        }
        else if (type == 'w' || type == 'W')
        {
            this->type = 'w';
            base_speed = 5;
            base_attack = 20;
            base_hp = 100;
        }
        else if (type == 'g' || type == 'G')
        {
            this->type = 'g';
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
    int total_hp;
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
        total_hp = 0;
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
        this->total_hp = this->current_hp;
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
        this->total_hp = this->type->base_hp * (1 + ((this->level - 1) * 0.10));
        this->current_hp = this->total_hp;
        this->total_hp = this->type->base_hp * (1 + ((this->level - 1) * 0.10));
        this->current_attack = this->type->base_attack * (1 + ((this->level - 1) * 0.05));
    }
    string getName()
    {
        return this->name;
    }
    int getCurrentSpeed()
    {
        return this->current_speed;
    }
    int getCurrentHp()
    {
        return this->current_hp;
    }
    int getLevel()
    {
        return this->level;
    }
    int getTotalHP()
    {
        return this->total_hp;
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
        cout << endl;
    }

    // leveler
    void levelUp()
    {
        int levelUpXp = this->level * this->type->base_attack * this->type->base_speed;
        if (this->xp >= levelUpXp)
        {
            this->xp -= levelUpXp;
            (*this)++;
            cout << this->name << " has leveled up to level " << this->level << endl;
        }
    }

    // actions
    void attack(Pokemon *opponent)
    {
        opponent->current_hp -= this->current_attack;
        cout << this->name << " attacks " << opponent->name << " for " << this->current_attack << " damage" << endl;

        if (opponent->current_hp <= 0)
        {
            opponent->current_hp = 0;
            cout << this->name << " has defeated " << opponent->name << endl;
            this->xp += BATTLE_WIN_XP * this->level * opponent->level;
            this->levelUp();
            cout << this->name << " has gained " << BATTLE_WIN_XP << " XP" << endl;
        }
    }

    friend void battleMenu(Trainer **trainers, int &num_trainers);
    friend Pokemon *selectPokemon(Trainer *trainer);
    friend struct Team;
};
// implment a Trainer class
class Trainer
{
private:
    string name;               // trainer name
    int num_pokemon;           // number of owned pokemon excluding the pokemon in the party
    Pokemon **pokemon_owned;   // array of pointers to pokemon
    int current_party_size;    // number of pokemon in the party
    Pokemon *current_party[6]; // array of pointers to pokemon in the party
public:
    // parameterized constructor
    Trainer(string name)
    {
        num_pokemon = 0;
        current_party_size = 0;
        this->name = name;
        pokemon_owned = NULL;
        for (int i = 0; i < 6; i++)
        {
            current_party[i] = NULL;
        }
    }
    void AddPokemon(string name, char type, int level)
    {
        // check if pokemon_owned is NULL
        if (num_pokemon == 0)
        {
            num_pokemon += 1;
            pokemon_owned = new Pokemon *[num_pokemon];
            pokemon_owned[0] = new Pokemon(name, type, level);
        }
        else
        {
            num_pokemon += 1;
            Pokemon **temp = new Pokemon *[num_pokemon];
            for (int i = 0; i < num_pokemon - 1; i++)
            {
                temp[i] = pokemon_owned[i];
            }
            temp[num_pokemon - 1] = new Pokemon(name, type, level);
            delete[] pokemon_owned;
            pokemon_owned = temp;
        }
    }
    void AddPokemon(Pokemon *pokemon)
    {
        // check if pokemon_owned is NULL
        if (num_pokemon == 0)
        {
            num_pokemon += 1;
            pokemon_owned = new Pokemon *[num_pokemon];
            pokemon_owned[0] = pokemon;
        }
        else
        {
            num_pokemon += 1;
            Pokemon **temp = new Pokemon *[num_pokemon];
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
            cout << i + 1 << ". " << pokemon_owned[i]->getName() << " --- " << pokemon_owned[i]->getLevel() << endl;
            pokemon_owned[i]->DisplayPokemon();
        }
        cout << endl
             << endl;
    }
    void DisplayParty()
    {
        // display the current party list
        cout << this->name << "'s Party:" << endl;
        for (int i = 0; i < 6; i++)
        {
            if (current_party[i] != NULL)
            {
                cout << current_party[i]->getName() << "\t Level: " << current_party[i]->getLevel() << "\t Total HP: " << current_party[i]->getTotalHP() << endl;
            }
        }
    }
    void TransferPokemonFromOwnedToParty(int PokeOwnedIndex)
    {
        // check if the current party is full
        if (current_party_size == 6)
        {
            cout << "The current party is full" << endl;
            return;
        }

        if (PokeOwnedIndex > num_pokemon)
        {
            cout << "Invalid Pokemon Owned Index" << endl;
            return;
        }

        // check if the pokemon is already in the party
        for (int i = 0; i < 6; i++)
        {
            if (current_party[i] == pokemon_owned[PokeOwnedIndex])
            {
                cout << "The pokemon is already in the party" << endl;
                return;
            }
        }

        // add the pokemon to the party
        current_party[current_party_size] = pokemon_owned[PokeOwnedIndex];
        (*this) - current_party[current_party_size];
        current_party_size++;
    }
    void TransferPokemonFromPartyToOwned(int PokePartyIndex)
    {
        // check if the pokemon is in the party
        if (current_party[PokePartyIndex] == NULL)
        {
            cout << "The pokemon is not in the party" << endl;
            return;
        }

        // check if the pokemon is already in the owned list
        for (int i = 0; i < num_pokemon; i++)
        {
            if (pokemon_owned[i] == current_party[PokePartyIndex])
            {
                cout << "The pokemon is already in the owned list" << endl;
                return;
            }
        }

        // add the pokemon to the owned list
        AddPokemon(current_party[PokePartyIndex]);
        current_party[PokePartyIndex] = NULL;
        current_party_size--;
    }
    friend ostream &operator<<(ostream &out, const Trainer &trainer)
    {
        out << trainer.name << "'s Pokemon:" << endl;
        for (int i = 0; i < trainer.num_pokemon; i++)
        {
            out << trainer.pokemon_owned[i]->getName() << " --- " << trainer.pokemon_owned[i]->getLevel() << endl;
        }
        out << endl
            << endl;
        return out;
    }
    void operator+(Pokemon *pokemon)
    {
        // all the pokemons will be dynamically allocated, and the system has been setup as such
        // hence, the copy constuctor and assignment operator need to be air tight

        AddPokemon(pokemon);
    }
    void operator-(Pokemon *pokemon)
    {
        // all the pokemons will be dynamically allocated, and the system has been setup as such
        // hence, the copy constuctor and assignment operator need to be air tight

        // check if the pokemon is in the owned list
        for (int i = 0; i < num_pokemon; i++)
        {
            if (pokemon_owned[i] == pokemon)
            {
                // delete the pokemon from the owned list
                Pokemon **temp = new Pokemon *[num_pokemon - 1];
                for (int j = 0; j < i; j++)
                {
                    temp[j] = pokemon_owned[j];
                }
                for (int j = i; j < num_pokemon - 1; j++)
                {
                    temp[j] = pokemon_owned[j + 1];
                }
                delete[] pokemon_owned;
                pokemon_owned = temp;
                num_pokemon--;
                return;
            }
        }
        cout << "The pokemon is not in the owned list" << endl;
    }
    string getName()
    {
        return this->name;
    }
    int getNumPokemon()
    {
        return this->num_pokemon;
    }
    friend Trainer *partyManagement(Trainer *trainer);
    friend void battleMenu(Trainer **trainers, int &num_trainers);
    friend Trainer *selectTrainer(Trainer **trainers, int &num_trainers);
    friend Pokemon *selectPokemon(Trainer *trainer);

    friend struct Team;
};

struct Team
{

    Trainer *trainer;
    Pokemon *current_Pokemon;
    int alive_pokemon;
    int move;
    bool forfeit;

    Team(Trainer *trainer)
    {
        this->trainer = trainer;
        this->current_Pokemon = nullptr;
        this->move = 0;
        this->forfeit = false;
        for (int i = 0; i < trainer->current_party_size; i++)
        {
            alive_pokemon++;
        }
    }

    void selectPokemon()
    {
        if (alive_pokemon == 0)
        {
            cout << "All pokemon of " << trainer->getName() << " are fainted" << endl;
            // exit the match here
            forfeit = true;
            return;
        }

        // this is a short circuit if statement -> what are those? -> this is when you have multiple conditions in an if statement and the first condition is false, the second condition is not checked
        if (current_Pokemon != nullptr && current_Pokemon->getCurrentHp() > 0)
        {
            return;
        }

        // 1. Display the Pokemon in Trainer 1’s current party.
        // 2. Ask Trainer 1 to select one Pokemon.
        string name;
        cout << trainer->getName() << "'s Battle Ready Pokemon: " << endl;
        alive_pokemon = 0;
        for (int i = 0; i < trainer->current_party_size; i++)
        {
            if (trainer->current_party[i]->current_hp > 0)
            {
                alive_pokemon++;
                cout << i + 1 << ". " << trainer->current_party[i]->getName() << endl;
            }
        }

        if (alive_pokemon == 0)
        {
            cout << "All pokemon of " << trainer->getName() << " are fainted" << endl;
            return;
        }

        cout << "Enter a pokemon name: " << endl;
        cin >> name;
        int valid = 0;
        while (true)
        {
            for (int i = 0; i < trainer->current_party_size; i++)
            {
                if (trainer->current_party[i]->getName() == name && trainer->current_party[i]->total_hp > 0)
                {
                    valid = 1;
                    current_Pokemon = trainer->current_party[i];
                    return;
                }
            }
            if (valid == 0)
            {
                cout << "Invalid pokemon, please enter again: " << endl;
                cin >> name;
            }
        }
    }
    void getMove()
    {
        cout << trainer->getName() << "'s Move: " << endl;
        while (true)
        {
            cout << "1. Attack" << endl;
            cout << "2. Switch" << endl;
            cout << "3. Forfeit" << endl;
            cout << "Choice: ";
            cin >> move;
            if (move >= 1 && move <= 3)
            {
                return;
            }
            else
            {
                cout << "Invalid Choice" << endl;
            }
        }
    }

    bool anyAlivePokemon()
    {
        for (int i = 0; i < trainer->current_party_size; i++)
        {
            if (trainer->current_party[i]->current_hp > 0)
            {
                return true;
            }
        }
        return false;
    }

    void switchPokemon()
    {
        if (alive_pokemon == 0)
        {
            cout << "All pokemon of " << trainer->getName() << " are fainted" << endl;
            return;
        }
        string name;
        cout << "Battle Ready Pokemon: " << endl;
        alive_pokemon = 0;
        for (int i = 0; i < trainer->current_party_size; i++)
        {
            if (trainer->current_party[i]->current_hp > 0)
            {
                alive_pokemon++;
                cout << i + 1 << ". " << trainer->current_party[i]->getName() << endl;
            }
        }
        if (alive_pokemon == 0)
        {
            cout << "All pokemon of " << trainer->getName() << " are fainted" << endl;
            return;
        }
        cout << "Enter a pokemon name: " << endl;
        cin >> name;
        int valid = 0;
        while (true)
        {
            for (int i = 0; i < trainer->current_party_size; i++)
            {
                if (trainer->current_party[i]->getName() == name && trainer->current_party[i]->total_hp > 0)
                {
                    valid = 1;
                    current_Pokemon = trainer->current_party[i];
                    return;
                }
            }
            if (valid == 0)
            {
                cout << "Invalid pokemon, please enter again: " << endl;
                cin >> name;
            }
        }
    }
    void endMatch()
    {
        // reset the current hp for all pokemon in the current party
        for (int i = 0; i < trainer->current_party_size; i++)
        {
            trainer->current_party[i]->current_hp = trainer->current_party[i]->total_hp;
        }
    }
    void winMatch()
    {
        // 1. Add 10 XP to the current Pokemon.
        // 2. Add 5 XP to each Pokemon in the current party.

        current_Pokemon->xp += MATCH_WIN_XP;
        // run leveler
        current_Pokemon->levelUp();

        for (int i = 0; i < trainer->current_party_size; i++)
        {
            trainer->current_party[i]->xp += MATCH_WIN_XP / 2;
            trainer->current_party[i]->levelUp();
        }
        endMatch();
    }
    void loseMatch()
    {
        // 1. Add 5 XP to the current Pokemon.
        // 2. Add 2 XP to each Pokemon in the current party.

        current_Pokemon->xp += MATCH_LOSE_XP;
        // run leveler
        current_Pokemon->levelUp();

        for (int i = 0; i < trainer->current_party_size; i++)
        {
            trainer->current_party[i]->xp += MATCH_LOSE_XP / 2;
            trainer->current_party[i]->levelUp();
        }
        endMatch();
    }
    void drawMatch()
    {
        // 1. Add 7 XP to the current Pokemon.
        // 2. Add 3 XP to each Pokemon in the current party.

        current_Pokemon->xp += MATCH_DRAW_XP;
        // run leveler
        current_Pokemon->levelUp();

        for (int i = 0; i < trainer->current_party_size; i++)
        {
            trainer->current_party[i]->xp += MATCH_DRAW_XP / 2;
            trainer->current_party[i]->levelUp();
        }
        endMatch();
    }

    friend void executeMoves(Team &team1, Team &team2);
};

void AddPokemonHelper(Trainer *trainer)
{
    string name;
    char type;
    int level;
    cout << "Enter the name of the Pokemon: ";
    cin >> name;
    while (true)
    {
        cout << "Enter the type of the Pokemon: ";
        cin >> type;
        if (type == 'f' || type == 'w' || type == 'g' || // check for upper case
            type == 'F' || type == 'W' || type == 'G')
        {
            break;
        }
        else
        {
            cout << "Invalid type, please enter again: \n";
        }
    }

    cout << "Enter the level of the Pokemon: ";
    cin >> level;

    trainer->AddPokemon(name, type, level);
}

Trainer *selectTrainer(Trainer **trainers, int &num_trainers)
{
    string name;
    for (int i = 0; i < num_trainers; i++)
    {
        cout << i + 1 << ". " << trainers[i]->getName() << endl;
    }
    cout << "Enter a trainer name: ";
    cin >> name;
    int valid = 0;
    while (true)
    {
        for (int i = 0; i < num_trainers; i++)
        {
            if (trainers[i]->getName() == name)
            {
                valid = 1;
                // check if trainer is battle ready
                if (trainers[i]->current_party_size > 0)
                {
                    valid = 2;
                    return trainers[i];
                }
            }
        }
        if (valid == 1)
        {
            cout << "Trainer is not battle ready, please enter again: \n";
            cin >> name;
        }
        if (valid == 0)
        {
            cout << "Invalid trainer name, please enter again: " << endl;
            cin >> name;
        }
    }
}
Trainer *partyManagement(Trainer *trainer)
{
    int choice;
    while (true)
    {
        cout << "Current Party Management: " << endl;
        cout << "1. View Current Party" << endl;
        cout << "2. Add Pokemon to Current Party" << endl;
        cout << "3. Remove Pokemon from Current Party" << endl;
        cout << "4. Return to Trainer Menu" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // view current party
            trainer->DisplayParty();
            break;
        case 2:

            // view pokemon owned
            for (int i = 0; i < trainer->num_pokemon; i++)
            {
                cout << i + 1 << ". " << trainer->pokemon_owned[i]->getName() << endl;
            }

            // call the transfer function
            int PokeOwnedIndex;
            cout << "Enter the index of the pokemon you want to add to the party: ";
            cin >> PokeOwnedIndex;
            PokeOwnedIndex--;
            trainer->TransferPokemonFromOwnedToParty(PokeOwnedIndex);
            break;
        case 3:
            // view current party
            for (int i = 0; i < 6; i++)
            {
                if (trainer->current_party[i] != NULL)
                {
                    cout << i + 1 << ". " << trainer->current_party[i]->getName() << endl;
                }
            }

            // call the transfer function
            int PokePartyIndex;
            cout << "Enter the index of the pokemon you want to remove from the party: ";
            cin >> PokePartyIndex;
            PokePartyIndex--;
            trainer->TransferPokemonFromPartyToOwned(PokePartyIndex);
            break;
        case 4:
            return trainer;
            break;
        default:
            break;
        }
    }
}
Trainer *trainerSubMenu(Trainer *trainer)
{
    int choice;
    while (true)
    {
        cout << trainer->getName() << "'s Menu:" << endl;
        cout << "1. Add Pokemon" << endl;
        cout << "2. Display Pokemon" << endl;
        cout << "3. Manage Current Party" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            AddPokemonHelper(trainer);
            break;
        case 2:
            trainer->DisplayPokemon();
            break;
        case 3:
            trainer = partyManagement(trainer);
            break;
        case 4:
            return trainer;
            break;
        default:
            break;
        }
    }
}
Trainer **trainerMenu(Trainer **trainers, int &num_trainers)
{

    while (true)
    {
        int choice = 0;
        int exitVal = 3;
        cout << "Trainer Menu" << endl;
        cout << "What would you like to do:" << endl;
        cout << "1. Create a trainer" << endl;
        cout << "2. Access a trainer" << endl;
        cout << "3. Exit to Main Menu" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // create a trainer
            {
                string name;
                cout << "Enter the name of the trainer: ";
                cin >> name;
                Trainer *trainer = new Trainer(name);
                // check if trainers is NULL
                if (num_trainers == 0)
                {
                    num_trainers += 1;
                    trainers = new Trainer *[num_trainers];
                    trainers[0] = trainer;
                }
                else
                {
                    num_trainers += 1;
                    Trainer **temp = new Trainer *[num_trainers];
                    for (int i = 0; i < num_trainers - 1; i++)
                    {
                        temp[i] = trainers[i];
                    }
                    temp[num_trainers - 1] = trainer;
                    delete[] trainers;
                    trainers = temp;
                }
            }
            break;

        case 2:
            // access a trainer
            {
                // check if no trainer exists, then ask to create one, if no then exit the menu
                if (num_trainers == 0)
                {
                    int createTrainer = 0;
                    cout << "No trainer exists, would you like to create one? 1: Yes, 2: No:  ";
                    cin >> createTrainer;
                    if (createTrainer == 1)
                    {
                        string name;
                        cout << "Enter the name of the trainer: ";
                        cin >> name;
                        Trainer *trainer = new Trainer(name);
                        // check if trainers is NULL
                        if (num_trainers == 0)
                        {
                            num_trainers += 1;
                            trainers = new Trainer *[num_trainers];
                            trainers[0] = trainer;
                        }
                        else
                        {
                            num_trainers += 1;
                            Trainer **temp = new Trainer *[num_trainers];
                            for (int i = 0; i < num_trainers - 1; i++)
                            {
                                temp[i] = trainers[i];
                            }
                            temp[num_trainers - 1] = trainer;
                            delete[] trainers;
                            trainers = temp;
                        }
                    }
                    else
                    {
                        break;
                    }
                }

                // print all trainers

                for (int i = 0; i < num_trainers; i++)
                {
                    cout << i + 1 << ". " << trainers[i]->getName() << endl;
                }

                string name;
                cout << "Which trainer would you like to access: ";
                cin >> name;
                for (int i = 0; i < num_trainers; i++)
                {
                    if (trainers[i]->getName() == name)
                    {
                        trainers[i] = trainerSubMenu(trainers[i]);
                        break;
                    }
                }
            }
            break;

        case 3:
            return trainers;
            break;

        default:
            break;
        }
    }

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

void executeMoves(Team &team1, Team &team2)
{
    // 7. Perform the actions.
    int moveSet = (team1.move * 10) + team2.move;
    switch (moveSet)
    {
    case 11:
        // both attack
        if (team1.current_Pokemon->getCurrentSpeed() > team2.current_Pokemon->getCurrentSpeed())
        {
            // pokemon 1 attacks first
            team1.current_Pokemon->attack(team2.current_Pokemon);
            if (team2.current_Pokemon->getCurrentHp() > 0)
            {
                team2.current_Pokemon->attack(team1.current_Pokemon);
                return;
            }
            else
            {
                cout << team2.trainer->getName() << "'s " << team2.current_Pokemon->getName() << " is dead, turn ended\n";
                return;
            }
        }
        else
        {
            // pokemon 2 attacks first
            team2.current_Pokemon->attack(team1.current_Pokemon);
            if (team1.current_Pokemon->getCurrentHp() > 0)
            {
                team1.current_Pokemon->attack(team2.current_Pokemon);
                return;
            }
            else
            {
                cout << team1.trainer->getName() << "'s " << team1.current_Pokemon->getName() << " is dead, turn ended\n";
                return;
            }
        }
        break;
    case 12:
        // trainer 1 attack, trainer 2 switch
        // 1. Trainer 1’s Pokemon attacks Trainer 2’s Pokemon.
        // 2. Trainer 2 selects a new Pokemon.
        team1.current_Pokemon->attack(team2.current_Pokemon);
        if (team2.current_Pokemon->getCurrentHp() > 0)
        {
            team2.switchPokemon();
            return;
        }
        else
        {
            cout << team2.trainer->getName() << "'s " << team2.current_Pokemon->getName() << " is dead, turn ended, switch will happen before next move\n";
            return;
        }
        break;
    case 13:
        // trainer 1 attack, trainer 2 forfeit
        team2.forfeit = true;
        team1.winMatch();
        break;
    case 21:
        // trainer 1 switch, trainer 2 attack
        // 2. Trainer 2’s Pokemon attacks Trainer 1’s Pokemon.
        // 1. Trainer 1 selects a new Pokemon.
        team2.current_Pokemon->attack(team1.current_Pokemon);
        if (team1.current_Pokemon->getCurrentHp() > 0)
        {
            team1.switchPokemon();
            return;
        }
        else
        {
            cout << team1.trainer->getName() << "'s " << team1.current_Pokemon->getName() << " is dead, turn ended, switch will happen before next move\n";
            return;
        }
        break;
    case 22:
        // both switch
        // 1. Trainer 1 selects a new Pokemon.
        // 2. Trainer 2 selects a new Pokemon.
        team1.switchPokemon();
        team2.switchPokemon();
        break;
    case 23:
        // trainer 1 switch, trainer 2 forfeit
        team2.forfeit = true;
        team1.winMatch();
        break;
    case 31:
        // trainer 1 forfeit, trainer 2 attack
        team1.forfeit = true;
        team2.winMatch();
        break;
    case 32:
        // trainer 1 forfeit, trainer 2 switch
        team1.forfeit = true;
        team2.winMatch();
        break;
    case 33:
        // both forfeit
        team1.forfeit = true;
        team2.forfeit = true;
        break;
    }
}

void battleMenu(Trainer **trainers, int &num_trainers)
{

    if (num_trainers <= 1)
    {
        cout << "Battle Menu: \n";
        cout << "The must be atleast 2 trainers for a battle\n";
        return;
    }

    int validPlayers = 0;
    for (int i = 0; i < num_trainers; i++)
    {
        if (trainers[i]->current_party_size > 0)
        {
            validPlayers++;
        }
    }

    if (validPlayers <= 1)
    {
        cout << "The must be atleast 2 trainers with pokemon for a battle\n";
        return;
    }

    Trainer *trainer1 = nullptr, *trainer2 = nullptr;
    if (validPlayers >= 2)
    {
        // display all trainers with indexs
        cout << "Battle Menu: \n";
        cout << "Select 2 trainers to battle: \n";
        // select 2 trainers
        cout << "Trainer 1: \n";
        trainer1 = selectTrainer(trainers, num_trainers);
        if (trainer1 == nullptr)
        {
            cout << "Invalid Trainer Selection\n";
            return;
        }

        cout << "Trainer 2: \n";
        trainer2 = selectTrainer(trainers, num_trainers);
        if (trainer2 == nullptr)
        {
            cout << "Invalid Trainer Selection\n";
            return;
        }
    }

    Team team1(trainer1);
    Team team2(trainer2);

    cout << "\n\n\n\n\n";
    // {
    //     cout << "Invalid Pokemon Selection\n";
    //     return trainers;
    // }

    // ready to enter battle loop

    while (true)
    {

        cout << "Battle Menu: \n";
        team1.selectPokemon();
        team2.selectPokemon();

        if (team1.alive_pokemon <= 0 && !team1.anyAlivePokemon())
        {
            cout << team1.trainer->getName() << " has no usable pokemon, " << team2.trainer->getName() << " wins\n";
            team2.winMatch();
            team1.loseMatch();
            return;
        }
        if (team2.alive_pokemon <= 0 && !team2.anyAlivePokemon())
        {
            cout << team2.trainer->getName() << " has no usable pokemon, " << team1.trainer->getName() << " wins\n";
            team1.winMatch();
            team2.loseMatch();
            return;
        }

        cout << "\n\n\n\n\n";
        team1.getMove();
        team2.getMove();
        cout << "\n\n\n\n\n";
        executeMoves(team1, team2);
        // //guard clause to check if either trainer has no pokemon left
        // if (team1.alive_pokemon <= 0)
        // {
        //     cout << team1.trainer->getName() << " has no pokemon left, " << team2.trainer->getName() << " wins\n";
        //     team2.winMatch();
        //     team1.loseMatch();
        //     break;
        // }
        // if (team2.alive_pokemon <= 0)
        // {
        //     cout << team2.trainer->getName() << " has no pokemon left, " << team1.trainer->getName() << " wins\n";
        //     team1.winMatch();
        //     team2.loseMatch();
        //     break;
        // }
        // 6. Check if either trainer has won.
        // a. If a trainer has no usable pokemon, they lose.
        // run out of usable pokemon -> the usable pokemon value is being updated through the selectPokemon, executeMoves functions, so no need to check here
        // If both trainers have won, the battle ends in a draw.
        // If one trainer has won, the battle ends and the winner is announced.
        // If the battle ends, the user is returned to the main menu.
        if (team1.alive_pokemon == 0 && team2.alive_pokemon == 0)
        {
            cout << "Both trainers have no usable pokemon, battle ended in a draw\n";

            team1.drawMatch();
            team2.drawMatch();
            return;
        }

        // b. If a trainer has no pokemon left, they lose.
        if (team1.forfeit && team2.forfeit)
        {
            cout << "Both trainers forfeited, battle ended in a draw\n";
            team1.drawMatch();
            team2.drawMatch();
            return;
        }
        else if (team1.forfeit && !team2.forfeit)
        {
            cout << team1.trainer->getName() << " forfeited, " << team2.trainer->getName() << " wins\n";
            team2.winMatch();
            team1.loseMatch();
            return;
        }
        else if (!team1.forfeit && team2.forfeit)
        {
            cout << team2.trainer->getName() << " forfeited, " << team1.trainer->getName() << " wins\n";
            team1.winMatch();
            team2.loseMatch();
            return;
        }
        // guard clause to check if both selected pokemon are fainted
        // if (pokemon1->current_hp <= 0 && pokemon2->current_hp <= 0)
        // {
        //     cout << "Both Pokemon have fainted. Battle is a draw\n";
        //     pokemon1->xp += MATCH_DRAW_XP;
        //     pokemon2->xp += MATCH_DRAW_XP;
        // }

        // guard clauses to check if pokemon 1 or 2 are dead, and ask the respective trainer to replace from party, if they have pokemon left, else forfeit
    }
    // 9. Award XP to the winning trainer’s Pokemon.
}

void game()
{
    int num_trainers = 0;
    Trainer **trainers;

    // if the debug flag is set, create 3 trainers with a full party of 2 pokemon and total 3 pokemon
    //  some initial trainers
    if(DEBUG == 1)
    {
        num_trainers = 3;
        trainers = new Trainer *[num_trainers];
        Trainer *ash = new Trainer("Ash");
        Trainer *misty = new Trainer("Misty");
        Trainer *brock = new Trainer("Brock");
        trainers[0] = ash;
        trainers[1] = misty;
        trainers[2] = brock;

        // some initial pokemon
        Pokemon *pikachu = new Pokemon("Pikachu", 'f', 10);
        Pokemon *charmander = new Pokemon("Charmander", 'f', 5);
        Pokemon *squirtle = new Pokemon("Squirtle", 'w', 6);
        // add these to ash
        (*ash).AddPokemon(pikachu);
        (*ash).AddPokemon(charmander);
        (*ash).AddPokemon(squirtle);
        // transfer 2 to current party
        (*ash).TransferPokemonFromOwnedToParty(0);
        (*ash).TransferPokemonFromOwnedToParty(1);

        Pokemon *bulbasaur = new Pokemon("Bulbasaur", 'g', 7);
        Pokemon *eevee = new Pokemon("Eevee", 'g', 3);
        Pokemon *jigglypuff = new Pokemon("Jigglypuff", 'w', 10);
        // add these to misty
        (*misty).AddPokemon(bulbasaur);
        (*misty).AddPokemon(eevee);
        (*misty).AddPokemon(jigglypuff);
        // transfer 2 to current party
        (*misty).TransferPokemonFromOwnedToParty(0);
        (*misty).TransferPokemonFromOwnedToParty(1);

        Pokemon *snorlax = new Pokemon("Snorlax", 'g', 12);
        Pokemon *mew = new Pokemon("Mew", 'g', 15);
        Pokemon *mewtwo = new Pokemon("Mewtwo", 'g', 20);
        // add these to brock
        (*brock).AddPokemon(snorlax);
        (*brock).AddPokemon(mew);
        (*brock).AddPokemon(mewtwo);
        // transfer 2 to current party
        (*brock).TransferPokemonFromOwnedToParty(0);
        (*brock).TransferPokemonFromOwnedToParty(1);
    }else{
        //base val
        num_trainers = 0;
        trainers = new Trainer *[num_trainers];
    }

    cout << "Welcome to The Pokemon Game" << endl;

    const int exitVal = 3;
    int choice = 0;
    while (choice != exitVal)
    {
        cout << "Enter a command: " << endl;
        cout << "1. Trainer Menu?" << endl;
        cout << "2. Battle Menu?" << endl;
        cout << "3. Exit?" << endl;

        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            trainers = trainerMenu(trainers, num_trainers);
        }
        else if (choice == 2)
        {
            battleMenu(trainers, num_trainers);
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