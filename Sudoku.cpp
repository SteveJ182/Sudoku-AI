#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
using namespace std;
const int ROWS=9;
const int COLS=9;

struct Game{
  bool filled=false;
  bool beginning=false;
  int num=0;
};
//Prints the game board
void Print(Game arr[ROWS][COLS]){
  for(int i=0; i<ROWS; i++){
    for(int j=0; j<COLS; j++){
      cout << arr[i][j].num << " ";}
    cout << endl;}
}

//returns true if number passed in was found in the row beforehand
bool checkRow(int row, int number, Game arr[][COLS]){
    for(int j=0; j<COLS; j++){
        //count only goes up if the number is encountered in the row
        if(arr[row][j].num==number && arr[row][j].filled==true){return true;}
      }
  return false;
}

//returns true if the column was filled in prior
bool checkCol(int col, int number, Game arr[][COLS]){
for(int i=0; i<ROWS; i++){
        //count only goes up if the number is encountered in the row
        if(arr[i][col].num==number && arr[i][col].filled==true){return true;}
    }
    return false;
}


bool Noctave(int col, int row, int number, Game arr[][COLS]){
int row_Loc=row, col_Loc=col;

//finds the beginning of the noctave or 3x3 matrix
if(!arr[row][col].beginning){
  while(row_Loc%3!=0){row_Loc--;}
  while(col_Loc%3!=0){col_Loc--;}
  }
  //will return true if the number was found in the noctave and means it can't be added in
  for(int i=row_Loc; i<row_Loc+3; i++){
    for(int j=col_Loc; j<col_Loc+3; j++){
      if(arr[i][j].num == number && arr[i][j].filled){return true;}
    }
  }
return false;
}

//intitalizes the beggining board
bool intialize(int& rows, int& cols, Game arr[][COLS]){
srand(time(NULL));
bool row_fill=false, col_fill=false, noctave = false;
int row_count=0, row_Loc=0;
int rep_count, col_Loc=0;
int number=0, temp=0;

  //sets the beginning of the seperated 3x3 matrices to true to make iteration and placement simpler
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
    if(j%3==0 && i%3==0){arr[i][j].beginning=true;}
    }
  }

//use to initialize the rows
for(; row_count<9; row_count++){
    row_fill=false;
    number = (rand() %9)+1;
    col_Loc = (rand() %9)+1;

    row_fill = checkRow(row_count, number, arr);
  if(row_fill){return false;}//if row was filled prior with the num it will reduce the value of row_count and start again
  else{col_fill=checkCol(col_Loc, number, arr);//if not it will check the column
      noctave=Noctave(col_Loc, row_count, number, arr);//will check its noctave to see if number is viable to be inserted
    }

  //if all three values return false it means the number was not found in the row or column and can be added in
  if(!col_fill && !row_fill && !noctave){

    arr[row_count][col_Loc].num = number;
    arr[row_count][col_Loc].filled = true;
    }
  }
  return true;
}

//This funtion solves the game after being intialized
bool Ai(Game board[ROWS][COLS]){
srand(time(NULL));
int row_Loc=0, col_Loc=0;
int sum, number, count=0;
bool row=false, col=false, noctave=false, inside=false;

//this will fill in the row with a num not used yet
    while(sum!=81){
      sum=0;
      count++;
      if(count==10000){
        cout << "********FAILED*******\nProgram failed to solve after: "<< count << " iterations\n\n";
        return true;}
        //while(!inside){
          for(int i=0; i<ROWS; i++){
            number = (rand() %9)+1;
              for(int j=0; j<COLS; j++){

                row=checkRow(i, number, board);
                col=checkCol(j, number, board);
                noctave = Noctave(j, i, number, board);
                if(!row && !col && !noctave){
                  board[i][j].num=number;
                  board[i][j].filled=true;

                }
              }
            }
        //}

        //will print it's progress every 100 iterations
      if(count%100==0){
        Print(board);
        cout<<"ITERATION::::::## " << count << endl;
      }

      for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
          sum += board[i][j].filled;
          }
      }

    }
    cout<<"\n*********SOLVED***********\n";
    Print(board);
    cout<<"Solved after: " << count << " iterations\n";
    return true;
}


int main(){
Game board[ROWS][COLS];
int col=COLS;
int row=ROWS;
int count=0;
bool initial=false, solve=false;


//intialize the board twice for some randomness
//I know this is a weird way to intialize twice, but it's the only way the program wouldn't crash
while(!initial){
  initial=intialize(row, col, board);
}
if(initial){
  initial = false;
  while(!initial){
    initial=intialize(row, col, board);
  }
}
Print(board);
cout<< "\n*************ATTEMPTING TO SOLVE GAME*************\n";
while(!solve){
  count++;
  cout << "\n**attempting resolve**\n###" << count<<endl;
  solve=Ai(board);


}
//Ai(board);
Print(board);



  return 0;
}
