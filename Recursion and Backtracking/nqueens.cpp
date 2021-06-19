    /*
    1. You are given a number n, the size of a chess board.
    2. You are required to place n number of queens in the n * n cells of board such that no queen can kill another.
    Note - Queens kill at distance in all 8 directions
    3. Complete the body of printNQueens function - without changing signature - 
    to calculate and print all safe configurations of n-queens. 


    very basic idea is , first try and put one queen in every row, then check if its valid answer;
    if it isnt , go back and try another column

    */

    #include<bits/stdc++.h>
    using namespace std;


    bool isSafe(vector<vector<int>>chess,int row,int col) {
        // diagonal check
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
                if(chess[i][j] == 1){
                    return false;
                }
            }
    // vertical check
            for(int i = row - 1, j = col; i >= 0; i--){
                if(chess[i][j] == 1){
                    return false;
                }
            }
    // another daigonal check
            for(int i = row - 1, j = col + 1; i >= 0 && j < chess.size(); i--, j++){
                if(chess[i][j] == 1){
                    return false;
                }
            }
    // horizontal check
            for(int i = row, j = col - 1; j >= 0; j--){
                if(chess[i][j] == 1){
                    return false;
                }
            }

            return true;

    }
    void queens(vector<vector<int> >chess,string qsf,int row){


        if(row == chess.size()){
            cout << qsf << "." << endl;
            return ;
        }
        for(int i=0;i<chess.size();i++){
            //  check karo safe position hai ki nahi fir aage badho .
        if(isSafe(chess,row,i)==true){
                chess[row][i]=1;// ye recursion call se pehle mark
        queens(chess,qsf+to_string(row)+"-"+to_string(i)+", ",row+1);
        chess[row][i]=0;// ye recursion call ke baad unmark
        }
    }
    }
    int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin >> n;
        vector<vector<int> > chess(n,vector<int>(n,0));
        queens(chess,"",0);
        }
