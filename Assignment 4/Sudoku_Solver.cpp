#include<iostream>
#include<vector>
using namespace std;

int N=9;

void printGrid(int grid[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;

    }
}

bool usedInRow(int grid[9][9], int row, int num)
{
    for(int col=0;col<9;col++)
    {
        if(grid[row][col]==num)
        {
            return true;
        }
    }
    return false;
}

bool usedInCol(int grid[9][9], int col, int num)
{
    for(int row=0;row<9;row++)
    {
        if(grid[row][col]==num)
        {
            return true;
        }
    }
    return false;
}

bool usedInBox(int grid[9][9], int startRow,int startCol, int num)
{
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            if(grid[row+startRow][col+startCol]==num)
            {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[9][9],int row,int col,int num)
{
    return (!usedInRow(grid,row,num) && !usedInCol(grid,col,num) && !usedInBox(grid,row-row%3,col-col%3,num));
}



bool findUnassignedLocation(int grid[9][9], int &row,int &col)
{
    //iterate through the matrix to find any 0, return the value of row and col
    for(row=0;row<N;row++)
    {
        for(col=0;col<N;col++)
        {
            if(grid[row][col]==0)
            {
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int grid[9][9])
{
    int row,col;
    if(!findUnassignedLocation(grid,row,col))
    {
        //all have been assigned
        return true;
    }
    //else find the number which is safe to place in unassigned location
    for(int num=1;num<=9;num++)
    {   
        if(isSafe(grid,row,col,num))
        {
            grid[row][col]=num;
            if(solveSudoku(grid))
            {
                return true;
            }
            //backtrack
            grid[row][col]=0;
        }
    }
    return false;
}

int main()
{
    int grid[9][9] = {
    {5, 0, 4, 0, 0, 0, 0, 6, 0},
    {0, 6, 0, 3, 0, 0, 1, 0, 0},
    {0, 9, 2, 5, 4, 0, 0, 0, 0},
    {6, 0, 8, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 8, 0, 4, 0, 0, 0},
    {0, 0, 0, 2, 0, 0, 6, 0, 1},
    {0, 0, 0, 0, 9, 5, 8, 1, 0},
    {0, 0, 1, 0, 0, 2, 0, 3, 0},
    {0, 8, 0, 0, 0, 0, 2, 0, 7}
    };

    if(solveSudoku(grid))
    {
        printGrid(grid);
    }
    else
    {
        cout<<"No Solution Exists"<<endl;
    }
}