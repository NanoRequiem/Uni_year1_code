#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 19 15:22:24 2021

@author: ed20b3m
"""


def wordsearch(string_search):
    puzzle = [['R', 'U', 'N', 'A', 'R', 'O', 'U', 'N', 'D', 'D', 'L'],
              ['E', 'D', 'C', 'I', 'T', 'O', 'A', 'H', 'C', 'Y', 'V'],
              ['Z', 'Y', 'U', 'W', 'S', 'W', 'E', 'D', 'Z', 'Y', 'A'],
              ['A', 'K', 'O', 'T', 'C', 'O', 'N', 'V', 'O', 'Y', 'V'],
              ['L', 'S', 'B', 'O', 'S', 'E', 'V', 'R', 'U', 'C', 'I'],
              ['B', 'O', 'B', 'L', 'L', 'C', 'G', 'L', 'P', 'B', 'D'],
              ['L', 'K', 'T', 'E', 'E', 'N', 'A', 'G', 'E', 'D', 'L'],
              ['I', 'S', 'T', 'R', 'E', 'W', 'Z', 'L', 'C', 'G', 'Y'],
              ['A', 'U', 'R', 'A', 'P', 'L', 'E', 'B', 'A', 'Y', 'G'],
              ['R', 'D', 'A', 'T', 'Y', 'T', 'B', 'I', 'W', 'R', 'A'],
              ['T', 'E', 'Y', 'E', 'M', 'R', 'O', 'F', 'I', 'N', 'U']]
    wordcords = []
    wordback = string_search[::-1]
    county = 0
    fndtype = ""

# For loop to iterate through all horizontal lines and check for the word
    for y in puzzle:
        row = ""
        for x in y:
            row = row + x
        if(string_search in row):
            fndtype = "horifor"
            xcoord = findString(row, string_search)
            wordcords.append((xcoord, county))
            break
        elif(wordback in row):
            fndtype = "horiback"
            xcoord = findString(row, wordback)
            wordcords.append((xcoord, county))
            break
        county = county + 1

# for loop to iterater through the virtal lines and check for the word
    for column in range(0, 11):
        columnstr = ""
        for item in range(0, 11):
            columnstr = columnstr + puzzle[item][column]
        if(string_search in columnstr):
            fndtype = "virtfor"
            ycoord = findString(columnstr, string_search)
            wordcords.append((column, ycoord))
            break
        if(wordback in columnstr):
            fndtype = "virtback"
            ycoord = findString(columnstr, wordback)
            wordcords.apppend((column, ycoord))
            break

    diaglen = 11
    for diagnum in range(0, 11):
        diag = ""
        for y in range(0, diaglen):
            diag = diag + puzzle[diagnum + y][0 + y]
        if(string_search in diag):
            fndtype = "diagrightsidefor"
            xcoord = findString(diag, string_search)
            diagy = diagnum + xcoord
            wordcords.append((xcoord, diagy))
            break
        if(wordback in diag):
            fndtype = "diagrightsideback"
            xcoord = findString(diag, wordback)
            diagy = diagnum + xcoord
            wordcords.append((xcoord, diagy))
            break
        diaglen = diaglen - 1

    diaglen = 10
    for diagnum in range(1, 11):
        diag = ""
        for y in range(0, diaglen):
            diag = diag + puzzle[0 + y][diagnum + y]
        if(string_search in diag):
            fndtype = "diagrighttopfor"
            xcoord = findString(diag, string_search)
            diagy = diagnum + xcoord
            wordcords.append((diagy, xcoord))
            break
        if(wordback in diag):
            fndtype = "diagrighttopback"
            xcoord = findString(diag, string_search)
            diagy = diagnum + xcoord
            wordcords.append((diagy, xcoord))
            break
        diaglen = diaglen - 1

    diaglen = 11
    diagnum = 10
    while(diagnum >= 0):
        diag = ""
        for y in range(0, diaglen):
            diag = diag + puzzle[0 + y][diagnum - y]
        if(string_search in diag):
            fndtype = "diaglefttopfor"
            xcoord = findString(diag, string_search)
            diagy = diagnum - xcoord
            wordcords.append((diagy, xcoord))
        if(wordback in diag):
            fndtype = "diaglefttopback"
            xcoord = findString(diag, wordback)
            diagy = diagnum - xcoord
            wordcords.append((diagy, xcoord))
        diaglen = diaglen - 1
        diagnum = diagnum - 1

    diaglen = 10
    diagnum = 0
    while(diagnum <= 10):
        diag = ""
        for y in range(0, diaglen):
            diag = diag + puzzle[diagnum+y][10-y]
        if(string_search in diag):
            fndtype = "diagleftsidefor"
            coord = findString(diag, string_search)
            xcoord = 10 - coord
            diagy = diagnum + coord
            wordcords.append((xcoord, diagy))
        if(wordback in diag):
            fndtype = "diagleftsideback"
            coord = findString(diag, wordback)
            xcoord = 10 - coord
            diagy = diagnum + coord
            wordcords.append((xcoord, diagy))
        diaglen = diaglen - 1
        diagnum = diagnum + 1

    if(fndtype == "horifor"):
        for x in range(1, len(string_search)):
            wordcords.append((xcoord + x, county))
    elif(fndtype == "horiback"):
        for x in range(1, len(string_search)):
            wordcords.append((xcoord + x, county))
        wordcords.reverse()
    elif(fndtype == "virtfor"):
        for x in range(1, len(string_search)):
            wordcords.append((column, ycoord + x))
    elif(fndtype == "virtback"):
        for x in range(1, len(string_search)):
            wordcords.append((column, ycoord + x))
        wordcords.reverse()
    elif(fndtype == "diagrightsidefor"):
        for x in range(1, len(string_search)):
            wordcords.append((xcoord + x, diagy + x))
    elif(fndtype == "diagrighttopfor"):
        for x in range(1, len(string_search)):
            wordcords.append((diagy + x, xcoord + x))
    elif(fndtype == "diagrightsideback"):
        for x in range(1, len(string_search)):
            wordcords.append((xcoord + x, diagy + x))
        wordcords.reverse()
    elif(fndtype == "diagrighttopback"):
        for x in range(1, len(string_search)):
            wordcords.append((diagy + x, xcoord + x))
        wordcords.reverse()
    elif(fndtype == "diaglefttopfor"):
        for x in range(1, len(string_search)):
            wordcords.append((diagy - x, xcoord + x))
    elif(fndtype == "diaglefttopback"):
        for x in range(1, len(string_search)):
            wordcords.append((diagy - x, xcoord + x))
        wordcords.reverse()
    elif(fndtype == "diagleftsidefor"):
        for x in range(1, len(string_search)):
            wordcords.append((xcoord - x, diagy - x))
    elif(fndtype == "diagleftsideback"):
        for x in range(1, len(string_search)):
            wordcords.append((xcoord - x, diagy - x))
        wordcords.reverse()

    if not wordcords:
        return "Not Found!"
    else:
        return wordcords


def findString(line, word):
    for count in range(0, len(line) - 1):
        if(line[count] == word[0] and line[count + 1] == word[1]):
            break
    return(count)
