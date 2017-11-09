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
    public static boolean is_leapyear(int year) {
        if (year%4 == 0  && year%100 != 0 || year%400 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    public static void main(String[] args) {
        // TODO code application logic here
        int year = 2016;
        boolean val = is_leapyear(year);
        System.out.println(val);
    }
    
}
