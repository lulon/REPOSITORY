import Image
ruta="Referencia/"
def recortar(nom,num):
    im=Image.open(ruta+nom)
    i,j=im.size
    cien_i=i/100;cien_j=j/100;rest_i=i%100;rest_j=j%100
    cont=0
    for x in xrange(cien_i):
        for y in xrange(cien_j)
