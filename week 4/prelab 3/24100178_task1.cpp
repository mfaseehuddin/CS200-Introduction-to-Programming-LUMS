#include <iostream>
using namespace std;

// create a class: Set
class Set
{
private:
    int *set;
    int size;

    // set member existence function
    bool numberExistInSet(int *setArray, int sizeSetArray, int searchNumber)
    {
        for (int i = 0; i < sizeSetArray; i++)
        {
            if (setArray[i] == searchNumber)
            {
                return true;
            }
        }
        return false;
    }

public:
    // default constructor
    Set()
    {
        set = NULL;
        size = 0;
    }
    // constructor
    Set(int *setArray, int setArraySize)
    {
        int effectiveSizeOfSet = 0;
        int *tempSet = new int[setArraySize];

        // we will count the number of unique elements in setArray while we copy over the unique elements to tempSet
        for (int i = 0; i < setArraySize; i++)
        {
            if (!numberExistInSet(tempSet, effectiveSizeOfSet, setArray[i]))
            {
                tempSet[effectiveSizeOfSet] = setArray[i];
                effectiveSizeOfSet++;
            }
        }
        // now we will copy over the unique elements from tempSet to set - set being an int array of size effectiveSizeOfSet
        set = new int[effectiveSizeOfSet + 1];
        size = effectiveSizeOfSet;
        for (int i = 0; i < effectiveSizeOfSet; i++)
        {
            set[i] = tempSet[i];
        }
        // delete tempSet
        delete[] tempSet;
    }
    // copy constructor
    Set(const Set &setObject)
    {
        size = setObject.size;
        set = new int[size];
        for (int i = 0; i < size; i++)
        {
            // setting the values of the array using pointer notation
            *(set + i) = *(setObject.set + i);
        }
    }
    // destructor
    ~Set()
    {
        delete[] set;
    }

    // public member functions
    
    
    // Union function
    /*
     * Union of two sets
     * @param set2: second set
     * @return: union object Set of set and set2
     */
    Set *Union(Set &Set2)
    {
        // setArray created with max possible size of the union
        int maxSizeOfUnion = size + Set2.size;
        int effectiveLengthOfUnion = 0;
        int *setArray = new int[maxSizeOfUnion];

        // add all the elements of set 1 to setArray
        for (int i = 0; i < size; i++)
        {
            *(setArray + i) = *(set + i);
            effectiveLengthOfUnion++;
        }

        // add all the elements of set 2 to setArray making sure that there are no duplicates
        for (int i = 0; i < Set2.size; i++)
        {
            if (!numberExistInSet(setArray, effectiveLengthOfUnion, *(Set2.set + i)))
            {
                *(setArray + effectiveLengthOfUnion) = *(Set2.set + i);
                effectiveLengthOfUnion++;
            }
        }
        Set *UnionSet = new Set(setArray, effectiveLengthOfUnion);
        return UnionSet;
    }

    
    // Intersection function
    /*
     * Intersection of two sets
     * @param set2: second set
     * @return: intersection object Set of set and set2
     */
    Set *Intersection(Set &set2)
    {
        int intersectionSize = size <= set2.size ? size : set2.size;
        int *intersectionArray = new int[intersectionSize];
        int intersectionArraySize = 0;
        for (int i = 0; i < intersectionSize; i++)
        {
            if (numberExistInSet(set2.set, set2.size, *(set + i)) && !numberExistInSet(intersectionArray, intersectionArraySize, *(set + i)))
            {
                intersectionArray[intersectionArraySize] = *(set + i);
                intersectionArraySize++;
            }
        }
        Set *intersectionSet = new Set(intersectionArray, intersectionArraySize);
        return intersectionSet;
    }
    
    
    // Difference function
    /*
     * Difference of two sets
     * @param set2: second set
     * @return: difference object Set of set and set2
     */
    Set *Difference(Set &set2)
    {
        int differenceMaxSize = size + set2.size;
        int *differenceArray = new int[differenceMaxSize];
        int differenceArrayEffectiveSize = 0;

        // difference of a two sets is the inverse intersection of union and intersection
        Set *unionSet = Union(set2);
        Set *intersectionSet = Intersection(set2);

        for (int i = 0; i < unionSet->size; i++)
        {
            if (!numberExistInSet(intersectionSet->set, intersectionSet->size, *(unionSet->set + i)))
            {
                differenceArray[differenceArrayEffectiveSize] = *(unionSet->set + i);
                differenceArrayEffectiveSize++;
            }
        }

        // now we will create the differenceSet
        Set *differenceSet = new Set(differenceArray, differenceArrayEffectiveSize);
        return differenceSet;
    }
    
    
    // Compare function
    /*
     * Compare two sets
     * @param set2: second set
     * @return: true if set and set2 are equal, false otherwise
     */
    bool Compare(Set &set2)
    {
        return Difference(set2)->size == 0 ? true : false;
    }
    
    
    // Print Set function
    /*
     * Print set
     * @return: void
     */
    void printSet()
    {
        cout << "{";
        if (size == 0)
        {
            cout << "\u03A6 "; // printing phi if set is empty phi - \u03A6
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                cout << set[i] << " ";
            }
        }
        cout << "\b}" << endl;
    }
};

int main()
{
    int userLen = 0;
    cout << "Please input length of set: ";
    cin >> userLen;
    if (userLen < 0)
    {
        exit(0);
    }
    int *userSet = new int[userLen];
    for (int i = 0; i < userLen; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> userSet[i];
    }
    Set set1(userSet, userLen);
    delete[] userSet;
    cout << "set1: ";
    set1.printSet();

    cout << "Please input length of set: ";
    cin >> userLen;
    if (userLen < 0)
    {
        exit(0);
    }
    userSet = new int[userLen];
    for (int i = 0; i < userLen; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> userSet[i];
    }
    Set set2(userSet, userLen);
    delete[] userSet;
    cout << "set1: ";
    set1.printSet();
    cout << "set2: ";
    set2.printSet();

    // print the union of set1 and set2
    Set *unionSet = set1.Union(set2);
    cout << "Union: ";
    unionSet->printSet();

    // print the intersection of set 1 and set 2
    Set *intersectionSet = set1.Intersection(set2);
    cout << "Intersection: ";
    intersectionSet->printSet();

    // print the difference of set1 and set2
    Set *differenceSet = set1.Difference(set2);
    cout << "Difference: ";
    differenceSet->printSet();

    // print the comparison of set1 and set2
    cout << "Comparison: ";
    set1.Compare(set2) ? cout << "The sets are equivalent" << endl : cout << "The sets are not equivalent" << endl;

    return 0;
}