#!/bin/bash

sed -ibak -e 's/Tourne gauche de 90 degrees/left(90)/g' \
	-e 's/Tourne droite de 90 degrees/right(90)/g' \
	-e 's/Avance 50 spaces/forward(50)/g' \
	-e 's/Avance 1 spaces/forward(1)/g' \
	-e 's/Tourne gauche de 1 degrees/left(1)/g' \
	-e 's/Tourne droite de 1 degrees/right(1)/g' \
	-e 's/Avance 210 spaces/forward(210)/g' \
	-e 's/Recule 210 spaces/backward(210)/g' \
	-e 's/Avance 120 spaces/forward(120)/g' \
	-e 's/Tourne droite de 10 degrees/right(10)/g' \
	-e 's/Avance 200 spaces/forward(200)/g' \
	-e 's/Tourne droite de 150 degrees/right(150)/g' \
	-e 's/Recule 100 spaces/backward(100)/g' \
	-e 's/Tourne droite de 120 degrees/right(120)/g' \
	-e 's/Avance 50 spaces/forward(50)/g' \
	-e 's/Avance 100 spaces/forward(100)/g' \
	-e 's/Recule 200 spaces/backward(200)/g' \
	instructions.txt
