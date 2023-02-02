#include "include/players.h"

void init_players(Players* players) {
    players->player_right_point = 0;
    players->player_left_point = 0;
}

int get_player_right_point(Players* players) {
    return players->player_right_point;
}

void add_player_right_point(Players* players, int number) {
    players->player_right_point += number;
}

int get_player_left_point(Players* players) {
    return players->player_left_point;
}

void add_player_left_point(Players* players, int number) {
    players->player_left_point += number;
}