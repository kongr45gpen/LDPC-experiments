#!/usr/bin/env python3

"""
Converter of an LDPC generator matrix from a Matlab
file to a hexadecimal string
"""

from scipy.io import loadmat
from code import interact
import numpy as np
from tqdm import tqdm

file = loadmat('gAR4JA_r45_k1024.mat')
G = file['G']

[K, N] = G.shape
P = N - K # Parity bits

#print(K, N, P)

# Reduce usable part
G = G[:, K:]
#print(G.shape)

#interact(local=locals())


for p in tqdm(range(0, G.shape[1])): # foreach parity bit
    Grow = G[:, p]
    bytes = np.split(Grow, Grow.size / 8)
    paritystring = ""
    for byte in bytes:
        paritystring += '{:02x}'.format(np.packbits(np.flip(byte))[0])

#    if p != 0:
#        print("_", end='')
    print(paritystring, end='')
