/*
//Encrypt
1. (pad)Convert each charaacter into new character
2. original_s xor pad
3. return ciphertext
//Decrypt
1. padd xor ciphertext
2. return original_s 
*/

#include <stdio.h>
#include <stdlib.h>

unsigned char rand_custom() {return rand() % 128;};

void enc(unsigned char* s, unsigned char* pad, unsigned char* cipher, int slen)
{
	for (int i=0; i<slen; i++) {pad[i] = rand_custom(); cipher[i] = s[i] ^ pad[i];}	
}

void dec(unsigned char* s_dec, unsigned char* pad, unsigned char* cipher, int slen)
{
	for (int i=0; i<slen; i++) {s_dec[i] = pad[i] ^ cipher[i];}
} 

void display(unsigned char* s, int slen)
{
	for (int i=0; i<slen; i++) printf("%c", s[i]);
	printf("\n");
}
void display_test(unsigned char* s, int slen)
{
	for (int i=0; i<slen; i++) printf("%c %d | ", s[i], s[i]);
	printf("\n");
}
int main()
{
	unsigned char s[] = {'p', 'b', 'd'}; int slen = 3;
	unsigned char* pad = (unsigned char*)malloc(slen);
	unsigned char* cipher = (unsigned char*)malloc(slen);
	unsigned char* s_dec = (unsigned char*)malloc(slen);
	
	enc(s, pad, cipher, slen);
	dec(s_dec, pad, cipher, slen);
	
	printf("enc: ");
	display(s, slen);
	printf("dec: "); 	
	display(s_dec, slen);

	printf("pad: ");
	display_test(pad, slen);
	printf("cipher: ");
	display_test(cipher, slen);
	
}

