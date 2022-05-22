import turtle

def dragon_curve(depth: int):

    start = "f-h"
    for i in range(depth):
        string = ""
        for j in range(len(start)):
            
            if start[j] == 'f':
                string += "f-h"
            elif start[j] == 'h':
                string += "f+h"
            else:
                string += start[j]
            
        start = string
        
    return start


def main():

    t.left(90)
    string = dragon_curve(depth=5)

    rules = {
            'f': [t.forward, 10],
            'h': [t.forward, 10],
            '+': [t.right, 90],
            '-': [t.left, 90],
        }
    
    for i in range(len(string)):
        rules.get(string[i])[0](rules.get(string[i])[1])        


t = turtle.Turtle()
main()
turtle.mainloop()
turtle.done()