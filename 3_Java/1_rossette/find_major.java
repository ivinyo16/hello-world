/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import java.util.Arrays;

/**
 *
 * @author sete
 */
public class Test {

    /**
     * @param arr
     * @param string1
     * @param args the command line arguments
     */
    public static int find_major(int[] arr) {
       int times = 0; int temp_times = 0;
       int num = 0; int temp_num = 0;
       int val = 0;
       Arrays.sort(arr);
       
       for (int i=0; i<(arr.length -1); i++)
       {
            if (arr[i] == arr[i+1])
            {
                 temp_times = temp_times + 1;
                // temp_num = arr[i];
            }
            else
            {
                if (temp_times > times)
                {
                    num = arr[i];
                    times = temp_times;
                }
            }
       }

       if ((times+1) > arr.length/2)
       {
           val = num;
       }
       else
       {
           val = 0;
       }
       return val;
    }
    
    public static void main(String[] args) {
        // TODO code application logic here
        int[] arr = {1,2,2,3,3,3,3,3,4,4};
        int val = find_major(arr);
        System.out.println(val);
    }
    
}
