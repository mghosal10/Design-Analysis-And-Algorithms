import java.util.Scanner;

public class Selection_Sort {
	
	static float[] input_arr;
	
	public static void main(String[] args)
	{
		try 
		{
			input_arr = read_input();				//read user input
			float[] array = SelectionSort();		// call SelectionSort
			
			System.out.println("\nThe sorted array is : ");
			for(int k=0; k<array.length ;k++)
			{
				System.out.print("" +array[k] +" ");		// print sorted array
			}
		}
		catch(Exception ex)
		{
			throw ex;
		}
	}
	
	private static float[] read_input()
	{
		try
		{
			Scanner input = new Scanner(System.in);
			System.out.println("Enter the number of elements : ");
			int input_size= Integer.parseInt(input.nextLine());			//read number of elements in the array
			System .out.println("\nEnter the elements:");
			float[] elements= new float[input_size];					// enter the elements of the array
			for(int i=0; i< input_size; i++)
			{
				elements[i] = input.nextFloat();
			}
			input.close();
			return elements;
		}
		catch(Exception ex)
		{
			throw ex;
		}	
	}
	
	private static float[] swap(int index_to_swap, int min_val)
	{
		// swap minimum element with current element
		float temp= input_arr[min_val];
		input_arr[min_val] = input_arr[index_to_swap];
		input_arr[index_to_swap] = temp;
		return input_arr;
	}
	
	private static float[] SelectionSort()
	{
		try
		{
			int min_val_index = 0;
			float[] array= {};
			
			for(int i=0; i < input_arr.length-1 ;i++)
			{
				min_val_index = i;			//set current element as minimum
				
				//check the element whether it is the minimum
				for(int j=i+1; j< input_arr.length; j++)
				{
					if(input_arr[j] < input_arr[min_val_index])
					{
						min_val_index = j;
					}			
				}
				array=  swap(i, min_val_index);		//call swap function
			}
			return array;
		}
		catch(Exception ex)
		{
			throw ex;
		}
	}
}
