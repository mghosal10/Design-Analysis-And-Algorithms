import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Cool_Sort {
	
	
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		System.out.println("Enter size of H : ");
		int h_size = input.nextInt();		//enter size  of h
		int[] h = new int[h_size];
		System.out.println("\nEnter the values for H : ");		//enter values of h
		for(int i =0 ; i<h_size ; i++)
		{
			h[i] = input.nextInt();
			System.out.print(" " +h[i]);
		}
		
		System.out.println("\nEnter size of array : ");
		int arr_size = input.nextInt();		//enter the size of array
		int[] input_arr = new int[arr_size];
		System.out.println("\nEnter the elements of the array : ");
		for(int i =0 ; i<arr_size ; i++)
		{
			input_arr[i] = input.nextInt();		// enter the elements of array
		}
		
		input.close();
		
		int x = 0;
		
		//run the loop h times
		for(int i=0; i<h_size ; i++)
		{
			int y=0, z=0;
			
			int[] arr = create_subarray(input_arr, h[x], arr_size);		// create subarrays of size h
			
			int[] sorted_arr = coolSort(arr, arr.length);			// call insertion sort function
			
			for(int k =0; k<h_size; k++)
			{
				while(y < arr_size)
				{
					input_arr[y] = sorted_arr[z];		// copy elements of sorted array into a new array at a distance of h
					y = y+h[x];
					z++;
				}
			}
			x++;
		}
		
		System.out.println("\nSorted array is: ");
		for(int p=0; p<input_arr.length; p++)
		{
			System.out.print(" " +input_arr[p]);		//print sorted array
		}
	}
	
	public static int[] create_subarray(int[] input_arr, int h, int arr_size)
	{
		try
		{
			List<Integer> sub_arr = new ArrayList<>();
			int a =0;
			// create subarray of size h
			while(a < arr_size)
			{	
				sub_arr.add(input_arr[a]);
				a = a+h;
			}				
	
			//convert arraylist to int[]
			int[] converted_arr = sub_arr.stream().mapToInt(Integer::intValue).toArray();   
			return converted_arr;
		}			
		catch(Exception ex) 
		{
			throw ex;
		}
	}
	
	public static int[] coolSort(int[] input_arr, int subarr_size)
	{
		try
		{
			int key=0, i=0;
			for(int j=1; j< subarr_size;j++)
			{
				key = input_arr[j];			//assign a key
				i= j-1;
				while(i>=0 && input_arr[i]>key)				//check whether previous element is greater than the key
				{
					input_arr[i+1] = input_arr[i];			//shift elements
					i=i-1;					// decrement the value of i
				}
				input_arr[i+1] = key;		// place the key in proper position
			}	
			return input_arr;
		}
		catch(Exception ex)
		{
			throw ex;
		}	
	}
}
