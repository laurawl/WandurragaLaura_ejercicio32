envolve.png : graficar.py datos.dat
	python graficar.py
	
datos.dat : ejercicio.x
	./ejercicio.x 100
	
ejercicio.x : ejercicio.cpp
	c++ ejercicio.cpp -o ejercicio.x

clean :
	rm parte1.dat ejercicio.x envolve.png