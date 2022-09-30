#include <iostream>
#include <string>
using namespace std;

//generate all possible combinations of mass C2O2NH2

// where
/*
// C = {{12 0.9891}},
        {13 0.0109}}
// O = {{15.99 0.9976}},
        {16.99 0.0004},
        {17.99 0.002}}

// N = {{14.01 0.99}},
        {15.01 0.004}}
// H = {{1 0.99}},
        {2.01 0.0001}}
*/
int main()
{
    double C[2][2] = {{12, 0.9891}, {13, 0.0109}};
    double O[3][2] = {{15.99, 0.9976}, {16.99, 0.0004}, {17.99, 0.002}};
    double N[2][2] = {{14.01, 0.99}, {15.01, 0.004}};
    double H[2][2] = {{1, 0.99}, {2.01, 0.0001}};

    //combination matrix
    const int numberOfCombinations = 2 * 3 * 2 * 2;
    const int numberOfElements = 4;
    //format of combination matrix
        // C O N H
        // 2 3 2 2
        //in array index 
        // 1 2 1 1
        // 2 x 3 x 2 x 2 = 24
    string combinationMatrix[numberOfCombinations];
    int index = 0;
    int maxCombination = 0;
    while(maxCombination < 1212)
    {
        string currentNumber = to_string(maxCombination);
        
        //making sure that the number is 4 digits -> string length is 4
        if(currentNumber.length() == 1){
            currentNumber = "000" + currentNumber;
        }else if(currentNumber.length() == 2){
            currentNumber = "00" + currentNumber;
        }else if(currentNumber.length() == 3){
            currentNumber = "0" + currentNumber;
        }


        //only add the combination if unique, and the digits are in correct range
        //possiblity for first digit ->C ie 0-1
        if (currentNumber[0] == '0' || currentNumber[0] == '1')
        {
            //possiblity for second digit ->O ie 0-2
            if (currentNumber[1] == '0' || currentNumber[1] == '1' || currentNumber[1] == '2')
            {
                //possiblity for third digit ->N ie 0-1
                if (currentNumber[2] == '0' || currentNumber[2] == '1')
                {
                    //possiblity for fourth digit ->H ie 0-1
                    if (currentNumber[3] == '0' || currentNumber[3] == '1')
                    {
                        //add to list if the combination is unique
                        combinationMatrix[index] = currentNumber;
                        index++;
                    }
                }
            }
        }
        maxCombination++;
    }
    
    //print all possible masses, where each mass is the sum of the mass of each element
    cout << "all possible masses: " << endl;
    for(int i = 0; i < numberOfCombinations; i++){
        double massOfCurrentIsotope = 0;
        double carbonMass = C[combinationMatrix[i][0] - '0'][0];
        double oxygenMass = O[combinationMatrix[i][1] - '0'][0];
        double nitrogenMass = N[combinationMatrix[i][2] - '0'][0];
        double hydrogenMass = H[combinationMatrix[i][3] - '0'][0];
        massOfCurrentIsotope = (2 * carbonMass) + (2 * oxygenMass) + (1 * nitrogenMass) + (2 * hydrogenMass);



        double relativeMolecularAbundancePercentage = 0;
        double carbonAbdundance = carbonMass * C[combinationMatrix[i][0] - '0'][1];
        double oxygenAbdundance = oxygenMass * O[combinationMatrix[i][1] - '0'][1];
        double nitrogenAbdundance = nitrogenMass * N[combinationMatrix[i][2] - '0'][1];
        double hydrogenAbdundance = hydrogenMass * H[combinationMatrix[i][3] - '0'][1];
        relativeMolecularAbundancePercentage = (2 * carbonAbdundance) + (2 * oxygenAbdundance) + (1 * nitrogenAbdundance) + (2 * hydrogenAbdundance);

        cout << "Combination: " << combinationMatrix[i]  << " -> Mass of Isotope: " << massOfCurrentIsotope << " -> Relative Molecular Abundance: " << relativeMolecularAbundancePercentage << "%" << endl;
    }


    return 0;
}