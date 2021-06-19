
/*
1. You are given a number n, the size of a chess board.
2. You are given a row and a column, as a starting point for a knight piece.
3. You are required to generate the all moves of a knight starting in (row, col) such that knight visits 
all cells of the board exactly once.
4. Complete the body of printKnightsTour function - without changing signature - to calculate and 
print all configurations of the chess board representing the route
of knight through the chess board.
*/

// array vs vector wali nautanki bhi hogi , to aese sawalon mein array hi use karna hai vrna tle 

#include<bits/stdc++.h>
using namespace std;
int chess[50][50];

void printKnightsTour(int chess[][50],int n, int r, int c, int upcomingMove){

    if(r < 0 || c < 0 || r >= n || c >= n || chess[r][c] != 0)
            return;
    if( upcomingMove == n*n ){
            chess[r][c]=upcomingMove;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << chess[i][j] <<  " ";
            }
            cout << endl;
        }
        cout << endl;
    chess[r][c]=0;
        return;
    }
        chess[r][c] = upcomingMove;
        //  basic idea is ki knight ek jagah se 8 jagah jaa skta hai
        // to vo saare travel karo with a negative condition.

        printKnightsTour(chess, n ,r - 2, c + 1 , upcomingMove + 1);
        printKnightsTour(chess, n ,r - 1, c + 2 , upcomingMove + 1);
        printKnightsTour(chess, n ,r + 1, c + 2 , upcomingMove + 1);
        printKnightsTour(chess, n ,r + 2, c + 1 , upcomingMove + 1);
        printKnightsTour(chess, n ,r + 2, c - 1 , upcomingMove + 1);
        printKnightsTour(chess, n ,r + 1, c - 2 , upcomingMove + 1);
        printKnightsTour(chess, n ,r - 1, c - 2 , upcomingMove + 1);
        printKnightsTour(chess, n ,r - 2, c - 1 , upcomingMove + 1);
        chess[r][c] = 0;
}
int32_t main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      int n;
      cin >> n;
      int r,c;
      cin >> r >> c;
      printKnightsTour(chess,n,r,c,1);
}
