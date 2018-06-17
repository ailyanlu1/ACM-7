import java.math.*;
import java.util.Scanner;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner  cin = new Scanner(System.in);

		BigInteger []Catalan = new BigInteger[220];
		Catalan[0] = BigInteger.ONE;
		Catalan[1] = BigInteger.ONE;
		int x,y;
		for (int i = 1;i < 110;++i){
			x = 4 * i - 2;
			y = i +1;
			Catalan[i] = Catalan[i-1].multiply(BigInteger.valueOf(x)).divide(BigInteger.valueOf(y));
		}

		int n;
		while(cin.hasNextInt()){

			n = cin.nextInt();
			if ( n == -1) break;
			System.out.println(Catalan[n]);
		}

		cin.close();
	}
}