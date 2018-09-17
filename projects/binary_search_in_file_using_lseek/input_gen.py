from random import randint

#201221Hackensack NJ

def randomString():
	a = "abcdefghijklmnopqrstuvz "
	x = ""
	for i in range(10, randint(20, 30)):
		m = randint(0, len(a) - 1)
		x += a[m]
	return x

with open("./nanpa", "w") as file:
	start = randint(1000, 2000)
	end = randint(start + 10000, 900000)
	pin = 100000
	for i in range(start, end):
		pin = pin + 1
		string = "{}{}".format(str(pin), randomString())
		string += " "*(30-len(string))
		string += "\n"
		file.write(string)