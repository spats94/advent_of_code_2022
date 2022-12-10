#include <iostream>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <vector>
#include <regex>

struct Elves {
    int first_id;
    int second_id;
};

std::vector<std::pair<Elves, Elves>> read_data()
{
  //  auto path = std::filesystem::current_path().string() + "/../../day4/inputs/test_input.txt";
  auto path = std::filesystem::current_path().string() + "/../../day4/inputs/input.txt";
  std::ifstream input (path);
  std::string line;
  std::vector<std::pair<Elves, Elves>> data;

  while (getline(input, line)) {
    std::regex words_regex("[0-9]+");
    auto words_begin = std::sregex_iterator(line.begin(), line.end(), words_regex);
    auto words_end = std::sregex_iterator();
    std::sregex_iterator i = words_begin;
    std::vector<int> vector_temp;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
      std::smatch match = *i;
      int match_int = std::stoi(match.str());
      vector_temp.emplace_back(match_int);
    }
    data.emplace_back(Elves{.first_id = vector_temp[0], .second_id = vector_temp[1]},
                      Elves{.first_id = vector_temp[2], .second_id = vector_temp[3]});
  }
  input.close();
  return data;
}

int solve_first_part()
{
  auto data = read_data();
  int count = 0;
  for (auto elem:data) {
    if (elem.first.first_id >= elem.second.first_id &&  elem.first.second_id <= elem.second.second_id) {
      count++;
      continue;
    }
    if (elem.second.first_id >= elem.first.first_id &&  elem.second.second_id <= elem.first.second_id) {
      count++;
      continue;
    }
  }
  return count;
}

int solve_second_part()
{
  auto data = read_data();
  int count = 0;
  for (auto elem:data) {
    if (elem.first.first_id >= elem.second.first_id && elem.first.first_id <= elem.second.second_id) {
      count++;
      continue;
    }
    if (elem.second.first_id >= elem.first.first_id && elem.second.first_id <= elem.first.second_id) {
      count++;
      continue;
    }
  }
  return count;
}

int main() {
  std::cout << "First_part: " << solve_first_part() << std::endl;
  std::cout << "Second_part: " << solve_second_part() << std::endl;
  return 0;
}
