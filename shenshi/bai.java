
public class Main {
   public static void main(String[] args) {
     Scanner sc= new Scanner(System.in);
     long n = sc.nextLong();
     long m = sc.nextLong();
     long k = sc.nextLong();  
     System.out.println(find(n,m,k)); 
   }
   private static long find(long n,long m,long k){
      long a=0;
      long b=0;
      long c=0;
      long min = Math.min(n,m);
      while ((n-a)*(m-b)) {
        if(m==n){
          a++; 
          b++;
        }else if(m>n){
          a++;
          
        }else{
          b++;
        }
      }
      return a+b;
   }
}
