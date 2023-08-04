#include<iostream>
using namespace std;

void displayTile(char (&board)[3][3]){
    cout<<endl;
    cout<<"\t   "<<board[0][0]<<"   |   "<<board[0][1]<<"   |   "<<board[0][2]<<endl;
    cout<<"\t-----------------------"<<endl;
    cout<<"\t   "<<board[1][0]<<"   |   "<<board[1][1]<<"   |   "<<board[1][2]<<endl;
    cout<<"\t-----------------------"<<endl;
    cout<<"\t   "<<board[2][0]<<"   |   "<<board[2][1]<<"   |   "<<board[2][2]<<endl;
    cout<<endl;
}

bool isGameOver(int &moves ,char (&board)[3][3]){
    if(moves==9)
    return true;
    for (int i = 0; i < 3; i++)
    {
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2])
            return true;
        if (board[0][i]==board[1][i]&&board[1][i]==board[2][i])     
            return true;
    }
    if (board[0][0]==board[1][1]&&board[1][1]==board[2][2])
        return true;
    if (board[2][0]==board[1][1]&&board[1][1]==board[0][2])
        return true;
    return false;
}

void swapPlayer(char &currentPlayer){
    currentPlayer = currentPlayer=='X'?'O':'X';
}

bool isValidMove(char (&board)[3][3],int (&matrixPos)[2],int position){
    if((board[matrixPos[0]][matrixPos[1]]=='x'||board[matrixPos[0]][matrixPos[1]]=='o')||(position<1||position>9)){
         cout<<"Invalid move try gain"<<endl;
         return false;
    }
    return true;
}

void convertToRowCol(int position,int (&matrixPos)[2]){
    if (position>0 && position < 4){
        matrixPos[0]=0;
        matrixPos[1]=position-1;
    }
    if (position>3 && position < 7){
        matrixPos[0]=1;
        matrixPos[1]=position-4;
    }
    if (position>6 && position < 10){
        matrixPos[0]=2;
        matrixPos[1]=position-7;
    }
}

int main (){
    char currentPlayer='X',board[3][3] ={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int moves=0,matrixPos[2]={0,0}, position;
    cout<<"Enter the position as shown in the table"<<endl;
    cout<<"Start the Game:"<<endl<<"\t      TIC TAC TOE"<<endl;
    displayTile(board);
    while (!isGameOver(moves,board))
        {   
            cout<<"Player "<<currentPlayer<<" turn"<<endl;
            cin>>position;
            convertToRowCol(position,matrixPos);
            if(isValidMove(board,matrixPos,position)){
                board[matrixPos[0]][matrixPos[1]]=currentPlayer;
                swapPlayer(currentPlayer);
                moves++;
            }
            displayTile(board);  

        }  
        swapPlayer(currentPlayer);  
        if (moves==9)
            cout<<"Its a tie!";
        else{
            cout<<"\t\t"<<currentPlayer<<" Won!"<<endl;
        }
        return 0;
}