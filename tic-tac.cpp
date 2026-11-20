#include <iostream>
using namespace std;

//functions prototypes 
void displayBoard(char board[3][3]);   //show board with numbers in 
bool checkWinner();     //check whether player has won or not
void replay();     // decide to repeat Game or not

void displayBoard(char board[3][3]) {
    for ( int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){

            cout<<" "<<board[row][col]<< " ";

            if (col < 2){
                cout<<" |";
            }

        }
        cout<<endl;
        if (row < 2){
            cout<<"----+----+---- "<<endl;
        }
        
    }
    cout<< endl;
}

int main()
{

     char board[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };

    displayBoard(board);

    return 0;

}