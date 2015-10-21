import Image

def prom(out):
    j,i=out.size
    R=G=B=0
    for x in xrange(j):
        for y in xrange(i):
            color=out.getpixel((x,y))
            print color
            R+=color[0];G+=color[1];B+=color[2]
    RGB=str(R/(j*i))+","+str(G/(j*i))+","+str(B/(j*i))
    return RGB
def reducir(out):
    out=out.resize((50,50))
    out.save("Reduccion.png","PNG")
    return out.getpixel((0,0))

out=Image.open("pila/1397780298721.png")
