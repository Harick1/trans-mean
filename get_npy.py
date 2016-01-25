#!/usr/bin/env python
import numpy as n
import sys
import math

input_file = sys.argv[1]
output_file = sys.argv[2]

input = open(input_file, 'r').readlines()

if len(input) == 1:
	pixs = input[0].strip().split(' ')
	w = h = math.sqrt(len(pixs))
	pixs = n.array(map(lambda x: float(x), pixs))
	npy = n.array([pixs.reshape(w, h)])
	print npy.shape
	output = open(output_file, 'w')
	n.ma.dump(npy, output)
else:
	b = input[0].strip().split(' ')
	g = input[1].strip().split(' ')
	r = input[2].strip().split(' ')
	w = h = math.sqrt(len(b))
	b = n.array(map(lambda x: float(x), b))
	g = n.array(map(lambda x: float(x), g))
	r = n.array(map(lambda x: float(x), r))
	npy = n.array([b.reshape(w, h), g.reshape(w, h), r.reshape(w, h)])
	print npy.shape
	output = open(output_file, 'w')
	n.ma.dump(npy, output)

