# -*- coding: cp1252 -*-
from os import listdir
import Image
import copy
direccion="pila/"
direccion_1="Referencia/"

def actualizar(resp_0,tam):
    if resp_0=="No" or resp_0=="NO" or resp_0=="no":
        #collage(RAM)
        return
    else:
        crear_fichero(direccion,tam)
        #collage(RAM)
        return
    
def crear_fichero(direccion,tam):
    fichero=open("fichero.txt","w")
    string=""
    for archivo in listdir(direccion):
		#print direccion+archivo
		imagen=Image.open(direccion+archivo)
		ancho,largo=imagen.size
		lista=[ancho,largo]
		menor=min(lista)/2
		pmedioLargo=largo/2
		pmedioAncho=ancho/2
		a=pmedioAncho-menor;b=pmedioLargo-menor;c=pmedioAncho+menor;d=pmedioLargo+menor
		#box=(xi,yi,xf,yf)
		box=(a,b,c,d)
		out=imagen.crop(box)
		out=out.resize((tam,tam))
		#out.save(direccion+archivo.split(".")[0],"PNG")
		string+=archivo+"|"+prom(out)+"|"+str(a)+";"+str(b)+";"+str(c)+";"+str(d)+"\n"
    fichero.write(string)
    fichero.close()
    print "\n\n"
    return 

def prom(out):
    j,i=out.size
    R=G=B=0
    for x in xrange(j):
        for y in xrange(i):
            color=out.getpixel((x,y))
            #print color
            if type(color)==type(()):
				R+=color[0];G+=color[1];B+=color[2]
    RGB=str(R/(j*i))+","+str(G/(j*i))+","+str(B/(j*i))
    return RGB    

def HDD_to_RAM():
    fichero=open("fichero.txt")
    lista=[]
    for linea in fichero:
        linea=linea.strip().split("|")
        RGB=tuple(map(int,linea[1].split(",")))
        box=tuple(map(int,linea[2].split(";")))
        lista.append([linea[0],RGB,box])
    return lista

def delta(RGB_ref,RGB):
    Ro,Go,Bo=RGB
    R,G,B=RGB_ref
    return (((Ro-R)**2)+((Go-G)**2)+((Bo-B)**2))**0.5

def collage(nom,tam,RAM):
    refer=Image.open("Referencia/"+nom)
    j,i=refer.size
    collage=Image.new("RGB",(j*tam,i*tam))
    for x in xrange(j):
        for y in xrange(i):
            RGB_ref=refer.getpixel((x,y))
            cont=0
            RAM_AUX=copy.deepcopy(RAM)
            for dato in RAM_AUX:
                d=delta(RGB_ref,dato[1])
                dato.append(d)
                dato.reverse()
                RAM_AUX[cont]=dato
                cont+=1
            im=min(RAM_AUX)
            print im[3]
            imagen=Image.open(direccion+im[3])
            imagen=imagen.crop(im[1])
            imagen=imagen.resize((tam,tam))
            collage.paste(imagen,(x*tam,y*tam))
    collage.save("Collage "+nom,"PNG")

def collage_sec():
    refer=Image.open("Referencia/"+nom)
    i,j=refer.size
    sec_i=i/50;sec_j=j/50;rest_i=i%50;rest_j=j%50
    list_x=[50*x for x in range(sec_i+1)]
    list_y=[50*x for x in range(sec_j+1)]
    list_x.append(sec_i*50+rest_i);list_y.append(sec_j*50+rest_j)
    #print list_x,list_y
    sec_x=0
    for rango_x in range(sec_i+1):
        #print 1
        sec_x+=1
        sec_y=0
        for rango_y in range(sec_j+1):
            #print 2
            sec_y+=1
            #print (list_x[rango_x:rango_x+2][1]-list_x[rango_x:rango_x+2][0],list_y[rango_y:rango_y+2][1]-list_y[rango_y:rango_y+2][0])
            collage=Image.new("RGB",((list_x[rango_x:rango_x+2][1]-list_x[rango_x:rango_x+2][0])*tam,(list_y[rango_y:rango_y+2][1]-list_y[rango_y:rango_y+2][0])*tam))
            pos_x=-1
            for x in range(list_x[rango_x:rango_x+2][0],list_x[rango_x:rango_x+2][1]):
                #print 3
                pos_x+=1
                pos_y=-1
                for y in range(list_y[rango_y:rango_y+2][0],list_y[rango_y:rango_y+2][1]):
                    #print 4
                    #print(x,y)
                    pos_y+=1
                    RGB_ref=refer.getpixel((x,y))
                    cont=0
                    RAM_AUX=copy.deepcopy(RAM)
                    for dato in RAM_AUX:
                        d=delta(RGB_ref,dato[1])
                        dato.append(d)
                        dato.reverse()
                        RAM_AUX[cont]=dato
                        cont+=1
                    im=min(RAM_AUX)
                    print im[3]
                    imagen=Image.open(direccion+im[3])
                    imagen=imagen.crop(im[1])
                    imagen=imagen.resize((tam,tam))
                    collage.paste(imagen,(pos_x*tam,pos_y*tam))
            collage.save("Secciones/Seccion "+str(sec_x)+","+str(sec_y)+".png","PNG")
             
def hola():
	print "hola"   
#resp=raw_input("\nAlteraste la pila de imagenes? si/no: ")
#tam=int(raw_input("\nTamano de las imagenes:"))
#nom=raw_input("\nNombre de la imagen de referencia:")
#actualizar(resp)
#RAM=HDD_to_RAM()

