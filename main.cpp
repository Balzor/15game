#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

void firstRequirement();

void checkUnique(int i, int i1, bool b);

int main () {
    cout << "Beginning of program\n";
    cout << "do you want to play this game\n";
    int x;
    cin >> x;
    firstRequirement();
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
                        cout << "Please choose the number for the " << i << "," << j << " position\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cin >> number;

                        for (int ii = 0; ii < 4; ii++){
                            for(int jj=0; jj < 4; jj++){
                                int* currentElement = &(gameField[ii][jj]);
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
            cout << "| " << gameField[i][j] << " |";
        }
        cout << "\n";
    }
}

void checkUnique(int i, int i1, bool b) {
    for (int ii = 0; ii < 4; ii++){
        for(int jj=0; jj < 4; jj++){
            int* currentElement = &(i);
            if (*currentElement == i1){
                cout << "Value exists " << *currentElement <<  endl;
                b= true;
            }else{
                b=false;
            }
        }
    }
}
