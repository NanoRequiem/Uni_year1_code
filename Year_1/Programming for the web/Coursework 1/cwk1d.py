#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Oct 16 11:09:36 2021

@author: ed20b3m
"""


def gameofliferun(origin):
    # table to track each cell's nghbrs
    nghbrs = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]

    xcnt = 0
    for x in origin:
        ycnt = 0
        for y in x:
            if(xcnt == 0):
                # accounts for top right cell within the spread
                if(ycnt == 0):
                    if(origin[xcnt][ycnt + 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt + 1][ycnt] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt + 1][ycnt + 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                # accounts for top right cell within the spread
                elif(ycnt == 19):
                    if(origin[xcnt][ycnt - 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt + 1][ycnt] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt + 1][ycnt - 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                # accounts for top row of the spread
                else:
                    if(origin[xcnt][ycnt + 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt + 1][ycnt] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt + 1][ycnt + 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt][ycnt - 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt + 1][ycnt - 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
            elif(xcnt == 17):
                if(ycnt == 0):
                    if(origin[xcnt - 1][ycnt] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt - 1][ycnt + 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt][ycnt + 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                elif(ycnt == 19):
                    if(origin[xcnt][ycnt - 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt - 1][ycnt] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt - 1][ycnt - 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                else:
                    if(origin[xcnt][ycnt - 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt - 1][ycnt] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt - 1][ycnt - 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt - 1][ycnt + 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt][ycnt + 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
            else:
                if(ycnt == 0):
                    if(origin[xcnt - 1][ycnt] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt - 1][ycnt + 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt][ycnt + 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt + 1][ycnt] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt + 1][ycnt + 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                elif(ycnt == 19):
                    if(origin[xcnt][ycnt - 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt + 1][ycnt] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt + 1][ycnt - 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt - 1][ycnt] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt - 1][ycnt - 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                else:
                    if(origin[xcnt - 1][ycnt] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt - 1][ycnt + 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt - 1][ycnt - 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt][ycnt + 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt][ycnt - 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt + 1][ycnt] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt + 1][ycnt + 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
                    if(origin[xcnt + 1][ycnt - 1] == 1):
                        nghbrs[xcnt][ycnt] = nghbrs[xcnt][ycnt] + 1
            ycnt = ycnt + 1
        xcnt = xcnt + 1

    for z in range(0, 17):
        for w in range(0, 19):
            if((nghbrs[z][w] == 2 or nghbrs[z][w] == 3) and origin[z][w] == 1):
                origin[z][w] = 1
            elif(nghbrs[z][w] == 3 and origin[z][w] == 0):
                origin[z][w] = 1
            else:
                origin[z][w] = 0
    return(origin)


def gameoflife(x_cycle):

    origin = [[0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0],
              [0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0],
              [0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1],
              [0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
    step = 0
    while(step < x_cycle):
        origin = gameofliferun(origin)
        step = step + 1
    return(origin)
