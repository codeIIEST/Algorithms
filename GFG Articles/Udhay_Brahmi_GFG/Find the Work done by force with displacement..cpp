/*Given two strings representing force and displacement.Consider a situation in which Force (F)acts on a particle and the displacement of the point of application is given as (D). The task is to find Work Done (W). 

W=F(ai+bj+ck).D(di+ej+fk) or W= a.d + b.e + c.f 

where a,b,c,d,e,f are variables.

Implementation in C++ */
#include <bits/stdc++.h>
#include<sstream>
using namespace std;

int main() {
    
    //Force
    string a="20i+31j-67k";
    
    //Displacement
    string b="3i+1j+765k";
    
    //To store i,j,k values of force.
    string i1="",j1="",k1="";
    
    //Used to allow digits to be stored in their respective variables.
    bool gi1=true,gj1=false,gk1=false;
    
//FORCE   
    //Extracting Force values from string a and store them in i1,j1,k1.
    for(int i=0;i<(a.length()-1);i++){
        if(a[i]=='i'){gi1=false;gj1=true;continue;}
        if(a[i]=='j'){gi1=false;gj1=false;gk1=true;continue;}
        if(gi1){i1+=a[i];}//Storing i value in i1
        if(gj1){j1+=a[i];}//Storing j value in j1
        if(gk1){k1+=a[i];}//Storing k value in k1
    }
//DISPLACEMENT 
    //To store i,j,k values of Displacement.
    string i2="",j2="",k2="";
    
    //Used to allow digits to be stored in their respective variables.
    bool gi2=true,gj2=false,gk2=false;
    
    //Extracting Force values from string a and store them in i1,j1,k1.
    for(int i=0;i<(b.length()-1);i++){
        if(b[i]=='i'){gi2=false;gj2=true;continue;}
        if(b[i]=='j'){gi2=false;gj2=false;gk2=true;continue;}
        if(gi2){i2+=b[i];}//Storing i value in i2
        if(gj2){j2+=b[i];}//Storing j value in j2
        if(gk2){k2+=b[i];}//Storing k value in k2
    }
//To convert string i1,j1,k1,i2,j2,k2 -to- integers
    stringstream geeki1(i1);
    stringstream geekj1(j1);
    stringstream geekk1(k1);
    stringstream geeki2(i2);
    stringstream geekj2(j2);
    stringstream geekk2(k2);
    int f1=0,f2=0,f3=0,d1=0,d2=0,d3=0;
    geeki1>>f1;
    geekj1>>f2;
    geekk1>>f3;
    geeki2>>d1;
    geekj2>>d2;
    geekk2>>d3;
    
    //To add + and - sign
    string str,sty,stm;
    
    // For i
    if((f2*d2)>0)str="+";
    else{str="-";}
    
    //For j
    if((f1*d1)>0){stm="+";}
    else{stm="-";}
    
    //For k
    if((f3*d3)>0)sty="+";
    else{sty="-";}
    
    //Printing result
    cout<<stm<<abs(f1*d1)<<"i"<<str<<abs(f2*d2)<<"j"<<sty<<abs(f3*d3)<<"k"<<endl;
	return 0;
}
