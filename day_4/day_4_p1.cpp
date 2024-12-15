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

bool findWord(int index, string word, vector<string> &grid,
              int x, int y, int dirX, int dirY) {
    
    if (index == word.length()) return true;
    
    if (validCoord(x, y, grid.size(), grid[0].size())
        && word[index] == grid[x][y])
        return findWord(index+1, word, grid, x+dirX, 
                        y+dirY, dirX, dirY);
        
    return false;
}

int searchWord(vector<string>grid, string word){
    int m = grid.size();
    int n = grid[0].length();
    
    int res = 0;
    vector<vector<int>>ans;
    
    // x and y are used to set the direction in which to move
    vector<int>x = { -1, -1, -1, 0, 0, 1, 1, 1 };
    vector<int>y = { -1, 0, 1, -1, 1, -1, 0, 1 };
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            // Search in all 8 directions
            for (int k=0; k<8; k++) {
                if (findWord(0, word, grid, i, j, x[k], y[k])) {
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
    for (int i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << '\n';
    }
    
    int res = searchWord(vec, "XMAS");


    std::cout << "Result : " << res << '\n';
    return 0;
}