#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Nov  4 14:50:52 2021

@author: ed20b3m
"""

def main():
    fileOBJ = open("squares", "w")
    for x in range(1, 100):
        y = x * x
        squarestr = str(y)
        fileOBJ.write(squarestr + "\n")
    fileOBJ.close()
