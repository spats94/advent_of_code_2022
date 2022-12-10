#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>
#include <utility>
#include <algorithm>

using Rukzak = std::pair<std::string, std::string>;

std::vector<Rukzak> read_data()
{

//  auto path = std::filesystem::current_path().string() + "/../../day3/inputs/test_input.txt";
  auto path = std::filesystem::current_path().string() + "/../../day3/inputs/input.txt";
  std::ifstream input (path);

  std::string line;
  std::vector<Rukzak> data;
  while (getline(input, line)) {
    data.emplace_back(line.substr(0, line.size() / 2), line.substr(line.size() / 2));
  }
  input.close();
  return data;
}

std::vector<std::string> read_data1()
{
//  auto path = std::filesystem::current_path().string() + "/../../day3/inputs/test_input.txt";
  auto path = std::filesystem::current_path().string() + "/../../day3/inputs/input.txt";
  std::ifstream input (path);

  std::string line;
  std::vector<std::string> data;
  while (getline(input, line)) {
    data.emplace_back(line);
  }
  input.close();
  return data;
}

int solve_first_part()
{
  auto data = read_data();
  int result = 0;
  for (auto el:data) {
    for (auto ch: el.first) {
      auto count = std::count_if(el.second.begin(), el.second.end(), [&ch](char c) { return c == ch; });
      if (count > 0) {
        if ('A' < ch && ch <= 'Z') {
          result += ch - 'A' + 27;
        } else {
          result += ch - 'a' + 1;
        }
        break;
      }
    }
  }
  return result;
}

int solve_second_part()
{
  auto data = read_data1();
  int result = 0;
  for (int i = 0; i < data.size(); i+=3)
  {
    for (auto ch:data[i]) {
      auto count2 = std::count_if(data[i+1].begin(), data[i+1].end(), [&ch](char c) { return c == ch; });
      auto count3 = std::count_if(data[i+2].begin(), data[i+2].end(), [&ch](char c) { return c == ch; });
      if (count2 > 0 && count3 > 0) {
        if ('A' < ch && ch <= 'Z') {
          result += ch - 'A' + 27;
        } else {
          result += ch - 'a' + 1;
        }
        break;
      }
    }
  }
  return result;
}

int main() {
  std::cout << "First_part: " << solve_first_part() << std::endl;
  std::cout << "Second_part: " << solve_second_part() << std::endl;
  return 0;
}
