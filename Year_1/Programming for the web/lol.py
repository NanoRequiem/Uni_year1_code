#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Dec  7 11:16:46 2021

@author: ed20b3m
"""

from matplotlib import pyplot as plt


grade_year = [1, 2]
grade_maths = [56, 85]
grade_english = [88, 77]

width = 0.25
x = [x - width for x in grade_year]

plt.bar(x,  grade_maths, label="Maths", width=width)
plt.bar(grade_year,  grade_english, label="English", width=width)
plt.title("Grade over time")
plt.xlabel("Year")
plt.ylabel("Grade")
plt.legend()
plt.show