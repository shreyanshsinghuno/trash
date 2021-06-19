/*
FLOODFILL !!!!!! (kaafi important sawal in some senses)
brute force is legit just op.
pen-paper lekr karo.

1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a. The numbers can be 1 or 0 only.
4. You are standing in the top-left corner and have to reach the bottom-right corner. 
Only four moves are allowed 't' (1-step up), 'l' (1-step left), 'd' (1-step down) 'r' (1-step right).
You can only move to cells which have 0 value in them. You can't move out of the boundaries or in the cells 
which have value 1 in them (1 means obstacle)
5. Complete the body of floodfill function - without changing signature - 
to print all paths that can be used to move from top-left to bottom-right.

*/

#include<bits/stdc++.h>
using namespace std;
bool vis[100][100];

void floodfill(vector < vector < int >>  maze, int sr, int sc, string asf,bool vis[][100]) {
  // stupid calls with negative cases which will help in avoiding illegal movements here
  if(sr<0 || sc <0 || sr >= int(maze.size()) || sc>= int(maze[0].size()) || maze[sr][sc]==1 || vis[sr][sc]==1)
  {
      // ye maze wala argument last mein likhna kaafi important hai
      // for example agr row +ive hui , aur maze[row][column]=1 hai to ye condition check hi nahi hogi
      // because or wali cheej aese hi kaam krti hai , ek true mili to aage ki check nahi hogi
      return ;
  }
  if(sr == maze.size()-1 && sc==maze[0].size()-1){
      cout << asf << endl;
      return ;
  }
  vis[sr][sc]=1;
    floodfill(maze,sr-1,sc,asf+'t',vis);
    floodfill(maze,sr,sc-1,asf+'l',vis);
    floodfill(maze,sr+1,sc,asf+'d',vis);
    floodfill(maze,sr,sc+1,asf+'r',vis);
    vis[sr][sc]=0;

}

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    floodfill(arr,0,0,"" ,vis);
}
