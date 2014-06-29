import java.util.ArrayList;

public class InterestingDigits {

	
	public int[] digits(int b){
		ArrayList<Integer> result = new ArrayList<Integer>();
		for(int d = 2; d< b; d++){
			boolean f = true;
			
			for(int n = 2; ; n++){
				int sum = 0;
				int res = n*d;
				int cnt =0;
				while(res > 0){
					sum += res%b;
					res/=b;
					cnt++;
				}
				if(cnt > 3)
					break;
				if(sum%d != 0)
				{
					f = false;
					break;
				}
			}
			
			if(f)
				result.add(d);
		}
		int[] r = new int[result.size()];
		for(int i = 0; i< result.size(); i++){
			r[i] = result.get(i);
		}
		//System.out.println(result);
		return r;
	}
}
