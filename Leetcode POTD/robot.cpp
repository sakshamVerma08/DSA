class Solution {
public:
    using pp = pair<int,int>;
    int robotSim(vector<int>& commands, vector<vector<int>>& obs) {
        set<pp> spp;
        int ans=0;
        for(auto &v:obs){
            spp.insert(pp{v[0],v[1]});
        }

        vector<int> p = {0,0};
        char dir = 'N';
        int dist;

        for(int i = 0; i < commands.size();i++){
            // looping from 0 to n-1 (inclusive) where 'n' is number of given commands.
            if(commands[i] == -1){
                if(dir=='N')dir='E';
                else if (dir=='E')dir='S';
                else if (dir=='S')dir='W';
                else dir = 'N';
            }
            else if (commands[i] == -2){
                if(dir=='N')dir = 'W';
                else if (dir == 'W')dir='S';
                else if (dir == 'S') dir = 'E';
                else dir = 'N';
            }
            else{
                int k = commands[i];
                if(dir=='N'){
                    int x,y;
                    for(int h = 0; h < k; h++){
                        // looping from 0 to k-1 (inclusive).
                        x = p[0], y = p[1]+1;
                        if(spp.find(pp{x,y})!=spp.end())
                            break;
                        
                        p[1] = y;
                    }
                    
                }
                else if (dir == 'E'){
                    int x,y;
                    for(int h = 0; h < k; h++){
                        // looping from 0 to k-1 (inclusive).
                        x = p[0]+1, y =p[1];
                        if(spp.find(pp{x,y})!=spp.end())break;

                        p[0] = x;
                    }
                   
                }
                else if (dir == 'W'){

                        int x,y;
                        for(int h = 0; h < k; h++){
                            x = p[0]-1, y = p[1];
                            if(spp.find(pp{x,y})!=spp.end())break;

                            p[0] = x;
                        }
                }

                else{

                   int x,y;
                   for(int h = 0; h < k; h++){
                        x = p[0], y = p[1]-1;
                        if(spp.find(pp{x,y})!=spp.end())break;

                        p[1] = y;
                   }
                }
            }
            dist = (p[0]*p[0]+p[1]*p[1]);
            ans=max(dist,ans);
        }
        return ans;
    }
};
