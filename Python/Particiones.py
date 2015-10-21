import Image
direccion_par="Particiones/"
def imag_part(tam,nom):
    refer=Image.open("Referencia/"+nom)
    i,j=refer.size
    sec_i=i/tam;sec_j=j/tam;rest_i=i%tam;rest_j=j%tam
    list_x=[tam*x for x in range(sec_i+1)]
    list_y=[tam*x for x in range(sec_j+1)]
    list_x.append(sec_i*tam+rest_i);list_y.append(sec_j*tam+rest_j)
    sec_x=0
    for x in range(sec_i+1):
        sec_x+=1
        sec_y=0
        for y in range (sec_j+1):
            sec_y+=1
            img=refer.crop((list_x[x],list_y[y],list_x[x+1],list_y[y+1]))
            img.save(direccion_par+"particion("+str(sec_x)+","+str(sec_y)+")"+".png","PNG")

def hola():
	print "Hola"
