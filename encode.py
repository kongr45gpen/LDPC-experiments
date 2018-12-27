# -*- coding: utf-8 -*-
"""
Simple encoder implementation based on an LDPC generator matrix
"""

from scipy.io import loadmat
import numpy as np
import matplotlib.pyplot as plt

# Assuming that the loaded file contains a 'G' matrix
file = loadmat('gAR4JA_r45_k1024.mat')
G = file['G']

[K, N] = G.shape
P = N - K # Parity bits
# Note: The above may contain punctured bits

print(K, N, P)
# Reduce usable part
G = G[:, K:]

# The message to encode
I = np.zeros([1, K]);
I[0, 4*8+4] = 1;

# Perform the encoding
CW = I.dot(G)

# Print the parity bits
# print(CW)

# Convert to ints
np.array(list(map(lambda n: n % 2, np.ravel(CW))))
bytes = np.packbits(CW.astype(int), axis=-1)
print(bytes.astype(np.uint8).data.hex())

# plt.plot(np.ravel(CW))
# plt.show()
