import java.util.Scanner;

public class PowerDenominations {
	
	public static void main(String args[])
	{
		int penny=0, nickel=0, dime=0, quarter=0;
		
		Scanner input = new Scanner(System.in);
		System.out.println("\n Enter the amount: ");	//user input of amount
		int amt = Integer.parseInt(input.nextLine());
		
		if(amt == 0)
		{
			System.out.println("Amount is 0");
		}
		else
		{
			while(amt>=25)
			{
				quarter++;		//increment number of quarter coins
				amt=amt-25;		//subtract original amount by 25
			}
			System.out.println("Quarters used: "+quarter);
			
			while(amt>=10)
			{
				dime++;			//increment number of dime coins
				amt=amt-10;		//subtract remaining amount by 10
			}
			System.out.println("Dimes used: "+dime);
			
			while(amt>=5)
			{
				nickel++;		//increment number of nickel coins
				amt=amt-5;		//subtract remaining amount by 5
			}
			System.out.println("Nickels used: "+nickel);
			
			while (amt < 5)
			{
				if(amt!=0)
				{
					penny++;		//increment number of penny coins
					amt=amt-1;		//subtract remaining amount by 1
				}
				else
				{	
					System.out.println("Pennies used: "+penny);
					break;
				}
			}
		}
		
		System.out.println("\n Enter the value of c: ");	//user input for value of c
		int c = Integer.parseInt(input.nextLine());
		System.out.println("\n Enter the value of k: ");	// user input for value of k
		int k = Integer.parseInt(input.nextLine());
		System.out.println("\n Enter the amount: ");		// user input of the amount
		int pow_amount = Integer.parseInt(input.nextLine());
		input.close();
		int power=0;
		int coin_used=0;
		int arr_deno[] = new int[k+1];
		
		for(int j=0; j <=k ; j++)
		{
			power = (int) Math.pow(c, j);		// calculate c to the power k
			arr_deno[j] = power;				// store new denomination values in an array
			System.out.print("\nThe denominations of coins are " +arr_deno[j]);
		}
		
		
		for(int i=k; i >0; i--)
		{
			coin_used = pow_amount/arr_deno[i];		// find the number of coins with a particular denomination
			System.out.println("\n "+ coin_used + " coins are used for " +arr_deno[i]+ "denominations value");
			pow_amount %= arr_deno[i];	//find the remaining amount		
		}
	}
}
