# pip install pyperclip

import pyperclip as ppc

hex_p_dec = lambda x: round(((int(x, 16)) / 255), 2)

lista = ppc.paste()

r, g, b = lista[1:3], lista[3:5], lista[5:7]
ppc.copy("f, ".join(map(str, (map(hex_p_dec, [r, g, b])))) + "f")
print("Valores copiados para a sua área de Transferência!")
