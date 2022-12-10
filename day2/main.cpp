#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>
#include <numeric>
#include <utility>
#include <map>

std::vector<std::pair<char, char>> read_data()
{
  std::string line;
//  auto path = std::filesystem::current_path().string() + "/../../day2/inputs/test_input.txt";
  auto path = std::filesystem::current_path().string() + "/../../day2/inputs/input.txt";
  std::ifstream input (path);

  std::vector<std::pair<char, char>> data;
  while (getline(input, line)) {
    auto test = line[0];
    auto elem = std::pair<char, char>(line[0], line[2]);
    data.emplace_back(elem);
  }
  input.close();
  return data;
}
enum points_per_game
{
    loss = 0,
    dead_heat = 3,
    win = 6
};

enum points_for_elem
{
    kamen = 1,
    bumaga = 2,
    nozhn = 3
};

int solve_first_part()
{
  std::map<std::pair<char, char>, int> map_cond_win;
  map_cond_win[std::make_pair('A', 'X')] = points_per_game::dead_heat + 1;
  map_cond_win[std::make_pair('A', 'Y')] = points_per_game::win + 2;
  map_cond_win[std::make_pair('A', 'Z')] = points_per_game::loss + 3;
  map_cond_win[std::make_pair('B', 'X')] = points_per_game::loss + 1;
  map_cond_win[std::make_pair('B', 'Y')] = points_per_game::dead_heat + 2;
  map_cond_win[std::make_pair('B', 'Z')] = points_per_game::win + 3;
  map_cond_win[std::make_pair('C', 'X')] = points_per_game::win + 1;
  map_cond_win[std::make_pair('C', 'Y')] = points_per_game::loss + 2;
  map_cond_win[std::make_pair('C', 'Z')] = points_per_game::dead_heat + 3;

  auto data = read_data();
  int sum_score = 0;
  for (auto elem:data) {
    sum_score += map_cond_win[elem];
  }
  return sum_score;
}

int solve_second_part()
{
  std::map<std::pair<char, char>, int> map_cond_win; // камень, бумага, ножницы
  map_cond_win[std::make_pair('A', 'X')] = points_per_game::loss + points_for_elem::nozhn;
  map_cond_win[std::make_pair('A', 'Y')] = points_per_game::dead_heat + points_for_elem::kamen;
  map_cond_win[std::make_pair('A', 'Z')] = points_per_game::win + points_for_elem::bumaga;
  map_cond_win[std::make_pair('B', 'X')] = points_per_game::loss + points_for_elem::kamen;
  map_cond_win[std::make_pair('B', 'Y')] = points_per_game::dead_heat + points_for_elem::bumaga;
  map_cond_win[std::make_pair('B', 'Z')] = points_per_game::win + points_for_elem::nozhn;
  map_cond_win[std::make_pair('C', 'X')] = points_per_game::loss + points_for_elem::bumaga;
  map_cond_win[std::make_pair('C', 'Y')] = points_per_game::dead_heat + points_for_elem::nozhn;
  map_cond_win[std::make_pair('C', 'Z')] = points_per_game::win + points_for_elem::kamen;

  auto data = read_data();
  int sum_score = 0;
  for (auto elem:data) {
    sum_score += map_cond_win[elem];
  }
  return sum_score;
}

int main() {
  std::cout << "First_part: " << solve_first_part() << std::endl;
  std::cout << "Second_part: " << solve_second_part() << std::endl;
  return 0;
}
