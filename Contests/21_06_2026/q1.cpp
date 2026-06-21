class Solution {
private:
    void helper(string &moves, int &x, int &y, char &lastMove, char &currMove, int idx){

        if(idx >= moves.size()){
            if(lastMove=='#'){
                x+=moves.size()-1;
                return;
            }
            return;
        }
        
            if(currMove == 'U')
                    y++;
            else if (currMove == 'D')
                y--;

            else if (currMove == 'L')
                x--;

            else if (currMove == 'R')
                x++;

            else{
                if((idx==0 || lastMove=='#')){
                    helper(moves,x,y,lastMove,moves[idx+1],idx+1);
                    
                }
                // currMove=='_'
                else
                    helper(moves,x,y,lastMove,lastMove,idx+1);
            }
    }
public:
    int maxDistance(string moves) {
        char lastMove = '#';
        int size = moves.size();
        int x=0,y=0;

        if(size==1 && moves[0] == '_'){
            return abs(1-0) + abs(y-0);
        }

        for(int i = 0; i < size; i++){
            if(i==0)
                helper(moves,x,y,lastMove,moves[i], i);

            else{
                lastMove=moves[i-1];
                helper(moves,x,y,lastMove,moves[i], i);
            }
        }

        return abs(x-0) + abs(y-0);
    }
};