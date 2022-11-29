#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Nov  5 15:02:25 2021

@author: ed20b3m
"""
import csv


class Leopard():
    header = []
    data = []
    def __init__(self, csvfile):
        try:
            open(csvfile, "r")
        except IOError:
            print("File not found")
            return None
        finally:
            self.csvfile = csvfile

        with open(csvfile) as file:
            reader = csv.reader(file)
            self.header = next(reader)
            for row in reader:
                self.data.append(row)

    def get_header(self):
        return self.header

    def get_dimension(self):
        oneRow = self.data[0]
        row = 0
        column = 0
        for x in self.data:
            row = row + 1
        for y in oneRow:
            column = column + 1
        returnValue = [row, column]
        return returnValue

    def count_instances(self, column_heading, value):
        headerindex = 0
        numbOfInstances = 0
        for x in self.header:
            if(x == column_heading):
                break
            headerindex = headerindex + 1
        for y in self.data:
            count = 0
            for z in y:
                if(value == z and count == headerindex):
                    numbOfInstances = numbOfInstances + 1
                count = count + 1
        return numbOfInstances

    def total_missing(self):
        numbMissing = 0
        for x in self.data:
            for y in x:
                if(y == "NA" or y == "" or y == "?"):
                    numbMissing = numbMissing + 1
                    break
        return numbMissing
