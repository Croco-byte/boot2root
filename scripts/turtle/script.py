from turtle import *

color('red', 'yellow')
begin_fill()

# DRAWING AN 'S'
left(90)
forward(50)
forward(1)
for i in range(0, 180):
    left(1)
    forward(1)
for i in range(0, 179):
    right(1)
    forward(1)
right(1)
forward(50)

# DRAWING AN 'L'
forward(210)
backward(210)
right(90)
forward(120)

# DRAWING AN 'A'
right(10)
forward(200)
right(150)
forward(200)
backward(100)
right(120)
forward(50)

# DRAWING AN 'S'
left(90)
forward(50)
forward(1)

for i in range(0, 180):
    left(1)
    forward(1)
for i in range(0, 179):
    right(1)
    forward(1)
right(1)
forward(50)

# DRAWING AN 'H'
forward(100)
backward(200)
forward(100)
right(90)
forward(100)
right(90)
forward(100)
backward(200)



end_fill()
done()
