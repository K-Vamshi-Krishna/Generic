#include<iostream>
#include<bitset>


bool isValid (int Sudoku[9][9])
{
	int i,j,k,m;
	//check row by row
	for( i =0 ; i<9 ; i++)
	 {
	   std::bitset<9> filled; 
	 for( j=0 ; j<9 ; j++)
       filled.set(Sudoku[i][j]-1);
      if(filled.count()!=9)
       return false;	  
	 }
	//check column by column
	 for( j =0 ; j<9 ; j++)
	 {
	   std::bitset<9> filled; 
	 for( i=0 ; i<9 ; i++)
       filled.set(Sudoku[i][j]-1);
      if(filled.count()!=9)
       return false;	  
	 }
	
	//check 3 by 3 matrix
	 for( i =0 ; i <9 ; i+=3)
	 {
		for( j=0 ; j<9 ; j+=3)
		{
			std::bitset<9> filled;
			for(k=i; k<i+3;k++)
			for(m=j; m<j+3; m++)
			filled.set(Sudoku[k][m]-1); 
			
			if(filled.count()!=9)
			return false;
		}
	 }
	
}


int main()
{
	int Sudoku[9][9];
	std::cout<<isValid(Sudoku)<<std::endl;
}