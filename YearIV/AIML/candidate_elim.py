import numpy as np 
import pandas as pd

df = pd.read_csv('../df/candidate_elimination.csv')
concepts = np.array(df.iloc[:,0:-1])
print("\nInstances are:\n",concepts)
target = np.array(df.iloc[:,-1])
print("\nTarget Values are: ",target)

s_final, g_final = learn(concepts, target)

print("Final Specific_h: ", s_final, sep="\n")
print("Final General_h: ", g_final, sep="\n")

def learn(concepts, target): 
	specific_h = concepts[0].copy()
	print("\nInitialization of specific_h and genearal_h")
	print("\nSpecific Boundary: ", specific_h)
	general_h = [
				  ["?" for i in range(len(specific_h))]
				  for i in range(len(specific_h))
				]
	print("\nGeneric Boundary: ",general_h)  

	for i, h in enumerate(concepts):
		print("\nInstance", i+1 , "is ", h)
		if target[i] == "yes":
			print("Instance is Positive ")
			for x in range(len(specific_h)): 
				if h[x]!= specific_h[x]:
					specific_h[x] ='?' 
					general_h[x][x] ='?'

		if target[i] == "no":
			print("Instance is Negative ")
			for x in range(len(specific_h)): 
				if h[x] != specific_h[x]:
					general_h[x][x] = specific_h[x]	
				else:
					general_h[x][x] = '?'
		
		print("Specific Bundary after ", i+1, "Instance is ", specific_h) 
		print("Generic Boundary after ", i+1, "Instance is ", general_h)
		print("\n")
	# Filter redundant structures
	general_h = [val for val in general_h
				  if val != ['?', '?', '?', '?', '?', '?']]
	return specific_h, general_h 
