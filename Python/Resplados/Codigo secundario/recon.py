import Image
from os import listdir
direccion="pila/"
for archivo in listdir(direccion):
    print archivo
    im=Image.open(direccion+archivo)
    RGB=im.getpixel((0,0))
    if type(RGB)==type(0) or archivo=="Thumbs.db":
        pass
    else:
        new=(RGB[0],RGB[1],RGB[2])
