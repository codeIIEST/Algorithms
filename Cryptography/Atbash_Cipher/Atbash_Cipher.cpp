//Atbash cipher
#include<iostream>
using namespace std;

//Function that convert the message.
string atbash(string msg)
{
	/*This function takes msg as input and
	  map it to its reverse alphabatically order.*/ 
	
	string cipher;
	for(int i=0;i<msg.length();i++)
	{
		if(msg[i]==' ')
		cipher= cipher + ' ';
		else if(msg[i]>='A' && msg[i]<='Z')
		cipher=cipher+(char)('Z'-(msg[i]-'A'));
		else
		cipher=cipher+(char)('z'-(msg[i]-'a'));
	}
	return cipher;
}

//Main program.
int main()
{
	string text;
	cout<<"Enter the message to encrypt/decrypt---"<<endl;
	cin>>text;
	cout<<"Converted message---"<<endl<<atbash(text);
}
