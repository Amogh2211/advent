// Author: πα

#include <bits/stdc++.h>
// using namespace std;
#define long int64_t
#define FILENAME "input.txt" 
#define MAX_VECTOR_SIZE 10


bool part_one(std::vector<int> vec)
{   
    int max_diff = 0; int min_diff = 0;
    bool diff_works = true;
    for (int i = 0; i < vec.size() - 1; ++i){
        int diff = abs(vec[i] - vec[i+1]);
        if(!(diff >= 1 && diff <= 3)){
            diff_works = false;
            break;
        }
    }
    
    bool isSafe = (std::is_sorted(vec.begin(), vec.end()) && diff_works) || (std::is_sorted(vec.begin(), vec.end(), std::greater<>()) && diff_works);
    return isSafe;
}

bool part_two(std::vector<int> vec)
{
    bool isSafe = false;
    for (int index = 0; index  < vec.size(); ++index){
        std::vector<int> temp = vec;
        temp.erase(temp.begin() + index);
        if(part_one(temp)){
            isSafe = true;
            break;
        }
    }
    return isSafe;
}


int main()
{
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    std::ifstream file(FILENAME);
    
    std::string line, str;
    
    int res = 0;
    int count = 0;
    
    if (file.is_open()) {
        while (std::getline(file, line)) {
            count++;
            std::vector<int> vec;

            std::stringstream ss(line);
            
            // get everything into an int vector
            while (getline(ss, str, ' '))
            {
                vec.push_back(stoi(str));
            }

            bool isSafe = part_one(vec);
            if(isSafe)
                res++;

            // if not safe then we send it to the part two of the statement
            else{
                isSafe = part_two(vec);
                if(isSafe)
                    res++;
            }
        }
        
    }
    

    std::cout << "Result = " << res << '\n';
    file.close();
    return 0;
}
