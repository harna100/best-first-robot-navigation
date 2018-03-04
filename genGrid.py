from random import randint

def weightedRandom():
	n = randint(0,100)
	if(n < 30):
		return 0
	else:
		return 1


def printGrid(size):
	chars = "+."
	
	grid = [[chars[weightedRandom()] for i in range(size)] for j in range(size)]

	grid[randint(0,size-1)][randint(0,size-1)] = 'g'
	grid[randint(0,size-1)][randint(0,size-1)] = 'i'
	print size
	for c in grid:
		print ''.join(c)



printGrid(randint(40,80))