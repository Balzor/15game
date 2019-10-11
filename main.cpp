#include <iostream>
#include <limits>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>


using namespace std;

void firstRequirement();

void secondRequirement();

int main () {
    int i;
    cout << "press any key to proceed... ";
    cin >> i;
    int x;
    bool valid=true;
    cout << "\nWhat do you want to do?\n\n";
    do{
        cout << "Choose between\n(1).First Requirement\n(2).Second Requirement\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin >> x;
        if (x==1){
            valid=false;
            firstRequirement();
        }
        if (x==2){
            valid = false;
            secondRequirement();
        }
    }while(valid);
}

void firstRequirement() {
    int ** gameField = new int * [ 4 ];
    for (int i=0; i < 4; i++)
        gameField[i] = new int [4];

    int count=0;
    int number;
    for (int i = 0; i < 4; i++){
        for(int j=0; j < 4; j++){
            bool exists = true;
            if (count!=15){
                do {
                    do {
                        cout << "Please choose a unique number from 1-20 for the " << i << "," << j << " position\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cin >> number;

                        for (int ii = 0; ii < 4; ii++){
                            for(int jj=0; jj < 4; jj++){
                                int* currentElement = &(gameField[ii][jj]);
                                if (number >20 || number < 1){
                                    cout << "Value must be between 1-20\n";
                                    exists =true;
                                    break;
                                }
                                if (*currentElement == number){
                                    cout << "Value exists " << *currentElement <<  endl;
                                    exists = true;
                                    break;
                                }else{
                                    exists = false;
                                }
                            }
                            if (exists)
                                break;
                        }

                        gameField[i][j] = number;
                    }while(exists);
                }while(cin.fail());
                count++;
            }else{
                gameField[i][j] =0;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "| " << setw(2) << gameField[i][j] << " |";
        }
        cout << "\n";
    }
}

void secondRequirement() {
    int puzzles;

    do{
        cout << "How many puzzles do you want?\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin >> puzzles;
    }while(cin.fail());


    srand(time(nullptr));

    int ** gameField = new int * [ 4 ];
    for (int i=0; i < 4; i++)
        gameField[i] = new int [4];

    for (int p = 0; p < puzzles; p++){

        cout << p+1 <<".\n";

        int count=0;
        for (int i = 0; i < 4; i++){
            for(int j=0; j < 4; j++){
                bool exists = true;
                if (count!=15){
                    do {
                        do {
                            int randomval = rand() % 20;

                            cin.clear();

                            for (int ii = 0; ii < 4; ii++){
                                for(int jj=0; jj < 4; jj++){
                                    int* currentElement = &(gameField[ii][jj]);
                                    if (randomval >20 || randomval < 1){
                                        exists =true;
                                        break;
                                    }
                                    if (*currentElement == randomval){
                                        exists = true;
                                        break;
                                    }else{
                                        exists = false;
                                    }
                                }
                                if (exists)
                                    break;
                            }

                            gameField[i][j] = randomval;
                        }while(exists);
                    }while(cin.fail());
                    count++;
                }else{
                    gameField[i][j] =0;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << "| " << setw(2) << gameField[i][j] << " |";
            }
            cout << "\n";
        }
    }
}