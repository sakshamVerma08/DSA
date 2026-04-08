class Robot {
private:
    vector<vector<int>> pos;
    int currentPos=0;
    int dir = 101;//ASCII value for 'e'.
    bool flag = false;
    // ASCII 'e' = 101, 's' = 115, 'n' = 110, 'w' = 119
public:
    Robot(int width, int height) {
        // For bottom boundary dir = 'E'.
        dir=101;
        for(int x = 0; x < width; x++){
            pos.emplace_back(vector<int>{x,0,101});
        }
        //For Right column, dir = 'N'
        for(int y = 1; y < height; y++){
            pos.emplace_back(vector<int>{width-1,y,110});
        }

        // For Top Boundary, dir = 'W'.
        for(int x = width-2; x>=0;x--){
            pos.emplace_back(vector<int>{x,height-1,119});
        }

        // For Left column, dir = 'S'.
        for(int y = height-2; y>0;y--){
            pos.emplace_back(vector<int>{0,y,115});
        }

        pos[0][2] = 115; // While pre-computing the directions for each cell, make sure that the direction for (0,0) cell should be South facing. This is because i've taken a flag variable that represents whether the robot has moved at all or not. If the robot has moved, i set flag = true.
        
    // Imagine we go around the grid once, return back at (0,0). According to my Idea, the direction at (0,0) should be South, not east, because i came from West->counterclockwise turn. So I handle the case when the robot has NOT moved manually, because i can't rely on pos table to return the correct direction for (0,0) cell.
    }
    
    void step(int num) {
        currentPos = (currentPos+num)%pos.size();
        flag=true;
    }
    
    vector<int> getPos() {
        vector<int> ans = {pos[currentPos][0],pos[currentPos][1]};
        return ans;
    }
    
    string getDir() {
        // Here check if the robot has moved or not. If the robot has not moved, then we can say that the robot is standing at (0,0), and we manually return 'East', becuase we took the initial direction as 'South'.
        if(!flag) return "East";

        int dir = pos[currentPos][2];
        if(dir==101) return "East";
        else if(dir==110) return "North";
        else if (dir == 119) return "West";
        else return "South";

    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
