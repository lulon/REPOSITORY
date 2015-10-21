import Image

import Collage

import Particiones

Collage.hola()

datos=[0,0,0,0,0,0,0,0]

def flag_1():
	if resp_2=="No" or resp_2=="NO" or resp_2=="no":
		return
	else:
		Particiones.imag_part(dim_part,nom)
		return

def flag_2():
	if resp_1=="No" or resp_1=="NO" or resp_1=="no":
		return
	else:
		Collage.collage_sec()
		return
		
def flag_3():
	if resp_1=="si" or resp_2=="si":
		return
	else:
		Collage.collage(nom,tam,RAM)
		return

def to_ram():
	cont=0
	text=open("parametros.txt")
	for linea in text:
		if cont>=2:
			linea=linea.strip().split(":")
			datos[cont-2]=linea[1]
		cont+=1
	text.close()

to_ram()
##esc=int(datos[7])
resp_0=datos[2]
resp_1=datos[1]
resp_2=datos[0]
dim_part=int(datos[3])
##dim_sec=int(datos[4])
tam=int(datos[5])
nom=datos[6]
Collage.actualizar(resp_0,tam)
RAM=Collage.HDD_to_RAM()
flag_1()
flag_2()
flag_3()
