ALPHABET = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

def enc(s, key):
	enc_s = ""
	for c in s:
		if c == ' ':
			enc_s += ' '
			continue
		isUpper = c.isupper()
		coef = 65 if isUpper else 97 
		index = ord(c) - coef
		changed_index = index + key
		changed_index = changed_index if changed_index % 26 == 0 else changed_index % 26
		changed_c = ALPHABET[changed_index]
		changed_c = changed_c.upper() if isUpper else changed_c
		enc_s += changed_c

	return enc_s   
def dec(s, key):
	dec_s = ""
	for c in s:
		if c == ' ':
			dec_s += ' '
			continue
		isUpper = c.isupper()
		coef = 65 if isUpper else 97 
		index = ord(c) - coef
		changed_index = index - key
		while (changed_index < -25):
			changed_index += 26
		changed_index = changed_index if changed_index % 26 == 0 else changed_index % 26
		
		changed_c = ALPHABET[changed_index]
		changed_c = changed_c.upper() if isUpper else changed_c
		dec_s += changed_c

	return dec_s   

s = input("Type data: ")
key = int(input("Type key: "))

enc_s = enc(s, key)
print(enc_s)

dec_s = dec(enc_s, key)
print(dec_s)
