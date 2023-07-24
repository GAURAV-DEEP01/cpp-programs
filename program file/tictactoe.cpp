#include<iostream>
using namespace std;
void displayTile(char (&board)[3][3]){
    cout<<board[0][0]<<"   |   "<<board[0][1]<<"   |   "<<board[0][2]<<endl;
    cout<<"-----------------"<<endl;
    cout<<board[1][0]<<"   |   "<<board[1][1]<<"   |   "<<board[1][2]<<endl;
    cout<<"-----------------"<<endl;
    cout<<board[2][0]<<"   |   "<<board[2][1]<<"   |   "<<board[2][2]<<endl;
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
    currentPlayer = currentPlayer=='x'?'o':'x';
}
bool isValidMove(char (&board)[3][3],int row, int col){
    if((board[row][col]=='x'||board[row][col]=='o')||((row<0||row>3)||(col<0||col>3))){
         cout<<"Invalid move try gain"<<endl;
         return false;
    }
    return true;
}
int main (){
    char currentPlayer='x',board[3][3] ={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int moves=0,row ,col;
    cout<<"start the game"<<endl;
    displayTile(board);
    while (!isGameOver(moves,board))
        {   
            cout<<"Enter the 2d position of player :"<<currentPlayer<<endl;
            cin>>row>>col;
            row--;col--;
            if(isValidMove(board,row,col)){
                board[row][col]=currentPlayer;
                swapPlayer(currentPlayer);
                moves++;
            }
            displayTile(board);  

        }  
        swapPlayer(currentPlayer);
        displayTile(board);   
        if (moves==9)
            cout<<"its a tie!";
        else{
            cout<<currentPlayer<<" won";
        }
        return 0;
}