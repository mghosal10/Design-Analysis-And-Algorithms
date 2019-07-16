
import java.util.Scanner;

public class Dynamic {
	
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		
		//user input for items
		System.out.println("\nEnter number of items: ");
		int item_size= Integer.parseInt(input.nextLine());
		
		int item_arr[] = new int[item_size];
		System.out.println("\nEnter the items: ");
		
		for(int i=0;i<item_size;i++)
		{
			item_arr[i] = input.nextInt();
			//System.out.print(" " +item_arr[i]);
		}
		
		//user input for weights
		System.out.println("\nEnter the weights: ");
		int weight_arr[] = new int[item_size];
		
		for(int i=0;i<item_size;i++)
		{
			weight_arr[i] = input.nextInt();
			//System.out.print(" " +weight_arr[i]);	
		}
		
		
		//user input for values
		System.out.println("\nEnter the values: ");
		int value_arr[] = new int[item_size];
		
		for(int i=0;i<item_size;i++)
		{
			value_arr[i] = input.nextInt();
			//System.out.print(" " +value_arr[i]);
		}
		
		//user input for weight of knapsack
		System.out.println("\nEnter weight of knapsack: ");
		int knapWeight= input.nextInt();
		
		input.close();
		
		//build table
		int[][] knap_table= new int[item_size+1][knapWeight+1];
		int i,j=0;
		int wi=0, vi=0;
		
		for(i=1; i<=item_size; i++)
		{
			for(j=1; j<=knapWeight; j++)
			{
				wi= weight_arr[i-1];		// compute weight of (i-1)th element
				//System.out.println(""+wi);
				vi= value_arr[i-1];			// compute value of (i-1)th element
				//System.out.println(""+vi);
				if(i == 0 || j == 0)
				{
					knap_table[i][j]= 0;
					
				}
			    if(wi <= j)
				{ 	
			    	knap_table[i][j] = Math.max(knap_table[i-1][j], vi+knap_table[i-1][j-wi] );		//compute maximum value		
				}
				else
				{
					knap_table[i][j] = knap_table[i-1][j];
				}	
			}
		}
		
		//print table
		for(int p=0; p<=item_size;p++)
		{
			for(int q=0; q<=knapWeight; q++)
			{
				System.out.print("" +knap_table[p][q]+" ");
			}
			System.out.print("\n");
		}
		System.out.println("\nMaximum value in knapsack is " +knap_table[item_size][knapWeight]);	
	
		//items in  knapsack
		int l = item_size;
		int k = knapWeight;
		int knap_arr[] = new int[item_size+1];
		while(l>0 && k>0)
		{
			if(knap_table[l][k] != knap_table[l-1][k])
			{
				
				knap_arr[l] = 1;   //mark lth item in knapsack
				l=l-1;
				k=k-weight_arr[l];		
			}
			else
			{
				l=l-1;
			}
		}
		for(int o=1; o<=item_size; o++)
		{
			if(knap_arr[o] == 1)
			{
				System.out.print("\nItems in knapsack are " +o); //print items in a knapsack
			}				
		}			
	}
}
