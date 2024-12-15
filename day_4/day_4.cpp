// Author: yeeter

#include <bits/stdc++.h>
using namespace std;
#define long int64_t
#define FILENAME "input.txt"


bool validCoord(int x, int y, int m, int n) {
    if (x>=0 && x<m && y>=0 && y<n)
        return true;
    return false;
}

bool findWord(int index, vector<string> &grid,
              int x, int y) {
    bool flag_1 = false;
    bool flag_2 = false;
    // top left and bottom right
    if (validCoord(x - 1, y - 1, grid.size(), grid[0].size()) and validCoord(x + 1, y + 1, grid.size(), grid[0].size()) ){
        flag_1 = (grid[x - 1][y - 1] == 'M' && grid[x + 1][y + 1] == 'S') || (grid[x - 1][y - 1] == 'S' && grid[x + 1][y + 1] == 'M');
    }

    // bottom left and top right
    if (validCoord(x - 1, y + 1, grid.size(), grid[0].size()) and validCoord(x + 1, y - 1, grid.size(), grid[0].size()) ){
        return flag_1 &= (grid[x - 1][y + 1] == 'M' && grid[x + 1][y - 1] == 'S') || (grid[x - 1][y + 1] == 'S' && grid[x + 1][y - 1] == 'M');
    }
    return false;
}

int searchWord(vector<string>grid, string word){
    
    int res = 0;
    vector<vector<int>>ans;
    
    // x and y are used to set the direction in which to move
    
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].length(); j++){
            // Find A
            if(grid[i][j] == 'A'){
                // check for M and S in four diagonal directions
                if (findWord(0, grid, i, j)) {
                    res++;
                }
            }
        }
    }
    return res;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    std::ifstream file(FILENAME);
    std::vector<std::string> vec;

    if (!file.is_open()) {
        std::cerr << "Error opening the file!";
        return 1;
    }

    // load vector of strings
    std::string temp;
    while(getline(file, temp)){
        vec.push_back(temp);
    }    

    // debug prints
    // for (int i = 0; i < vec.size(); ++i){
    //     std::cout << vec[i] << '\n';
    // }
    
    int res = searchWord(vec, "XMAS");


    std::cout << "Result : " << res << '\n';
    return 0;
}
