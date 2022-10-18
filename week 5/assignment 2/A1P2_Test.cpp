#include <iostream>
#include "24100178_A1P2.cpp"

using namespace std;

class VectorTest
{
private:
    Vector testObj;

public:
    void TestingPriv(int &);
    void TestingInit(int &);
    void TestingGetLen(int &);
    void TestingIsEmpty(int &);
    void TestingChangeType(int &);
    void TestingInsertAtHead(int &);
    void TestingInsertAtTail(int &);
    void TestingIsFull(int &);
    void TestingIncreaseCap(int &);
    void TestingDeleteHead(int &);
    void TestingGetHead(int &);
    void TestingGetTail(int &);
    void TestingDeleteTail(int &);
    void TestingPushPop(int &);
    void TestingDestructor(int &);
    void TestingCopyConstructor(int &, VectorTest &);
};

int main()
{
    int score = 0;
    cout << "-----------------------------------------------" << endl;
    cout << "Testing Implementation " << endl
         << endl;

    VectorTest test;
    test.TestingPriv(score);
    test.TestingInit(score);
    test.TestingGetLen(score);
    test.TestingIsEmpty(score);
    test.TestingChangeType(score);
    test.TestingInsertAtHead(score);
    // Test has {7, 6, 5}

    VectorTest test2;
    test2.TestingInsertAtTail(score);

    VectorTest test3;
    test3.TestingIsFull(score);
    test3.TestingIncreaseCap(score);

    test2.TestingDeleteHead(score);
    // Now test2 is empty.

    test.TestingGetHead(score);

    test3.TestingGetTail(score);

    test2.TestingDeleteTail(score);
    test2.TestingPushPop(score);
    test2.TestingDestructor(score);
    test2.TestingCopyConstructor(score, test);

    cout
        << endl
        << endl
        << endl;

    cout << "-----------------------------------------------" << endl
         << endl;
    cout << "Total Score: " << score << "/105" << endl
         << endl;
    return 0;
}

void VectorTest::TestingPriv(int &score)
{
    cout << "Initializing Test 1 - Private Member Variables" << endl;

    try
    {
        score += 5;
        cout << "Test 1 Passed! Score: " << score << "/105" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "Test 1 Failed. Score: " << score << "/105" << endl;
    }
}

void VectorTest::TestingInit(int &score)
{
    cout << "Initializing Test 2 - Object Initialization" << endl;

    try
    {
        if (testObj.getLength() != 0)
        {
            cout << "Test 2 Failed. Length Not Set. Score: " << score << "/105" << endl;
        }
        else if (testObj.capacity != 10)
        {
            cout << "Test 2 Failed. Capacity Not Set. Score: " << score << "/105" << endl;
        }
        else if (testObj.type != 's')
        {
            cout << "Test 2 Failed. Type Not Set. Score: " << score << "/105" << endl;
        }
        else
        {
            score += 7;
            cout << "Test 2 Passed! Score: " << score << "/105" << endl;
        }
    }
    catch (const std::exception &e)
    {
        cout << "Test 2 Failed. Score: " << score << "/105" << endl;
    }
}

void VectorTest::TestingGetLen(int &score)
{
    cout << "Initializing Test 3 - Get Length" << endl;

    try
    {
        if (testObj.getLength() != 0)
        {
            cout << "Test 3 Failed. Empty Vector Should Have Length 0. Score: " << score << "/105" << endl;
        }
        else
        {
            score += 2;
            cout << "Test 3 Passed! Score: " << score << "/105" << endl;
        }
    }
    catch (const std::exception &e)
    {
        cout << "Test 3 Failed. Score: " << score << "/105" << endl;
    }
}

void VectorTest::TestingIsEmpty(int &score)
{
    cout << "Initializing Test 4 - Is Empty" << endl;

    try
    {
        if (testObj.isEmpty() != true)
        {
            cout << "Test 4 Failed. Score: " << score << "/105" << endl;
        }
        else
        {
            score += 2;
            cout << "Test 4 Passed! Score: " << score << "/105" << endl;
        }
    }
    catch (const std::exception &e)
    {
        cout << "Test 4 Failed. Score: " << score << "/105" << endl;
    }
}

