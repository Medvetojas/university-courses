#ifndef PLAYER_H
#define PLAYER_H

typedef struct Players {
    int player_right_point;
    int player_left_point;
} Players;

void init_players(Players* players);

int get_player_right_point(Players* players);
void add_player_right_point(Players* players, int number);

int get_player_left_point(Players* players);
void add_player_left_point(Players* players, int number);
#endif