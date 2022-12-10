#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <numeric>
#include <algorithm>


std::vector<std::vector<int>> read_data()
{
  std::string line;
  auto path = std::filesystem::current_path().string() + "/../../day1/inputs/input.txt";
  std::ifstream input (path);
  std::vector<std::vector<int>> data;
  data.emplace_back();
  while ( getline (input,line) )
  {
    if (!line.empty())
      data.back().emplace_back(std::stoi(line));
    else
      data.emplace_back();
  }
  input.close();
  return data;
}

int solve_first_part()
{
  auto data = read_data();
  int max_sum = 0;
  for (auto elem : data) {
    auto result = std::reduce(elem.begin(), elem.end());
    if (max_sum < result)
      max_sum = result;
  }
  return max_sum;
}

int second_second_part()
{
  auto data = read_data();
  std::vector<int> vector_sum;
  for (auto elem : data) {
    vector_sum.emplace_back(std::reduce(elem.begin(), elem.end()));
  }
  std::sort(vector_sum.begin(), vector_sum.end(), std::greater<int>());
  return std::reduce(vector_sum.begin(), vector_sum.begin() + 3);
}

int main() {
  std::cout << "First_part: " << solve_first_part() << std::endl;
  std::cout << "Second_part: " << second_second_part() << std::endl;
  return 0;
}
