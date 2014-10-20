import java.util.Arrays;
public class FanFailure {
	public static void main(String[] args){
		FanFailure ff = new FanFailure();
		int[] cap = {676, 11, 223, 413, 823, 122, 547, 187, 28};
		int mincooling = 1000;
		System.out.println(Arrays.toString(ff.getRange(cap,mincooling)));
	}
	public int[] getRange(int[] capacities, int minCooling){
		int[] res = new int[2];
		Arrays.sort(capacities);

		int sum = 0;
		int n = capacities.length-1;
		while(sum<=minCooling){
			sum+=capacities[n];
			n--;
		}
		res[0] = n+1;
		sum = 0;
		n = 0;
		while(sum<=minCooling){
			sum += capacities[n];
			n++;
		}
		res[1] = capacities.length-n;
		return res;
	}
}