void VectorTest::TestingChangeType(int &score)
{
    cout << "Initializing Test 5 - Change Type" << endl;

    try
    {
        testObj.changeType('q');

        if (testObj.type != 'q')
        {
            throw std::exception();
        }
        else
        {
            score += 5;
            cout << "Test 5 Passed! Score: " << score << "/105" << endl;
        }
    }
    catch (const std::exception &e)
    {
        cout << "Test 5 Failed. Score: " << score << "/105" << endl;
    }
}

void VectorTest::TestingInsertAtHead(int &score)
{
    cout << "Initializing Test 6 - Insert At Head" << endl;

    try
    {
        testObj.insertAtHead(5);
        testObj.insertAtHead(6);
        testObj.insertAtHead(7);

        int testArr[3] = {7, 6, 5};

        for (int i = 0; i < 3; i++)
        {
            if (testObj.array[i] != testArr[i])
            {
                throw std::exception();
            }
        }

        if (testObj.getLength() != 3 || testObj.isEmpty())
        {
            cout << "Test 6 Failed. Score: " << score << "/105" << endl;
        }
        else
        {
            score += 3;
            cout << "Test 6 Passed! Score: " << score << "/105" << endl;
        }
    }
    catch (const std::exception &e)
    {
        cout << "Test 6 Failed. Score: " << score << "/105" << endl;
    }
}

void VectorTest::TestingInsertAtTail(int &score)
{
    cout << "Initializing Test 7 - Insert At Tail" << endl;

    try
    {
        testObj.insertAtTail(5);
        testObj.insertAtTail(6);
        testObj.insertAtTail(7);

        int testArr[3] = {5, 6, 7};

        for (int i = 0; i < 3; i++)
        {
            if (testObj.array[i] != testArr[i])
            {
                throw std::exception();
            }
        }

        if (testObj.getLength() != 3 || testObj.isEmpty())
        {
            cout << "Test 7 Failed. Score: " << score << "/105" << endl;
        }
        else
        {
            score += 2;
            cout << "Test 7 Passed! Score: " << score << "/105" << endl;
        }
    }
    catch (const std::exception &e)
    {
        cout << "Test 7 Failed. Score: " << score << "/105" << endl;
    }
}

void VectorTest::TestingIsFull(int &score)
{
    cout << "Initializing Test 8 - Is Full" << endl;

    try
    {
        int insertArr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        for (int i = 0; i < 10; i++)
        {
            testObj.insertAtHead(insertArr[i]);
        }

        if (testObj.isFull())
        {
            score += 2;
            cout << "Test 8 Passed! Score: " << score << "/105" << endl;
        }
        else
        {
            throw std::exception();
        }
    }
    catch (const std::exception &e)
    {
        cout << "Test 8 Failed. Score: " << score << "/105" << endl;
    }
}

void VectorTest::TestingIncreaseCap(int &score)
{
    cout << "Initializing Test 9 - Increase Cap" << endl;

    try
    {
        int insertArr[1] = {10};

        for (int i = 0; i < 1; i++)
        {
            testObj.insertAtHead(insertArr[i]);
        }

        int testArr[11] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

        for (int i = 0; i < 11; i++)
        {
            if (testObj.array[i] != testArr[i])
            {
                throw std::exception();
            }
        }

        if (testObj.capacity == 20)
        {
            score += 17;
            cout << "Test 9 Passed! Score: " << score << "/105" << endl;
        }
        else
        {
            throw std::exception();
        }
    }
    catch (const std::exception &e)
    {
        cout << "Test 9 Failed. Score: " << score << "/105" << endl;
    }
}

