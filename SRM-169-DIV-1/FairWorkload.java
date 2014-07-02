public class FairWorkload {
	public static void main(String[] args){
		FairWorkload f = new FairWorkload();
		int n = f.getMostWork(new int[]{ 10, 20, 30, 40, 50, 60, 70, 80, 90 },3);
		System.out.println(n);
	}
	public int getMostWork(int[] folders, int workers){
		int lo = 0;
		int hi = 15000;
		while(lo+1 < hi){
			int mid = lo +(hi - lo)/2;
			if(cabinets(folders, mid) <= workers)
				hi = mid;
			else 
				lo = mid;
		}
		return hi;
	}
	public int cabinets(int[] folders, int limit){
		int cnt = 0;
		int sum = 0;
		for(int i = 0; i<folders.length; i++){
			if(folders[i] > limit)
				return Integer.MAX_VALUE;
			sum += folders[i];
			if(sum > limit){
				cnt++;
				sum = folders[i];
			}			
			
		}
		return cnt+1;
	}
	
}
