import turtle

def c_curve(depth: int):
    
    start = "+f--f+"
    for i in range(depth):
        string = ""
        for j in range(len(start)):
            
            if start[j] == 'f':
                string += "+f--f+"
            else:
                string += start[j]
        start = string
        
    return start

def main():
    
    string = c_curve(depth=4)
    rules = {
            'f': [t.forward, 10],
            '+': [t.right, 45],
            '-': [t.left, 45],
        }
    
    for i in range(len(string)):
        rules.get(string[i])[0](rules.get(string[i])[1])        


t = turtle.Turtle()
main()
turtle.mainloop()
turtle.done()