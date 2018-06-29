According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
Seen this question in a real interview before?  YesNo

class Solution {
  int getNeighbour(vector<vector<int>>& board, int p, int q, int m , int n) {
      
    int total = 0;
    for(int i = max(p-1, 0); i <= min(p+1, m); i++) {
        for(int j = max(0, q-1); j <= min(q+1, n); j++) {
            if(i == p && j == q) continue;
              total+=board[i][j] & 1;
        }
    }
    //cout << total << endl;
    return total;
  }    

public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
            int total = getNeighbour( board, i, j, m-1, n-1); 
            cout << total <<endl;
            if(board[i][j] == 0) {
                if(total == 3)  board[i][j] = 2;
            }
            else {
                if(total == 2 || total == 3) board[i][j] = 3;
            }
          }
        }
        
        //int total = 0;
        for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
              board[i][j] >>= 1;      
          }
        }   
    }
};

// Infinite solution


    private Set<Coord> gameOfLife(Set<Coord> live) {
        Map<Coord,Integer> neighbours = new HashMap<>();
        for (Coord cell : live) {
            for (int i = cell.i-1; i<cell.i+2; i++) {
                for (int j = cell.j-1; j<cell.j+2; j++) {
                    if (i==cell.i && j==cell.j) continue;
                    Coord c = new Coord(i,j);
                    if (neighbours.containsKey(c)) {
                        neighbours.put(c, neighbours.get(c) + 1);
                    } else {
                        neighbours.put(c, 1);
                    }
                }
            }
        }
        Set<Coord> newLive = new HashSet<>();
        for (Map.Entry<Coord,Integer> cell : neighbours.entrySet())  {
            if (cell.getValue() == 3 || cell.getValue() == 2 && live.contains(cell.getKey())) {
                newLive.add(cell.getKey());
            }
        }
        return newLive;
    }
where Coord is:

    private static class Coord {
        int i;
        int j;
        private Coord(int i, int j) {
            this.i = i;
            this.j = j;
        }
        public boolean equals(Object o) {
            return o instanceof Coord && ((Coord)o).i == i && ((Coord)o).j == j;
        }
        public int hashCode() {
            int hashCode = 1;
            hashCode = 31 * hashCode + i;
            hashCode = 31 * hashCode + j;
            return hashCode;
        }
    }
and the wrapper:

    public void gameOfLife(int[][] board) {
        Set<Coord> live = new HashSet<>();
        int m = board.length;
        int n = board[0].length;
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                if (board[i][j] == 1) {
                    live.add(new Coord(i,j));
                }
            }
        };
        live = gameOfLife(live);
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                board[i][j] = live.contains(new Coord(i,j))?1:0;
            }
        };
        
    }
