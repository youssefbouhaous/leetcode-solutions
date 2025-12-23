import java.time.LocalDate;

class Solution {
    public int dayOfYear(String date) {
        String[] arr = date.split("-");
        
        int year = Integer.parseInt(arr[0]);
        int month = Integer.parseInt(arr[1]);
        int day = Integer.parseInt(arr[2]);

        LocalDate localDate = LocalDate.of(year, month, day);
        return localDate.getDayOfYear();
    }
}