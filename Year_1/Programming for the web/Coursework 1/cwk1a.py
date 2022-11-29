#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 13 14:55:24 2021

@author: ed20b3m
"""


def main():
    taxInput = input("please enter tax: ")
    numbCheck = taxInput.isnumeric()

    if (numbCheck):
        tax = int(taxInput)
        if(tax == 0):
            income = 12500.00
        elif(tax > 0 and tax <= 7500):
            income = (tax/0.2) + 12500
        elif(tax > 7500 and tax <= 51000):
            income = ((tax - 7500) / 0.4) + 50000
        elif(tax > 51000):
            income = ((tax - 47500) / 0.45) + 150000
        print("{}".format(income))
    else:
        print("Invalid amount!")
