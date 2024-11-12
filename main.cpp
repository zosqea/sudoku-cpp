#include <iostream>
#include <iterator>



class sudoku
{
private:
  // int board[81];
  int board[81]={0,0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0,0};
public:
  // sudoku(){
  //   // for(int& element: board){
  //   //   element = -1;
  //   // }
  // }
  bool check(){
    for(int i=0; i<9 ;i++){
      int exampleArrayHorizontal[9] = {0,0,0,0,0,0,0,0,0};
      for(int j=0; j<9;j++){
        if(this->board[i*9+j]<10&&this->board[i*9+j]>0)exampleArrayHorizontal[this->board[i*9+j]]++;
        if(exampleArrayHorizontal[this->board[i*9+j]]>1)return false;
      }
      int exampleArrayVertical[9] = {0,0,0,0,0,0,0,0,0};
      for(int j=0; j<9;j++){
        if(this->board[i+j*9]<10&&this->board[i+j*9]>0) exampleArrayVertical[this->board[i+j*9]]++;
        if(exampleArrayVertical[this->board[i+j*9]]>1) return false;
      }
    }
    int b = 0;
    for(int i=0;i<9;){
      int exampleArray[9] = {0,0,0,0,0,0,0,0,0};
      for(int j=0;j<9;j++){
        board[i]
        // if(this->board[i+j*9]<10&&this->board[i+j*9]>0) exampleArrayVertical[this->board[i+j*9]]++;
        // if(exampleArrayVertical[this->board[i+j*9]]>1) return false;
      }
    }
    return true;
  }
  void print(){
    for(int i=0; i<std::size(this->board);i++){
      if(i%3==0&&i%9!=0) std::cout<<'|';
      else if(i%9==0) std::cout<<'\n';
      if(i%27==0) std::cout<<"===========\n";
      if(this->board[i]!=0)std::cout<<this->board[i];
      else std::cout<<" ";
    }
    std::cout<<"\n===========";
  }
};


int main()
{
  sudoku bobr;
  bobr.print();
  std::cout<<'\n'<<bobr.check();
  return 0;
}