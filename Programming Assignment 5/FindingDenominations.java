import java.util.Scanner;
import java.util.stream.IntStream;

public class FindingDenominations {
	
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		System.out.println("\n Enter the amount: ");		// User input of amount and coin denominations
		int amount = Integer.parseInt(input.nextLine());
		System.out.println("\n Enter the number of coin denominations: ");
		int deno_num = Integer.parseInt(input.nextLine());
		System.out.println("\n Enter the coin denominations: ");  // Please give denominations in descending order
		int deno[] = new int[deno_num];
		for(int i=0; i<deno_num; i++)
		{
			deno[i] = input.nextInt();
		}
		
		input.close();
		
		boolean flag = IntStream.of(deno).anyMatch(x->x==1);   //check if input contains 1
		
		if(flag)
		{
			int penny =1, count=0;
			amount= amount-1;		// reduce amount by 1 since one penny already exists
			
			for(int i=0; i<deno_num ; i++)
			{
				count=0;
				while(amount>=deno[i])
				{
					count++;		// count number of coin denominations
					amount=amount-deno[i];		// decrement amount value by denomination value
					if(deno[i] == 1)
					{
						penny++;	// count number of pennies
					}
					
				}
				if(deno[i] != 1)
				{
					System.out.println("\n "+ count + " coins are used for " +deno[i]+ "denominations value");
				}
				else
				{
					System.out.println("\n "+ penny + " coins are used for " +deno[i]+ "denominations value");
				}
			}	
		}
		else
		{
			System.out.println("No penny denominations");
			return;
		}
	}	
}
