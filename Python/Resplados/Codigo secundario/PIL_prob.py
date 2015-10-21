import Image
direccion="Referencia/molt.jpg"
imagen=Image.open(direccion)
ancho,largo=imagen.size
lista=[ancho,largo]
menor=min(lista)/2
pmedioLargo=largo/2
pmedioAncho=ancho/2
a=pmedioAncho-menor;b=pmedioLargo-menor;c=pmedioAncho+menor;d=pmedioLargo+menor
        #box=(xi,yi,xf,yf)
box=(a,b,c,d)
imagen=imagen.crop(box)
imagen=imagen.resize((200,200))
imagen.save("crop molt.png","PNG")
