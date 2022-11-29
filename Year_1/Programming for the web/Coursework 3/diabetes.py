#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Dec  2 13:16:37 2021

@author: ed20b3m
"""
import csv
from matplotlib import pyplot as plt
import numpy


def generate_summary_for_web(csvfile, html_title,
                             html_filename, show_barchar_gender=True):

    data = []
    datacounts = [[],
                  [],
                  [],
                  [],
                  [],
                  [],
                  [],
                  [],
                  [],
                  [],
                  [],
                  [],
                  [],
                  []]

    with open(csvfile) as file:
        reader = csv.reader(file)
        for row in reader:
            data.append(row)

    datcount = 0
    for x in range(2, 16):
        datacounts[datcount].append(data[0][x])
        for y in range(0, 4):
            datacounts[datcount].append(0)
        datcount += 1

    for x in range(1, 521):
        for y in range(2, 16):
            if(data[x][y] == "Yes"):
                if(data[x][16] == "Positive"):
                    datacounts[y - 2][1] = datacounts[y - 2][1] + 1
                elif(data[x][16] == "Negative"):
                    datacounts[y - 2][3] = datacounts[y - 2][3] + 1
            elif(data[x][y] == "No"):
                if(data[x][16] == "Positive"):
                    datacounts[y - 2][2] = datacounts[y - 2][2] + 1
                elif(data[x][16] == "Negative"):
                    datacounts[y - 2][4] = datacounts[y - 2][4] + 1

    for x in datacounts:
        for y in range(1, 5):
            x[y] = str(x[y])

    if show_barchar_gender:
        bardata = get_barchart_data(data)
        create_barchart(bardata)
    print(bardata)

    with open(html_filename, "w") as html:
        html.write('<html>\n')
        html.write('<title>' + html_filename + '</title>\n')
        html.write('<h1>' + html_title + '</h1>\n')

        html.write("<style>\n")
        html.write("table, th, td {\n border: 1px solid black;\n")
        html.write("border-collapse: collapse; text-align:center\n")
        html.write("}\n")
        html.write("</style>\n")
        html.write("<table>\n")

        html.write("<tr>\n")
        html.write('<th rowspan = "3">Attributes</th>\n')
        html.write('<th colspan="4">Class</th>\n')
        html.write("</tr>\n")

        html.write("<tr>\n")
        html.write('<th colspan = "2">Positive</th>\n')
        html.write('<th colspan = "2">Negative</th>\n')
        html.write("</tr>\n")

        html.write("<tr>\n")
        html.write('<th>Yes</th>\n')
        html.write('<th>No</th>\n')
        html.write('<th>Yes</th>\n')
        html.write('<th>No</th>\n')
        html.write("</tr>\n")

        for x in datacounts:
            html.write("<tr>\n")
            for y in x:
                html.write("<td>" + y + "</td>\n")
            html.write("</tr>\n")

        html.write('<center>\n')
        html.write('</center>\n')
        html.write('</html>\n')


def get_barchart_data(data):

    bardata = [[0, 0], [0, 0]]
    for x in data:
        if(x[1] == "Male" and x[16] == "Positive"):
            bardata[0][0] += 1
        elif(x[1] == "Male" and x[16] == "Negative"):
            bardata[0][1] += 1
        elif(x[1] == "Female" and x[16] == "Positive"):
            bardata[1][0] += 1
        elif(x[1] == "Female" and x[16] == "Negative"):
            bardata[1][1] += 1
    return bardata


def create_barchart(data):
    x = [0.75, 1.5]
    notchwidth = [0.62, 1.37]
    names = ["Positive", "Negative"]
    bardataM = data[0]
    bardataF = data[1]
    
    width = 0.25
    y = [y - width for y in x]
    
    plt.bar(y, bardataM, label="Male", width = 0.25)
    plt.bar(x, bardataF, label="Female", width = 0.25)
    plt.title("Gender of Positive vs Negative case")
    plt.xlabel("Class")
    plt.ylabel("Count")
    plt.xticks(notchwidth, names)
    plt.legend()
    plt.show()
