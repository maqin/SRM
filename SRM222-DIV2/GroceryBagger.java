import java.util.*;
public class GroceryBagger {
	
	public int minimumBags(int strength, String[] itemType){
		Map<String,Integer> dict = new HashMap<String,Integer>();
		for(String s: itemType){
			if(!dict.containsKey(s))
				dict.put(s, 0);			
			dict.put(s, dict.get(s)+1);			
		}
		int res = 0;
		for(int i:dict.values()){
			res += Math.ceil(1.0*i/strength);
		}
		return res;
	}
}
