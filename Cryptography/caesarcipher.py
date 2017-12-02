"""
A general purpose function for both, encryption and decryption.
After giving the string that you want, if you decide to shift it to right,
encryption will take place by shifting characters to the right and
the decrypted string can be obtained by shifting the encrypted string to the left.
The general purpose function takes care of both the left and the right shifts.
Based on how the user uses it, he or she can encrypt and decrypt the data.
"""


def encrypt_and_decrypt(string,shift,val): 
  ascii_vals=[ord(c) for c in string]                #To get a list of ASCII Values of each character in string
  if(shift == "right"):                              #When the text it shifted to the right
    for i in range(0,len(ascii_vals)):
      ascii_vals[i] = ascii_vals[i] + val
      if(ascii_vals[i]>97 and ascii_vals[i]>122):  #If the values in the list are greater than 97 and 122, we get it back b/w 97 and 122
        ascii_vals[i] = 97 + (ascii_vals[i]-122) -1
      elif((ascii_vals[i]>97 and ascii_vals[i]<=122) or (ascii_vals[i]>65 and ascii_vals[i]<=90)):
        ascii_vals[i] = ascii_vals[i]
      elif(ascii_vals[i]>65 and ascii_vals[i]>90):
        ascii_vals[i] = 65 + (ascii_vals[i]-90) -1   #If the values in the list are greater than 65 and 90, we get it back b/w 97 and 122
  if(shift == "left"):                               #When the text it shifted to the left
    for i in range(0,len(ascii_vals)):
      ascii_vals[i] = ascii_vals[i] - val
      if(ascii_vals[i]<97 and ascii_vals[i]<122):  #If the values in the list are greater than 97 and 122, we get it back b/w 97 and 122
        ascii_vals[i] = 122 + (ascii_vals[i]-97) +1  
      elif((ascii_vals[i]>97 and ascii_vals[i]<=122) or (ascii_vals[i]>65 and ascii_vals[i]<=90)):
        ascii_vals[i] = ascii_vals[i]
      elif(ascii_vals[i]<65 and ascii_vals[i]<90): #If the values in the list are greater than 65 and 90, we get it back b/w 97 and 122
        ascii_vals[i] = 90 + (ascii_vals[i]-65) +1
          
  encrypt_or_decrypt_string = ''.join(chr(i) for i in ascii_vals) # To get the encrypted string using the list of manipulated ASCII vals
  print encrypt_or_decrypt_string
  
def caesar_cipher():
  string = raw_input("Enter text to be encrypted:")
  encrypt_and_decrypt(string,shift,val) 
    
if __name__=="__main__":
  shift = str(raw_input("Do you want to shift to right or to left?"))
  val = int(raw_input("By what value do you want to shift?"))
  caesar_cipher()
