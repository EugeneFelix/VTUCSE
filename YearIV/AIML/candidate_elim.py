import csv

path = '.././data/candidate_elim.csv'
data = []

with open(path, 'r') as file:
	reader = csv.reader(file)
	for row in reader:
		data.append(row)

print(data)
concepts = [row[:-1] for row in data]
target = [row[-1] for row in data]

def learn(concepts, target):
	specific_h = concepts[0].copy()
	print("\nInitialization of specific_h and general_h")
	print("\nSpecific Boundary: ", specific_h)
	general_h = [["?" for i in range(len(specific_h))] for i in range(len(specific_h))]
	print("\nGeneric Boundary: ", general_h)

	for i, h in enumerate(concepts):
		print("\nInstance", i + 1, "is", h)
		if target[i] == "yes":
			print("Instance is Positive")
			for x in range(len(specific_h)):
				if h[x] != specific_h[x]:
					specific_h[x] = '?'
					general_h[x][x] = '?'

		if target[i] == "no":
			print("Instance is Negative")
			for x in range(len(specific_h)):
				if h[x] != specific_h[x]:
					general_h[x][x] = specific_h[x]
				else:
					general_h[x][x] = '?'

		print("Specific Boundary after", i + 1, "Instance is", specific_h)
		print("Generic Boundary after", i + 1, "Instance is", general_h)
		print("\n")

	indices = [i for i, val in enumerate(general_h) if val == ['?', '?', '?', '?', '?', '?']]
	for i in indices:
		general_h.remove(['?', '?', '?', '?', '?', '?'])
	return specific_h, general_h

s_final, g_final = learn(concepts, target)

print("Final Specific_h: ", s_final, sep="\n")
print("Final General_h: ", g_final, sep="\n")