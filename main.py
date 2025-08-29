data = "mot con ca da qua che bien"

def enc(data):
	pos = []
	dec = len(data) % 3
	
	for i in range(len(data) - dec):
		if i % 3 == 0:
			pos.append(i + 2)
		else:
			pos.append(i - 1)
	start = len(data) - dec 
	for i in range(start, len(data)):
		pos.append(i)
	print(pos)
	
	enced_data = ""

	for i in pos:
		enced_data += data[i]
	
	return enced_data

def dec(data):
	pos = []
	dec = len(data) % 3
	for i in range(len(data) - dec):
		if (i % 3 == 2):
			pos.append(i - 2)
		else:
			pos.append(i + 1)

	start = len(data) - dec 
	for i in range(start, len(data)):
		pos.append(i)
	print(pos)
	
	deced_data = ""

	for i in pos:
		deced_data += data[i]
	
	return deced_data
enc_data = enc(data)
print(enc_data)

dec_data = dec(enc_data)
print(dec_data)	
