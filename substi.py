data = "mot con ca da qua che bien"

def enc(s):
	enc_s = ""

	for i in range(len(s)):
		remain = i % 3
		if remain == 0:
							
		elif remain == 1:
			pass
		elif remain == 2:
			pass
def dec(s):
	pass

s = ""
enc_data = enc(s)
print(enc_data)

dec_data = dec(enc_data)
print(dec_data)	
