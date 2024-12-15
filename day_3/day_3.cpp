// Author: πα

#include <bits/stdc++.h>

#define long int64_t
#define FILENAME "input.txt" 


std::vector<std::string> split(char* s, const char* delimiter) {
    std::vector<std::string> tokens;
    char* token;

    token = strtok(s, delimiter);
    while (token != NULL) {
        tokens.push_back(std::string(token));
        token = strtok(NULL, delimiter);
    }
    
    return tokens;
}


int main()
{
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    std::ifstream file(FILENAME);

    std::vector<std::string> tokens;


    if (!file.is_open()) {
        std::cerr << "Error opening the file!";
        return 1;
    }
    
    std::string s;
    std::string delimiter = "mul";

    while (getline(file, s)){
        char* line = new char[s.length() + 1];
        char* delimiter = "mul";

        std::strcpy(line, s.c_str());
        tokens = split(line, delimiter);
        delete[] line;
    }
        
    // Print the tokens stored in the vector
    for (const auto& t : tokens) {
        std::cout << t << std::endl;
    }
    /////////////////////////////////////////////

    for (int i = 0; i < tokens.size(); ++i){
        if(tokens[i][0] != '('){
            continue;
        }
        std::string temp;
        for (int j = 0; j < tokens[i].length(); ++j){
            
        }
    }
    
    return 0;
}
