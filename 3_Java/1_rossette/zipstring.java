/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

/**
 *
 * @author sete
 */
public class Test {

    /**
     * @param string1
     * @param args the command line arguments
     */
    public static String zipstring(String string1, String string2) {
        String val = "";
        if (string1.length() != string2.length())
        {
             val = "Empty String";
        }
        else 
        {
            String newString = "";
            for (int i=0; i<string1.length(); i++)
            {
                newString += (Character.toString(string1.charAt(i))).concat(Character.toString(string2.charAt(i)));
            }
            val = newString;
        }
        return val;
    }
    
    public static void main(String[] args) {
        // TODO code application logic here
        String String1 = "abc";
        String String2 = "123";
        String val = zipstring(String1, String2);
        System.out.println(val);
    }
    
}
