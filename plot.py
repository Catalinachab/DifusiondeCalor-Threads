#!/usr/bin/python3

import sys
import numpy as np
import matplotlib.pyplot as plt
import csv

if len(sys.argv) < 2:
    print("Usage:")
    print("  $ ./plot.py <FILE> <(COLORS)>")
    print("")
    print("    FILE = filename or path to data.")
    print("  COLORS = name of colorset (optional)")
    print("")
    print("For more info see: https://matplotlib.org/stable/tutorials/colors/colormaps.html")
    print("Examples:")
    print("  $ ./plot.py resultadosParalelos.txt")
    print("  $ ./plot.py resultados.txt viridis")
    print("  $ ./plot.py resultados.txt hot")
    print("  $ ./plot.py resultados.txt flag")
    print("  $ ./plot.py resultados.txt jet")
    exit(0)

file = sys.argv[1]
colorset = "prism"
if len(sys.argv) > 2:
    colorset = sys.argv[2]

array = []
try:
    with open(file, newline='', encoding='utf-8') as csvfile:
        spamreader_space = csv.reader(csvfile, delimiter=' ')
        for row in spamreader_space:
            array.append(list(map(float,row)))
except FileNotFoundError:
    print("ERROR: file \"" + file + "\" does not exist")
    exit(1)

try:
    data = np.array(array)

    fig = plt.figure('FILE:' + file)

    plt.subplot(111)
    plt.imshow(data, cmap=colorset)

    plt.subplots_adjust(bottom=0.1, right=0.8, top=0.9)
    cax = plt.axes([0.85, 0.1, 0.05, 0.8])
    plt.colorbar(cax=cax)

    fig.savefig(file+".pdf", bbox_inches='tight')
    
    plt.show()

except:
    print("ERROR: impossible plot, use other options")
    exit(1)

