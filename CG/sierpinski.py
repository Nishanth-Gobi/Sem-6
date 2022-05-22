import turtle


def sierpinski(depth):

    start = "f-g-g"
    for i in range(depth):
        string = ""
        for j in range(len(start)):

            if start[j] == 'f':
                string += "f-g+f+g-f"
            elif start[j] == 'g':
                string += "gg"
            else:
                string += start[j]

        start = string

    return start


if __name__ == '__main__':

    t = turtle.Turtle()
    string = sierpinski(depth=3)

    for i in range(len(string)):
        if string[i] == 'f' or string[i] == 'g':
            t.forward(20)
        elif string[i] == '-':
            t.left(120)
        elif string[i] == '+':
            t.right(120)

    turtle.mainloop()
    turtle.done()