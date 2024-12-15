// Author: πα

#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;
#define long int64_t

long solve(vector<int> left, vector<int> right)
{
    // sort the vectors first
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    
    long last_element = right[right.size() - 1];
    std::cout << "Last Element = " << last_element << '\n';

    vector<int> freq(last_element);
    for (int i = 0; i < right.size(); ++i){
        freq[right[i]]++;
    }

    long res = 0; 
    for (int i = 0; i < left.size(); ++i){
        res += left[i] * freq[left[i]];
    }
   
    return res;
}


// Do file IO here
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    vector<int> left; vector<int> right;
    
    std::string line;
    std::fstream file("input.txt", std::ios_base::in);

    int temp_left, temp_right;
    while(file >> temp_left && file >> temp_right){ 
        left.push_back(temp_left); right.push_back(temp_right);
    }
    
    long result = solve(left, right);
    std::cout << "Result is: " << result << '\n';

    return 0;
}
