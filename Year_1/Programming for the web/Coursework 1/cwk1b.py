#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 13 15:51:31 2021

@author: ed20b3m
"""


def ext_vigenere(text, key, option):
    output = ""

    if(option == "encrypt"):
        count = 0
        for i in text:
            currlet = ord(i)
            currkey = ord(key[count])

            outcharint = ((currlet-32) + (currkey-32)) % 94

            if (outcharint > 126):
                outchar = chr(outcharint - 62)
            else:
                outchar = chr(outcharint+32)

            output = output + outchar

            count = count+1

            if(count > len(key)-1):
                count = 0

    elif(option == "decrypt"):
        count = 0
        for i in text:
            currlet = ord(i)
            currkey = ord(key[count])

            outcharint = ((currlet-32) - (currkey-32) + 94) % 94

            if (outcharint > 126):
                outchar = chr(outcharint - 62)
            else:
                outchar = chr(outcharint+33)

            output = output + outchar

            count = count+1

            if(count > len(key)-1):
                count = 0
    else:
        output = "Invalid option!"
    return output
