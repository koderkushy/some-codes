import re
import os

header_path = "/home/kushagra/.config/sublime-text/Packages/User/multitest.sublime-snippet"

reader = open(header_path, "r")

data = reader.read()

# print(data)

try:
	header_text = re.search(r"\[CDATA\[(.*)\]\]", data, flags=re.DOTALL).group(1)

except:
	print('No matching snippet: multitest.sublime-snippet')
	exit()

names = [str(chr(i + ord('A'))) for i in range(8)]

for file in names:
	try:
		os.remove(file + '.cpp:tests')
	except:
		pass
	try:
		os.remove(file)
	except:
		pass
	writer = open(file + '.cpp', "w")
	writer.write(header_text)



