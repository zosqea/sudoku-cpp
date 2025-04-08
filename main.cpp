#include <iostream>

bool isValidBoard(int *board);
bool boardGeneration(int *board, int currentIndex, int size);


int main(){
		int aboba [81] = {};
		boardGeneration(aboba,0,81);
		for(int i = 0; i<9; i++){
				for(int j = 0; j<9; j++){
						std::cout<<'['<<aboba[i*9+j]<<']';
				}
				std::cout<<'\n';
		}
		return 0;
}

bool isValidBoard(int *board){
		for(int i = 0; i<9; i++){
				int counterVertical [10] = {};
				int counterHorizontal [10] = {};
				for(int j = 0; j<9; j++){
						int rowValue = board[i*9+j];
						int colValue = board[j*9+i];
						if(rowValue){
								if(counterHorizontal[rowValue]) return false;
								counterHorizontal[rowValue]++;
						}
						if(colValue){
								if(counterVertical[colValue]) return false;
								counterVertical[colValue]++;
						}
				}
		}
		for(int i = 0; i<61; i+=3){
				int counterSquare [10] = {};
				for(int j = 0; j<21; j++){
						int value = board[i+j];
						if(value){
								if(counterSquare[value]) return false;
								counterSquare[value]++;
						}
						if((j+1)%3==0) j+=6;
				}
				if((i/3+1)%3==0) i+=18;
		}
		return true;
}

bool boardGeneration(int *board, int currentIndex, int size){
		if(size==currentIndex) return true; 
		for(int i = 1; i<10; i++){
				board[currentIndex]=i;
				if(isValidBoard(board)){
						if(boardGeneration(board,currentIndex+1,size)) return true;
				}
				board[currentIndex]=0;
		}
		return false;	
}
