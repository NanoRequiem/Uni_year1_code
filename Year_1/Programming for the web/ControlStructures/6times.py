#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct  7 13:28:46 2021

@author: ed20b3m
"""

userInput1 = int(input("please enter a number: "))
userInput2 = int(input("please enter another number: "))

sum = 0

for x in range(userInput1, userInput2 + 1):
    sum += x

print("the sum is", sum)
