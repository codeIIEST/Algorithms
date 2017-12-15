/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.util.Scanner;
class Student{
    int key;
    String date;
    String name;
    Student next;
}
class Hashtable{
    Scanner s=new Scanner(System.in);
    
    Student node=new Student();
    static Hashtable n=new Hashtable();
    Student arr[]=new Student[10];
    void Hash(){

        System.out.print("enter input elements");
        for(int x=0;x<5;x++) {
            Student node=new Student();
            node.key = s.nextInt();
            node.date=s.next();
            node.name=s.next();
            
        int v= n.calculate(node.key);
            
if (arr[v]==null)
{
node.next=null;
arr[v]=node;
}
else
{
            Student ptr;
            ptr=arr[v];
            while(ptr.next!=null){
                ptr=ptr.next;
            }
            ptr.next=node;
            node.next=null;
} 
       }
    }
    int calculate(int value)
    {
        int index =value%10;
        return index;
    }
    void display()
    {
        for(int i=0;i<10;i++){
    if(arr[i]==null)
{
System.out.println(arr[i]);
}
else
{
Student ptr=arr[i];
while(ptr!=null)
{
System.out.print("->"+ptr.key);

ptr=ptr.next;
}
System.out.println();
}
    }}
    public static void main(String args[])
    {

       n.Hash();
        n.display();
    }
}
