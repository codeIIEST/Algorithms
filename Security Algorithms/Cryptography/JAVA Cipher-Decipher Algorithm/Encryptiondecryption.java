
import java.util.*;
package cryptography;
public class Encryptiondecryption {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		System.out.println("Enter the encryption key(1-25):");
		int e=s.nextInt();                                                  //Encryption key taken from user
		String ptext;
		String ctext="";
		char ch;
		System.out.println("Plaintext-Uppercase Letters Only:");
		ptext=s.next();                                                     //Plaintext taken from user
		int len=ptext.length();
		//Encryption starts from here.
		for(int i=0;i<len;i++)
		{
			ch=ptext.charAt(i);
			ch=(char)(ch+e);
			if(ch>90)
				ch=(char)(ch-26);
			ctext=ctext+ch;
			
		}
		System.out.println("Ciphertext:"+ctext);
		//Decryption starts from here.
		System.out.println("Enter Ciphertext-Uppercase Letters Only:");
		ctext=s.next();
		len=ctext.length();
		System.out.println("Plaintext for each encryption key from 1 to 25:");
		ptext="";
		for(int i=1;i<=25;i++)
		{
			for(int j=0;j<len;j++)
			{
				ch=ctext.charAt(j);
				ch=(char)(ch-i);
				if(ch<65)
					ch=(char)(ch+26);
				ptext=ptext+ch;
			}
			System.out.println("Key "+i+" : Plaintext="+ptext);
			ptext="";
		}
		

	}

}
