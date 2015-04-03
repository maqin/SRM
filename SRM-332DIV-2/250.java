public class TextStatistics {
    /*public static void main(String[] args){
        TextStatistics t = new TextStatistics();
        System.out.println(t.averageLength("This is div2 easy problem."));
        System.out.println(t.averageLength("Hello, world!"));
        System.out.println(t.averageLength("Simple"));
        System.out.println(t.averageLength(""));
        System.out.println(t.averageLength("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"));
    }*/
    public double averageLength(String text){
        int word = 0;
        int charLen = 0;
        int len = text.length();
        boolean pre = false;
        if(len==0)
            return 0.0;
        for(int i = 0; i<len; i++){
            char ch = text.charAt(i);
            if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')) {
                charLen++;
                pre = true;
            }
            else
                if(pre==true) {
                    word++;
                    pre = false;
                }
        }
        if(Character.isLetter(text.charAt(len-1)))
           word++;
        if(word==0 && charLen==0)
        		return 0;
        //System.out.println(word+"    "+charLen);
        return 1.0*charLen/word;
    }
}
