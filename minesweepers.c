#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define COLUMN 10
#define ROW 10
void ViewBoard( char PrintBoard[ROW][COLUMN], int size);
void playBoard(char gameBoard[ROW][COLUMN],char actualGameBoard[ROW][COLUMN],int sizeOfArray);
void createsBoard(char CreateBoard[ROW][COLUMN],int sizeOfBoard);
void createsActualBoard(char CreateactualBoard[ROW][COLUMN], int sizeOfActualBoard);
void changeTheBoard(char gameBoard[ROW][COLUMN],char actualGameBoard[ROW][COLUMN],char positionBoard[], int sizeOfFakeBoard);

int main()
{
   char actualBoard[COLUMN][ROW];
   char Board[COLUMN][ROW];
   int size;
   
   printf("Choose size(5-10): ");
   scanf("%d",&size);

   createsActualBoard(actualBoard,size);
   createsBoard(Board,size);
   
   playBoard(Board,actualBoard,size);
}

//Initiates the actual board
void createsActualBoard(char CreateActualBoard[ROW][COLUMN], int sizeOfActualBoard)
{
      srand(time(NULL));
      int randomNumber;

      for(int i = 0; i<sizeOfActualBoard; i++)
      {
          for(int k = 0; k<sizeOfActualBoard; k++)
          {
            //20% chance that one of position will be a mine
            randomNumber = rand() %6;
            if(randomNumber == 2)
            {
              CreateActualBoard[i][k] = '*';
            }
            else
            {
              CreateActualBoard[i][k] = randomNumber + '0'; //transforms number to a character.
            }
             
          }
      }
}

//initiates the FakeBoard
void createsBoard(char CreateBoard[ROW][COLUMN],int sizeOfBoard)
{

      //Populates the board with char '#'
      for(int i = 0; i<sizeOfBoard; i++)
      {
        for(int k = 0; k<sizeOfBoard; k++)
          {
            CreateBoard[i][k] = '#'; 
          }
      }
}

//This where you play the game
void playBoard(char gameBoard[ROW][COLUMN],char actualGameBoard[ROW][COLUMN],int sizeOfArray)
{
    char Position[3+1];
    int column;
    int row;
    int rowWhenTen;
     
    do
    {
      for(int k=0; k<sizeOfArray; k++)
        {
          printf("%d",k);


        }
      printf("\n");

    ViewBoard(gameBoard,sizeOfArray);
    printf(": ");
    scanf("%s",Position);

    //to transform A-E to numbers in index and 1-5 to int
    column = Position[0] - 65 ;
    row = (Position[1] -'0')-1;
  
    changeTheBoard(gameBoard,actualGameBoard,Position,sizeOfArray);
    ViewBoard(gameBoard,sizeOfArray);
    printf("%d",row);
  }while(gameBoard[column][row] != '*');
    
    printf("BOOM!!*_-*_'-`!€3!#\n");
    ViewBoard(actualGameBoard,sizeOfArray);
   
}

void changeTheBoard(char gameBoard[ROW][COLUMN],char actualGameBoard[ROW][COLUMN],char positionBoard[], int sizeOfFakeBoard)
{

    //transform positionboard char to number 
    int column = positionBoard[0] - 65 ;
    int row = (positionBoard[1] -'0')-1;
    int rowWhenTen = (positionBoard[2] -'0');
    
  
    //if pos[2] is 0, then that means the person typed 10
    if(row == 0 && rowWhenTen== 0)
    {
        gameBoard[column][9] = actualGameBoard[column][9];
    }
    else
    {
          gameBoard[column][row] = actualGameBoard[column][row];

    }
}

void ViewBoard( char PrintBoard[ROW][COLUMN], int size)
{

    for(int i=0; i<size; i++)
    {
         printf("%c ",'A'+i);
         for(int j = 0; j <size; j++)
         {
            printf("%c",PrintBoard[i][j]);

         }
         printf("\n");
    }
}