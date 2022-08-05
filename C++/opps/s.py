from math import e
from math import pi 
from math import log10
from math import sqrt
import matplotlib.pyplot as plt


if __name__ == "__main__":
    p_t = 1
    R = -1
    H_t = 50
    H_r = 2
    G_l = 1

    l_arr = [sqrt((H_t - H_r) ** 2 + d ** 2) for d in range(1, 101)]
    z_arr = [sqrt((H_t + H_r) ** 2 + d ** 2) for d in range(1, 101)]

    lambda_w = 1 / 3

    del_fi_arr = [2 * pi * (z - l) / lambda_w for z, l in zip(z_arr, l_arr)]

    plt.figure(figsize=(18, 10))
    for i, G_r in enumerate([1, 0.316, 0.1, 0.01]):
        plt.subplot(2, 2, i + 1)
        G_r_arr = [10 * log10(p_t) + 20 * log10(lambda_w / 4 * pi) + 20 * log10(
            abs((sqrt(G_l) / l) + (R * sqrt(G_r) * e ** (1j * del_fi)) / z)) for l, z, del_fi in
                   zip(l_arr, z_arr, del_fi_arr)]
        plt.plot(range(1, 101), G_r_arr)
        plt.axvline(x=log10(d_c))
        plt.title(f"for G_r {G_r}", weight='bold')
        plt.xscale("log")
        plt.ylabel(" ")
        plt.xlabel(" ")
        plt.tight_layout()
        plt.show()