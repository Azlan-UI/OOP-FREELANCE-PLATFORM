import java.util.*;
class BookStoreSalesTracker{
    public static void main(String[]args) {
        Scanner sc=new Scanner(System.in);
        String[] Days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        HashMap<String, int[]> Books = new HashMap<>();
        Books.put("Fiction", new int[]{1, 2, 3, 4, 5, 6, 7});
        Books.put("Self Help", new int[]{7, 2, 5, 4, 5, 8, 7});
        System.out.println("Enter a day e.e.,Friday");
        String day=sc.nextLine();
        int dayIndex=0;
        for(int i=0;i<Days.length;i++){
            if(Days[i].equals(day)){
                dayIndex=i;
            }
        }
        for(String genre:Books.keySet()){
            int[]sales=Books.get(genre);
            System.out.println(genre+" "+sales[dayIndex]);
        }
    }


}