
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class QuiningTopCoder
{
	public int pop(Stack<Integer> stack){
		if(stack.isEmpty()) return 0;
		else return stack.pop();
	}
	public String testCode(String source)
	{
		Stack<Integer> stack = new Stack<Integer>();
		int ip = 0;
		int d = 1;
		int cycle = 0;
		int matched = 0;
		int n = source.length();
		while(cycle<80000){
			char c = source.charAt(ip);
			if(c>='0' && c<='9'){
				stack.push(c - '0');
				
			}else if(c=='$'){
				pop(stack);
			}else if(c==':'){
				int x = pop(stack);
				stack.push(x);
				stack.push(x);
			}else if(c=='W'){
				int a = pop(stack);
				int b = pop(stack);
				stack.push(a);
				stack.push(b);
			
			}else if(c==','){
				int x=pop(stack);
				char pr = source.charAt(Math.abs(x)%n);
				if(source.charAt(matched) != pr)
					return "MISMATCH "+cycle;
				matched ++;
				if(matched == n)
					return "QUINES "+cycle;
				
			}else if(c=='+'){
				int a = pop(stack);
				int b = pop(stack);
				if(a+b < -1000000000 || a+b > 1000000000)
					return "OVERFLOW "+cycle;
				stack.push(a+b);
			}else if(c=='-'){
				int a = pop(stack);
				int b = pop(stack);
				if(a-b < -1000000000 || a-b > 1000000000)
					return "OVERFLOW "+cycle;
				stack.push(a-b);
			}else if(c=='#'){
				ip = (3*n+ip+2*d)%n;
				cycle ++;
				continue;
			}else if(c=='R'){
				d = -d;
			}else if(c=='S'){
				int x = pop(stack);
				if(x > 0)
					stack.push(1);
				else
					stack.push(-1);
			}else if(c=='_'){
				int x = pop(stack);
				d = x%n;
			}else if(c=='J'){
				int x = pop(stack);
				cycle ++;
				ip = Math.abs(x)%n;
				continue;
			}else if(c=='@'){
				break;
			}
			
			
			ip = (3*n+ip+d)%n;
			cycle ++;
		}
		if(cycle<80000)
			return "BADEND "+cycle;
		else
			return "TIMEOUT";
		
	}
	
	public static void main(String[] args)
	{
		long time;
		String answer;
		boolean errors = false;
		String desiredAnswer;
		
		
		time = System.currentTimeMillis();
		answer = new QuiningTopCoder().testCode(",");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "QUINES 0";
		System.out.println("Your answer:");
		System.out.println("\t\"" + answer + "\"");
		System.out.println("Desired answer:");
		System.out.println("\t\"" + desiredAnswer + "\"");
		if (!answer.equals(desiredAnswer))
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new QuiningTopCoder().testCode("_");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "TIMEOUT";
		System.out.println("Your answer:");
		System.out.println("\t\"" + answer + "\"");
		System.out.println("Desired answer:");
		System.out.println("\t\"" + desiredAnswer + "\"");
		if (!answer.equals(desiredAnswer))
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new QuiningTopCoder().testCode("1:+:1J");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "OVERFLOW 147";
		System.out.println("Your answer:");
		System.out.println("\t\"" + answer + "\"");
		System.out.println("Desired answer:");
		System.out.println("\t\"" + desiredAnswer + "\"");
		if (!answer.equals(desiredAnswer))
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new QuiningTopCoder().testCode("0,1+:#@:$1J");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "QUINES 91";
		System.out.println("Your answer:");
		System.out.println("\t\"" + answer + "\"");
		System.out.println("Desired answer:");
		System.out.println("\t\"" + desiredAnswer + "\"");
		if (!answer.equals(desiredAnswer))
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new QuiningTopCoder().testCode("0,1+::9W-9W-S1W1W:+2_J_@_@");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "BADEND 437";
		System.out.println("Your answer:");
		System.out.println("\t\"" + answer + "\"");
		System.out.println("Desired answer:");
		System.out.println("\t\"" + desiredAnswer + "\"");
		if (!answer.equals(desiredAnswer))
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new QuiningTopCoder().testCode("#R,#:+1+:#,R#");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "QUINES 97";
		System.out.println("Your answer:");
		System.out.println("\t\"" + answer + "\"");
		System.out.println("Desired answer:");
		System.out.println("\t\"" + desiredAnswer + "\"");
		if (!answer.equals(desiredAnswer))
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		time = System.currentTimeMillis();
		answer = new QuiningTopCoder().testCode("R,#1+1:");
		System.out.println("Time: " + (System.currentTimeMillis()-time)/1000.0 + " seconds");
		desiredAnswer = "MISMATCH 7";
		System.out.println("Your answer:");
		System.out.println("\t\"" + answer + "\"");
		System.out.println("Desired answer:");
		System.out.println("\t\"" + desiredAnswer + "\"");
		if (!answer.equals(desiredAnswer))
		{
			errors = true;
			System.out.println("DOESN'T MATCH!!!!");
		}
		else
			System.out.println("Match :-)");
		System.out.println();
		
		
		if (errors)
			System.out.println("Some of the test cases had errors :-(");
		else
			System.out.println("You're a stud (at least on the test data)! :-D ");
	}

}
//Powered by [KawigiEdit] 2.0!
