import java.util.HashMap;
import java.util.Map;


/*
 In this problem , need to find the maximum scoring value based on the 2 dna strings given. The similarity between
 2 characters were given in the scoring matrix.
 Need to maximize the total simiarlity value in the string by adding _ wherever it is applicable, should not
 match 2 spaces in the dna

*/

public class ModifiedEditDistance {

    public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String dna1 = new String("AGTGATG");
		String dna2 = new String("GTTAG");
		
		Map<Character,Integer > map = new HashMap<Character,Integer>();
		map.put('A', 0);
		map.put('C', 1);
		map.put('G', 2);
		map.put('T', 3);
		map.put('-', 4);
		
		int m = dna1.length();
		int n = dna2.length();
        //System.out.println(n);
		int[][] scoring = {{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,-1000000}};
		int i,j,k;
		
		//dynamic programming
		int [][] sol = new int[m+1][n+1];
        sol[0][0]=0;
		for(i=1;i<=m;i++){
          //  System.out.println(scoring[map.get(dna1.charAt(i-1))][map.get('-')]);
            sol[i][0] = scoring[map.get(dna1.charAt(i-1))][map.get('-')]+ sol[i-1][0];
         //   System.out.println(sol[i][0]);
		}
		for(i=1;i<=n;i++){
			sol[0][i] = scoring[map.get('-')][map.get(dna2.charAt(i-1))] + sol[0][i-1];
		}
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
                    sol[i][j]=Math.max((Math.max(sol[i-1][j]+scoring[map.get(dna1.charAt(i-1))][map.get('-')],sol[i][j-1]+scoring[map.get(dna2.charAt(j-1))][map.get('-')])), sol[i-1][j-1] + scoring[map.get(dna1.charAt(i-1))][map.get(dna2.charAt(j-1))]);
			}
		}		
	System.out.println(sol[m][n]);
	}
}	