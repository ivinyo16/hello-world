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
    public static int factorial(int num) {
       int val = 0;
       if (num == 1)
       {
           val = 1;
       }
       else
       {
           val = num * factorial(num-1);
       }
       return val;
    }
    
    public static void main(String[] args) {
        // TODO code application logic here
        int num = 3;
        int val = factorial(num);
        System.out.println(val);
    }
    
}
