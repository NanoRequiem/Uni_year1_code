#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Nov 11 14:14:33 2021

@author: ed20b3m
"""

import csv

with open("index2.html", "w") as html:
    html.write("<html>\n")
    html.write("<head>\n")
    html.write("<meta charset=\"UTF-8\">\n")
    html.write("<style>\n")
    html.write("table, th, td {\n")
    html.write("border: 1px solid black;\n")
    html.write("border-collapse: collapse;\n")
    html.write("}\n")
    html.write("</style>\n")
    html.write("<title>Student grades</title>\n")
    html.write("</head>\n")
    html.write("<body>\n")
    html.write("<h2>Test scores</h2>\n")
    html.write("<table>\n")

    with open("scores.csv", "r") as students:
        students.readline()
        html.write("<tr>\n")
        html.write("<th> First name</th>\n")
        html.write("<th> Surname</th>\n")
        html.write("<th> Maths score</th>\n")
        html.write("<th> English score</th>\n")
        html.write("<th>Average</th>\n")
        html.write("</tr>\n")

        reader = csv.reader(students)
        for row in reader:
            html.write("<tr>\n")
            for elm in row:
                html.write("<td>" + elm + "</td>\n")
            math_score = int(row[2])
            english_score = int(row[3])
            html.write("<td>"+ str((math_score + english_score)/2) + "</td>\n")
            html.write("</tr>\n")

    html.write("</table>\n")
    html.write("</body>\n")
    html.write("</html>\n")
