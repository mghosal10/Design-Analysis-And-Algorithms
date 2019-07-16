import java.util.Scanner;

public class K_smallest_elements {
		
		static int[] input_arr;
		
		public static void main(String[] args)
		{
			try
			{
				Scanner input = new Scanner(System.in);
				input_arr = read_input();					//read user input
				System.out.println("\n\nEnter the value of k:");
			    int k = Integer.parseInt(input.nextLine());		
			    input.close();
			    int k_element_arr[] =new int[k];
				int[] array = SelectionSort();			// call SelectionSort
				
				System.out.println("\nThe sorted array is : ");
				for(int a=0; a<k ;a++)
				{
					System.out.print("" +array[a] +" ");    //print sorted array
					k_element_arr[a] = array[a];
				}
				
				//find median
				if(k_element_arr.length %2 == 0)			//median if number of elements are even
				{
					int div= k_element_arr.length/2;
					float sum_mid_nos= k_element_arr[div]+k_element_arr[div-1];
					float mid_val = sum_mid_nos/2;
					System.out.format("\n\nThe median is %.1f", mid_val);
				}
				else
				{
					//median if number of elements are odd
					int mid_index= array.length/2;
					System.out.println("\n\nThe median is " +k_element_arr[mid_index]);
				}	
					
			}
			catch(Exception ex)
			{
				throw ex;
			}
		}
		
		private static int[] read_input()
		{
			try 
			{
				Scanner input = new Scanner(System.in);
				System.out.println("Enter the number of elements : ");
				int input_size= Integer.parseInt(input.nextLine());		//read number of elements in the array
			
				System.out.println("\nEnter the numbers:");
				int[] elements= new int[input_size];					// enter the elements of the array
				for(int i=0; i< input_size; i++)
				{
					elements[i] = input.nextInt();
						
				}	
				
				return elements;
			}
			catch(Exception ex)
			{
				throw ex;
			}
		}
		
		private static int[] swap(int index_to_swap, int min_val)
		{
			// swap minimum element with current element
			int temp= input_arr[min_val];
			input_arr[min_val] = input_arr[index_to_swap];
			input_arr[index_to_swap] = temp;
			return input_arr;
		}
		
		private static int[] SelectionSort()
		{
			try
			{
				int min_val_index = 0;
				int[] array= {};
				
				for(int i=0; i < input_arr.length-1 ;i++)
				{
					min_val_index = i;					//set current element as minimum
					
					//check the element whether it is the minimum
					for(int j=i+1; j< input_arr.length; j++)
					{
						if(input_arr[j] < input_arr[min_val_index])
						{
							min_val_index = j;
						}			
					}
					array=  swap(i, min_val_index);		// call swap function
				}
				return array;
			
			}
			catch(Exception ex)
			{
				throw ex;
			}
		}
}
