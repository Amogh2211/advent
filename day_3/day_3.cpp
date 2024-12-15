// Author: πα

#include <bits/stdc++.h>
#include <regex>

#define long int64_t
#define FILENAME "input.txt" 


void solve(std::string& buffer){
    long res = 0;

    // finds string of type needed

    // use this for part 1
    // std::regex mul_regex(R"(mul\([0-9]{1,3},[0-9]{1,3}\))");

    // use this for part 2
    std::regex mul_regex(R"(mul\([0-9]{1,3},[0-9]{1,3}\)|do\(\)|don't\(\))");
    
    
    auto mul_regex_iter_begin = std::sregex_iterator(buffer.begin(), buffer.end(), mul_regex);
    auto mul_regex_iter_end = std::sregex_iterator();

    std::regex num_regex(R"(\b[0-9]{1,3}\b)");
    bool mul_true = true;
    
    for (std::sregex_iterator i = mul_regex_iter_begin; i != mul_regex_iter_end; i++) {
        std::smatch match = *i;
        std::string s_match = match.str();

        if (s_match == "do()") mul_true = true;
        if (s_match == "don't()") mul_true = false;
    

        auto num_regex_iter_begin = std::sregex_iterator(s_match.begin(), s_match.end(), num_regex);
        auto num_regex_iter_end = std::sregex_iterator();
        std::vector<int> two_num;
        for (std::sregex_iterator j = num_regex_iter_begin; j != num_regex_iter_end; j++) {
            std::smatch num = *j;
            std::string num_s_match = num.str();
            two_num.push_back(std::stoi(num_s_match)); 
        }

        if (two_num.size() == 2 && mul_true) {
            std::cout << "num1 : " << two_num[0] << " num2: " << two_num[1] << '\n'; 
            res += two_num[0]*two_num[1]; 
        }
    }

    std::cout << "Result = " << res << '\n';


}

int main()
{
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    std::ifstream file(FILENAME);
    std::stringstream buffer; buffer << file.rdbuf();

    std::string input = buffer.str();

    // wanted to give input directly as buffer.str() but const says no
    solve(input);


    return 0;
}
