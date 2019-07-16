import java.util.Scanner;

public class FindMatch {
	
	public static void main(String args[])
	{
		try 
		{
			Scanner input = new Scanner(System.in);
			System.out.println("Enter number of elements in the array: ");
			int num = input.nextInt();		// enter number of elements in the array
			int[] input_arr = new int[num];
			System.out.println("\nEnter the elements: ");
			for(int i=1; i<num-1 ; i++)
			{
				input_arr[i] = input.nextInt();			// enter the elements in the array
			}
			input.close();
			
			int low = 0;
			int high = input_arr.length-1;
			
			int k =bin_Search(input_arr, low, high);
			if(k == 0)
			{
				System.out.println("No index such that A[i] = i. Match not found!");
			}
			
		}
		catch(Exception ex)
		{
			throw ex;
		}	
	}
	
	private static int bin_Search(int[] input_arr, int low, int high)
	{
		
		int mid = 0;
		
		if(high >= low)
		{
			mid = (low+high)/2;			// find mid value
			
			//if element is present in middle
			if(input_arr[mid] == mid)
			{
				System.out.println("Element "+input_arr[mid]+ " equals index " +mid + ". Match Found!");
				return mid;			// find the match
			}
			else if(input_arr[mid] < mid)   // if element is smaller  than mid  it can be present in left subarray
			{
				return bin_Search(input_arr, mid+1, high);		//recursive call to bin_search
			}
			else if(input_arr[mid] > mid)   // if element is smaller  than mid  it can be present in right subarray
			{
				return bin_Search(input_arr, low, (mid-1));		//recursive call to bin_search
			}
		}
		return 0;
	}
}
