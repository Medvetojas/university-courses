from turtle import Turtle
SCOREBOARDPOS = (0, 255)
EXITPOS = (200, -275)


class Scoreboard(Turtle):

    def __init__(self):
        super().__init__()
        self.score = 0
        with open("highscore.txt", "r") as file:
            self.highscore = int(file.read())
        self.color("white")
        self.hideturtle()
        self.draw()


    def draw(self):
        self.clear()
        self.hideturtle()
        self.penup()
        self.goto(SCOREBOARDPOS)
        self.write(f"Score: {self.score} || High Score: {self.highscore}", False, align="center", font=("Arial", 24, "normal"))
        self.goto(EXITPOS)
        self.write(f"Press the X button to quit", False, align="center", font=("Arial", 10, "normal"))

    def increase_score(self):
        self.score += 1
        self.draw()

    def reset(self):
        if self.score > self.highscore:
            self.highscore = self.score
            with open("highscore.txt", "w") as file:
                file.write(str(self.highscore))
        self.score = 0
        self.draw()
