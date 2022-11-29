#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 14 14:30:58 2021

@author: ed20b3m
"""


def count_occurences(input_string):
    input_list = list(input_string.split(", "))
    count_list = [["filler", 0]]

    for x in input_list:
        found = False
        count = 0
        for y in count_list:
            if(x == y[0]):
                y[1] = y[1] + 1
                found = True
                break
            else:
                count = count + 1

        if(not found):
            count_list.append([x, 1])

    highest = [["filler", 0]]
    for z in count_list:
        if (z[1] > highest[0][1]):
            highest = [z]
        elif (z[1] == highest[0][1]):
            highest.append(z)
    return highest
