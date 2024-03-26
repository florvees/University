# Ex 1
line = input("Enter your string: ")
new_line = ""
i = 0
while i < len(line):
	if i == len(line) - 1:
		new_line += line[i]
		break
	counter = 1
	while (line[i] == line[i+counter]):
		counter += 1
		if (i+counter >= len(line)):
			break
	new_line += line[i]
	if counter > 1:
		new_line += str(counter)
		i += counter-1
	i += 1
print("Here's the shorted version: ",new_line)