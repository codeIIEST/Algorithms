"""
A Caesar Cipher function for both, encryption and decryption.
After giving the string that you want, encryption will take place by shifting
characters to the right and the decrypted string can be obtained by shifting
the encrypted string to the left.
The cipher is ready for Capital Letters only
"""

def encrypt(message,key):
  ascii_vals_enc=[ord(c) for c in message]               #To get a list of ASCII Values of each character in string
  for i in range(0,len(ascii_vals_enc)):
    if(ascii_vals_enc[i]>=65 and ascii_vals_enc[i]<=90):
	ascii_vals_enc[i] = 65 + (ascii_vals_enc[i] + key - 91)%26  #If the values in the list are greater than 65 and 90, we get it back b/w 65 and 90
  encrypt_string = ''.join(chr(i) for i in ascii_vals_enc) # To get the encrypted string using the list of manipulated ASCII vals
  return encrypt_string

def decrypt(message,key):
  ascii_vals_dec=[ord(c) for c in message]
  for i in range(0,len(ascii_vals_dec)):
    if(ascii_vals_dec[i]>=65 and ascii_vals_dec[i]<=90):
	ascii_vals_dec[i] = 90 - (90 - ascii_vals_dec[i] + key )%26
  decrypt_string = ''.join(chr(i) for i in ascii_vals_dec) # To get the decrypted string using the list of manipulated ASCII vals
  return decrypt_string

def caesar_cipher():
  #message_enc = raw_input("Enter text to be encrypted:")	#Can be used to give custom strings
  message_enc ="CODING IS FUN"	#string to be encrypted
  encrypt_string = encrypt(message_enc,key)		#Calling the function to encrypt the string
  print "The string to be encrypted is: ",message_enc
  print "THe encrypted string is: ",encrypt_string
  print "----------------------------------------"
  #message_dec = raw_input("Enter text to be encrypted:")	#Can be used to give custom strings
  message_dec ="M PSZI GSHMRK"	#string to be decrypted
  decrypt_string = decrypt(message_dec,key)		#Calling the function to decrypt the string
  print "The string to be decrypted is: ",message_dec
  print "THe decrypted string is: ",decrypt_string

if __name__=="__main__":
  #key = int(raw_input("By what value do you want to shift?"))	#Can be used to give custom key values
  key = 4
  caesar_cipher()