void VectorTest::TestingDeleteHead(int &score)
{
    cout << "Initializing Test 10 - Delete Head" << endl;

    try
    {
        testObj.deleteHead();

        if (testObj.array[0] != 6 || testObj.array[1] != 7)
        {
            throw std::exception();
        }

        testObj.deleteHead();
        testObj.deleteHead();

        if (testObj.getLength() != 0 || !testObj.isEmpty())
        {
            throw std::exception();
        }
        else
        {
            score += 10;
            cout << "Test 10 Passed! Score: " << score << "/105" << endl;
        }
    }
    catch (const std::exception &e)
    {
        cout << "Test 10 Failed. Score: " << score << "/105" << endl;
    }
}

void VectorTest::TestingGetHead(int &score)
{
    cout << "Initializing Test 11 - Get Head" << endl;

    try
    {
        int num = testObj.getHead();

        if (num != 7)
        {
            throw std::exception();
        }
        else
        {
            score += 2;
            cout << "Test 11 Passed! Score: " << score << "/105" << endl;
        }
    }
    catch (const std::exception &e)
    {
        cout << "Test 11 Failed. Score: " << score << "/105" << endl;
    }
}

void VectorTest::TestingGetTail(int &score)
{
    cout << "Initializing Test 12 - Get Tail" << endl;

    try
    {
        int num = testObj.getTail();

        if (num != 0)
        {
            throw std::exception();
        }
        else
        {
            score += 2;
            cout << "Test 12 Passed! Score: " << score << "/105" << endl;
        }
    }
    catch (const std::exception &e)
    {
        cout << "Test 12 Failed. Score: " << score << "/105" << endl;
    }
}

void VectorTest::TestingDeleteTail(int &score)
{
    cout << "Initializing Test 13 - Delete Tail" << endl;

    try
    {
        testObj.insertAtTail(5);

        testObj.deleteTail();

        if (testObj.getLength() != 0 || !testObj.isEmpty())
        {
            throw std::exception();
        }
        else
        {
            score += 2;
            cout << "Test 13 Passed! Score: " << score << "/105" << endl;
        }
    }
    catch (const std::exception &e)
    {
        cout << "Test 13 Failed. Score: " << score << "/105" << endl;
    }
}

void VectorTest::TestingPushPop(int &score)
{
    cout << "Initializing Test 14 - Push & Pop" << endl;

    try
    {
        testObj.push(5);
        testObj.push(6);
        testObj.push(7);

        int num1 = testObj.pop();
        int num2 = testObj.pop();
        int num3 = testObj.pop();

        if (num1 != 7 || num2 != 6 || num3 != 5 || !testObj.isEmpty() || testObj.getLength() != 0)
        {
            throw std::exception();
        }

        testObj.type = 'q';

        testObj.push(5);
        testObj.push(6);
        testObj.push(7);

        num1 = testObj.pop();
        num2 = testObj.pop();
        num3 = testObj.pop();

        if (num1 != 5 || num2 != 6 || num3 != 7 || !testObj.isEmpty() || testObj.getLength() != 0)
        {
            throw std::exception();
        }

        score += 30;
        cout << "Test 14 Passed! Score: " << score << "/105" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "Test 14 Failed. Score: " << score << "/105" << endl;
    }
}

void VectorTest::TestingDestructor(int &score)
{
    cout << "Initializing Test 15 - Destructor" << endl;

    try
    {
        score += 7;
        cout << "Test 15 Passed! Score: " << score << "/105" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "Test 15 Failed. Score: " << score << "/105" << endl;
    }
}

void VectorTest::TestingCopyConstructor(int &score, VectorTest &obj2)
{

    cout << "Initializing Test 16 - Copy Constructor" << endl;

    try
    {
        testObj = obj2.testObj;

        if (testObj.array[0] != 7 || testObj.array[1] != 6 || testObj.array[2] != 5)
        {
            throw std::exception();
        }
        else
        {
            score += 7;
            cout << "Test 16 Passed! Score: " << score << "/105" << endl;
        }
    }
    catch (const std::exception &e)
    {
        cout << "Test 16 Failed. Score: " << score << "/105" << endl;
    }
}