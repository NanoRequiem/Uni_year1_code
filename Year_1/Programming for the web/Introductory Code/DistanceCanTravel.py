#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 28 14:54:17 2021

@author: ed20b3m
"""

capacitystr = input("Please input fuel capacity in letres: ")
capacity = int(capacitystr)
kiloPerLstr = input("Please input how many km your car can travel per Letre: ")
kiloPerL = int(kiloPerLstr)


print("Your car can travel", capacity * kiloPerL, ("km"))
