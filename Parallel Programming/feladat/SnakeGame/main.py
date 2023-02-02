# Project made by: Szilárd Kristóf Babik
# Date: 2022.02.25
#
# Description:
# This program is a Snake game which uses multithreading using the library threading.
# The game saves high scores to a file.
# Two threads are being used: one for rendering the screen, and one for handling the keyboard inputs.
# The game is played by pressing the arrow keys.
# The game can be paused by clicking the X button in the top right corner of the window.

from turtle import Screen
from snake import Snake
from food import Food
from scoreboard import Scoreboard
import threading
import time


def update_game():
    screen.update()
    time.sleep(0.09)
    snake.move()


screen = Screen()
screen.setup(width=600, height=600)
screen.bgcolor("black")
screen.title("Babik Szilárd Kristóf - A6NQW1 - Snake")
screen.tracer(0)

snake = Snake()
food = Food()
scoreboard = Scoreboard()

listenThread = threading.Thread(target=screen.listen())  # Thread that listens to keyboard input
listenThread.start()
screen.onkey(snake.up, "Up")
screen.onkey(snake.down, "Down")
screen.onkey(snake.left, "Left")
screen.onkey(snake.right, "Right")


game_is_on = True
while game_is_on:
    renderThread = threading.Thread(target=update_game())  # Thread that updates the game
    renderThread.start()

    if snake.collision_with_food_detected(food):
        food.refresh()
        scoreboard.increase_score()
        snake.extend()

    if snake.collision_with_object_detected():
        scoreboard.reset()
        snake.reset()
